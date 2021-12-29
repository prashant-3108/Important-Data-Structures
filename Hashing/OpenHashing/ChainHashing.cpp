#include <bits/stdc++.h>
using namespace std;

#define ll long long

template <typename HashedObj>
class HashTable
{
public:
    /* dont do anything implicitly */
    explicit HashTable(int size = 10);

    bool contains(const HashedObj &x) const;
    void makeEmpty();
    void printLists();
    bool insert(const HashedObj &x);
    bool insert(HashedObj &&x);
    bool remove(const HashedObj &x);

    size_t getHashIndex(const HashedObj &x) const
    {
        static hash<HashedObj> hf;
        return (hf(x) % lists.size());
    }

private:
    std::vector<std::list<HashedObj>> lists; // The array of Lists
    int currentSize;

    void rehash();
};

template <typename HashedObj>
HashTable<HashedObj>::HashTable(int size)
{
    this->currentSize = 0;
    makeEmpty();
    lists.resize(size);
}

template <typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj &x) const
{
    auto &whichList = lists[getHashIndex(x)];
    if (find(whichList.begin(), whichList.end(), x) != whichList.end())
        return true;
    return false;
}

template <typename HashedObj>
void HashTable<HashedObj>::makeEmpty()
{
    for (auto &i : this->lists)
    {
        i.clear();
    }
}

template <typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj &x)
{
    auto &whichList = lists[getHashIndex(x)];
    if (find(begin(whichList), end(whichList), x) != end(whichList))
        return false;
    whichList.push_back(x);

    if (++currentSize > lists.size())
        rehash();

    return true;
}

template <typename HashedObj>
bool HashTable<HashedObj>::insert(HashedObj &&x)
{
    auto &whichList = lists[getHashIndex(x)];
    if (find(begin(whichList), end(whichList), x) != end(whichList))
        return false;
    whichList.push_back(std::move(x));

    if (++currentSize > lists.size())
        rehash();

    return true;
}

vector<int> primes;
const int MAX = 1000000;

void primeSieve()
{
    int n = MAX;
    int nNew = sqrt(n);
    int marked[n / 2 + 500] = {0};

    for (int i = 1; i <= (nNew - 1) / 2; i++)
        for (int j = (i * (i + 1)) << 1; j <= n / 2; j = j + 2 * i + 1)
            marked[j] = 1;

    primes.push_back(2);

    for (int i = 1; i <= n / 2; i++)
        if (marked[i] == 0)
            primes.push_back(2 * i + 1);
}

int searchNearestPrime(int left, int right, int n)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;
        if (mid == 0 || mid == primes.size() - 1)
            return primes[mid];

        if (primes[mid] == n)
            return primes[mid - 1];

        if (primes[mid] < n && primes[mid + 1] > n)
            return primes[mid];
        if (n < primes[mid])
            return searchNearestPrime(left, mid - 1, n);
        else
            return searchNearestPrime(mid + 1, right, n);
    }
    return 0;
}

template <typename HashedObj>
void HashTable<HashedObj>::rehash()
{
    vector<list<HashedObj>> oldLists = lists;
    int size = (int)lists.size();
    int nearestPrime = searchNearestPrime(0, primes.size() - 1, 2 * size);

    makeEmpty();
    this->lists.resize(nearestPrime);
    this->currentSize = 0;

    for (auto L : oldLists)
    {
        for (auto element : L)
        {
            insert(element);
        }
    }

    for (auto &i : oldLists)
    {
        i.clear();
    }
    oldLists.clear();
}

template <typename HashedObj>
void HashTable<HashedObj>::printLists()
{
    for (int i = 0; i < lists.size(); i++)
    {
        cout << i << " : [";
        for (auto j : lists[i])
        {
            cout << j << ",";
        }

        cout << "]\n";
    }
}

int main(void)
{
    primeSieve();
    HashTable<int> hTable;
    hTable.insert(10);
    hTable.insert(10);
    hTable.insert(5);
    hTable.insert(5);
    hTable.insert(2);
    hTable.insert(2);
    hTable.insert(29);
    hTable.insert(1);
    hTable.insert(1);
    hTable.insert(11);
    hTable.insert(11);
    hTable.insert(111);
    hTable.insert(112);
    hTable.insert(113);
    hTable.insert(114);
    hTable.insert(115);
    hTable.insert(116);

    hTable.printLists();

    return 0;
}