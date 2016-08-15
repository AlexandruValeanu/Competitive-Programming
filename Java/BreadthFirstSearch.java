import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Graph{
    private static class Edge{
        int node;
        int next;

        Edge(int node, int next){
            this.node = node;
            this.next = next;
        }
    }

    final static int NIL = -1;
    private int[] head;
    private ArrayList<Edge> graph;

    private int N;
    private int counter;

    Graph(int N){
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

    void addEdge(int x, int y){
        assert 1 <= x && x <= N;
        x--; y--;
        graph.add(new Edge(y, head[x]));
        head[x] = counter++;
    }

    int getHead(int node){
        assert 1 <= node && node <= N;
        node--;
        return head[node];
    }

    int getNext(int p){
        assert 0 <= p && p < counter;
        return graph.get(p).next;
    }

    int getNeighbour(int p){
        assert 0 <= p && p < counter;
        return graph.get(p).node + 1;
    }
}

class BreadthFirstSearch {
    static int[] bfs(Graph graph, int source){
        final int N = graph.getN();

        int[] distance = new int[N];
        Arrays.fill(distance, -1);
        Queue<Integer> queue = new LinkedList<>();

        source--;
        distance[source] = 0;
        queue.add(source);

        while (!queue.isEmpty()){
            int node = queue.remove();

            for (int p = graph.getHead(node + 1); p != Graph.NIL; p = graph.getNext(p)) {
                int son = graph.getNeighbour(p) - 1;

                if (distance[son] == -1){
                    distance[son] = distance[node] + 1;
                    queue.add(son);
                }
            }
        }

        return distance;
    }
}
