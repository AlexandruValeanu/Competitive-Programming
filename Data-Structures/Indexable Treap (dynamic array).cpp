#include <bits/stdc++.h>

using namespace std;

class IndexableTreap ///1-based
{
private:

    static const int MAX_PRIORITY = 1000000000;

    class Node
    {
    public:

        int Key;
        size_t Size;
        bool Reverse;
        size_t Priority;

        int Sum;

        Node *Left, *Right;

        Node(const int k, const size_t nr, const bool rev, const size_t pr, Node *l, Node *r) : Key(k), Size(nr),
            Reverse(rev), Priority(pr), Sum(k), Left(l), Right(r) {
        }
    };

    void lazy_update(Node* &T)
    {
        if (T != NIL && T->Reverse == true)
        {
            T->Left->Reverse  ^= 1;
            T->Right->Reverse ^= 1;
            T->Reverse = false;

            swap(T->Left, T->Right);
        }
    }

    void update(Node* &T)
    {
        lazy_update(T);
        lazy_update(T->Left);
        lazy_update(T->Right);

        if (T != NIL)
        {
            T->Size = 1 + T->Left->Size + T->Right->Size;
            T->Sum = T->Key + T->Left->Sum + T->Right->Sum;
        }
    }

    Node* rotate_to_right(Node* &T)
    {
        assert(T != NIL);

        Node *tmp = T->Left;
        T->Left = tmp->Right;
        tmp->Right = T;

        update(T);
        update(tmp);

        return tmp;
    }

    Node* rotate_to_left(Node* &T)
    {
        assert(T != NIL);

        Node *tmp = T->Right;
        T->Right = tmp->Left;
        tmp->Left = T;

        update(T);
        update(tmp);

        return tmp;
    }

    void balance(Node* &T)
    {
        assert(T != NIL);

        if (T->Left->Priority > T->Priority)
            T = rotate_to_right(T);
        else if (T->Right->Priority > T->Priority)
                T = rotate_to_left(T);
        else
            update(T);
    }

    void insert_after(Node* &T, size_t position, const int key, const int priority)
    {
        if (T == NIL)
            T = new Node(key, 1, false, priority, NIL, NIL);
        else
        {
            lazy_update(T);
            lazy_update(T->Left);
            lazy_update(T->Right);

            if (position <= T->Left->Size)
                insert_after(T->Left, position, key, priority);
            else
                insert_after(T->Right, position - 1 - T->Left->Size, key, priority);

            balance(T);
        }
    }

    void change_key(Node* &T, size_t position, const int key)
    {
        assert(T != NIL);

        lazy_update(T);
        lazy_update(T->Left);
        lazy_update(T->Right);

        if (T->Left->Size + 1 == position)
        {
            T->Key = key;
            update(T);
        }
        else
        {
            if (position <= T->Left->Size)
                change_key(T->Left, position, key);
            else
                change_key(T->Right, position - 1 - T->Left->Size, key);
        }

        if (T != NIL)
            update(T);
    }

    int kth_element(Node* &T, size_t position)
    {
        assert(T != NIL);

        lazy_update(T);
        lazy_update(T->Left);
        lazy_update(T->Right);

        if (T->Left->Size + 1 == position)
            return T->Key;

        if (position <= T->Left->Size)
            return kth_element(T->Left, position);
        else
            return kth_element(T->Right, position - 1 - T->Left->Size);
    }

    void erase(Node* &T, size_t position)
    {
        if (T == NIL)
            return;

        lazy_update(T);
        lazy_update(T->Left);
        lazy_update(T->Right);

        if (position <= T->Left->Size)
            erase(T->Left, position);
        else if (position > T->Left->Size + 1)
            erase(T->Right, position - 1 - T->Left->Size);
        else
        {
            if (T->Left == NIL && T->Right == NIL)
            {
                delete T;
                T = NIL;
            }
            else
            {
                if (T->Left->Priority > T->Right->Priority)
                {
                    T = rotate_to_right(T);
                    erase(T->Right, position - 1 - T->Left->Size);
                }
                else
                {
                    T = rotate_to_left(T);
                    erase(T->Left, position);
                }
            }
        }

        if (T != NIL)
            update(T);
    }

    void split(Node* &T, Node* &L, Node* &R, const size_t position) ///splits in [1...position] and [position+1...treap.size()]
    {
        insert_after(T, position, 1, MAX_PRIORITY);
        L = T->Left;
        R = T->Right;

        delete T;
        T = NIL;
    }

    void join(Node* &T, Node* &L, Node* &R)
    {
        T = new Node(1, 1, false, MAX_PRIORITY, L, R);
        update(T);

        erase(T, T->Left->Size + 1);
    }

    void inorder(Node* &T, vector<int> &keys)
    {
        if (T == NIL)
            return;

        lazy_update(T);
        lazy_update(T->Left);
        lazy_update(T->Right);

        inorder(T->Left, keys);
        keys.push_back(T->Key);
        inorder(T->Right, keys);
    }

    void clear(Node* &T)
    {
        if (T == NIL)
            return;

        clear(T->Left);
        clear(T->Right);

        delete T;
        T = NIL;
    }

public:

    Node *Root;
    Node *NIL; ///dummy node

    IndexableTreap() : Root(nullptr), NIL(nullptr)
    {
        srand(time(nullptr));

        NIL = new Node(0, 0, 0, 0, nullptr, nullptr);
        Root = NIL;
    }

    ~IndexableTreap()
    {
        this->clear();
    }

    IndexableTreap(IndexableTreap &IT) : Root(nullptr), NIL(nullptr)
    {
        srand(time(nullptr));

        NIL = new Node(0, 0, 0, 0, nullptr, nullptr);
        Root = NIL;

        for (size_t i = 1; i <= IT.size(); ++i)
        {
            int key = IT.kth_element(i);
            this->insert_after(i - 1, key);
        }
    }

    IndexableTreap& operator = (IndexableTreap &IT)
    {
        Root = nullptr;
        NIL = nullptr;

        srand(time(nullptr));

        NIL = new Node(0, 0, 0, 0, nullptr, nullptr);
        Root = NIL;

        for (size_t i = 1; i <= IT.size(); ++i)
        {
            int key = IT.kth_element(i);
            this->insert_after(i - 1, key);
        }

        return *this;
    }

    ///Modifiers ----------------------------------------------------------------------
    void insert_after(const size_t position, const int key) ///inserts after position
    {
        assert(position <= this->size());

        insert_after(Root, position, key, rand() % (MAX_PRIORITY - 2) + 1);
    }

    void erase(const size_t position)
    {
        assert(1 <= position);
        assert(position <= this->size());

        erase(Root, position);
    }

    void change_key(const size_t position, const int key)
    {
        assert(1 <= position);
        assert(position <= this->size());

        change_key(Root, position, key);
    }

    void clear()
    {
        clear(Root);
    }
    ///---------------------------------------------------------------------------------

    void reverse(const size_t start, const size_t finish)
    {
        assert(1 <= start);
        assert(start <= finish);
        assert(finish <= this->size());

        Node *tmp, *T1, *T2, *T3;

        split(this->Root, tmp, T3, finish); ///tmp = [1...finish] | T3 = [finish+1...treap.size()]
        split(tmp, T1, T2, start - 1);      ///T1 = [1...start-1] | T2 = [start...finish]

        T2->Reverse = true;

        join(tmp, T1, T2);
        join(this->Root, tmp, T3);
    }

    size_t query(const size_t start, const size_t finish)
    {
        assert(1 <= start);
        assert(start <= finish);
        assert(finish <= this->size());

        Node *tmp, *T1, *T2, *T3;

        split(this->Root, tmp, T3, finish);
        split(tmp, T1, T2, start - 1);

        size_t sum = T2->Sum;

        join(tmp, T1, T2);
        join(this->Root, tmp, T3);

        return sum;
    }

    ///Element access --------------------------------------------------------------------------
    int kth_element(const size_t position)
    {
        assert(1 <= position);
        assert(position <= this->size());

        return kth_element(Root, position);
    }

    int at(const size_t position)
    {
        return kth_element(position);
    }

    int operator [] (const size_t position)
    {
        return kth_element(position);
    }

    int front()
    {
        assert(this->empty() == false);

        return kth_element(1);
    }

    int back()
    {
        assert(this->empty() == false);

        return kth_element(this->size());
    }
    ///---------------------------------------------------------------------------------

    void inorder(vector<int> &keys)
    {
        inorder(Root, keys);
    }

    ///Capacity ------------------------------------------------------------------------
    size_t size() const
    {
        return Root->Size;
    }

    bool empty() const
    {
        return (Root->Size == 0);
    }
    ///---------------------------------------------------------------------------------
};

int main()
{
    return 0;
}
