#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class ExpressionSolver
{
private:

    const int Hmax = 2;
    char Operator[4][4] = { "+-", "*/", "^", "" };

    string Expr;
    unsigned position;

    int pow( int a, int b )
    {
        int r = 1;

        for ( int i = 0; ( 1 << i ) <= b; ++i )
        {
            if ( b & ( 1 << i ) )
                r *= a;

            a *= a;
        }

        return r;
    }

    int operation( int a, int b, char c )
    {
        switch( c )
        {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            case '^': return pow( a, b );
        }

        return 0;
    }

    int termen()
    {
        int t = 0;

        if ( Expr[position] == '(' )
        {
            position++;
            t = solve( 0 );
            position++;
        }
        else
        {
            while ( position < Expr.size() && isdigit( Expr[position] ) )
            {
                t = t * 10 + Expr[position] - '0';
                position++;
            }
        }

        return t;
    }

    int solve( int level )
    {
        int t = 0;

        if ( level == Hmax )
            t = termen();
        else
            t = solve( level + 1 );

        while ( position < Expr.size() && strchr( Operator[level], Expr[position] ) )
            t = operation( t, solve( level + 1 ), Expr[position++] );

        return t;
    }

public:

    ExpressionSolver( const string &str )
    {
        position = 0;
        Expr = str;
    }

    int solve()
    {
        return solve( 0 );
    }
};

int main()
{
    return 0;
}
