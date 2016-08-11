import java.util.*;

class Pair{
    int first, second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

public class MinCostMaxFlow {

    static class Edge{
        int flow;
        int capacity;
        int cost;
        int node;
        int next;

        Edge(int flow, int capacity, int cost, int node, int next) {
            this.flow = flow;
            this.capacity = capacity;
            this.cost = cost;
            this.node = node;
            this.next = next;
        }
    }

    private static final int NIL = -1;

    private ArrayList<Edge> graph;
    private int N;

    private int[] head;
    private int[] father;
    private int[] pointer;

    private int[] oldDist, newDist, realDist;

    MinCostMaxFlow(int N){
        assert 2 <= N;
        this.N = N;

        graph = new ArrayList<>();
        father = new int[N];
        pointer = new int[N];

        head = new int[N];
        Arrays.fill(head, NIL);

        oldDist = new int[N];
        newDist = new int[N];
        realDist = new int[N];
    }

    void addEdge(int from, int to, int capacity, int cost){
        from--; to--;
        assert 0 <= from && from < N;
        assert 0 <= to && to < N;

        graph.add(new Edge(0, capacity, cost, to, head[from]));
        head[from] = graph.size() - 1;
    }

    private void bellmanFord(int S){
        assert 0 <= S && S < N;
        boolean[] inQueue = new boolean[N];

        Arrays.fill(inQueue, false);
        Arrays.fill(oldDist, Integer.MAX_VALUE);

        Queue<Integer> queue = new LinkedList<>();

        queue.add(S);
        inQueue[S] = true;
        oldDist[S] = 0;

        while (!queue.isEmpty()){
            int node = queue.remove();
            inQueue[node] = false;

            for (int p = head[node]; p != NIL; p = graph.get(p).next) {
                Edge edge = graph.get(p);

                if (edge.capacity > edge.flow && oldDist[edge.node] > oldDist[node] + edge.cost){
                    oldDist[edge.node] = oldDist[node] + edge.cost;

                    if (!inQueue[edge.node]){
                        inQueue[edge.node] = true;
                        queue.add(edge.node);
                    }
                }
            }
        }
    }

    private boolean dijkstra(int S, int T){
        Arrays.fill(newDist, Integer.MAX_VALUE);
        Arrays.fill(realDist, Integer.MAX_VALUE);
        Arrays.fill(father, NIL);
        Arrays.fill(pointer, NIL);

        Queue<Pair> minHeap = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.first, o2.first));
        minHeap.add(new Pair(0, S));
        realDist[S] = 0;
        newDist[S] = 0;
        father[S] = S;

        while (!minHeap.isEmpty()){
            Pair pp = minHeap.remove();

            int node = pp.second;
            int d = pp.first;

            if (d != newDist[node])
                continue;

            for (int p = head[node]; p != NIL; p = graph.get(p).next) {
                Edge edge = graph.get(p);
                int son = edge.node;
                int capacity = edge.capacity;
                int flow = edge.flow;
                int cost = edge.cost;

                int new_distance = oldDist[node] - oldDist[son] + newDist[node] + cost;

                if (capacity > flow && newDist[son] > new_distance){
                    newDist[son] = new_distance;
                    realDist[son] = realDist[node] + cost;

                    pointer[son] = p;
                    father[son] = node;

                    minHeap.add(new Pair(newDist[son], son));
                }
            }
        }

        System.arraycopy(realDist, 0, oldDist, 0, N);

        return newDist[T] != Integer.MAX_VALUE;
    }

    Pair minCostMaxFlow(int S, int T){
        S--; T--;
        assert 0 <= S && S < N;
        assert 0 <= T && T < N;
        assert S != T;

        int totalFlow = 0;
        int costTotalFlow = 0;

        bellmanFord(S);

        while (dijkstra(S, T)){
            int fmin = Integer.MAX_VALUE;
            int node = T;

            while (node != S){
                fmin = Math.min(fmin, graph.get(pointer[node]).capacity - graph.get(pointer[node]).flow);
                node = father[node];
            }

            node = T;

            while (node != S){
                graph.get(pointer[node]).flow += fmin;
                graph.get(pointer[node] ^ 1).flow -= fmin;
                node = father[node];
            }

            totalFlow += fmin;
            costTotalFlow += fmin * realDist[T];
        }

        return new Pair(totalFlow, costTotalFlow);
    }
}
