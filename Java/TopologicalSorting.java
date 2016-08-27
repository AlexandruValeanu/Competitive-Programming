import java.util.*;

class TopologicalSorting {
    private static void dfs(int node, final Main.Graph G, final boolean[] visited, final Deque<Integer> list){
        visited[node] = true;

        for (int p = G.getHead(node); p != Main.Graph.NIL; p = G.getNext(p)) {
            int son = G.getNeighbour(p);

            if (!visited[son])
                dfs(son, G, visited, list);
        }

        list.addFirst(node);
    }

    static int[] topologicalSorting(final Main.Graph graph){
        final int N = graph.getN();
        boolean[] visited = new boolean[N + 1];
        Arrays.fill(visited, false);
        Deque<Integer> list = new ArrayDeque<>();

        for (int i = 1; i <= N; i++) {
            if (!visited[i])
                dfs(i, graph, visited, list);
        }

        int[] topSort = new int[N];

        for (int i = 0; i < N; i++) {
            topSort[i] = list.removeFirst();
        }

        return topSort;
    }
}

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
    private int[] degree;
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
        degree = new int[N];
        graph = new ArrayList<>();

        this.N = N;
        this.counter = 0;

        Arrays.fill(head, NIL);
        Arrays.fill(degree, 0);
    }

    void addEdge(int x, int y){
        if (!(1 <= x && x <= N)) throw new AssertionError();
        x--; y--;
        graph.add(new Edge(y, head[x]));
        head[x] = counter++;
        degree[x]++;
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

    boolean isEmpty(int node){
        if (!(1 <= node && node <= N)) throw new AssertionError();
        node--;
        return head[node] == NIL;
    }

    int size(int node){
        assert 1 <= node && node <= N;
        node--;
        return degree[node];
    }

    Graph transpose(){
        Graph GT = new Graph(N);

        for (int i = 1; i <= N; i++) {
            for (int son : getNeighbours(i))
                GT.addEdge(son, i);
        }

        return GT;
    }

    List<Integer> getNeighbours(int node){
        if (!(1 <= node && node <= N)) throw new AssertionError();

        List<Integer> list = new ArrayList<>();

        for (int p = head[node - 1]; p != NIL; p = graph.get(p).next) {
            list.add(graph.get(p).node + 1);
        }

        return list;
    }
}

