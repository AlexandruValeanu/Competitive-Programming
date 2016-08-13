static class Graph{

    private static class Edge{
        int node;
        int next;

        Edge(int node, int next){
            this.node = node;
            this.next = next;
        }
    }

    public final static int NIL = -1;
    private int[] head;
    private ArrayList<Edge> graph;

    private int N;
    private int contor;
    
    Graph(int N){
        initialize(N);
    }

    void initialize(final int N){
        head = new int[N];
        graph = new ArrayList<>();

        System.gc();

        this.N = N;
        this.contor = 0;

        for (int i = 0; i < N; ++i)
            head[i] = NIL;
    }

    void addEdge(int x, int y){
        x--; y--;
        graph.add(new Edge(y, head[x]));
        head[x] = contor++;
    }

    int getHead(int node){
        node--;
        return head[node];
    }

    int getNext(int p){
        assert 0 <= p && p < contor;
        return graph.get(p).next;
    }

    int getNeighbour(int p){
        assert 0 <= p && p < contor;
        return graph.get(p).node + 1;
    }
    
    int getN(){
        return N;
    }
}
