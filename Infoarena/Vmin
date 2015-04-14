#include <bits/stdc++.h>

using namespace std;

const int N_LINES = 100000 + 1;
const int N_POINTS = 1000000 + 1;

/// y = m*x + n
struct Line
{
    int m, n; /// slope-intercept form
    int ind;

    explicit Line() : m(0), n(0), ind(0) {
    }

    Line(const int a, const int b, const int c) : m(a), n(b), ind(c) {
    }

    long long eval(const int x)
    {
        return 1LL * this->m * x + 1LL * this->n;
    }

    bool operator < (const Line& L) const
    {
        return this->m > L.m;
    }
};

Line L[N_LINES];
Line Stack[N_LINES];
int N, M;
int pointer, top;

bool bad(const Line l1, const Line l2, const Line l3) /// l2 is irrelevant?
{
    /**
        (l1∩l3) < (l1∩l2)
        l2 becomes irrelevant if and only if the intersection point of l1 and l3
        is to the left of the intersection of l1 and l2.
    **/

    return 1LL * (l3.n - l1.n) * (l1.m - l2.m) <= 1LL * (l1.m - l3.m) * (l2.n - l1.n);
}

void addLine(const Line &A)
{
    while (top >= 2 && bad(Stack[top - 2], Stack[top - 1], A))
        top--;

    Stack[top++] = A;
}

int query(int x)
{
    if (pointer >= top)
        pointer = top - 1;

    while (pointer + 1 < top && Stack[pointer + 1].eval(x) <= Stack[pointer].eval(x))
        pointer++;

    return Stack[pointer].ind;
}

int main()
{
    ifstream in("vmin.in");
    ofstream out("vmin.out");

    ios_base::sync_with_stdio(false);

    in >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        in >> L[i].m >> L[i].n;
        L[i].ind = i;
    }

    sort(L, L + N);

    top = 0;
    for (int i = 0; i < N; ++i)
        addLine(L[i]);

    pointer = 0;
    for (int i = 0; i < M; ++i)
    {
        int x;
        in >> x;
        out << query(x) + 1 << " ";
    }

    return 0;
}
