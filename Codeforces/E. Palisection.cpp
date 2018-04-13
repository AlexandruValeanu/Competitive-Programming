#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 2e6;
const int SIGMA = 26;

struct PalindromicTree
{
    struct Node
    {
        vector< pair<char,int> > next;
        int length;
        int suffixLink;
        int countPalindromes;
    };

    Node Tree[MAX_LEN + 2 + 1];
    char String[MAX_LEN + 1];

    int countNodes;
    int lastNode;
    int lengthString;

    PalindromicTree() : countNodes(2), lastNode(2), lengthString(0)
    {
        Tree[1].length = -1; Tree[1].suffixLink = 1;
        Tree[2].length =  0; Tree[2].suffixLink = 1;
    }

    void clear()
    {
        for (int i = 0; i <= countNodes; ++i)
            Tree[i].next.clear();

        countNodes = 2;
        lastNode = 2;
        lengthString = 0;

        Tree[1].length = -1; Tree[1].suffixLink = 1;
        Tree[2].length =  0; Tree[2].suffixLink = 1;
    }

    int getSuffixLink(int node)
    {
        while (true)
        {
            int lg = Tree[node].length;

            if (lengthString - 2 - lg >= 0 && String[lengthString - 2 - lg] == String[lengthString - 1])
                break;

            node = Tree[node].suffixLink;
        }

        return node;
    }

    int Next(int node, int ch)
    {
        for (auto it: Tree[node].next)
            if (it.first == ch)
                return it.second;

        return 0;
    }

    bool addLetter(int c)
    {
        String[ lengthString++ ] = c;

        int node = getSuffixLink(lastNode);

        if (Next(node, c) != 0)
        {
            lastNode = Next(node, c);

            return false;
        }

        lastNode = ++countNodes;
        Tree[lastNode].length = Tree[node].length + 2;
        Tree[node].next.push_back({c, lastNode});

        if (Tree[lastNode].length == 1)
        {
            Tree[lastNode].suffixLink = 2;
            Tree[lastNode].countPalindromes = 1;

            return true;
        }

        node = getSuffixLink(Tree[node].suffixLink);

        Tree[lastNode].suffixLink = Next(node, c);
        Tree[lastNode].countPalindromes = Tree[ Tree[lastNode].suffixLink ].countPalindromes + 1;

        return true;
    }

    int countPalindromes() const
    {
        return Tree[lastNode].countPalindromes;
    }
};

const int MOD = 51123987;

char str[MAX_LEN];
int start[MAX_LEN], finish[MAX_LEN];
PalindromicTree P;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    cin >> N;
    cin >> str;

    for (int i = 0; i < N; ++i)
    {
        P.addLetter(str[i] - 'a');
        finish[i] = P.countPalindromes();
    }

    P.clear();

    for (int i = 0; i < N; ++i)
    {
        P.addLetter(str[N - i - 1] - 'a');
        start[N - i - 1] = P.countPalindromes();
    }

    long long totalSum = 0;

    for (int i = 0; i < N; ++i)
        totalSum += (long long)start[i];

    totalSum %= MOD;

    long long sol = (totalSum * (totalSum - 1) / 2LL) % MOD;
    long long sum = 0;

    for (int i = 1; i < N; ++i)
    {
        sum = (sum + finish[i - 1]) % MOD;
        sol = (sol - (1LL * sum * start[i]) % MOD + MOD) % MOD;
    }

    cout << sol << "\n";

    return 0;
}
