import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

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

class StronglyConnectedComponents {
    private Graph G;
    private Graph GT;
    private int N;

    StronglyConnectedComponents(Graph graph){
        G = graph;
        GT = graph.transpose();
        N = graph.getN();
    }

    private void dfs(int node, boolean[] visited, List<Integer> list){
        visited[node] = true;

        for (int son : G.getNeighbours(node + 1)){
            if (!visited[son - 1])
                dfs(son - 1, visited, list);
        }

        list.add(node);
    }

    private void dfsT(int node, boolean[] visited, int[] color, int currentColor){
        color[node] = currentColor;
        visited[node] = false;

        for (int son : GT.getNeighbours(node + 1)){
            if (visited[son - 1])
                dfsT(son - 1, visited, color, currentColor);
        }
    }

    int[] topologicalSorting(){
        boolean[] visited = new boolean[N];
        Arrays.fill(visited, false);

        List<Integer> list = new ArrayList<Integer>();

        for (int i = 0; i < N; i++) {
            if (!visited[i])
                dfs(i, visited, list);
        }

        int[] array = new int[list.size()];

        for (int i = 0; i < N; i++) {
            array[i] = list.get(i);
        }

        return array;
    }

    int[] computeSCCs(){
        boolean[] visited = new boolean[N];
        Arrays.fill(visited, false);

        int[] color = new int[N];
        Arrays.fill(color, -1);

        ArrayList<Integer> list = new ArrayList<Integer>();

        for (int i = 0; i < N; i++) {
            if (!visited[i])
                dfs(i, visited, list);
        }

        int numberOfSCCs = 0;

        for (int i = N - 1; i >= 0; i--) {
            int v = list.get(i);

            if (visited[v]){
                dfsT(v, visited, color, numberOfSCCs++);
            }
        }

        return color;
    }
}
