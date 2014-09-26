#include <bits/stdc++.h>

using namespace std;

class Treap
{
    typedef struct _Node
    {
        int key;
        int priority;
        int contor;
        _Node *l, *r;

        _Node(const int x = 0) : key(x), priority(rand() % 1000000), contor(1), l(NULL), r(NULL) {}

        void update()
        {
            this->contor = 1;

            if ( l ) this->contor += this->l->contor;
            if ( r ) this->contor += this->r->contor;
        }

    } *Node;

    Node merge(Node L, Node R)
    {
        if ( !L || !R )
            return L ? L : R;

        if ( L->priority < R->priority )
        {
            L->r = merge( L->r, R );
            L->update();
            return L;
        }
        else
        {
            R->l = merge( L, R->l );
            R->update();
            return R;
        }
    }

    void split(Node T, const int value, Node &L, Node &R)
    {
        L = R = NULL;

        if ( !T ) return;

        if ( T->key < value )
        {
            split( T->r, value, T->r, R );
            L = T;
        }
        else
        {
            split( T->l, value, L, T->l );
            R = T;
        }

        T->update();
    }

    bool find( Node T, const int key )
    {
        if ( !T ) return false;
        if ( T->key == key ) return true;
        if ( key < T->key )
            return find( T->l, key );
        else
            return find( T->r, key );
    }

    Node root;

public:

    Treap() : root(NULL) {}

    bool find( const int key )
    {
        return find( root, key );
    }

    void insert( const int key )
    {
        if ( find( key ) == true ) return;

        Node L, R;

        split(root, key, L, R);
        root = merge( merge( L, new _Node( key ) ), R );
    }

    void erase( const int key )
    {
        if ( find( key ) == false ) return;

        Node L, M, R;

        split( root, key, L, M );
        split( M, key + 1, M, R );

        delete M;
        root = merge( L, R );
    }
};

int main()
{
    return 0;
}
