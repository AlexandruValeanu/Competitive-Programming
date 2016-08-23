class DisjointSet {
    private final int[] father;
    private final int[] rank;
    private final int[] size;
    private final int N;
    private int numberOfComponents;

    DisjointSet(int N){
        this.N = N;
        rank = new int[N + 1];
        father = new int[N + 1];
        size = new int[N + 1];

        for (int i = 1; i <= N; i++)
            initialize(i);

        numberOfComponents = N;
    }

    void initialize(int node){
        if (!(1 <= node && node <= N)) throw new AssertionError();
        father[node] = node;
        rank[node] = 1;
        size[node] = 1;
    }

    int find(int node){
        if (!(1 <= node && node <= N)) throw new AssertionError();

        if (father[node] == node)
            return node;
        else
            return father[node] = find(father[node]);
    }
    
    int sizeComponent(int node){
        if (!(1 <= node && node <= N)) throw new AssertionError();
        return size[find(node)];
    }

    void union(int x, int y){
        x = find(x);
        y = find(y);

        if (x != y){
            numberOfComponents--;

            if (rank[x] < rank[y]) {
                father[x] = y;
                size[y] += size[x];
            }
            else {
                father[y] = x;
                size[x] += size[y];
            }
            
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    boolean connected(int x, int y){
        return find(x) == find(y);
    }

    int getNumberOfComponents(){
        return numberOfComponents;
    }
}
