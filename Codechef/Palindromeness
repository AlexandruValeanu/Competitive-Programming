#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 1e5;
const int SIGMA = 26;

struct Node
{
    int next[SIGMA];
    int length;
    int suffixLink;
    int count;
};

vector<int> G[MAX_LEN + 3];

Node Tree[MAX_LEN + 2 + 1];
char String[MAX_LEN + 1];

char str[MAX_LEN];

int lengthString;
int countNodes;
int lastNode;

long long solution;

void initTree()
{
    countNodes = 2;
    lastNode = 2;

    Tree[1].length = -1; Tree[1].suffixLink = 1;
    Tree[2].length =  0; Tree[2].suffixLink = 1;

    String[ lengthString++ ] = -1;
}

void clearTree()
{
    for (int i = 1; i <= MAX_LEN + 2; ++i)
    {
        memset(Tree[i].next, 0, sizeof(Tree[i].next));
        G[i].clear();
        Tree[i].count = 0;
        Tree[i].length = 0;
        Tree[i].suffixLink = 0;
    }

    lengthString = 0;
    countNodes = 0;
    lastNode = 0;
}

int getSuffixLink(int node)
{
    while (true)
    {
        int len = Tree[node].length;

        if (lengthString - 2 - len >= 0 && String[lengthString - 2 - len] == String[lengthString - 1])
            break;

        node = Tree[node].suffixLink;
    }

    return node;
}

bool addLetter(int c)
{
    String[ lengthString++ ] = c;

    int node = getSuffixLink(lastNode);

    if (Tree[node].next[c] != 0)
    {
        lastNode = Tree[node].next[c];
        Tree[lastNode].count++;

        return false;
    }

    lastNode = ++countNodes;
    Tree[lastNode].length = Tree[node].length + 2;
    Tree[node].next[c] = lastNode;
    Tree[lastNode].count = 1;

    if (Tree[lastNode].length == 1)
    {
        Tree[lastNode].suffixLink = 2;
        G[2].push_back(lastNode);

        return true;
    }

    node = getSuffixLink(Tree[node].suffixLink);

    Tree[lastNode].suffixLink = Tree[node].next[c];
    G[ Tree[lastNode].suffixLink ].push_back(lastNode);

    return true;
}

int P[MAX_LEN + 1];

void dfs(int node, long long nr)
{
    int l = Tree[node].length;

    if (l == 1)
        P[l] = 1;
    else if (l > 1)
            P[l] = P[l / 2] + 1;

    nr += P[l];
    solution += 1LL * Tree[node].count * nr;

    for (auto it: G[node])
        dfs(it, nr);

    P[l] = 0;
}

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio(false);
    cin.tie(false);

    int t;
    cin >> t;

    while (t--)
    {
        clearTree();
        initTree();

        cin >> str;
        const int n = strlen(str);

        for (int i = 0; i < n; ++i)
            addLetter(str[i] - 'a');

        solution = 0;
        dfs(2, 0);

        cout << solution << "\n";
    }

    return 0;
}
