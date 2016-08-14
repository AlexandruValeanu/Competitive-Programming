import java.util.function.IntBinaryOperator;

class SparseTable {
    private IntBinaryOperator binaryOperator;
    private int N;
    private int[][] rmq;
    private int[] log2;

    SparseTable(int N, IntBinaryOperator operator){
        this.binaryOperator = operator;
        this.N = N;
        this.rmq = new int[32 - Integer.numberOfLeadingZeros(N)][N + 1];
        this.log2 = new int[N + 1];
    }

    void set(int index, int key){
        rmq[0][index] = key;
    }

    void build(){
        log2[1] = 0;

        for (int i = 2; i <= N; i++)
            log2[i] = log2[i >> 1] + 1;

        for (int i = 1; (1 << i) <= N; ++i)
            for (int j = 1; j + (1 << i) - 1 <= N; ++j)
                rmq[i][j] = binaryOperator.applyAsInt(rmq[i - 1][j], rmq[i - 1][j + (1 << (i - 1))]);
    }

    int query(int x, int y){
        int k = log2[y - x + 1];
        return binaryOperator.applyAsInt(rmq[k][x], rmq[k][y - (1 << k) + 1]);
    }
}
