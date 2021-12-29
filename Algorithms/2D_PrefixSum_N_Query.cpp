#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void setPrefixMatrix(vector<vector<int>> &mat, vector<vector<int>> &prefix)
{
    int N = mat.size();
    int M = mat[0].size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            prefix[i][j] += mat[i][j];
            if (i > 0)
                prefix[i][j] += prefix[i - 1][j];
            if (j > 0)
                prefix[i][j] += prefix[i][j - 1];

            if (i > 0 && j > 0)
                prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }
}

int Query(vector<vector<int>> prefix, int x1, int y1, int x2, int y2)
{
    int sum = 0;

    sum += prefix[x2][y2];

    if (x1 > 0)
        sum -= prefix[x1 - 1][y2];
    if (y1 > 0)
        sum -= prefix[x2][y1 - 1];

    if (x1 > 0 && y1 > 0)
        sum += prefix[x1 - 1][y1 - 1];

    return sum;
}

int main()
{
    int N = 5, M = 5;
    vector<vector<int>> mat(N, vector<int>(M, 0));

    vector<vector<int>> prefix(N, vector<int>(M, 0));

    setPrefixMatrix(mat, prefix);
    // int Sum = Query(prefix, x1, y1, x2, y2);

    return 0;
}