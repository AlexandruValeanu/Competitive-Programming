#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 50 + 1;
constexpr int MAX_T = 1000 + 1;
constexpr int INF = numeric_limits<int>::max() / 2;

struct Node{
    int node;
    int time;
    int dist;
    
    bool operator < (const Node &X) const{
        return dist > X.dist;
    }
};

int times[MAX_N][MAX_N];
int tolls[MAX_N][MAX_N];

int dist[MAX_N][MAX_T];

int N, T;

void fill_matrix(){
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_T; j++)
            dist[i][j] = INF;
}

void dijkstra(int source, int destination){
    fill_matrix();
    priority_queue<Node> minHeap;

    dist[source][0] = 0;
    minHeap.push({source, 0, 0});
    
    while (!minHeap.empty()){
        Node NodeHeap = minHeap.top();
        minHeap.pop();
        
        int node = NodeHeap.node;
        int time = NodeHeap.time;
        int _dist = NodeHeap.dist;
        
        if (dist[node][time] != _dist)
            continue;
            
        for (int i = 1; i <= N; i++){
            if (i == node)
                continue;
            
            int son = i;
            int newTime = time + times[node][son];
            int cost = tolls[node][son];
            
            if (newTime <= T && dist[son][newTime] > dist[node][time] + cost){
                dist[son][newTime] = dist[node][time] + cost;
                minHeap.push({son, newTime, dist[son][newTime]});
            }
        }
    }
    
    int minDist = INF;
    int t = -1;
    
    for (int tmp = 0; tmp < MAX_T; tmp++)
        if (dist[destination][tmp] < minDist){
            minDist = dist[destination][tmp];
            t = tmp;
        }
        
    cout << minDist << " " << t << "\n";
}

int main()
{   
    #ifndef ONLINE_JUDGE
        assert(freopen("data.in", "r", stdin));
    #endif // ONLINE_JUDGE
    
    ios_base::sync_with_stdio(false);
    
    /*Code starts here*/
    
    while (true){
        cin >> N >> T;
        
        if (N == 0 && T == 0)
            break;
            
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                cin >> times[i][j];
                
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                cin >> tolls[i][j];
                
        dijkstra(1, N);
    }
    
    /* Code ends here */

    return 0;
}
