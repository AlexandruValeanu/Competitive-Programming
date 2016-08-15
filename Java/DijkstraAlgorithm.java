import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;

class WeightedGraph{
    private class Edge{
        int node;
        int cost;
        int next;

        Edge(int node, int cost, int next){
            this.node = node;
            this.cost = cost;
            this.next = next;
        }
    }

    final static int NIL = -1;
    private int[] head;
    private ArrayList<Edge> graph;

    private int N;
    private int counter;

    WeightedGraph(int N){
        initialize(N);
    }

    public int getN() {
        return N;
    }

    private void initialize(final int N){
        head = new int[N];
        graph = new ArrayList<>();

        this.N = N;
        this.counter = 0;

        Arrays.fill(head, NIL);
    }

    void addEdge(int x, int y, int w){
        if (!(1 <= x && x <= N)) throw new AssertionError();
        x--; y--;
        graph.add(new Edge(y, w, head[x]));
        head[x] = counter++;
    }

    int getHead(int node){
        if (!(1 <= node && node <= N)) throw new AssertionError();
        node--;
        return head[node];
    }

    int getNext(int p){
        if (!(0 <= p && p < counter)) throw new AssertionError();
        return graph.get(p).next;
    }

    int getNeighbour(int p){
        if (!(0 <= p && p < counter)) throw new AssertionError();
        return graph.get(p).node + 1;
    }

    int getCost(int p){
        if (!(0 <= p && p < counter)) throw new AssertionError();
        return graph.get(p).cost;
    }
}

class Node implements Comparable<Node>{
    int distance;
    int node;

    public Node(int distance, int node) {
        this.distance = distance;
        this.node = node;
    }

    @Override
    public int compareTo(Node o) {
        return Integer.compare(distance, o.distance);
    }
}

class DijkstraAlgorithm {
    private final WeightedGraph weightedGraph;
    private final int[] distance;
    private final int N;

    DijkstraAlgorithm(WeightedGraph WG){
        weightedGraph = WG;
        this.N = WG.getN();
        distance = new int[N];
    }

    int[] computeDistances(int source){
        Arrays.fill(distance, Integer.MAX_VALUE);
        Queue<Node> minHeap = new PriorityQueue<>();

        source--;
        distance[source] = 0;
        minHeap.add(new Node(0, source));

        while (!minHeap.isEmpty()){
            Node topNode = minHeap.remove();
            int node = topNode.node;

            if (distance[node] != topNode.distance)
                continue;

            for (int p = weightedGraph.getHead(node + 1); p != WeightedGraph.NIL; p = weightedGraph.getNext(p)) {
                int son = weightedGraph.getNeighbour(p) - 1;
                int cost = weightedGraph.getCost(p);

                if (distance[son] > distance[node] + cost){
                    distance[son] = distance[node] + cost;
                    minHeap.add(new Node(distance[son], son));
                }
            }
        }

        return distance;
    }
}
