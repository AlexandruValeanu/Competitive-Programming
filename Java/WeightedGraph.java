import java.util.ArrayList;
import java.util.Arrays;

class WeightedGraph{
    private static class Edge{
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
    
    WeightedGraph transpose(){
        WeightedGraph GT = new WeightedGraph(N);

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
