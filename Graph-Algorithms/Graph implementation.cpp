#include <bits/stdc++.h>

using namespace std;

const int Vmax = 100000 + 1;
const int Emax = 200000 + 1;

struct Graph
{
    struct Node
    {
        int nod;
        int next;
    };

    Node listEdges[Emax];
    int head[Vmax];
    int contor;

    Graph()
    {
        contor = 0;

        for ( int i = 0; i < Vmax; ++i )
            head[i] = 0;
    }

    void addEdge( int a, int b )
    {
        contor++;
        listEdges[contor].nod = b;
        listEdges[contor].next = head[a];
        head[a] = contor;
    }
};

int main()
{
    return 0;
}
