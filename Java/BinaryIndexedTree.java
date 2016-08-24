class BinaryIndexedTree
{
    private final int[] tree;
    private final int N;

    BinaryIndexedTree(int N){
        this.tree = new int[N + 1];
        this.N = N;
    }

    private int lsb(int x){
        return x & (-x);
    }

    void update(int position, int key){
        while (position <= N){
            tree[position] += key;
            position += lsb(position);
        }
    }

    int query(int position){
        int sum = 0;

        while (position >= 1){
            sum += tree[position];
            position -= lsb(position);
        }

        return sum;
    }

    int query(int x, int y){
        return query(y) - query(x - 1);
    }
}
