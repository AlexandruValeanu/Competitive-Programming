#include <bits/stdc++.h>

using namespace std;

template <typename Type>
class Skiplist
{
public:

    class Node
    {
    public:

        Node **Next;
        Type Value;

        explicit Node()
        {
        }

        Node(Type value, int level)
        {
            Value = value;
            Next = new Node*[level];

            for (int i = 0; i < level; ++i)
                Next[i] = NULL;
        }
    };

    Node *Head;
    int MAX_LEVEL;

    Skiplist()
    {
        MAX_LEVEL = 31;
        Head = new Node(0, MAX_LEVEL + 1);

        srand(time(NULL));
    }

    int generateLevel()
    {
        int level = 0;

        for ( int R = rand(); ( R & 1 ) == 1; R >>= 1 )
            level++;

        if ( level > MAX_LEVEL )
            level = MAX_LEVEL;

        return level;
    }

    void insert(const Type value)
    {
        int level = generateLevel();

        Node *newNode = new Node(value, level + 1);
        Node *current = Head;

        for (int i = MAX_LEVEL - 1; i >= 0; i--)
        {
            while ( current->Next[i] != NULL && current->Next[i]->Value <= value )
                current = current->Next[i];

            if ( i <= level )
            {
                newNode->Next[i] = current->Next[i];
                current->Next[i] = newNode;
            }
        }
    }

    bool find(const Type value)
    {
        Node *current = Head;

        for (int i = MAX_LEVEL - 1; i >= 0; i--)
        {
            while ( current->Next[i] != NULL && current->Next[i]->Value < value )
                current = current->Next[i];

            if ( current->Next[i] != NULL && current->Next[i]->Value == value )
                return true;
        }

        return false;
    }

    void erase(const Type value)
    {
        Node *current = Head;
        Node *toErase = NULL;

        for (int i = MAX_LEVEL - 1; i >= 0; i--)
        {
            while ( current->Next[i] != NULL && current->Next[i]->Value <= value )
            {
                if ( current->Next[i]->Value == value )
                {
                    toErase = current->Next[i];
                    current->Next[i] = current->Next[i]->Next[i];
                    break;
                }

                current = current->Next[i];
            }
        }

        if ( toErase != NULL )
        {
            delete toErase->Next;
            delete toErase;
        }
    }

    void print()
    {
        Node *current = Head->Next[0];

        while ( current )
        {
            cout << current->Value << " ";
            current = current->Next[0];
        }
    }
};

int main()
{
    return 0;
}
