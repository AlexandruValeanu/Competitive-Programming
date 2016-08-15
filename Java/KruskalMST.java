import java.util.ArrayList;
import java.util.Arrays;

class DisjointSet {
    private final int[] father;
    private final int[] rank;
    private final int N;

    DisjointSet(int N){
        this.N = N;
        rank = new int[N + 1];
        father = new int[N + 1];

        for (int i = 1; i <= N; i++)
            initialize(i);
    }

    void initialize(int node){
        if (!(1 <= node && node <= N)) throw new AssertionError();
        father[node] = node;
        rank[node] = 1;
    }

    int find(int node){
        if (!(1 <= node && node <= N)) throw new AssertionError();

        if (father[node] == node)
            return node;
        else
            return father[node] = find(father[node]);
    }

    void union(int x, int y){
        x = find(x);
        y = find(y);

        if (x != y){
            if (rank[x] < rank[y])
                father[x] = y;
            else
                father[y] = x;

            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    boolean connected(int x, int y){
        return find(x) == find(y);
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

class KruskalMST {
    private Edge[] edges;
    private final int N;

    public KruskalMST(Edge[] edges, int N) {
        this.edges = Arrays.copyOf(edges, edges.length);
        this.N = N;
    }

    ArrayList<Edge> minimumSpanningTree(){
        Arrays.sort(edges);
        DisjointSet dsu = new DisjointSet(N);

        int totalCost = 0;
        int countEdges = 0;
        ArrayList<Edge> finalEdges = new ArrayList<>();

        for (int i = 0; i < edges.length && countEdges < (N - 1); i++) {
            int x = edges[i].x;
            int y = edges[i].y;

            if (!dsu.connected(x, y)){
                dsu.union(x, y);
                totalCost += edges[i].cost;
                countEdges++;
                finalEdges.add(edges[i]);
            }
        }

        return finalEdges;
    }
}
