#include <bits/stdc++.h>
#include <boost/rational.hpp>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost;

namespace GaussianElimination
{
    ///------------------------------------------------------------
    constexpr int MAX_EQ = 500;
    constexpr int MAX_VAR = 500;

    using T = boost::multiprecision::cpp_int;

    rational<T> A[MAX_EQ + 1][MAX_VAR + 1];
    rational<T> B[MAX_EQ + 1][MAX_VAR + 1];

    rational<T> solutions[MAX_VAR + 1];

    int N, M;
    ///------------------------------------------------------------

    ///------------------------------------------------------------
    void clear()
    {
        for (int i = 0; i <= MAX_EQ; ++i)
            for (int j = 0; j <= MAX_VAR; ++j)
                A[i][j] = B[i][j] = 0;

        for (int j = 0; j <= MAX_VAR; ++j)
            solutions[j] = 0;
    }

    void makeIdentity()
    {
        for (int i = 1; i <= N; ++i)
            B[i][i] = 1;
    }

    bool checkIfInvertible()
    {
        assert(N == M);

        for (int i = 1; i <= N; ++i)
            if (A[i][i] != 1)
                return false;

        return true;
    }
    ///------------------------------------------------------------

    ///------------------------------------------------------------
    void swapLines(int x, int y) /// swap(X, Y)
    {
        swap(A[x], A[y]);
        swap(B[x], B[y]);

        cerr << "SWAP LINES : " << x << " " << y << endl;
    }

    void divideLine(int line, rational<T> rat) /// X = X / rat
    {
        assert(rat != 0);

        for (int j = 1; j <= M; ++j)
            A[line][j] /= rat;

        for (int j = 1; j <= M; ++j)
            B[line][j] /= rat;

        cerr << "DIVIDE LINE_" << line << " BY " << rat << endl;
    }

    void changeLines(int x, int y, rational<T> rat) /// X = X - rat * Y
    {
        for (int i = 1; i <= M; ++i)
            A[x][i] -= rat * A[y][i];

        for (int i = 1; i <= M; ++i)
            B[x][i] -= rat * B[y][i];

        cerr << "ADD TO LINE_" << x << " => LINE_" << y << " x " << -rat << endl;
    }
    ///------------------------------------------------------------

    void rowEchelonForm()
    {
        cerr << "START ROW ECHELON" << endl;

        int i = 1, j = 1;

        while (i <= N && j <= M)
        {
            int k = i;

            while (k <= N && A[k][j] == 0)
                k++;

            if (k == N + 1)
            {
                j++;
                continue;
            }

            if (k != i)
                swapLines(k, i);

            assert(A[i][j] != 0);
            divideLine(i, A[i][j]);

            for (int l = i + 1; l <= N; ++l)
                changeLines(l, i, A[l][j]);

            i++;
            j++;
        }

        cerr << "FINISH ROW ECHELON" << endl << endl;
    }

    void reducedRowEchelonForm()
    {
        cerr << "START REDUCED ROW ECHELON" << endl;

        for (int i = N; i >= 1; i--)
        {
            int j = 1;

            while (j <= M && A[i][j] == 0)
                j++;

            if (j <= M)
            {
                for (int k = i - 1; k >= 1; k--)
                    changeLines(k, i, A[k][j]);
            }
        }

        cerr << "FINISH REDUCED ROW ECHELON" << endl << endl;
    }

    vector<vector<double>> getInverse(const vector<vector<int>> &coef, ostream &out = cout)
    {
        assert(coef.size() >= 1);
        assert(coef[0].size() >= 1);

        GaussianElimination::N = coef.size();
        GaussianElimination::M = coef[0].size();

        if (N != M)
        {
            out << "Matrix not invertible : N != M (non-square)\n";
            return {};
        }

        clear();

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                A[i + 1][j + 1] = coef[i][j];

        makeIdentity();
        rowEchelonForm();

        if (checkIfInvertible() == false)
        {
            out << "Matrix not invertible\n";
            return {};
        }

        reducedRowEchelonForm();

        vector<vector<double>> inverse(N + 2);

        for (int i = 1; i <= N; ++i)
        {
            inverse[i - 1].resize(M + 1);

            for (int j = 1; j <= M; ++j)
            {
                inverse[i - 1][j - 1] = boost::rational_cast<double>(B[i][j]);
                out << B[i][j] << " ";
            }

            out << endl;
        }

        return inverse;
    }

    vector<double> solveSystemEquations(const vector<vector<int>> &coef, const vector<int> &bs, ostream &out = cout)
    {
        assert(coef.size() >= 1);
        assert(coef[0].size() >= 1);

        GaussianElimination::N = coef.size();
        GaussianElimination::M = coef[0].size();

        assert(static_cast<int>(bs.size()) == GaussianElimination::N);

        clear();

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                A[i + 1][j + 1] = coef[i][j];

        for (int i = 0; i < N; ++i)
            B[i + 1][1] = bs[i];

        rowEchelonForm();
        reducedRowEchelonForm();

        for (int i = N; i >= 1; i--)
        {
            int j = 1;

            while (j <= M && A[i][j] == 0)
                j++;

            if (j == M + 1)
            {
                if (B[i][1] != 0)
                {
                    out << "Impossible!" << endl;
                    return {};
                }
            }
            else
            {
                solutions[i] = B[i][1];

                for (int p = j + 1; p <= M; ++p)
                    solutions[i] -= A[i][p] * solutions[p];
            }
        }

        vector<double> solution(M);

        for (int j = 0; j < M; ++j)
            solution[j] = boost::rational_cast<double>(solutions[j + 1]);

        for (int j = 1; j <= M; ++j)
            out << solutions[j] << " ";

        out << endl;

        return solution;
    }
}

int main()
{
    ifstream in("data.in");

    assert(in.is_open());

    vector<vector<int>> A;
    int n, m;

    in >> n >> m;
    A.resize(n);
    vector<int> bs(n);

    for (int i = 0; i < n; ++i)
    {
        A[i].resize(m);

        for (int j = 0; j < m; ++j)
            in >> A[i][j];

        in >> bs[i];
    }

    vector<double> xs = GaussianElimination::solveSystemEquations(A, bs);

    return 0;
}
