#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 1e5;
const int SIGMA = 26;

struct PalindromicTree
{
    struct Node
    {
        int next[SIGMA];
        int length;
        int suffixLink;
    };

    Node Tree[MAX_LEN + 2 + 1];
    char String[MAX_LEN + 1];

    int lastNode;
    int countNodes;
    int lengthString;

    PalindromicTree() : lastNode(2), countNodes(2), lengthString(0)
    {
        Tree[1].length = -1; Tree[1].suffixLink = 1;
        Tree[2].length =  0; Tree[2].suffixLink = 1;

        String[ lengthString++ ] = -1;
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

            return false;
        }

        lastNode = ++countNodes;
        Tree[lastNode].length = Tree[node].length + 2;
        Tree[node].next[c] = lastNode;

        if (Tree[lastNode].length == 1)
        {
            Tree[lastNode].suffixLink = 2;

            return true;
        }

        node = getSuffixLink(Tree[node].suffixLink);

        Tree[lastNode].suffixLink = Tree[node].next[c];

        return true;
    }
};

PalindromicTree P;

int main()
{
    ///ifstream cin("data.in");

    ios_base::sync_with_stdio(false);

    static char str[MAX_LEN];
    cin >> str;
    const int n = strlen(str);
    int sol = 0;

    for (int i = 0; i < n; ++i)
    {
        sol += P.addLetter(str[i] - 'a');
        cout << sol << " ";
    }

    return 0;
}
