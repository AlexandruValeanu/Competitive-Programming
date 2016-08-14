class SegmentTree {
    private static class Node{
        int maxim;

        Node(int maxim) {
            this.maxim = maxim;
        }

        static Node merge(Node L, Node R){
            return new Node(Math.max(L.maxim, R.maxim));
        }

        static void merge(Node T, Node L, Node R){
            T.maxim = Math.max(L.maxim, R.maxim);
        }
    }

    private Node[] tree;
    private final int N;

    SegmentTree(int N){
        tree = new Node[4 * N];
        this.N = N;
    }

    SegmentTree(int[] array){
        this(array.length);
        build(1, 0, N - 1, array);
    }

    private void build(int node, int l, int r, int[] array){
        if (l == r)
            tree[node] = new Node(array[l]);
        else{
            int m = (l + r) / 2;

            build(2 * node, l, m, array);
            build(2 * node + 1, m + 1, r, array);

            tree[node] = Node.merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

    private void update(int node, int l, int r, int position, int key){
        if (l == r)
            tree[node].maxim = key;
        else{
            int m = (l + r) / 2;

            if (position <= m)
                update(2 * node, l, m, position, key);
            else
                update(2 * node + 1, m + 1, r, position, key);

            Node.merge(tree[node], tree[2 * node], tree[2 * node + 1]);
        }
    }

    private int query(int node, int l, int r, int st_q, int dr_q){
        if (st_q <= l && r <= dr_q)
            return tree[node].maxim;
        else{
            int m = (l + r) / 2;

            if (st_q <= m && m < dr_q){
                int left = query(2 * node, l, m, st_q, dr_q);
                int right = query(2 * node + 1, m + 1, r, st_q, dr_q);

                return Math.max(left, right);
            }
            else if (st_q <= m)
                return query(2 * node, l, m, st_q, dr_q);
            else
                return query(2 * node + 1, m + 1, r, st_q, dr_q);
        }
    }

    void update(int position, int newKey){
        if (!(0 <= position && position < N)) throw new AssertionError("position : out of bounds in update");
        update(1, 0, N - 1, position, newKey);
    }

    int query(int x, int y){
        if (!(0 <= x && x <= y && y < N)) throw new AssertionError("x or y : out of bounds in query");
        return query(1, 0, N - 1, x, y);
    }
}
