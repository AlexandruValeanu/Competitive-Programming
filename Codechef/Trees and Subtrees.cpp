#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/// O(Q*(N + M))

const int Nmax = 1e5 + 2;

struct Tree
{
    char age;
    int M, E;
};

Tree Restaurant[Nmax];
char Text[4 * Nmax];
char Pattern[4 * Nmax];
int pi[4 * Nmax];

int T, P;

void createText( int root, char S[], int &P )
{
    if ( root )
    {
        S[ ++P ] = Restaurant[root].age;
        createText( Restaurant[root].M, S, P );
        createText( Restaurant[root].E, S, P );
    }

    S[ ++P ] = '*';
}

void readTree()
{
    int N;

    cin >> N;

    for ( int i = 1, age; i <= N; ++i )
    {
        cin >> age;
        Restaurant[i].age = age;
        Restaurant[i].E = Restaurant[i].M = 0;
    }

    for ( int i = 1; i < N; ++i )
    {
        int A, B;
        char C;

        cin >> A >> B >> C;

        if ( C == 'M' )
        {
            Restaurant[A].M = B;
        }
        else
        {
            Restaurant[A].E = B;
        }
    }
}

void build_prefix()
{
    pi[1] = 0;

    int lgprefix = 0;

    for ( int i = 2; i <= P; ++i )
    {
        while ( lgprefix && Pattern[i] != Pattern[lgprefix + 1] )
                lgprefix = pi[lgprefix];

        if ( Pattern[i] == Pattern[lgprefix + 1] )
            lgprefix++;

        pi[i] = lgprefix;
    }
}

int KMP()
{
    int lgprefix = 0;

    for ( int i = 1; i <= T; ++i )
    {
        while ( lgprefix && Text[i] != Pattern[lgprefix + 1] )
                lgprefix = pi[lgprefix];

        if ( Text[i] == Pattern[lgprefix + 1] )
                lgprefix++;

        if ( lgprefix == P )
                return 1;
    }

    return 0;
}

int main()
{
    cin.sync_with_stdio( false );

	readTree();

	T = 0;
	createText( 1, Text, T );
	Text[T + 1] = '\0';

	int Q;

	cin >> Q;

	while ( Q-- )
	{
	    readTree();

		P = 0;
		createText( 1, Pattern, P );
		Pattern[P + 1] = '\0';

		if ( P > T )
        {
            cout << "NO\n";
            continue;
        }

        build_prefix();

		if ( KMP() == 0 )
            cout << "NO\n";
		else
            cout << "YES\n";
	}

	return 0;
}
