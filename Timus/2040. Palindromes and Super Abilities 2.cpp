#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 5000000;
const int SIGMA = 2;

struct PalindromicTree
{
    struct Node
    {
        int next[SIGMA];
        int length;
        int suffixLink;
        ///int countPalindromes;
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
            ///Tree[lastNode].countPalindromes = 1;

            return true;
        }

        node = getSuffixLink(Tree[node].suffixLink);

        Tree[lastNode].suffixLink = Tree[node].next[c];
        ///Tree[lastNode].countPalindromes = Tree[ Tree[lastNode].suffixLink ].countPalindromes + 1;

        return true;
    }

    int countPalindromes() const
    {
        ///return Tree[lastNode].countPalindromes;
    }
};

char str[MAX_LEN];
PalindromicTree P;

int main()
{
    ///freopen("data.in", "r", stdin);

    ios_base::sync_with_stdio(false);

    cin >> str;
    const int n = strlen(str);

    for (int i = 0; i < n; ++i)
    {
        str[i] = '0' + P.addLetter(str[i] - 'a');
    }

    cout << str << "\n";

    return 0;
}
