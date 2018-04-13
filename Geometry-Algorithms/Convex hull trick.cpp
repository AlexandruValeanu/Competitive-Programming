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

    ///find function's value in x
    long long evaluate(const int x)
    {
        return 1LL * this->m * x + 1LL * this->n;
    }

    ///order by slope
    bool operator < (const Line& L) const
    {
        return this->m > L.m;
    }
};

Line L[N_LINES];
Line Stack[N_LINES];
int N, M;
int pointer, top;

bool isBad(const Line l1, const Line l2, const Line l3) /// l2 is irrelevant?
{
    /**
        (l1∩l3) < (l1∩l2)
        l2 becomes irrelevant if and only if the intersection point of l1 and l3
        is to the left of the intersection of l1 and l2.
    **/

    return 1LL * (l3.n - l1.n) * (l1.m - l2.m) <= 1LL * (l1.m - l3.m) * (l2.n - l1.n);
}

/// line.slope is descending
void addLine(const Line &A)
{
    while (top >= 2 && isBad(Stack[top - 2], Stack[top - 1], A))
        top--;

    Stack[top++] = A;
}

/// x values are increasing
int query(int x)
{
    if (pointer >= top)
        pointer = top - 1;

    ///Any better line must be to the right, since query values are
	///non-decreasing
    while (pointer + 1 < top && Stack[pointer + 1].evaluate(x) < Stack[pointer].evaluate(x))
        pointer++;

    return Stack[pointer].ind; ///returns index
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        cin >> L[i].m >> L[i].n;
        L[i].ind = i;
    }

    /// sort after slope
    sort(L, L + N);

    ///add lines
    top = 0;
    for (int i = 0; i < N; ++i)
        addLine(L[i]);

    ///initially, the best line could be any of the lines in the "stack"
    pointer = 0;
    for (int i = 0; i < M; ++i)
    {
        int x;
        cin >> x;
        cout << query(x) << "\n"; /// returns original index in range [1...N]
    }

    return 0;
}
