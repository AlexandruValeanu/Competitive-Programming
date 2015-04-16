#include <bits/stdc++.h>

using namespace std;

template <typename type, bool (*compare)(const type&, const type&)>
class BinomialHeap
{
private:

    class Node
    {
    public:

        type key;
        unsigned short degree;

        Node *parent;
        Node *child;
        Node *sibling;

        Node() : key(0), degree(0), parent(nullptr), child(nullptr), sibling(nullptr) {
        }

        Node(const type k) : key(k), degree(0), parent(nullptr), child(nullptr), sibling(nullptr) {
        }
    };

    Node *head;

    BinomialHeap(Node* aux) : head(aux), dim(0), minimGlobal(nullptr) {
    }

    BinomialHeap& operator = (const BinomialHeap *BH)
    {
        *this = BH;
        return *this;
    }

    void combineTrees(Node *&y, Node *&z) /// O(1)
    {
        /// y and z have same degree
        /// y becomes son of z
        y->parent = z;
        y->sibling = z->child;
        z->child = y;
        z->degree++;
    }

    Node* mergeLists(BinomialHeap &heap1, BinomialHeap &heap2) /// ~O(logN)
    {
        if (heap1.head == nullptr)
            return heap2.head;

        if (heap2.head == nullptr)
            return heap1.head;

        Node *head = nullptr;
        Node *heap1Next = heap1.head;
        Node *heap2Next = heap2.head;

        if (heap1.head->degree <= heap2.head->degree)
        {
            head = heap1.head;
            heap1Next = heap1Next->sibling;
        }
        else
        {
            head = heap2.head;
            heap2Next = heap2Next->sibling;
        }

        Node *tail = head;

        while (heap1Next != nullptr && heap2Next != nullptr)
        {
            if (heap1Next->degree <= heap2Next->degree)
            {
                tail->sibling = heap1Next;
                heap1Next = heap1Next->sibling;
            }
            else
            {
                tail->sibling = heap2Next;
                heap2Next = heap2Next->sibling;
            }

            tail = tail->sibling;
        }

        while (heap1Next != nullptr)
        {
            tail->sibling = heap1Next;
            tail = tail->sibling;
            heap1Next = heap1Next->sibling;
        }

        while (heap2Next != nullptr)
        {
            tail->sibling = heap2Next;
            tail = tail->sibling;
            heap2Next = heap2Next->sibling;
        }

        return head;
    }

    Node* join(BinomialHeap &heap) /// O(logN)
    {
        Node *newHead = mergeLists(*this, heap);

        this->head = nullptr;
        heap.head = nullptr;

        if (newHead == nullptr)
            return nullptr;

        Node *prev = nullptr;
        Node *curr = newHead;
        Node *next = curr->sibling;

        while (next != nullptr)
        {
            if (curr->degree != next->degree || (next->sibling != nullptr && next->sibling->degree == curr->degree))
            {
                prev = curr;
                curr = next;
            }
            else if (compare(curr->key, next->key) == true)
            {
                curr->sibling = next->sibling;
                combineTrees(next, curr);
            }
            else
            {
                if (prev == nullptr)
                    newHead = next;
                else
                    prev->sibling = next;

                combineTrees(curr, next);
                curr = next;
            }

            next = curr->sibling;
        }

        return newHead;
    }

    void insert(const type key) /// O(logN)
    {
        Node *newNode = new Node(key);
        BinomialHeap tempHeap(newNode);
        this->head = this->join(tempHeap);
        dim++;

        if (minimGlobal == nullptr ||  compare(key, minimGlobal->key))
            minimGlobal = newNode;
    }

    void decreaseKey(Node *&node, const type newKey) /// O(logN)
    {
        if (newKey > node->key)
            throw "Error in decreaseKey: newKey is not smaller!";

        node->key = newKey;
        Node *y = node;
        Node *z = y->parent;

        while (z != nullptr && compare(y->key, z->key) == true)
        {
            swap(y->key, z->key);
            y = z;
            z = y->parent;
        }

        if (minimGlobal == nullptr ||  compare(newKey, minimGlobal->key))
            minimGlobal = node;
    }

    void removeTreeRoot(Node *&root, Node *&prevRoot) /// O(logN)
    {
        /// Remove root from the heap
        if (root == this->head)
            this->head = root->sibling;
        else
            prevRoot->sibling = root->sibling;

        /// Reverse the order of root's children
        Node *newHead = nullptr;
        Node *child = root->child;

        delete root;

        while (child != nullptr)
        {
            Node *next = child->sibling;

            child->sibling = newHead;
            child->parent = nullptr;
            newHead = child;

            child = next;
        }

        /// Create new heap from newHead
        BinomialHeap tempHeap(newHead);
        /// join the heaps and set its head as this->head
        this->head = this->join(tempHeap);

        /// update minimGlobal
        minimGlobal = nullptr;
        Node *tmp = head;

        while (tmp != nullptr)
        {
            if (minimGlobal == nullptr ||  compare(tmp->key, minimGlobal->key))
                minimGlobal = tmp;

            tmp = tmp->sibling;
        }
    }

    void extractMinimum() /// O(logN)
    {
        if (this->head == nullptr)
            return;

        dim--;

        Node *minim = this->head;
        Node *minPrev = nullptr;
        Node *next = minim->sibling;
        Node *nextPrev = minim;

        while (next != nullptr)
        {
            if (compare(next->key, minim->key) == true)
            {
                minim = next;
                minPrev = nextPrev;
            }

            nextPrev = next;
            next = next->sibling;
        }

        removeTreeRoot(minim, minPrev);
    }

    void erase(Node *node) /// O(logN)
    {
        decreaseKey(node, numeric_limits<type>::min());
        extractMinimum();
    }

public:

    /**
      Operation             | Runtime
      ----------------------+----------
       Decrease key         | Θ(log N)
       Delete               | Θ(log N)
       Extract minimum      | Θ(log N)
       Find minimum         | O(1)
       Insert               | O(log N)
       Union                | Θ(log N)

      Memory: ~26 bytes/node
    */

    size_t dim;
    Node *minimGlobal;

    BinomialHeap() : head(nullptr), dim(0), minimGlobal(nullptr) {
    }

    BinomialHeap(const vector<type> keys) : head(nullptr), dim(0), minimGlobal(nullptr) {

        for (type key: keys)
            this->insert(key);
    }

    type top() const
    {
        if (minimGlobal == nullptr)
            throw "Error in top(): heap is empty!";

        return minimGlobal->key;
    }

    void push(const type key)
    {
        this->insert(key);
    }

    void pop()
    {
        this->extractMinimum();
    }

    void merge(BinomialHeap& H)
    {
        this->head = this->join(H);
    }

    size_t size() const
    {
        return dim;
    }

    bool empty() const
    {
        return (dim == 0);
    }
};

bool cmp(const int &a, const int &b)
{
    return a < b;
}

int main()
{
    return 0;
}
