#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 1;
const int SIGMA = 26;

char A[2 * Nmax];
char B[Nmax];
int vis[SIGMA];

char maxim;
int N, M;

void marcheaza( char c, int &cate )
{
    for ( int i = 0; i < N && cate; ++i )
        if ( A[i] == c )
        {
            cate--;
            A[i] = '#';
        }
}

void changeString()
{
    int n = 0;

    for ( int i = 0; i < N; ++i )
        if ( A[i] != '#' )
            B[ n++ ] = A[i];

    for ( int i = 0; i < n; ++i )
        A[i] = B[i];

    N = n;
}

void moveString( int p, int how, char c )
{
    for ( int j = N - 1; j >= p; j-- )
            A[j + how] = A[j];

    for ( int k = 0; k < how; ++k )
        A[p + k] = c;

    N += how;
}

void solve( char c, int cate )
{
    maxim = 0;

    for ( int i = 0; i < N; ++i )
        maxim = max( maxim, A[i] );

    if ( c > maxim )
    {
        cate %= 2;

        if ( cate )
            A[ N++ ] = c;

        return;
    }

    if ( c == maxim )
    {
        marcheaza( c, cate );
        changeString();

        cate %= 2;

        if ( cate )
            A[ N++ ] = c;

        return;
    }

    if ( c < A[0] )
    {
        moveString( 0, cate, c );
        cate = 0;
        return;
    }

    int i = 0;

    while ( i < N && cate )
    {
        int j = i;

        if ( A[i] < c )
        {
            i++;
            continue;
        }

        if ( A[i] > c )
        {
            moveString( i, cate, c );
            cate = 0;
            i++;
            continue;
        }

        while ( j < N && A[j] == c ) j++;
        j--;

        if ( A[j + 1] < c || j + 1 == N )
        {
            for ( int k = i; k <= j && cate; ++k )
            {
                A[k] = '#';
                cate--;
            }
        }

        i = j + 1;
    }

    changeString();
}

string sursaAux()
{
    ifstream in("tensor.in");

    string s, t;
    int cnt[255], ma[200005];

    memset( cnt, 0, sizeof( cnt ) );
    memset( ma, 0, sizeof( ma ) );

    in >> s >> t;

        stack<char> st;
        while (!st.empty()) {
            st.pop();
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < t.length(); i++) {
            cnt[t[i]]++;
        }
        for (int c = 'z'; c >= 'a'; c--) {
            int ma = -1;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] > c) {
                    ma = i;
                    break;
                }
            }
            int i = 0;
            if (ma == -1)
                ma = s.length();
            while (i < min((int)s.length(), ma)) {
                while (!st.empty() && st.top() == c && st.top() > s[i] && cnt[st.top()] > 0) {
                        cnt[st.top()]--;
                        st.pop();
                }
                st.push(s[i]);
                i++;
            }
            for (; i < s.length(); i++)
                st.push(s[i]);
            s = "";
            while (!st.empty()) {
                s += st.top();
                st.pop();
            }
            reverse(s.begin(), s.end());
        }
        bool flag = true;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] < s[i - 1]) {
                flag = false;
                break;
            }
        }
        //cout<<s<<" "<<flag<<endl;
        ma[0] = s[0];
        for (int i = 1; i < s.length(); i++) {
           ma[i] = max(ma[i - 1], (int)s[i]);
        }
        //cout<<s<<endl;
        //cout<<flag<<" "<<ma2<<endl;
        //cout<<s<<endl;
        int i = s.length() - 1;
        while (i >= 0 && cnt[s[i]] > 0) {
            int ma1 = -1, ma2 = -1;
            for (int j = 'a'; j <= 'z'; j++)
                if (cnt[j] > 0 && cnt[j] % 2 == 1)
                        ma2 = j;
            if((ma[i] <= s[i] && ma2 <= s[i]) && i >= 0 && cnt[s[i]] > 0) {
                cnt[s[i]]--;
                i--;
            }
            else
                break;
        }
        string x = "";
        for (int j = 0; j <= i; j++)
            x += s[j];
        s = x;
        //cout<<s<<endl;
        for (int c = 'a'; c <= 'z'; c++) {
            string x = "";
            int j = -1;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] > c) {
                    j = i;
                    break;
                }
            }
            if (j == -1) {
                bool hasLarger = false;
                for (int y = c + 1; y <= 'z'; y++) {
                    if (cnt[y] & 1)
                        hasLarger = true;
                }
                if (hasLarger) {
                    for (int y = 0; y < cnt[c]; y++)
                        s += (char)c;
                }
                else {
                    if (cnt[c] & 1)
                        s += (char)c;
                }
            }
            else {
                for (int i = 0; i < j; i++) {
                    x += s[i];
                }
                for (int i = 0; i < cnt[c]; i++) {
                    x += (char)c;
                }
                for (int i = j; i < s.length(); i++) {
                    x += s[i];
                }
                s = x;
            }
        }

    in.close();

    return s;
}

void gen()
{
    ofstream out("tensor.in");

    srand( time( NULL ) );

    const int N = 1 + rand() % 100000;

    for ( int i = 0; i < 2 * N; ++i )
    {
        if ( i == N - 1 )
            out << "\n";

        out << char( 'a' + rand() % SIGMA );
    }

    out.close();
}

int main()
{
    ///const int T = 1000;

    ///for ( int k = 0; k < T; ++k )
    {
        ///gen();

        ///string s = sursaAux();

        ifstream in("tensor.in");
        ofstream out("tensor.out");

        in >> A >> B;

        N = strlen( A );
        M = strlen( B );

        for ( int i = 0; i < M; ++i )
            vis[ B[i] - 'a' ]++;

        for ( char i = 'z'; i >= 'a'; i-- )
        {
            if ( vis[i - 'a'] )
                solve( i, vis[i - 'a'] );
        }

        ///cout << N << endl;

        ///assert( N == s.size() );

        for ( int i = 0; i < N; ++i )
            cout << A[i];

        memset( vis, 0, sizeof( vis ) );
        maxim = 0;
        N = 0;
        memset( A, 0, sizeof( A ) );
        memset( B, 0, sizeof( B ) );

///        in.close();
   ///     out.close();
    }

    return 0;
}
