#include <bits/stdc++.h>

///#include <sys/time.h>
///#include <time.h>

using namespace std;

///---------------------------------

const int BS = ( 1 << 16 );
char buffer[BS];
int position = BS;

inline char getChar()
{
    if ( position == BS )
    {
        position = 0;
        fread( buffer, BS, 1, stdin );
    }

    return buffer[ position++ ];
}

inline int getNr()
{
    int a = 0;
    char ch;

    do
    {
        ch = getChar();

    } while ( !isdigit( ch ) );

    do
    {
        a = a * 10 + ch - '0';
        ch = getChar();

    } while ( isdigit( ch ) );

    return a;
}

///--------------------------------------

const int INF = ( 1U << 31 ) - 1;
const int MAX_LEVEL = 21;
const int SIZE_SKIPLIST = 350000;

int SL[SIZE_SKIPLIST], width[SIZE_SKIPLIST];
int levelNode[MAX_LEVEL], jumped[MAX_LEVEL];
int pointer, maxLevel;

double getMemory()
{
    return 2.0 * (double)sizeof( SL ) / 1024.0 / 1024.0;
}

void initSkiplist()
{
    srand( time( 0 ) );

    SL[0] = -INF;

    for ( int i = 0; i < MAX_LEVEL; ++i )
        SL[i + 1] = MAX_LEVEL + 1;

    SL[MAX_LEVEL + 1] = INF;

    pointer = MAX_LEVEL + 2;
    maxLevel = 1;
}

inline int generateLevel()
{
    int level = 1;

    for ( int R = rand() % ( 1 << (MAX_LEVEL - 1) ); ( R & 1 ) == 1; R >>= 1 )
        level++;

    if ( level > MAX_LEVEL )
        level = MAX_LEVEL;

    return level;
}

inline void search(int& current, const int value)
{
    for ( int i = 0; i < MAX_LEVEL; ++i )
    {
        jumped[i] = 0;
        levelNode[i] = 0;
    }

    for ( int l = maxLevel - 1; l >= 0; l-- )
    {
        while ( SL[ SL[current + l + 1] ] < value )
        {
            jumped[l] += width[current + l + 1];
            current = SL[current + l + 1];
        }

        levelNode[l] = current;
    }
}

void insert(const int value)
{
    int current = 0;
    search(current, value);

    current = SL[current + 1];

    if ( /**value != SL[current]**/ 1 == 1 )
    {
        int newLevel = generateLevel();

        if ( newLevel > maxLevel )
            maxLevel = newLevel;

        SL[pointer] = value;
        int J = 0;

        for ( int l = 0; l < newLevel; ++l )
        {
            SL[pointer + l + 1] = SL[levelNode[l] + l + 1];
            SL[levelNode[l] + l + 1] = pointer;

            width[pointer + l + 1] = width[levelNode[l] + l + 1] - J;
            width[levelNode[l] + l + 1] = J + 1;

            J += jumped[l];
        }

        for ( int l = newLevel; l < MAX_LEVEL; ++l )
            width[levelNode[l] + l + 1]++;

        pointer += newLevel + 1;

        ///assert( pointer < SIZE_SKIPLIST );
    }
}

bool find(const int value)
{
    int current = 0;
    search(current, value);

    current = SL[current + 1];

    return ( value == SL[current] );
}

void erase(const int value)
{
    int current = 0;
    search(current, value);

    current = SL[current + 1];

    if ( SL[current] == value )
    {
        for ( int l = 0; l < MAX_LEVEL; ++l )
        {
            if ( SL[levelNode[l] + l + 1] == current )
            {
                SL[levelNode[l] + l + 1] = SL[current + l + 1];
                width[levelNode[l] + l + 1] += width[current + l + 1] - 1;
            }
            else
            {
                width[levelNode[l] + l + 1]--;
            }
        }
    }
}

int kth_element(int k)
{
    int current = 0;

    for ( int l = maxLevel - 1; l >= 0; l-- )
    {
        while ( SL[ SL[current + l + 1] ] != INF && width[current + l + 1] < k )
        {
            k -= width[current + l + 1];
            current = SL[current + l + 1];
        }
    }

    current = SL[current + 1];

    return SL[current];
}

void printList()
{
    int current = 0;

    while ( SL[current] != INF )
    {
        cerr << SL[current] << " ";
        current = SL[current + 1];
    }
}

/// TESTARE PROGRAM
/**
long long t0;

void markTime() {
  timeval tv;

  gettimeofday (&tv, NULL);
  t0 = 1000LL * tv.tv_sec + tv.tv_usec / 1000;
}

void reportTime(const char* msg) {
  timeval tv;

  gettimeofday (&tv, NULL);
  long long t = 1000LL * tv.tv_sec + tv.tv_usec / 1000;
  printf("%s: %lld ms\n", msg, t - t0);
}

void gen_testMare();
void testare_program();
**/

int main()
{
    ///cerr << sizeof( buffer ) / 1024.0 / 1024.0 << endl;
    ///cerr << fixed << setprecision( 10 );
    ///cerr << "Memory: " << getMemory() << "\n";

    initSkiplist();

    freopen("magazin2.in", "r", stdin);
    freopen("magazin2.out", "w", stdout);

    int N;
    N = getNr();

    while ( N-- )
    {
        int tip, x;

        tip = getNr(); x = getNr();

        if ( tip == 1 )
            insert(x);
        else
            printf("%d\n", kth_element(x));
    }

    fclose( stdin );
    fclose( stdout );

    return 0;
}

/**
void gen_testMare()
{
    const int TRIAL_SIZE = 100000;

    markTime();
    for (int i = 0; i < TRIAL_SIZE; i++) {
        insert(rand() % INF);
    }
    reportTime("inserare");

    markTime();
  for (int i = 0; i < TRIAL_SIZE; i++) {
    kth_element(1 + rand() % TRIAL_SIZE);
  }
  reportTime("căutare");

  cerr << endl;

  cout << pointer << " " << SIZE_SKIPLIST << endl;

}

void testare_program()
{
    ifstream ok("teste//grader_test10.ok");
    ifstream out("magazin.out");;

    if ( !ok )
    {
        cerr << "OK file not found!\n";
        exit( 0 );
    }

    if ( !out )
    {
        cerr << "OUT file not found!\n";
        exit( 0 );
    }

    int a, b;

    while ( ok >> a )
    {
        out >> b;

        assert( a == b );
    }

    cout << "Accepted\n";

    ok.close();
    out.close();
}
**/
