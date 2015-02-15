#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

struct Node
{
    string key;
    int priority;
    int size;
    Node *st, *dr;

    Node(const string& str, const int& prior, Node* lt, Node* rt, int dim)
    {
        key = str;
        priority = prior;
        st = lt;
        dr = rt;
        size = dim;
    }
};

Node *root, *NIL;

void initTreap()
{
    NIL = new Node("", 0, NULL, NULL, 0);
    root = NIL;
    srand(time(0));
}

inline bool compare(string a, string b)
{
    if ( a.size() != b.size() )
        return a.size() < b.size();
    else
        return a < b;
}

inline void update(Node*& T)
{
    T->size = 1 + T->st->size + T->dr->size;
}

void rol(Node*& T)
{
    Node *aux = T->st;
    T->st = aux->dr;
    aux->dr = T;

    update(T);
    update(aux);

    T = aux;
}

void ror(Node*& T)
{
    Node *aux = T->dr;
    T->dr = aux->st;
    aux->st = T;

    update(T);
    update(aux);

    T = aux;
}

void balance(Node*& T)
{
    if ( T->st->priority > T->priority ) rol(T);
    if ( T->dr->priority > T->priority ) ror(T);

    update(T);
}

void insert(Node*& T, string str, const int p = 1 + rand() % INF)
{
    if ( T == NIL )
    {
        T = new Node(str, p, NIL, NIL, 1);
    }
    else
    {
        if ( compare(str, T->key) )
            insert(T->st, str, p);
        else
            if ( compare(T->key, str) )
                insert(T->dr, str, p);

        balance(T);
    }
}

string& kth_element(Node*&T, int k)
{
    assert( T != NIL );

    if ( k == T->st->size + 1 )
        return T->key;

    if ( k <= T->st->size )
        return kth_element(T->st, k);
    else
        return kth_element(T->dr, k - 1 - T->st->size);
}

string str;

int main()
{
    ifstream in("nums.in");
    ofstream out("nums.out");

    ios_base::sync_with_stdio(false);

    int N;
    in >> N;

    initTreap();

    while ( N-- )
    {

        int tip, k;

        in >> tip;

        if ( tip == 1 )
        {
            in >> str;
            insert(root, str);
        }
        else
        {
            in >> k;
            out << kth_element(root, k) << "\n";
        }
    }

    return 0;
}
