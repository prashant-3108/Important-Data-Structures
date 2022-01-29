#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int kadaneS_algorithm(vector<int> A)
{
    int N = A.size();
    int current_sum = A[0], overall_best_sum = A[0];

    for (int i = 1; i < N; i++)
    {
        if (current_sum >= 0)
        {
            current_sum += A[i];
        }
        else
        {
            current_sum = A[i];
        }

        overall_best_sum = max(overall_best_sum, current_sum);
    }

    return overall_best_sum;
}

int main()
{

    return 0;
}