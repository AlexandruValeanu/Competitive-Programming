#include <bits/stdc++.h>

using namespace std;

template <typename dataType, bool (*compare)(const dataType&, const dataType&)>
class FibonacciHeap
{
private:

    class Node
    {
    public:

        dataType key;
        size_t index;
        size_t degree;

        Node *parent;
        Node *child;
        Node *left, *right;

        bool isMarked;

        Node() : key(0), index(0), degree(0), parent(nullptr), child(nullptr),
                 left(this), right(this), isMarked(false) {
        }

        Node(const dataType k, const size_t id) : key(k), index(id), degree(0), parent(nullptr), child(nullptr),
                 left(this), right(this), isMarked(false) {
        }

        ~Node()
        {
            parent = nullptr;
            child = nullptr;
            left = right = nullptr;

            key = dataType();
            index = 0;
            degree = 0;
            isMarked = false;
        }
    };

    /// circular doubly linked list
    class DoublyLinkedList
    {
    public:

        ///Merge two doubly linked lists and return minimum
        static Node* mergeLists(Node *u, Node *v)
        {
            if (u == nullptr)
                return v;

            if (v == nullptr)
                return u;

            u->right->left = v->left;
            v->left->right = u->right;
            u->right = v;
            v->left = u;

            return u;
        }

        ///Insert a node to a doubly linked list
        static Node* insert(Node *r, Node *u)
        {
            if (r == nullptr)
            {
                u->left = u;
                u->right = u;

                return u;
            }
            else
            {
                r->right->left = u;
                u->right = r->right;
                u->left = r;
                r->right = u;

                return r;
            }
        }

        ///Remove a node from a doubly linked list
        static Node* remove(Node *u)
        {
            if (u->right == u)
                return nullptr;

            u->right->left = u->left;
            u->left->right = u->right;

            return u->right;
        }
    };

    const double PHI =  1.618033988749;

    Node **Array;
    Node **D;

    Node *minNode;
    size_t nr_nodes;

    size_t MAX_N;

    void insert(Node *x)
    {
        x->degree = 0;
        x->parent = nullptr;
        x->child = nullptr;
        x->isMarked = false;

        if (minNode == nullptr)
        {
            minNode = x;
            x->left = x->right = x;
        }
        else
        {
            minNode = DoublyLinkedList::insert(minNode, x);

            if (compare(x->key, minNode->key))
                minNode = x;
        }

        this->nr_nodes++;
    }

    void cut(Node *node, Node *parent)
    {
        parent->child = DoublyLinkedList::remove(node);
        parent->degree--;

        node->left = node->right = node;
        node->parent = nullptr;

        DoublyLinkedList::mergeLists(minNode, node);
        node->isMarked = false;
    }

    void cascadingCut(Node *node)
    {
        Node *parent = node->parent;

        if (parent != nullptr)
        {
            if (node->isMarked == false)
                node->isMarked = true;
            else
            {
                cut(node, parent);
                cascadingCut(parent);
            }
        }
    }

    void ChangeKey(Node *node, const dataType newKey)
    {
        if (compare(node->key, newKey))
        {
            node->key = newKey;

            if (node->child != nullptr)
                cutAllChildren(node);

            if (node == minNode)
                consolidate();

        } else if (compare(newKey, node->key))
        {
            node->key = newKey;
            Node *parent = node->parent;

            if (parent != nullptr && compare(node->key, parent->key))
            {
                cut(node, parent);
                cascadingCut(parent);
            }

            if (compare(node->key, minNode->key))
                minNode = node;
        }
    }

    void remove(Node *node)
    {
        Node *parent = node->parent;

        if (parent != nullptr)
        {
            cut(node, parent);
            cascadingCut(parent);
        }

        minNode = node;
        extractMinimum();
    }

    void cutAllChildren(Node *node)
    {
        Node *x = node->child;

        do
        {
            x->parent = nullptr;
            x->isMarked = false;
            x = x->left;

        } while (x != node->child);

        DoublyLinkedList::mergeLists(minNode, x);

        node->child = nullptr;
        node->degree = 0;
        node->isMarked = true;
    }

    void extractMinimum()
    {
        Node *extractedMin = minNode;

        if (extractedMin != nullptr)
        {
            if (minNode->child != nullptr)
                cutAllChildren(minNode);

            minNode = DoublyLinkedList::remove(minNode);

            if (minNode != nullptr)
                consolidate();

            this->nr_nodes--;
        }
    }

    void linkHeaps(Node *y, Node *x)
    {
        y->parent = x;
        x->child = DoublyLinkedList::insert(x->child, y);
        x->degree++;
        y->isMarked = false;
    }

    void consolidate()
    {
        size_t MAX_DEGREE = compute_degree(this->nr_nodes);

        for (size_t i = 0; i < MAX_DEGREE; ++i)
            D[i] = nullptr;

        Node *w = minNode;

        do
        {
            Node *x = w;
            size_t deg = x->degree;
            w = DoublyLinkedList::remove(w);

            while (D[deg] != nullptr)
            {
                Node *y = D[deg];

                if (compare(y->key, x->key))
                    swap(x, y);

                linkHeaps(y, x);
                D[deg] = nullptr;
                deg++;
            }

            D[deg] = x;

        } while (w != nullptr);

        minNode = nullptr;

        for (size_t i = 0; i < MAX_DEGREE; ++i)
            if (D[i] != nullptr)
            {
                DoublyLinkedList::insert(minNode, D[i]);

                if (minNode == nullptr || compare(D[i]->key, minNode->key))
                    minNode = D[i];
            }
    }

    size_t compute_degree(size_t n) const
    {
		size_t ans = 0;
		double cur = 1;

		while (cur < n)
        {
			cur *= PHI;
            ans++;
		}

		return ans + 1;
	}

public:

    size_t pointer;

    FibonacciHeap() : Array(nullptr), D(nullptr), minNode(nullptr),
                      nr_nodes(0), MAX_N(0), pointer(0) {
    }

    FibonacciHeap(const size_t N) : Array(new Node*[N]), D(new Node*[40]), minNode(nullptr),
                                 nr_nodes(0), MAX_N(N), pointer(0) {

    }

    ~FibonacciHeap()
    {
        for (int i = 0; i < MAX_N; ++i)
            delete Array[i];

        delete [] Array;
        delete [] D;

        minNode = nullptr;
        nr_nodes = 0;
        MAX_N = 0;
        pointer = 0;
    }

    void push(const size_t id, const dataType key)
    {
        assert(pointer < MAX_N);

        Array[pointer] = new Node(key, id);
        insert(Array[pointer]);

        pointer++;
    }

    dataType top() const
    {
        assert(minNode != nullptr);

        return minNode->key;
    }

    void changeKey(const size_t id, const dataType newKey)
    {
        assert(Array[id] != nullptr);

        ChangeKey(Array[id], newKey);
    }

    void remove(const size_t id)
    {
        assert(Array[id] != nullptr);

        remove(Array[id]);
    }

    void merge(FibonacciHeap &H)
    {
        minNode = DoublyLinkedList::mergeLists(minNode, H.minNode);

        if (minNode == nullptr || (H.minNode != nullptr && compare(H.minNode->key, minNode->key)))
            minNode = H.minNode;

        this->nr_nodes += H.nr_nodes;
    }

    void pop()
    {
        extractMinimum();
    }

    double memory() const
    {
        return (sizeof(Node) * (40 + MAX_N)) / 1024.0 / 1024.0;
    }

    bool empty() const
    {
        return (this->nr_nodes == 0);
    }

    size_t size() const
    {
        return this->nr_nodes;
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
