#include <bits/stdc++.h>

template<const size_t bufferSize>
class Scanner
{
public:

    Scanner(std::istream& s = std::cin, std::string sep = " ") : stream(s),
        buffer(new char[bufferSize]), pointer(bufferSize), lengthInput(0), separators(sep) {

        this->separators.push_back('\0');
        this->separators.push_back('\n');

        this->stream.seekg(0, this->stream.end);
        this->lengthInput = this->stream.tellg();
        this->stream.seekg(0, this->stream.beg);
    }

    Scanner(const Scanner &scan) : stream(scan.stream), pointer(scan.pointer),
        lengthInput(scan.lengthInput), separators(scan.separators) {

        for (size_t i = 0; i < bufferSize; ++i)
            this->buffer[i] = scan.buffer[i];
    }

    Scanner& operator = (const Scanner &scan)
    {
        this->stream = scan.stream;
        this->pointer = scan.pointer;
        this->lengthInput = scan.lengthInput;
        this->separators = scan.separators;

        for (size_t i = 0; i < bufferSize; ++i)
            this->buffer[i] = scan.buffer[i];

        return *this;
    }

    ~Scanner()
    {
        delete[] this->buffer;
        this->pointer = bufferSize;
        this->lengthInput = 0;
    }

    char nextChar()
    {
        if (this->eof())
            return '\0';

        if (this->pointer == bufferSize)
        {
            this->pointer = 0;
            stream.read(buffer, bufferSize);
        }

        this->lengthInput--;

        return this->buffer[this->pointer++];
    }

    size_t nextUnsigned(void)
    {
        return this->nextInteger<size_t>();
    }

    int nextInt(void)
    {
        return this->nextInteger<int>();
    }

    long long nextLongLong(void)
    {
        return this->nextInteger<long long>();
    }

    double nextDouble(void)
    {
        double key = 0;
        double fract = 0;
        int sign = 1;
        char ch;

        do
        {
            ch = this->nextChar();

        } while (separators.find(ch) != std::string::npos && ch != '+' && ch != '-' && !this->eof());

        if (!ch)
            return 0.0f;

        if (!isdigit(ch))
        {
            sign = (ch == '-') ? -1 : 1;
            ch = this->nextChar();
        }

        do
        {
            key = key * 10.0f + ch - '0';
            ch = this->nextChar();

        } while (isdigit(ch));

        if (ch == '.')
        {
            ch = this->nextChar();
            size_t lg = 0;

            do
            {
                lg++;
                fract = fract * 10.0f + ch - '0';
                ch = this->nextChar();

            } while (isdigit(ch));

            while (lg--)
                fract /= 10.0f;
        }

        return sign * (key + fract);
    }

    std::string nextString(void)
    {
        std::string str;
        char ch;

        do
        {
            ch = this->nextChar();

        } while (separators.find(ch) != std::string::npos && !this->eof());

        if (!ch)
            return str;
        do
        {
            str.push_back(ch);
            ch = this->nextChar();

        } while (separators.find(ch) == std::string::npos);

        return str;
    }

    bool eof(void) const
    {
        return this->lengthInput == 0;
    }

private:

    std::istream& stream;
    char *buffer;
    size_t pointer, lengthInput;
    std::string separators;

    template<class T>
    T nextInteger(void)
    {
        T key = 0;
        T sign = 1;
        char ch;

        do
        {
            ch = this->nextChar();

        } while (separators.find(ch) != std::string::npos && ch != '+' && ch != '-' && !this->eof());

        if (!isdigit(ch))
        {
            sign = (ch == '-') ? -1 : 1;
            ch = this->nextChar();
        }

        do
        {
            key = key * 10 + ch - '0';
            ch = this->nextChar();

        } while (isdigit(ch));

        return sign * key;
    }
};

int main()
{
    return 0;
}
