import java.io.*;
import java.util.*;

class MaxFlow{
    private static class Edge{
        int flow;
        int capacity;
        int node;
        int next;

        Edge(int flow, int capacity, int node, int next) {
            this.flow = flow;
            this.capacity = capacity;
            this.node = node;
            this.next = next;
        }
    }

    private final int NIL = -1;

    private ArrayList<Edge> G;
    private int[] head, pointer, father;
    private int N, contor;

    MaxFlow(int N){
        this.G =  new ArrayList<>();
        this.head = new int[N + 1];
        this.pointer = new int[N + 1];
        this.father = new int[N + 1];
        this.N = N;
        this.contor = 0;

        for (int i = 1; i <= N; ++i)
            this.head[i] = NIL;
    }

    void addEdge(int x, int y, int capacity){
        G.add(new Edge(0, capacity, y, head[x]));
        head[x] = contor++;
    }

    private boolean BFS(int S, int T){
        for (int i = 1; i <= N; i++) {
            pointer[i] = 0;
            father[i] = 0;
        }

        Queue<Integer> queue = new LinkedList<>();
        queue.add(S);
        father[S] = S;

        while (!queue.isEmpty()){
            int node = queue.remove();

            for (int p = head[node]; p != NIL; p = G.get(p).next) {
                Edge e = G.get(p);
                int son = e.node;
                int flow = e.flow;
                int capacity = e.capacity;

                if (father[son] == 0 && capacity > flow){
                    father[son] = node;
                    pointer[son] = p;

                    if (son == T)
                        return true;

                    queue.add(son);
                }
            }
        }

        return false;
    }

    int maxFlow(int S, int T){
        int totalFlow = 0;

        while (BFS(S, T)){
            for (int p = head[T]; p != NIL; p = G.get(p).next) {
                int son = G.get(p).node;

                if (father[son] != 0 && G.get(p ^ 1).capacity > G.get(p ^ 1).flow){
                    father[T] = son;
                    pointer[T] = p ^ 1;

                    int fmin = Integer.MAX_VALUE;
                    int node = T;

                    while (node != S){
                        Edge e = G.get(pointer[node]);
                        fmin = Math.min(fmin, e.capacity - e.flow);
                        node = father[node];
                    }

                    totalFlow += fmin;
                    node = T;

                    while (node != S){
                        G.get(pointer[node]).flow += fmin;
                        G.get(pointer[node] ^ 1).flow -= fmin;
                        node = father[node];
                    }
                }
            }
        }

        return totalFlow;
    }
}
