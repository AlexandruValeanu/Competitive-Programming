public class AncestorMatrix{
    private static final int NIL = -1;
    private final int[][] ancestor;
    private final int MAX_LG;

    private static int log2(int x){
        for (int i = 0; i < 30; i++) {
            if ((1 << i) >= x)
                return i;
        }

        throw new RuntimeException();
    }

    AncestorMatrix(int N){
        MAX_LG = log2(N) + 1;

        ancestor = new int[MAX_LG][N];

        for (int i = 0; i < MAX_LG; i++) {
            for (int j = 0; j < N; j++) {
                ancestor[i][j] = NIL;
            }
        }
    }

    public void removeLeaf(int leaf){
        for (int i = 0; i < MAX_LG; i++) {
            ancestor[i][leaf] = NIL;
        }
    }

    public void addLeaf(int leaf, int parent){
        removeLeaf(leaf);
        ancestor[0][leaf] = parent;

        for (int i = 1; i < MAX_LG; i++) {
            if (ancestor[i - 1][leaf] != NIL)
                ancestor[i][leaf] = ancestor[i - 1][ancestor[i - 1][leaf]];
        }
    }

    public int kthAncestor(int node, int k){
        int p = MAX_LG - 1;

        while (p >= 0){
            if ((k >= (1 << p)) && ancestor[p][node] != NIL){
                k -= (1 << p);
                node = ancestor[p][node];
            }

            p--;
        }

        if (k == 0)
            return node + 1;
        else
            return 0;
    }
}
