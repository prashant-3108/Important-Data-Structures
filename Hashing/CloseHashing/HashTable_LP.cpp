#include <bits/stdc++.h>
using namespace std;

#define ll long long

template <typename HashedObj>
class HashTable
{
public:
    explicit HashTable(int size = 10);

    bool contains(const HashedObj &x) const;

    void makeEmpty();
    bool insert(const HashedObj &x);
    bool insert(HashedObj &&x);
    bool remove(const HashedObj &x);

    enum EntryType
    {
        ACTIVE,
        EMPTY,
        DELETED
    };

private:
    struct HashEntry
    {
        HashedObj element;
        EntryType info;

        HashEntry(const HashedObj &e = HashedObj{}, EntryType i = EMPTY)
            : element{e}, info{i} {}
        HashEntry(HashedObj &&e, EntryType i = EMPTY)
            : element{std::move(e)}, info{i} {}
    };

    vector<HashEntry> array;
    int currentSize;

    bool isActive(int currentPos) const;
    int findPos(const HashedObj &x) const;
    void rehash();
    size_t getHashIndex(const HashedObj &x) const
    {
        static hash<HashedObj> hf;
        return (hf(x) % array.size());
    }
};

template <typename HashedObj>
HashTable<HashedObj>::HashTable(int size)
{
    array.resize(size);
}

template <typename HashedObj>
bool HashTable<HashedObj>::isActive(int currentPos) const
{
    currentPos %= array.size();

    if (array[currentPos].info == EntryType::ACTIVE)
    {
        return true;
    }
    return false;
}

template <typename HashedObj>
bool HashTable<HashedObj>::isActive(int currentPos) const
{
    currentPos %= array.size();

    if (array[currentPos].info == EntryType::ACTIVE)
    {
        return true;
    }
    return false;
}

template <typename HashedObj>
bool HashTable<HashedObj>::isActive(int currentPos) const
{
    currentPos %= array.size();

    if (array[currentPos].info == ACTIVE)
    {
        return true;
    }
    return false;
}

template <typename HashedObj>
int HashTable<HashedObj>::findPos(const HashedObj &x) const
{
    int offset = 1;
    int currentPos = getHashIndex(x);

    while (array[currentPos].info != EMPTY && array[currentPos].element != x)
    {
        currentPos += offset; // Compute ith probe
        currentPos %= array.size();
    }
    return currentPos;
}

template <typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj &x) const
{
    return isActive(findPos(x));
}

template <typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj &x)
{
    int currentPos = findPos(x);
    if (isActive(currentPos))
        return false;

    array[currentPos].element = x;
    array[currentPos].info = ACTIVE;

    if (++currentSize > array.size() / 2)
        rehash();

    return true;
}

template <typename HashedObj>
bool HashTable<HashedObj>::insert(HashedObj &&x)
{
    int currentPos = findPos(x);
    if (isActive(currentPos))
        return false;

    array[currentPos].element = std::move(x);
    array[currentPos].info = ACTIVE;

    if (++currentSize > array.size() / 2)
        rehash();

    return true;
}

template <typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj &x)
{
    int currentPos = findPos(x);
    if (!isActive(currentPos))
        return false;

    array[currentPos].info = DELETED;
    return true;
}

int main(void)
{

    return 0;
}