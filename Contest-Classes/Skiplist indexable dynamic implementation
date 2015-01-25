#include <bits/stdc++.h>

using namespace std;

const int MAX_LEVEL = 30;
const int INF = ( 1U << 31 ) - 1;

struct Node
{
    int key;

    Node** link;
    int* jump;

    Node(const int _key = 0)
    {
        key = _key;
        link = NULL;
        jump = NULL;
    }

    void alloc(const int level)
    {
        link = new Node*[level];
        jump = new int[level];

        for ( int i = 0; i < level; ++i )
        {
            link[i] = NULL;
            jump[i] = 0;
        }
    }
};

Node *Head, *Tail;
Node *path[MAX_LEVEL];
int jumped[MAX_LEVEL];
int maxLevel;

void initSkiplist()
{
    Head = new Node( -INF );
    Head->alloc( MAX_LEVEL );

    Tail = new Node( INF );

    for ( int i = 0; i < MAX_LEVEL; ++i )
        Head->link[i] = Tail;

    maxLevel = 1;

    srand(time(NULL));
}

inline int generateLevel()
{
    return 3;

    int level = 1;

    for ( int R = rand() % ( 1 << (MAX_LEVEL - 1) ); ( R & 1 ) == 1; R >>= 1 )
        level++;

    assert( level < MAX_LEVEL );

    return level;
}

Node* search(int value)
{
    Node *current = Head;

    for ( int i = 0; i < MAX_LEVEL; ++i )
        jumped[i] = 0;

    for ( int l = maxLevel - 1; l >= 0; l-- )
    {
        while ( current->link[l] != NULL && current->link[l]->key < value )
        {
            jumped[l] += current->link[l]->jump[l];
            current = current->link[l];
        }

        path[l] = current;
    }

    return current;
}

void insert(const int value)
{
    Node *current = search(value);

    current = current->link[0];

    if (current->key != value)
    {
        int newLevel = generateLevel();

        if ( newLevel > maxLevel )
        {
            for ( int i = maxLevel; i < MAX_LEVEL; ++i )
                path[i] = Head;

            maxLevel = newLevel;
        }

        Node *newNode = new Node(value);
        newNode->alloc(newLevel);

        int J = 0;

        for ( int l = 0; l < newLevel; ++l )
        {
            assert( path[l] != NULL );

            newNode->link[l] = path[l]->link[l];
            path[l]->link[l] = newNode;

            newNode->jump[l] = path[l]->jump[l] - J;
            path[l]->jump[l] = J + 1;

            J += jumped[l];
        }

        for ( int i = newLevel; i < MAX_LEVEL; ++i )
            path[i]->jump[i]++;
    }
}

bool find(const int value)
{
    Node *current = search(value);
    current = current->link[0];

    return (current->key == value);
}

void erase(const int value)
{
    Node *current = search(value);

    current = current->link[0];

    if (value == current->key)
    {
        for ( int l = 0; l < MAX_LEVEL; ++l )
        {
            if ( path[l]->link[l] == current )
            {
                path[l]->link[l] = current->link[l];
                current->link[l] += current->jump[l] - 1;
            }
            else
            {
                path[l]->link[l]--;
            }
        }

        delete current;
    }
}

int kth_element(int k)
{
    Node* current = Head;

    for ( int l = maxLevel - 1; l >= 0; l-- )
    {
        while ( current->link[l] != NULL && current->jump[l] < k )
        {
            k -= current->jump[l];
            current = current->link[l];
        }

        assert( current != NULL );
    }

    current = current->link[0];

    return current->key;
}

void printList()
{
    Node* current = Head;

    while ( current->key != INF )
    {
        cout << current->key << " ";
        current = current->link[0];
    }
}

int main()
{
    return 0;
}
