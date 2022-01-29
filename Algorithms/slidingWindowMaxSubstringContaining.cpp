#include <bits/stdc++.h>
using namespace std;

/*
    int : 4B
    long int : "4B in 32" and "8B in 64"
    long long int : 8B
*/

/*       --------------------TEMPLATE----------------------        */

#define pie acos(-1)
#define int long long int
#define u unsigned
#define ld long double
#define debug(a) cerr << #a << " = " << a << endl
#define pres(n) cout << fixed << setprecision(n)
#define MOD 1000000007
#define test_cases \
    int T;         \
    cin >> T;      \
    while (T--)
#define loop(i, n) for (int i = 0; i < n; i++)
#define rloop(i, n) for (int i = n - 1; i >= 0; i--)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define i1(x) \
    int x;    \
    cin >> x;
#define i2(x, y) \
    int x, y;    \
    cin >> x >> y;
#define i3(x, y, z) \
    int x, y, z;    \
    cin >> x >> y >> z;
#define take(x, n)              \
    for (int i = 0; i < n; i++) \
        cin >> x[i];
#define take_max(x, n, M)       \
    for (int i = 0; i < n; i++) \
        cin >> x[i], M = max(M, x[i]);
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl
#define print_with_size(a)    \
    cout << a.size() << endl; \
    for (auto x : a)          \
        cout << x << " ";     \
    cout << endl

template <class T>
void swap(T &xp, T &yp)
{
    T temp = xp;
    xp = yp;
    yp = temp;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int nCr(int n, int k) // binomial cofficient//
{
    int res = 1;
    if (k > (n - k))
        k = n - k;

    loop(i, k)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int pwr(int a, int b) //"logb"//without MOD//
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = result * a;
        a = a * a;
        b >>= 1;
    }
    return result;
}

int power(int x, int y, int p)
{
    int res = 1; // Initialize result
    x = x % p;   // Update x if it is more than or
    // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int extended_gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = (x1 - y1 * (a / b));
    return d;
}

void sieve(bool *primes, int n, vector<int> *s)
{
    for (int i = 0; i <= n; i++)
    {
        primes[i] = true;
    }
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i] == true)
        {
            for (int p = i * i; p <= n; p += i)
            {
                primes[p] = false;
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (primes[i])
        {
            s->push_back(i);
        }
    }
}

bool is_Prime(int n)
{
    if (n == 2 && n == 3)
    {
        return true;
    }
    if ((n == 1) || (n % 2 == 0) || (n % 3 == 0))
    {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        if ((n % i == 0) || (n % (i + 2) == 0))
            return false;
    }
    return true;
}

vector<bool> segmentedSieve(long long L, long long R)
{
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim + 1, false);
    vector<long long> primes;
    for (long long i = 2; i <= lim; ++i)
    {
        if (!mark[i])
        {
            primes.emplace_back(i);
            for (long long j = i * i; j <= lim; j += i)
                mark[j] = true;
        }
    }

    vector<bool> isPrime(R - L + 1, true);
    for (long long i : primes)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}

int bintonum(string s)
{
    int i = 0, res = 0;
    for (int j = s.size() - 1; j >= 0; j--)
    {
        res += (pwr(2, i) * (int)(s[j]));
        i++;
    }
    return res;
}

int mod_add(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
int mod_mul(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
int mod_sub(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}

// Returns n^(-1) mod p
int modInverse(int n, int p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
int nCrModPFermat(int n, int r, int p)
{
    // Base case
    if (r == 0)
        return 1;

    int fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

/*       --------------------CODE STARTS HERE----------------------        */

/*
    'a'=97 && 'z'=122
    'A'=65 && 'Z'=90
*/

/*STL shorts*/

#define initialise(n, k) memset(n, k, sizeof(n))
#define nextl cout << endl
#define setbits(n) __builtin_popcount(n)
#define sz(x) (int)x.size()
#define INF 1e18
#define _INF -1e18
#define _y cout << "YES\n";
#define _n cout << "NO\n";
#define nline "\n"
#define all(v) v.begin(), v.end()
#define rall(v) (v.rbegin(), v.rend())

#define mp(x, y) make_pair(x, y)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvi_size(name, row, col) vector<vector<int>> name(row, vector<int>(col, 0));
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define vstr vector<string>
#define umpii unordered_map<int, int>
#define umpci unordered_map<char, int>
#define pb push_back

void solve()
{
    string s;
    cin >> s;

    // sliding window
    int n = s.length(), ans = (int)(1e9 + 7);
    int hasDiff = 0;

    map<char, int> m;
    m['1'] = 0;
    m['2'] = 0;
    m['3'] = 0;

    int r = 0, l = 0;

    while (r < n)
    {

        if (m[s[r]] == 0)
        {
            hasDiff += 1;
            if (hasDiff == 3)
            {
                ans = min(ans, r - l + 1);
            }
        }

        m[s[r]] += 1;

        while (hasDiff == 3)
        {
            m[s[l]] -= 1;
            if (!m[s[l]])
            {
                hasDiff -= 1;
            }

            ans = min(ans, r - l + 1);
            l++;
        }

        r += 1;
    }

    if (ans == (int)(1e9 + 7))
    {
        ans = 0;
    }

    cout << ans << endl;

    return;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        // cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}
