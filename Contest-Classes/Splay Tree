#include <bits/stdc++.h>

using namespace std;

template <typename T>
class SplayTree
{
public:

    SplayTree();
    SplayTree(vector<T> &v);

    bool insert(const T& value);
    bool find(const T& value);
    bool erase(const T& value);

    void inorder() const;

protected:

    class Node
    {
    public:

        Node(){}

        T key;
        Node *left, *right;

        Node(const T& value);
        Node(const T value, Node *_left, Node *_right);

        void update();
    };

    Node *ROOT, *nullNode;

    Node* rotateLeft(Node *root);
    Node* rotateRight(Node *root);

    Node* splay(Node *root, const T& value);

    bool insert(Node *&root, const T& value);
    bool find(Node *&root, const T& value);
    bool erase(Node *&root, const T& value);

    void inorder(Node *root) const;
};

///--------------------------------------------------------------------------------------
/// begin class Node implementation

template <typename T>
SplayTree<T>::Node::Node(const T& value)
{
    this->key = value;
    this->left = nullptr;
    this->right = nullptr;
}

template <typename T>
SplayTree<T>::Node::Node(const T value, Node *_left, Node *_right)
{
    this->key = value;
    this->left = _left;
    this->right = _right;
}

template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::rotateRight(Node *N)
{
    Node *aux = N->left;
    N->left = aux->right;
    aux->right = N;

    return aux;
}

template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::rotateLeft(Node *N)
{
    Node *aux = N->right;
    N->right = aux->left;
    aux->left = N;

    return aux;
}

/// end class Node implementation
///--------------------------------------------------------------------------------------

template <typename T>
SplayTree<T>::SplayTree()
{
    nullNode = new Node(T());
    this->ROOT = nullNode;
}

template <typename T>
typename SplayTree<T>::Node* SplayTree<T>::splay(Node *root, const T& value)
{
    if ( root == nullNode || root->key == value )
        return root;

    Node *leftTreeMax, *rightTreeMin;
    static Node header;

    header.left = header.right = nullNode;
    leftTreeMax = rightTreeMin = &header;

    nullNode->key = value;

    while ( true )
    {
        if ( value == root->key ) break;

        if ( value < root->key )
        {
            if ( value < root->left->key )
                root = rotateRight(root);

            if ( root->left == nullNode ) break;

            rightTreeMin->left = root;
            rightTreeMin = root;
            root = root->left;
        }
        else
        {
            if ( root->right->key < value )
                root = rotateLeft(root);

            if ( root->right == nullNode ) break;

            leftTreeMax->right = root;
            leftTreeMax = root;
            root = root->right;
        }
    }

    leftTreeMax->right = root->left;
    rightTreeMin->left = root->right;
    root->left = header.right;
    root->right = header.left;

    return root;
}

template <typename T>
bool SplayTree<T>::insert(const T& value)
{
    return insert(ROOT, value);
}

template <typename T>
bool SplayTree<T>::insert(Node *&root, const T& value)
{
    if ( root == nullNode )
    {
        root = new Node(value);
        root->left = root->right = nullNode;
        return true;
    }

    root = splay(root, value);

    if ( root->key == value )
        return false;

    Node *newNode = new Node(value);

    if ( value < root->key )
    {
        newNode->left = root->left;
        newNode->right = root;
        root->left = nullNode;

        root = newNode;
    }
    else
    {
        newNode->right = root->right;
        newNode->left = root;
        root->right = nullNode;

        root = newNode;
    }

    return true;
}

template <typename T>
bool SplayTree<T>::find(const T& value)
{
    return find(ROOT, value);
}

template <typename T>
bool SplayTree<T>::find(Node *&root, const T& value)
{
    root = splay(root, value);

    return ( root->key == value );
}

template <typename T>
bool SplayTree<T>::erase(const T& value)
{
    return erase(ROOT, value);
}

template <typename T>
bool SplayTree<T>::erase(Node *&root, const T& value)
{
    if ( root == nullNode )
        return false;

    Node *newNode, *aux = root;

    root = splay(root, value);

    if ( root->key != value )
        return false;

    if ( root->left == nullNode )
        newNode = root->right;
    else
    {
        newNode = splay(root->left, value);
        newNode->right = root->right;
    }

    delete root;
    root = newNode;

    return true;
}

template <typename T>
void SplayTree<T>::inorder(Node *root) const
{
    if ( root == nullNode )
        return;

    inorder(root->left);
    cerr << root->key << " ";
    inorder(root->right);
}

template <typename T>
void SplayTree<T>::inorder() const
{
    return inorder(ROOT);
}

int main()
{
    return 0;
}
