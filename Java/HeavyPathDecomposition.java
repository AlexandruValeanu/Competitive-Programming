import java.util.ArrayList;
import java.util.Arrays;

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
        graph = new ArrayList<>();

        this.N = N;
        this.counter = 0;

        Arrays.fill(head, NIL);
    }

    void addEdge(int x, int y){
        assert 1 <= x && x <= N;
        x--; y--;
        graph.add(new Edge(y, head[x]));
        head[x] = counter++;
    }

    int getHead(int node){
        assert 1 <= node && node <= N;
        node--;
        return head[node];
    }

    int getNext(int p){
        assert 0 <= p && p < counter;
        return graph.get(p).next;
    }

    int getNeighbour(int p){
        assert 0 <= p && p < counter;
        return graph.get(p).node + 1;
    }
}

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

class HeavyPathDecomposition {
    private Graph graph;
    private final int N;
    private int numberOfPaths;
    private ArrayList<SegmentTree> segmentTrees;

    private final int[] size, father, depth;
    private final int[] path, lengthPath, posInPath, startNode;

    HeavyPathDecomposition(Graph G){
        this.graph = G;
        this.N = G.getN();
        this.numberOfPaths = 0;
        segmentTrees = new ArrayList<>();

        size = new int[N + 1];
        father = new int[N + 1];
        depth = new int[N + 1];

        path = new int[N + 1];
        lengthPath = new int[N + 1];
        posInPath = new int[N + 1];
        startNode = new int[N + 1];
    }

    private void dfs(int node){
        size[node] = 1;
        int heavySon = 0;

        for (int p = graph.getHead(node); p != Graph.NIL; p = graph.getNext(p)) {
            int son = graph.getNeighbour(p);

            if (father[son] == 0){
                father[son] = node;
                depth[son] = depth[node] + 1;
                dfs(son);

                size[node] += size[son];

                if (size[heavySon] < size[son])
                    heavySon = son;
            }
        }

        if (heavySon == 0)
            path[node] = numberOfPaths++;
        else
            path[node] = path[heavySon];

        posInPath[node] = lengthPath[path[node]]++;
    }

    void buildHeavyPaths(int root){
        if (!(1 <= root && root <= N)) throw new AssertionError();

        father[root] = root;
        depth[root] = 0;
        dfs(root);

        for (int i = 1; i <= N; i++) {
            posInPath[i] = lengthPath[path[i]] - posInPath[i] - 1;

            if (posInPath[i] == 0)
                startNode[path[i]] = i;
        }
    }

    int lca(int x, int y){
        if (!(1 <= x && x <= N)) throw new AssertionError();
        if (!(1 <= y && y <= N)) throw new AssertionError();

        while (path[x] != path[y]){
            if (depth[startNode[path[x]]] < depth[startNode[path[y]]])
                y = father[startNode[path[y]]];
            else
                x = father[startNode[path[x]]];
        }

        return posInPath[x] < posInPath[y] ? x : y;
    }

    void buildSegmentTrees(int[] keys){
        int[][] values = new int[numberOfPaths][];

        for (int i = 0; i < numberOfPaths; i++)
            values[i] = new int[lengthPath[i]];

        for (int i = 1; i <= N; i++)
            values[path[i]][posInPath[i]] = keys[i];

        for (int i = 0; i < numberOfPaths; i++)
            segmentTrees.add(new SegmentTree(values[i]));
    }

    void update(int node, int newKey){
        segmentTrees.get(path[node]).update(posInPath[node], newKey);
    }

    int query(int x, int y){
        if (depth[startNode[path[x]]] < depth[startNode[path[y]]]){
            int tmp = x;
            x = y;
            y = tmp;
        }

        if (path[x] == path[y])
            return segmentTrees.get(path[x]).query(Math.min(posInPath[x], posInPath[y]),
                                                   Math.max(posInPath[x], posInPath[y]));
        else
            return Math.max(segmentTrees.get(path[x]).query(0, posInPath[x]),
                            query(father[startNode[path[x]]], y));
    }
}
