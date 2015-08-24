#include <bits/stdc++.h>

using namespace std;

class Printer
{
private:

    FILE *outputFile;
    int cursor;

    static const int MAX_SIZE = 1 << 16;
    static const int MAX_DIGIT = 20;
    char buffer[MAX_SIZE];
    char digits[MAX_DIGIT];

    inline void putChar(const char c)
    {
        buffer[cursor++] = c;

        if (cursor == MAX_SIZE)
        {
            cursor = 0;
            fwrite(buffer, 1, MAX_SIZE, outputFile);
        }
    }

    inline void writeNr(int x)
    {
        if (x < 0)
        {
            putChar('-');
            x = -x;
        }

        int p = 0, q;

        do
        {
            q = x / 10;
            digits[p++] = x - q * 10 + '0';
            x = q;

        } while (x);

        while (p--)
        {
            putChar(digits[p]);
        }
    }

public:

    Printer() {
    }

    Printer(const char *file)
    {
        outputFile = fopen(file, "w");
        cursor = 0;
    }

    inline Printer& operator << (const int &x)
    {
        writeNr(x);
        return *this;
    }

    inline Printer& operator << (const char &c)
    {
        putChar(c);
        return *this;
    }

    void fflush()
    {
        fwrite(buffer, 1, cursor, outputFile);
    }
};

int main()
{
    return 0;
}
