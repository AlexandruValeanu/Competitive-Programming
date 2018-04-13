#include <bits/stdc++.h>

using namespace std;

///---------------------------------------------------
const int BUFFER_SIZE = (1 << 16);
char buffer[BUFFER_SIZE];
int position = BUFFER_SIZE;

inline char getChar()
{
    if ( position == BUFFER_SIZE )
    {
        position = 0;
        fread(buffer, BUFFER_SIZE, 1, stdin);
    }

    return buffer[position++];
}

inline int getInt()
{
    register int a = 0;
    char ch;
    int sgn = 1;

    do
    {
        ch = getChar();

    } while ( !isdigit(ch) && ch != '-' );

    if ( ch == '-' )
    {
        sgn = -1;
        ch = getChar();
    }

    do
    {
        a = (a << 3) + (a << 1) + ch - '0';
        ch = getChar();

    } while ( isdigit(ch) );

    return a * sgn;
}
///---------------------------------------------------

int main()
{
    return 0;
}
