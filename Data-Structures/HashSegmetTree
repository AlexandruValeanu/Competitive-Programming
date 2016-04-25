#include <iostream>
#include <type_traits>
#include <cassert>
#include <vector>

template<unsigned int MOD>
class ModInteger
{
public:

    ModInteger() : data(0) {
    }

    ModInteger(const ModInteger &rhs) : data(rhs.data) {
    }

    explicit ModInteger(const std::string& str) : data(0) {

        assert(str.size() > 0);

        bool flag = false;
        std::string a = str;

        if (str[0] == '-')
        {
            flag = true;
            a.erase(a.begin());
        }

        for (const char &c : a)
            this->data = (this->data * 10 + (c - '0')) % MOD;

        if (flag && this->data > 0)
            this->data = MOD - this->data;
    }

    explicit ModInteger(const unsigned int &rhs) : data(rhs % MOD) {
    }

    explicit ModInteger(const unsigned long long &rhs) : data(rhs % MOD) {
    }

    ModInteger(const int &rhs) : data(0) {

        if (rhs < 0)
        {
            this->data = (-rhs) % MOD;
            this->data = (MOD -this->data) % MOD;
        }
        else
        {
            this->data = rhs % MOD;
        }
    }

    explicit ModInteger(const long long &rhs) : data(0) {

        if (rhs < 0)
        {
            this->data = (-rhs) % MOD;
            this->data = (MOD -this->data) % MOD;
        }
        else
        {
            this->data = rhs % MOD;
        }
    }

    ModInteger operator + (const ModInteger &rhs) const
    {
        return ModInteger(this->data + rhs.data);
    }

    ModInteger& operator += (const ModInteger &rhs)
    {
        *this = *this + rhs;
        return *this;
    }

    ModInteger operator - (const ModInteger &rhs) const
    {
        return ModInteger(static_cast<long long>(this->data) - rhs.data);
    }

    ModInteger& operator -= (const ModInteger &rhs)
    {
        *this = *this - rhs;
        return *this;
    }

    ModInteger operator * (const ModInteger &rhs) const
    {
        return ModInteger(static_cast<long long>(this->data) * rhs.data);
    }

    ModInteger& operator *= (const ModInteger &rhs)
    {
        *this = *this * rhs;
        return *this;
    }

    ModInteger operator / (const ModInteger &rhs) const
    {
        ///fails if MOD is not prime
        return ModInteger(*this * power(rhs, MOD - 2));
    }

    ModInteger& operator /= (const ModInteger &rhs)
    {
        *this = *this / rhs;
        return *this;
    }

    ModInteger inverseMod(void) const
    {
        return power(*this, MOD - 2);
    }

    bool operator == (const ModInteger &rhs) const
    {
        return this->data == rhs.data;
    }

    bool operator != (const ModInteger &rhs) const
    {
        return this->data != rhs.data;
    }

    template<class T>
    ModInteger operator ^ (T p) const
    {
        static_assert(std::is_integral<T>::value, "Integer required.");
        return power(*this, p);
    }

    unsigned int toInteger(void) const
    {
        return this->data;
    }

    friend std::ostream& operator << (std::ostream& stream, const ModInteger& rhs)
    {
        stream << rhs.data;
        return stream;
    }

    friend std::istream& operator >> (std::istream& stream, ModInteger& rhs)
    {
        std::string tmp;
        stream >> tmp;
        rhs = ModInteger(tmp);

        return stream;
    }

    template<class T>
    static ModInteger power(ModInteger a, T p)
    {
        ModInteger solution(1U);

        while (p > 0)
        {
            if (p & 1)
                solution *= a;

            a *= a;
            p >>= 1;
        }

        return solution;
    }

private:

    unsigned int data;
};

constexpr unsigned int MOD1 = 666013;
constexpr unsigned int MOD2 = 1000000000 + 9;
constexpr unsigned int BASE = 137;

std::vector<ModInteger<MOD1>> bases1;
std::vector<ModInteger<MOD2>> bases2;

ModInteger<MOD1> inverseBase1 = ModInteger<MOD1>(BASE - 1).inverseMod();
ModInteger<MOD2> inverseBase2 = ModInteger<MOD2>(BASE - 1).inverseMod();

void initBases(unsigned int N)
{
    N++;

    bases1.resize(N);
    bases2.resize(N);

    bases1[0] = ModInteger<MOD1>(1);
    bases2[0] = ModInteger<MOD2>(1);

    for (unsigned int i = 1; i < N; ++i)
    {
        bases1[i] = ModInteger<MOD1>(BASE) * bases1[i - 1];
        bases2[i] = ModInteger<MOD2>(BASE) * bases2[i - 1];
    }
}

class Node
{
public:

    ModInteger<MOD1> h1;
    ModInteger<MOD2> h2;

    unsigned int length;

    ModInteger<MOD1> invH1;
    ModInteger<MOD2> invH2;

    char lazy;

    Node() : h1(), h2(), length(0), invH1(), invH2(), lazy(0) {
    }

    Node(const char &c) : h1(c), h2(c), length(1), invH1(c), invH2(c), lazy(0) {
    }

    Node& operator = (const Node &rhs)
    {
        this->h1 = rhs.h1;
        this->h2 = rhs.h2;

        this->length = rhs.length;

        this->invH1 = rhs.invH1;
        this->invH2 = rhs.invH2;

        this->lazy = rhs.lazy;

        return *this;
    }

    Node realNode() const
    {
        Node T = *this;

        if (T.lazy)
        {
            ModInteger<MOD1> tmp1 = bases1[T.length] - 1;
            tmp1 *= inverseBase1;

            ModInteger<MOD2> tmp2 = bases2[T.length] - 1;
            tmp2 *= inverseBase2;

            T.h1 = ModInteger<MOD1>((unsigned int)this->lazy) * tmp1;
            T.invH1 = T.h1;

            T.h2 = ModInteger<MOD2>((unsigned int)this->lazy) * tmp2;
            T.invH2 = T.h2;

            T.lazy = 0;
        }

        return T;
    }

    bool operator == (const Node &rhs) const
    {
        Node L = this->realNode();
        Node R = rhs.realNode();

        return (L.h1 == R.h1) && (L.h2 == R.h2) && (L.invH1 == R.invH1) &&
               (L.invH2 == R.invH2);
    }

    bool operator != (const Node &rhs) const
    {
        return !(*this == rhs);
    }

    friend std::ostream& operator << (std::ostream &stream, const Node &T)
    {
        stream << T.h1 << " " << T.h2 << " " << T.length << " ";
        stream << T.invH1 << " " << T.invH2;
        return stream;
    }
};

void pushLazy(Node &T, Node &L, Node &R)
{
    if (T.lazy != 0)
    {
        L.lazy = T.lazy;
        R.lazy = T.lazy;

        L = L.realNode();
        R = R.realNode();

        L.lazy = T.lazy;
        R.lazy = T.lazy;

        T.lazy = 0;
    }
}

Node join(Node L, Node R)
{
    L = L.realNode();
    R = R.realNode();

    Node T;

    if (L.length == 0)
        T = R;
    else if (R.length == 0)
        T = L;
    else
    {
        T.h1 = L.h1 * bases1[R.length] + R.h1;
        T.h2 = L.h2 * bases2[R.length] + R.h2;

        T.length = L.length + R.length;

        T.invH1 = L.invH1 + R.invH1 * bases1[L.length];
        T.invH2 = L.invH2 + R.invH2 * bases2[L.length];
    }

    return T;
}

class HashTree
{
public:

    HashTree(const std::string &str) : tree(std::vector<Node>()), N(str.size()) {

        tree.resize(4 * N);
        build(1, 0, N - 1, str);
    }

    void update(const unsigned int position, const char c)
    {
        assert(position < N);
        update(1, 0, N - 1, position, c);
    }

    void updateInterval(const unsigned int x, const unsigned int y, const char c)
    {
        assert(x <= y && y < N);
        updateInterval(1, 0, N - 1, x, y, c);
    }

    Node query(const unsigned int x, const unsigned int y)
    {
        assert(x <= y && y < N);
        return query(1, 0, N - 1, x, y);
    }

    char getChar(const unsigned int x)
    {
        assert(x < N);
        return static_cast<char>(query(1, 0, N - 1, x, x).h1.toInteger());
    }

    size_t size() const
    {
        return this->N;
    }

    unsigned int getPeriod()
    {
        if (checkPeriod(1))
            return 1;

        int i = 2;

        while (i * i <= N)
        {
            if (N % i == 0)
            {
                if (checkPeriod(i))
                    return i;
            }

            i++;
        }

        while (i > 1)
        {
            if (N % i == 0)
            {
                if (checkPeriod(N / i))
                    return N / i;
            }

            i--;
        }

        return N;
    }

    bool checkPeriod(int lengthPeriod)
    {
        if (N % lengthPeriod != 0)
            return false;

        Node node = this->query(0, lengthPeriod - 1);

        int cnt = N / lengthPeriod;

        ModInteger<MOD1> H1 = bases1[node.length];
        ModInteger<MOD2> H2 = bases2[node.length];

        ModInteger<MOD1> h1 = node.h1 * ((H1 ^ cnt) - 1) / (H1 - 1);
        ModInteger<MOD2> h2 = node.h2 * ((H2 ^ cnt) - 1) / (H2 - 1);

        Node X = this->query(0, N - 1);

        return (X.h1 == h1) && (X.h2 == h2);
    }

private:

    std::vector<Node> tree;
    unsigned int N;

    void build(unsigned int node, unsigned int l, unsigned int r, const std::string &str)
    {
        if (l == r)
            tree[node] = Node(str[l]);
        else
        {
            unsigned int m = (l + r) / 2;

            build(2 * node, l, m, str);
            build(2 * node + 1, m + 1, r, str);

            tree[node] = join(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(unsigned int node, unsigned int l, unsigned int r, unsigned int position, char c)
    {
        if (l == r)
            tree[node] = Node(c);
        else
        {
            pushLazy(tree[node], tree[2 * node], tree[2 * node + 1]);

            unsigned int m = (l + r) / 2;

            if (position <= m)
                update(2 * node, l, m, position, c);
            else
                update(2 * node + 1, m + 1, r, position, c);

            tree[node] = join(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void updateInterval(unsigned int node, unsigned int l, unsigned int r, unsigned int i, unsigned int j, char c)
    {
        if (i <= l && r <= j)
            tree[node].lazy = c;
        else
        {
            pushLazy(tree[node], tree[2 * node], tree[2 * node + 1]);

            unsigned int m = (l + r) / 2;

            if (i <= m)
                updateInterval(2 * node, l, m, i, j, c);

            if (m < j)
                updateInterval(2 * node + 1, m + 1, r, i, j, c);

            tree[node] = join(tree[2 * node], tree[2 * node + 1]);
        }
    }

    Node query(unsigned int node, unsigned int l, unsigned int r, unsigned int i, unsigned int j)
    {
        if (i <= l && r <= j)
            return tree[node].realNode();
        else
        {
            pushLazy(tree[node], tree[2 * node], tree[2 * node + 1]);

            unsigned int m = (l + r) / 2;
            Node solution;

            if (i <= m && m < j)
                solution = join(query(2 * node, l, m, i, j), query(2 * node + 1, m + 1, r, i, j));
            else
            {
                if (i <= m)
                    solution = query(2 * node, l, m, i, j);
                else
                    solution = query(2 * node + 1, m + 1, r, i, j);
            }

            tree[node] = join(tree[2 * node], tree[2 * node + 1]);

            return solution;
        }
    }
};

const int MAX_L = 2000000;

int main()
{
    initBases(MAX_L);

    return 0;
}
