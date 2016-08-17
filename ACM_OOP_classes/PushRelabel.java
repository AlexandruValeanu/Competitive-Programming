import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class PushRelabel {
    private static class Edge{
        int flow;
        int capacity;

        int node;
        int next;

        public Edge(int flow, int capacity, int node, int next) {
            this.flow = flow;
            this.capacity = capacity;
            this.node = node;
            this.next = next;
        }
    }

    static private final int NIL = -1;

    ArrayList<Edge> graph;
    int[] head;

    int[] excess, height, pointer;
    boolean[] active;

    int[] countHeights;

    Queue<Integer> queue;

    final int N;

    PushRelabel(int _N){
        this.N = _N;

        graph = new ArrayList<>();
        head = new int[N + 1];
        Arrays.fill(head, NIL);

        excess = new int[N + 1];
        height = new int[N + 1];
        pointer = new int[N + 1];
        active = new boolean[N + 1];

        countHeights = new int[2 * N + 1];

        queue = new LinkedList<>();
    }

    void addEdge(int from, int to, int capacity){
        graph.add(new Edge(0, capacity, to, head[from]));
        head[from] = graph.size() - 1;
    }

    void addDoubleEdge(int from, int to, int capacity){
        addEdge(from, to, capacity);
        addEdge(to, from, 0);
    }

    private void enqueue(int v){
        if(!active[v] && excess[v] > 0){
            active[v] = true;
            queue.add(v);
        }
    }

    private void push(int u, int p){
        Edge edge = graph.get(p);
        int v = edge.node;
        int delta = Math.min(excess[u], edge.capacity - edge.flow);

        if (height[u] <= height[v] || delta == 0)
            return;

        graph.get(p).flow += delta;
        graph.get(p ^ 1).flow -= delta;

        excess[u] -= delta;
        excess[v] += delta;

        enqueue(v);
    }

    private void relabel(int v){
        countHeights[height[v]]--;
        height[v] = 2 * N;

        for (int p = head[v]; p != NIL; p = graph.get(p).next) {
            Edge edge = graph.get(p);

            if (edge.capacity > edge.flow)
                height[v] = Math.min(height[v], 1 + height[edge.node]);
        }

        countHeights[height[v]]++;
        enqueue(v);
    }

    private void gap(int h){
        for (int i = 1; i <= N; i++) {
            if (height[i] >= h){
                countHeights[height[i]]--;
                height[i] = Math.max(height[i], N + 1);
                countHeights[height[i]]++;

                enqueue(i);
            }
        }
    }

    private void discharge(int u){
        boolean doneGap = false;

        while (excess[u] > 0){
            if (countHeights[height[u]] == 1 && !doneGap){
                gap(height[u]);
                doneGap = true;
                pointer[u] = NIL;
            }

            if (pointer[u] == NIL){
                relabel(u);
                pointer[u] = head[u];
            }
            else{
                int p = pointer[u];
                Edge edge = graph.get(p);
                int v = edge.node;

                if (height[u] >= height[v] + 1 && edge.capacity > edge.flow)
                    push(u, p);
                else
                    pointer[u] = edge.next;
            }
        }
    }

    private void initPreflow(int S, int T){
        Arrays.fill(countHeights, 0);
        Arrays.fill(excess, 0);
        Arrays.fill(height, 0);
        Arrays.fill(active, false);

        queue.clear();

        for (int i = 1; i <= N; i++) {
            pointer[i] = head[i];
        }

        height[S] = N;
        active[S] = active[T] = true;

        countHeights[N] = 1;
        countHeights[0] = N - 1;

        for (int p = head[S]; p != NIL; p = graph.get(p).next) {
            excess[S] += graph.get(p).capacity;
            push(S, p);
        }
    }

    int maximumFlow(int S, int T){
        initPreflow(S, T);

        while (!queue.isEmpty()){
            int v = queue.remove();
            active[v] = true;
            discharge(v);
        }

        int maxFlow = 0;

        for (int p = head[S]; p != NIL; p = graph.get(p).next) {
            maxFlow += graph.get(p).flow;
        }

        return maxFlow;
    }
}
