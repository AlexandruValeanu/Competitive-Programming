#include <bits/stdc++.h>

using namespace std;

/**
    Find two segments that intersect
    -sweep line technique
    -binary search tree (std::set)

    TIME:   O(N*logN)
    Memory: O(N)
**/

#define Point pair<int,int>
#define x first
#define y second

const double EPS = 1e-10;

int sign(int a)
{
    if (a > 0)
        return 1;
    else if (a < 0)
        return -1;
    else
        return 0;
}

/**
    -1 counter-clockwise
     0 collinear
    +1 clockwise
**/
int CCW(Point A, Point B, Point C)
{
    return sign( (C.x - A.x) * (B.y - A.y) - (C.y - A.y) * (B.x - A.x) );
}

double dist(Point A, Point B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

struct Segment
{
    Point A, B;
    int id;

    explicit Segment() : A(), B(), id(0) {
    }

    Segment(Point _A, Point _B, int _id) : A(_A), B(_B), id(_id) {
    }

    bool operator < (const Segment& S) const
    {
        if (this->A.x < S.A.x) /// *this starts first
        {
            /// *this comes before S if (A, B, S.a) are counter-clockwise
            int ccw = CCW(this->A, this->B, S.A);
            return (ccw < 0 || (ccw == 0 && this->A.y < S.A.y));
        }
        else
        {
            /// *this comes before S if (A, B, S.a) are clockwise
            int ccw = CCW(S.A, S.B, this->A);
            return (ccw > 0 || (ccw == 0 && this->A.y < S.A.y));
        }
    }
};

bool onSegment(const Segment& S, const Point& P)
{
    return fabs(dist(S.A, S.B) - dist(S.A, P) - dist(S.B, P)) < EPS;
}

bool intersect(const Segment& S1, const Segment& S2)
{
    if (onSegment(S1, S2.A) || onSegment(S1, S2.B) || onSegment(S2, S1.A) || onSegment(S2, S1.B))
        return true;

    if (CCW(S1.A, S1.B, S2.A) == CCW(S1.A, S1.B, S2.B) || CCW(S2.A, S2.B, S1.A) == CCW(S2.A, S2.B, S1.B))
        return false;

    return true;
}

/// O(N^2) solution
pair<int,int> bruteForce(vector<Segment>& S)
{
    int sol = 0;

    for (int i = 0; i < S.size(); ++i)
        for (int j = i + 1; j < S.size(); ++j)
            if (intersect(S[i], S[j]))
                return {S[i].id, S[j].id};

    return make_pair(-1, -1);
}

struct Event
{
    Point P;
    int id;
    bool type; /// 0/1 for insert/erase

    bool operator < (const Event& E) const
    {
        if (P.x != E.P.x)
            return P.x < E.P.x;
        else
        {
            /// first inserts (on the same sweep line)
            if (type != E.type)
                return type > E.type;
            else
                return P.y < E.P.y;
        }
    }
};

pair<int,int> findIntersection(vector<Segment>& segments)
{
    int N = segments.size();
    int nrEvents = 0;

    set<Segment> BST; /// binary search tree which stores segments (ordered using ccw)
    vector<Event> events(2 * N);

    for (int i = 0; i < N; ++i)
    {
        if (segments[i].A > segments[i].B)
            swap(segments[i].A, segments[i].B);

        events[nrEvents++] = {segments[i].A, i, 1};
        events[nrEvents++] = {segments[i].B, i, 0};
    }

    sort(events.begin(), events.end());

    for (int i = 0; i < nrEvents; ++i)
    {
        if (events[i].type == 1)
        {
            auto it = BST.lower_bound(segments[ events[i].id ]);

            /// try to intersect *it with its neighbours
            if (it != BST.end())
            {
                if (intersect(*it, segments[ events[i].id ]))
                    return {it->id, segments[ events[i].id ].id};
            }

            if (it != BST.begin())
            {
                it--;

                if (intersect(*it, segments[ events[i].id ]))
                    return {it->id, segments[ events[i].id ].id};
            }

            BST.insert(segments[ events[i].id ]);
        }
        else
        {
            auto it = BST.lower_bound(segments[ events[i].id ]);
            auto prec = it, urm = it;

            /// check if there are segment before and after *it (and test them)
            if (it != BST.begin() && it != --BST.end())
            {
                prec--;
                urm++;

                if (intersect(*urm, *prec))
                    return {urm->id, prec->id};
            }

            BST.erase(segments[ events[i].id ]);
        }
    }

    /// no intersection
    return {-1, -1};
}

int main() {

    ///ifstream cin("data.in");

    int N;
    cin >> N;
    vector<Segment> V;

    for (int i = 1; i <= N; ++i)
    {
        Point a, b;
        cin >> a.x >> a.y;
        cin >> b.x >> b.y;
        V.push_back({a, b, i});
    }

    pair<int,int> sol = findIntersection(V);

    if (sol.first != -1)
    {
        cout << "YES\n";
        cout << sol.first << " " << sol.second << "\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
