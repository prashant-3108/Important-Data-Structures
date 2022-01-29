#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> zArray(string s)
{
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main()
{
    string pattern = "aab";
    int N = pattern.length();
    string text = "aabaabaabhxaa";
    vector<int> Z = zArray(pattern + "#" + text);

    int count = 0;
    for (auto i : Z)
    {
        if (i == N)
        {
            count += 1;
        }
    }
    cout << count << endl;
    return 0;
}