import java.util.ArrayList;
import java.util.Arrays;

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

class MaximumMatching {
    private Graph graph;
    private int V1, V2;
    private boolean[] used;
    private int[] matched;
    private boolean[] visited;

    MaximumMatching(int V1, int V2){
        graph = new Graph(V1 + V2);

        this.V1 = V1;
        this.V2 = V2;

        used = new boolean[V1];
        matched = new int[V1 + V2];
        visited = new boolean[V1 + V2];
    }

    void addEdge(int from, int to){
        graph.addEdge(from, V1 + to);
        graph.addEdge(V1 + to, from);
    }

    private boolean pairUp(int node){
        assert 0 <= node && node < V1;

        if (used[node])
            return false;

        used[node] = true;

        for (int p = graph.getHead(node + 1); p != Graph.NIL; p = graph.getNext(p)) {
            int son = graph.getNeighbour(p) - 1;
            if (matched[son] == -1){
                matched[son] = node;
                matched[node] = son;
                return true;
            }
        }

        for (int p = graph.getHead(node + 1); p != Graph.NIL; p = graph.getNext(p)) {
            int son = graph.getNeighbour(p) - 1;
            if (pairUp(matched[son])){
                matched[son] = node;
                matched[node] = son;
                return true;
            }
        }

        return false;
    }

    private void mark(int node, int side){
        if (side == 0){
            visited[node] = true;

            for (int p = graph.getHead(node + 1); p != Graph.NIL; p = graph.getNext(p)) {
                int son = graph.getNeighbour(p) - 1;

                if (!visited[son] && matched[node] != son) //not an edge from the matching
                    mark(son, side ^ 1);
            }
        }
        else{
            visited[node] = true;

            for (int p = graph.getHead(node + 1); p != Graph.NIL; p = graph.getNext(p)) {
                int son = graph.getNeighbour(p) - 1;

                if (!visited[son] && matched[node] == son) //edge from the matching
                    mark(son, side ^ 1);
            }
        }
    }

    void MVC_MIS(){
        Arrays.fill(visited, false);

        for (int i = 0; i < V1; i++) {
            if (matched[i] == -1)
                mark(i, 0);
        }
    }

    boolean[] minimumVertexCover(){
        boolean[] mvc = new boolean[V1 + V2];

        for (int i = 0; i < V1; i++)
            if (!visited[i])
                mvc[i] = true;

        for (int i = 0; i < V2; i++)
            if (visited[i + V1])
                mvc[i + V1] = true;

        return mvc;
    }

    boolean[] maximumIndependentSet(){
        boolean[] mis = new boolean[V1 + V2];

        for (int i = 0; i < V1; i++)
            if (visited[i])
                mis[i] = true;

        for (int i = 0; i < V2; i++)
            if (!visited[i + V1])
                mis[i + V1] = true;

        return mis;
    }

    int maximumMatching(){
        Arrays.fill(matched, -1);
        boolean changed;

        do {
            changed = false;
            Arrays.fill(used, false);

            for (int i = 0; i < V1; i++)
                if (matched[i] == -1)
                    changed |= pairUp(i);

        } while (changed);

        int matching = 0;

        for (int i = 0; i < V1; i++)
            if (matched[i] != -1)
                matching++;

        return matching;
    }

    int[] getMatched(){
        int[] matching = Arrays.copyOf(matched, V1);

        for (int i = 0; i < matching.length; i++) {
            if (matching[i] != -1)
                matching[i] = matching[i] - V1 + 1;
        }

        return matching;
    }
}
