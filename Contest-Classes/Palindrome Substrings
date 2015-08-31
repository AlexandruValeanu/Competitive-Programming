#include <bits/stdc++.h>

using namespace std;

class Palindrome_Substrings
{
public:

    string S;
    vector<int> P;

    Palindrome_Substrings() {
    }

    Palindrome_Substrings(const string &str)
    {
        S.push_back('@');
        S.push_back('$');

        for (size_t i = 0; i < str.size(); ++i)
        {
            S.push_back(str[i]);
            S.push_back('$');
        }

        S.push_back('#');

        this->computeManacher();
    }

    void computeManacher()
    {
        const int N = S.size();
        P = vector<int>(N, 0);

        int indexOfLongestPalindrome = 0, rightEndOfLongestPalindrome = 0;

        for (int i = 1; i <= N - 1; ++i)
        {
            if (rightEndOfLongestPalindrome > i)
                P[i] = min(P[2 * indexOfLongestPalindrome - i], rightEndOfLongestPalindrome - i);
            else
                P[i] = 0;

            while (S[i - P[i] - 1] == S[i + P[i] + 1])
                P[i]++;

            if (P[i] + i > rightEndOfLongestPalindrome)
            {
                rightEndOfLongestPalindrome = P[i] + i;
                indexOfLongestPalindrome = i;
            }
        }
    }

    bool isPalindrome(int i, int j) const
    {
        int l = j - i + 1;

        if (l % 2 == 1) ///is odd
        {
            int pos = 2 * (i + l / 2);
            int lgPal = 2 * (P[pos] / 2) + 1;

            return (lgPal >= l);
        }
        else
        {
            int pos = 2 * (i + l / 2) - 1;
            int lgPal = 2 * (P[pos] / 2);

            return (lgPal >= l);
        }
    }
};

bool isPal(const string &str, int i, int j)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return 0;

        i++;
        j--;
    }

    return 1;
}

int main()
{
    return 0;
}
