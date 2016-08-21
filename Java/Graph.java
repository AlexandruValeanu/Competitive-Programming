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
}
