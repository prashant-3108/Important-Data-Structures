#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> getLps(string A)
{
    int N = A.length();
    vector<int> lps(N);

    int i = 1, len = 0;

    while (i < N)
    {
        if (A[i] == A[len])
        {
            len += 1;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return lps;
}

int main()
{
    string s = "aabaacaadaabaaba";
    vector<int> lpsArray = getLps(s);

    for (auto i : lpsArray)
    {
        cout << i << " ";
    }
    cout << endl;

    string pattern = "aab";
    string text = "aabaacaadaabaaba";

    string kmpStr = pattern + "#" + text;
    int P = pattern.length();

    lpsArray = getLps(kmpStr);

    int ans = 0;
    for (auto i : lpsArray)
    {
        if (i == P)
        {
            ans += 1;
        }
    }

    cout << "Pattern Matches with text (times): " << ans << endl;

    return 0;
}