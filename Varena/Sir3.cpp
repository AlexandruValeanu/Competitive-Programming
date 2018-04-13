#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

const int Lmax = 60000 + 2;
const int INF = numeric_limits<int>::max() / 2;
const ULL BASE = 137;

ULL base[Lmax];

class Treap
{
private:

    class NodeTreap
    {
    public:

        char key;
        int priority;
        int nr_nodes;

        NodeTreap *st, *dr;

        ULL codeHash;

        NodeTreap(char k, int p, int n, NodeTreap *l, NodeTreap *r) : key(k), priority(p), nr_nodes(n), st(l), dr(r), codeHash(k) {

            this->codeHash = static_cast<ULL>(this->key);
        }

        void update()
        {
            this->nr_nodes = this->st->nr_nodes + this->dr->nr_nodes + 1;

            ULL code = this->st->codeHash;
            code = code * BASE + static_cast<ULL>(this->key);
            code = code * base[this->dr->nr_nodes] + this->dr->codeHash;
            this->codeHash = code;
        }
    };

    NodeTreap *root;
    NodeTreap *NIL;

    void rotateRight(NodeTreap *&T)
    {
        NodeTreap *aux = T->st;
        T->st = aux->dr;
        aux->dr = T;

        T->update();
        aux->update();

        T = aux;
    }

    void rotateLeft(NodeTreap *&T)
    {
        NodeTreap *aux = T->dr;
        T->dr = aux->st;
        aux->st = T;

        T->update();
        aux->update();

        T = aux;
    }

    void balance(NodeTreap *&T)
    {
        if (T->st->priority > T->priority)
            rotateRight(T);

        if (T->dr->priority > T->priority)
            rotateLeft(T);

        T->update();
    }

    void insert(NodeTreap *&T, int pos, char key, int priority = 1 + rand() % (INF - 2))
    {
        if (T == NIL)
        {
            T = new NodeTreap(key, priority, 1, NIL, NIL);
        }
        else
        {
            if (pos <= T->st->nr_nodes + 1)
                insert(T->st, pos, key, priority);
            else
                insert(T->dr, pos - T->st->nr_nodes - 1, key, priority);

            balance(T);
        }
    }

    void erase(NodeTreap *&T, int pos)
    {
        if (T == NIL) return;

        if (T->st->nr_nodes + 1 == pos)
        {
            if (T->st == NIL && T->dr == NIL)
            {
                delete T;
                T = NIL;
            }
            else
            {
                if (T->st->priority > T->dr->priority)
                {
                    rotateRight(T);
                    erase(T->dr, pos - T->st->nr_nodes - 1);
                }
                else
                {
                    rotateLeft(T);
                    erase(T->st, pos);
                }
            }
        }
        else
        {
            if (pos <= T->st->nr_nodes)
                erase(T->st, pos);
            else
                erase(T->dr, pos - T->st->nr_nodes - 1);
        }

        if (T != NIL)
            T->update();
    }

    char kth_element(NodeTreap *&T, int pos)
    {
        if (T->st->nr_nodes + 1 == pos)
            return T->codeHash;

        if (pos <= T->st->nr_nodes)
            return kth_element(T->st, pos);
        else
            return kth_element(T->dr, pos - T->st->nr_nodes - 1);
    }

    void merge(NodeTreap *&root, NodeTreap *&L, NodeTreap *&R)
    {
        root = new NodeTreap(0, INF, 1, L, R);
        root->update();

        erase(root, root->st->nr_nodes + 1);
    }

    /// [0...pos-1] U [pos...sizeTreap]
    void split(NodeTreap *&root, NodeTreap *&L, NodeTreap *&R, int pos)
    {
        insert(root, pos, 'a', INF);

        L = root->st;
        R = root->dr;

        delete root;
        root = NIL;
    }

    void printTree(NodeTreap *&R)
    {
        if (R == NIL) return;

        printTree(R->st);
        cerr << R->key;
        printTree(R->dr);
    }

public:

    Treap() : NIL()
    {
        srand(time(nullptr));
        NIL = new NodeTreap(0, 0, 0, nullptr, nullptr);
        root = NIL;
    }

    /// hash[x...y]
    ULL getHash(int x, int y)
    {
        ULL code = 0;
        NodeTreap *tmp, *T1, *T2, *T3;

        split(root, tmp, T3, y + 1);
        split(tmp, T1, T2, x);

        code = T2->codeHash;

        merge(tmp, T1, T2);
        merge(root, tmp, T3);

        return code;
    }

    /// print keys in inorder
    void printTree()
    {
        printTree(this->root);
    }

    /// 1-based
    void insert(int pos, char ch)
    {
        insert(root, pos, ch);
    }

    /// 1-based
    void erase(int pos)
    {
        erase(root, pos);
    }

    /// 1-based
    char kth_element(int pos)
    {
        return kth_element(root, pos);
    }
};

void initBaseVector()
{
    base[0] = 1;

    for (int i = 1; i < Lmax; ++i)
        base[i] = base[i - 1] * BASE;
}

ULL genHash(const string str)
{
    ULL code = 0;

    for (char c: str)
        code = code * BASE + c;

    return code;
}

int main()
{
    ifstream in("sir3.in");
    ofstream out("sir3.out");

    initBaseVector();

    int N, M;
    string sirInitial, str;
    in >> sirInitial;

    Treap T;

    for (int i = 0; i < sirInitial.size(); ++i)
        T.insert(i + 1, sirInitial[i]);

    in >> N;

    vector<ULL> codes(N, 0);
    vector<int> dim(N, 0);

    for (int i = 0; i < N; ++i)
    {
        in >> str;
        codes[i] = genHash(str);
        dim[i] = str.size();
    }

    in >> M;

    int sol = 0;

    while (M--)
    {
        int tip, poz, a, b, ind;
        char c;

        in >> tip;

        if (tip == 0)
        {
            in >> poz >> c >> a >> b;

            if (sol == 0)
                poz ^= a;
            else
                poz ^= b;

            T.insert(poz, c);
        }
        else
        {
            in >> poz >> ind >> a >> b;

            if (sol == 0)
                poz ^= a;
            else
                poz ^= b;

            ind--;

            int st = poz - dim[ind] + 1;

            sol = (T.getHash(st, poz) == codes[ind]);

            out << sol << "\n";
        }
    }

    in.close();
    out.close();

    return 0;
}
