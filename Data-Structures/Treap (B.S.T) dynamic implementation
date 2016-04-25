#include <bits/stdc++.h>

using namespace std;

class randomGenerator
{
public:

    std::mt19937 generator;

    randomGenerator()
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        generator = mt19937(seed);
    }

    int randomInt()
    {
        return generator();
    }

} generator;

template <typename T> ///only integers
class Treap
{
private:

    class Node
    {
    public:
        T key;
        T sumTree;
        int priority;
        unsigned int size;

        Node *leftSon, *rightSon;

        Node(const T k) : key{k}, sumTree{k}, priority{generator.randomInt()},
            size{1}, leftSon{nullptr}, rightSon{nullptr} {
        }

        void update()
        {
            this->size = 1;
            this->sumTree = this->key;

            if (this->leftSon != nullptr)
            {
                this->size += this->leftSon->size;
                this->sumTree += this->leftSon->sumTree;
            }

            if (this->rightSon != nullptr)
            {
                this->size += this->rightSon->size;
                this->sumTree += this->rightSon->sumTree;
            }
        }
    };

    Node* join(Node *L, Node *R)
    {
        if (L == nullptr)
            return R;

        if (R == nullptr)
            return L;

        if (L->priority < R->priority) ///min-heap
        {
            L->rightSon = join(L->rightSon, R);
            L->update();

            return L;
        }
        else
        {
            R->leftSon = join(L, R->leftSon);
            R->update();

            return R;
        }
    }

    void split(Node *tree, Node *&L, Node *&R, const T &key)
    {
        L = nullptr;
        R = nullptr;

        if (tree == nullptr)
            return;

        if (tree->key < key)
        {
            split(tree->rightSon, tree->rightSon, R, key);
            L = tree;
        }
        else
        {
            split(tree->leftSon, L, tree->leftSon, key);
            R = tree;
        }

        tree->update();
    }

    bool find(const Node *&tree, const T &key) const
    {
        if (tree == nullptr)
            return false;

        if (tree->key == key)
            return true;

        if (key < tree->key)
            return find(tree->leftSon, key);
        else
            return find(tree->rightSon, key);
    }

    T kth_element(const Node *&tree, const unsigned int position) const
    {
        assert(tree != nullptr);

        if (realSize(tree->leftSon) + 1 == position)
            return tree->key;
        else if (position <= realSize(tree->leftSon))
            return kth_element(tree->leftSon, position);
        else
            return kth_element(tree->rightSon, position - realSize(tree->leftSon) - 1);
    }

    vector<T> print(const Node *tree) const
    {
        if (tree == nullptr)
            return {};

        vector<T> a = print(tree->leftSon);
        a.push_back(tree->key);
        vector<T> b = print(tree->rightSon);

        for (const auto &it : b)
            a.push_back(it);

        return a;
    }

    unsigned int realSize(const Node *tree) const
    {
        if (tree == nullptr)
            return 0;
        else
            return tree->size;
    }

    void clear(Node *&tree)
    {
        if (tree == nullptr)
            return;

        clear(tree->leftSon);
        clear(tree->rightSon);

        delete tree;
        tree = nullptr;
    }

    void clearOnce(Node *&tree)
    {
        assert(tree != nullptr);

        if (tree->leftSon == nullptr && tree->rightSon == nullptr)
        {
            delete tree;
            tree = nullptr;
        }
        else
        {
            Node *aux = tree;

            vector<Node*> stackNodes;

            while (aux->leftSon != nullptr || aux->rightSon != nullptr)
            {
                stackNodes.push_back(aux);

                if (aux->leftSon != nullptr)
                    aux = aux->leftSon;
                else
                    aux = aux->rightSon;
            }

            for (auto it : stackNodes)
                assert(it != nullptr);

            assert(stackNodes.size() > 0);
            assert(aux != nullptr);
            assert(aux->leftSon == nullptr && aux->rightSon == nullptr);

            if (stackNodes.back()->leftSon == aux)
                stackNodes.back()->leftSon = nullptr;
            else
                stackNodes.back()->rightSon = nullptr;

            while (stackNodes.size())
            {
                stackNodes.back()->update();
                stackNodes.pop_back();
            }

            delete aux;
            aux = nullptr;
        }
    }

    T sumSmallerOrEqual(const T &key)
    {
        Node *L, *M, *R;

        split(this->root, L, M, key);
        split(M, M, R, key + EPSILON);

        T answer = 0;

        if (L != nullptr)
            answer += L->sumTree;

        if (M != nullptr)
            answer += M->sumTree;

        L = join(L, M);
        this->root = join(L, R);

        return answer;
    }

    T min_element(Node *tree) const
    {
        if (tree == nullptr)
            throw "Treap::min_element -> treap is null";

        Node *aux = tree;

        while (aux->leftSon != nullptr)
            aux = aux->leftSon;

        return aux->key;
    }

    T max_element(Node *tree) const
    {
        if (tree == nullptr)
            throw "Treap::max_element -> treap is null";

        Node *aux = tree;

        while (aux->rightSon != nullptr)
            aux = aux->rightSon;

        return aux->key;
    }

    Treap(const Node *& tree) : root{nullptr}, EPSILON{1}
    {
        this->root = tree;
    }

    Node *root;
    T EPSILON;

public:

    Treap() : root{nullptr}, EPSILON{1} {

    }

    Treap(const Treap &rhs) : root{nullptr}, EPSILON{rhs.EPSILON}
    {
        vector<T> arr = rhs.print();

        for (const T &it : arr)
            this->root(it);
    }

    Treap(const vector<T> &arr) : root{nullptr}, EPSILON{1}
    {
        for (const T &it : arr)
            this->insert(it);
    }

    Treap(const initializer_list<T> &ls) : root{nullptr}, EPSILON{1}
    {
        for (const T &it : ls)
            this->insert(it);
    }

    ~Treap()
    {
        this->clear(this->root);
    }

    Treap& operator = (const Treap &rhs)
    {
        this->clear(this->root);

        vector<T> arr = rhs.print();

        for (const auto &it : arr)
            this->insert(it);

        return *this;
    }

    void setEpsilon(const T &e)
    {
        this->EPSILON = e;
    }

    void insert(const T &key)
    {
        Node *L, *R;

        split(this->root, L, R, key);
        this->root = join(join(L, new Node(key)), R);
    }

    /*
        eraseOne(key) - erases one instance of key
        key + EPSILON must not overflow
    */
    bool eraseOne(const T &key)
    {
        Node *L, *M, *R;

        split(this->root, L, M, key);
        split(M, M, R, key + EPSILON);

        bool success = false;

        if (M != nullptr)
        {
            success = true;
            clearOnce(M);
        }

        L = join(L, M);
        this->root = join(L, R);

        return success;
    }

    /*
        eraseAll(key) - erases all instances of key
        key + EPSILON must not overflow
    */
    bool eraseAll(const T &key)
    {
        Node *L, *M, *R;

        split(this->root, L, M, key);
        split(M, M, R, key + EPSILON);

        bool success = false;

        if (M != nullptr)
        {
            success = true;
            clear(M);
        }

        this->root = join(L, R);

        return success;
    }

    /*
        divide - count number of elements smaller, equal, greater than key
        key + EPSILON must not overflow
    */
    tuple<unsigned int, unsigned int, unsigned int> divide(const T &key)
    {
        Node *L, *M, *R;

        split(this->root, L, M, key);
        split(M, M, R, key + EPSILON);

        auto t = make_tuple(realSize(L), realSize(M), realSize(R));

        L = join(L, M);
        this->root = join(L, R);

        return t;
    }

    unsigned int countSmaller(const T &key)
    {
        auto t = divide(key);
        return get<0>(t);
    }

    unsigned int countEqual(const T &key)
    {
        auto t = divide(key);
        return get<1>(t);
    }

    unsigned int countSmallerOrEqual(const T &key)
    {
        auto t = divide(key);
        return get<0>(t) + get<1>(t);
    }

    unsigned int countGreater(const T &key)
    {
        auto t = divide(key);
        return get<2>(t);
    }

    T min_element() const
    {
        return min_element(this->root);
    }

    T max_element() const
    {
        return max_element(this->root);
    }

    T next_element(const T &key)
    {
        Node *M, *R;

        split(this->root, M, R, key + EPSILON);

        T answer;

        if (R == nullptr)
            answer = numeric_limits<T>::max();
        else
            answer = min_element(R);

        this->root = join(M, R);

        return answer;
    }

    T prev_element(const T &key)
    {
        Node *L, *M;

        split(this->root, L, M, key);

        T answer;

        if (L == nullptr)
            answer = numeric_limits<T>::min();
        else
            answer = max_element(L);

        this->root = join(L, M);

        return answer;
    }

    bool find(const T &key) const
    {
        return find(this->root, key);
    }

    /*
        kth_element is 1-based
    */
    T kth_element(const unsigned int position) const
    {
        if (position < 1 || position > realSize(this->root))
            throw out_of_range{"Treap::kth_element"};

        return kth_element(this->root, position);
    }

    /*
        operator[] is 1-based (calls Treap::kth_element)
    */
    T operator [](const unsigned int position) const
    {
        return kth_element(position);
    }

    /*
        x - EPSILON must not underflow
    */
    T sumRange(const T &x, const T &y)
    {
        if (y > x)
            return static_cast<T>(0);
        else
            return sumSmallerOrEqual(y) - sumSmallerOrEqual(x - EPSILON);
    }

    vector<T> print() const
    {
        return this->print(this->root);
    }

    bool empty() const
    {
        return this->root == nullptr;
    }

    unsigned int size() const
    {
        return realSize(root);
    }

    /**
        Interface

    Treap()
    Treap(const Treap &rhs)
    Treap(const vector<T> &arr)
    Treap(const initializer_list<T> &ls)
    Treap& operator = (const Treap &rhs)
    ~Treap()
    void setEpsilon(const T &e)

    void insert(const T &key)

    bool eraseOne(const T &key)
    bool eraseAll(const T &key)

    T operator [](const unsigned int position) const
    T kth_element(const unsigned int position) const
    bool find(const T &key) const

    tuple<unsigned int, unsigned int, unsigned int> divide(const T &key)
    unsigned int countSmaller(const T &key)
    unsigned int countEqual(const T &key)
    unsigned int countSmallerOrEqual(const T &key)
    unsigned int countGreater(const T &key)

    T prev_element(const T &key)
    T next_element(const T &key)
    T max_element() const
    T min_element() const

    T sumRange(const T &x, const T &y)

    unsigned int size() const
    bool empty() const
    vector<T> print() const
**/
};

int main()
{
    return 0;
}
