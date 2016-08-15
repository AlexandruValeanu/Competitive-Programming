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

class Edge implements Comparable<Edge>{
    int x, y;
    int cost;

    public Edge(int x, int y, int cost) {
        this.x = x;
        this.y = y;
        this.cost = cost;
    }

    public int compareTo(Edge edge){
        return Integer.compare(cost, edge.cost);
    }
}

class PrimMST {
    private WeightedGraph weightedGraph;
    private int N;
    private int[] distance, father;
    private boolean[] visited;

    PrimMST(WeightedGraph WG){
        this.weightedGraph = WG;
        this.N = WG.getN();
        this.distance = new int[N + 1];
        this.father = new int[N + 1];
        this.visited = new boolean[N + 1];
    }

    ArrayList<Edge> minimumSpanningTree(){
        ArrayList<Edge> treeEdges = new ArrayList<>();
        Queue<Node> minHeap = new PriorityQueue<>();

        Arrays.fill(distance, Integer.MAX_VALUE);
        Arrays.fill(father, -1);
        Arrays.fill(visited, false);

        distance[1] = 0;
        minHeap.add(new Node(distance[1], 1));

        while (!minHeap.isEmpty()){
            Node topNode = minHeap.remove();
            int node = topNode.node;

            if (distance[node] != topNode.distance)
                continue;

            visited[node] = true;

            if (father[node] != -1)
                treeEdges.add(new Edge(node, father[node], distance[node]));

            for (int p = weightedGraph.getHead(node); p != WeightedGraph.NIL; p = weightedGraph.getNext(p)) {
                int son = weightedGraph.getNeighbour(p);
                int cost = weightedGraph.getCost(p);

                if (!visited[son] && distance[son] > cost){
                    distance[son] = cost;
                    father[son] = node;
                    minHeap.add(new Node(distance[son], son));
                }
            }
        }

        return treeEdges;
    }
}