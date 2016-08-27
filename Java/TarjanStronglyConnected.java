import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

class TarjanStronglyConnected {
    private final Graph G;
    private final int N;

    private final int[] index, lowlink;
    private final boolean[] onStack;
    private final Stack<Integer> stack;

    private int numberOfSCCs;
    private int[] component;
    private int _index;

    TarjanStronglyConnected(Graph graph){
        this.G = graph;
        this.N = graph.getN();

        index = new int[N + 1];
        lowlink = new int[N + 1];

        onStack = new boolean[N + 1];
        stack = new Stack<>();
    }

    private void dfs(int node){
        index[node] = _index;
        lowlink[node] = _index;
        _index++;

        onStack[node] = true;
        stack.push(node);

        for (int p = G.getHead(node); p != Graph.NIL; p = G.getNext(p)) {
            int son = G.getNeighbour(p);

            if (index[son] == -1){
                dfs(son);
                lowlink[node] = Math.min(lowlink[node], lowlink[son]);
            }
            else if (onStack[son])
                lowlink[node] = Math.min(lowlink[node], index[son]);
        }

        if (index[node] == lowlink[node]){
            numberOfSCCs++;
            int w;

            do {
                w = stack.peek();
                onStack[w] = false;
                stack.pop();
                component[w] = numberOfSCCs;

            } while (w != node);
        }
    }

    int[] computeStronglyConnectedComponents(){
        component = new int[N + 1];
        _index = 0;
        numberOfSCCs = 0;

        Arrays.fill(component, -1);
        Arrays.fill(index, -1);
        Arrays.fill(onStack, false);
        stack.clear();

        for (int i = 1; i <= N; i++) {
            if (index[i] == -1)
                dfs(i);
        }

        return component;
    }

    int getNumberOfStronglyConnectedComponents(){
        return numberOfSCCs;
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

