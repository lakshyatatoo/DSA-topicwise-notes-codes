/*
============================================================
              C++ STL — ORGANIZED INTERVIEW NOTES
============================================================

STL = Standard Template Library

Main things:
1. pair
2. vector
3. list
4. stack
5. queue
6. priority_queue
7. set
8. multiset
9. unordered_set
10. map
11. multimap
12. unordered_map
13. Algorithms
14. Custom comparator
15. Built-in functions
16. next_permutation
17. max_element / min_element

*/

#include <bits/stdc++.h>
using namespace std;

/*
============================================================
1. PAIR
============================================================

pair stores EXACTLY 2 values.

Syntax:
    pair<dataType1, dataType2>

Example:
    pair<int, int> p = {1, 2};

Access:
    p.first
    p.second

Useful when we want to keep two related values together.
*/

void pairExample()
{
    // Basic pair
    pair<int, int> p = {1, 2};

    cout << p.first << " ";
    cout << p.second << endl;

    // Nested pair
    // Useful when we want more than 2 values
    pair<int, pair<int, int>> p2 = {1, {3, 4}};

    cout << p2.first << " ";
    cout << p2.second.first << " ";
    cout << p2.second.second << endl;

    // Array of pairs
    pair<int, int> a[] =
        {
            {1, 2},
            {3, 4},
            {5, 6},
            {7, 8}};

    cout << a[3].second << endl;
}

/*
============================================================
2. VECTOR
============================================================

vector = dynamic array

Unlike normal array:
    - size can grow/shrink
    - elements stored contiguously
    - supports random access using []
    - insertion at end is efficient

Common functions:
    push_back()
    emplace_back()
    size()
    pop_back()
    clear()
    empty()
    front()
    back()
    erase()
    insert()
*/

void vectorExample()
{
    // Empty vector
    vector<int> p;

    p.push_back(1);
    p.emplace_back(3);

    // Vector of pairs
    vector<pair<int, int>> pr;

    pr.push_back({1, 2});
    pr.emplace_back(1, 3);

    // Vector containing 5 copies of 69
    vector<int> v1(5, 69);

    // Copy vector
    vector<int> v2(v1);

    // Normal initialization
    vector<int> por =
        {
            1, 2, 3, 4, 5,
            6, 7, 8, 9};

    /*
    --------------------------------------------------------
    ITERATORS
    --------------------------------------------------------
    */

    vector<int>::iterator it = por.begin();

    // begin() points to first element
    // *(it + 4) gives 5

    cout << *(it + 4) << endl;

    // end() points JUST AFTER the last element

    vector<int>::iterator iti = por.end();

    // iti is NOT the last element
    // iti-- makes it point to last element

    iti--;

    cout << *iti << endl;

    /*
    --------------------------------------------------------
    REVERSE ITERATORS
    --------------------------------------------------------
    */

    // rbegin() -> last element
    // rend()   -> before first element

    cout << *por.rbegin() << endl;

    /*
    --------------------------------------------------------
    BACK
    --------------------------------------------------------
    */

    cout << por.back() << endl;

    /*
    --------------------------------------------------------
    AUTO
    --------------------------------------------------------

    auto automatically determines the data type.
    */

    for (auto x : por)
    {
        cout << x << " ";
    }

    cout << endl;

    /*
    --------------------------------------------------------
    ERASE
    --------------------------------------------------------
    */

    // Erase element at index 1
    // por.erase(por.begin() + 1);

    // Erase range [begin()+1, begin()+6)
    por.erase(por.begin() + 1, por.begin() + 6);

    /*
    --------------------------------------------------------
    INSERT
    --------------------------------------------------------
    */

    // Insert one element
    por.insert(por.begin(), 34);

    // Insert multiple elements
    por.insert(por.begin() + 3, {4, 5, 6, 6});

    /*
    --------------------------------------------------------
    PRINT
    --------------------------------------------------------
    */

    for (auto x : por)
    {
        cout << x << " ";
    }

    cout << endl;

    /*
    --------------------------------------------------------
    INSERT ONE VECTOR INTO ANOTHER
    --------------------------------------------------------
    */

    vector<int> cpy(3, 92);

    por.insert(
        por.begin(),
        cpy.begin(),
        cpy.end());

    /*
    --------------------------------------------------------
    COMMON VECTOR FUNCTIONS
    --------------------------------------------------------

    size()      -> number of elements
    pop_back()  -> removes last element
    clear()     -> removes all elements
    empty()     -> true if empty, otherwise false
    front()     -> first element
    back()      -> last element
    */

    cout << por.size() << endl;
    cout << por.empty() << endl;
}

/*
============================================================
3. LIST
============================================================

list = doubly linked list

Properties:
    - dynamic
    - elements are NOT stored contiguously
    - fast insertion/deletion at known position
    - supports front operations efficiently

Common:
    push_front()
    emplace_front()
    push_back()
    emplace_back()
    pop_front()
    pop_back()
    insert()
    erase()

Unlike vector:
    list does NOT support random access like:

        ls[3]     // invalid
*/

void listExample()
{
    list<int> ls;

    ls.push_back(10);
    ls.push_front(20);

    ls.emplace_back(30);
    ls.emplace_front(40);

    ls.pop_front();
    ls.pop_back();
}

/*
============================================================
4. STACK
============================================================

Stack follows:

    LIFO
    Last In First Out

Example:

    push 100
    push 120
    push 103

Top = 103

Common:
    push()
    emplace()
    top()
    pop()
    size()
    empty()

NO random indexing.

    st[2]   // INVALID
*/

void stackExample()
{
    stack<int> st;

    st.push(100);
    st.push(120);
    st.push(103);
    st.push(400);
    st.push(150);
    st.push(106);

    // Last inserted element
    cout << st.top() << endl;

    // Removes top element
    st.pop();

    cout << st.top() << endl;

    cout << st.size() << endl;

    cout << st.empty() << endl;

    // Swap two stacks
    stack<int> s1, s2;

    s1.swap(s2);
}

/*
============================================================
5. QUEUE
============================================================

Queue follows:

    FIFO
    First In First Out

Example:

    push 1
    push 2
    push 4

Front = 1
Back  = 4

Common:
    push()
    emplace()
    front()
    back()
    pop()
    size()
    empty()
*/

void queueExample()
{
    queue<int> q;

    q.push(1);
    q.push(2);
    q.emplace(4);

    // Last element
    q.back() += 5;

    // First element
    cout << q.front() << endl;

    // Removes first element
    q.pop();

    cout << q.front() << endl;
}

/*
============================================================
6. PRIORITY QUEUE
============================================================

priority_queue is generally implemented using a heap.

DEFAULT:
    MAX HEAP

Largest element stays at top.

    priority_queue<int> q;

q.top() -> largest element


MIN HEAP:

    priority_queue<
        int,
        vector<int>,
        greater<int>
    >

Smallest element stays at top.
*/

void maxHeapExample()
{
    priority_queue<int> q;

    q.push(1);
    q.push(2);
    q.emplace(4);

    cout << q.top() << endl;

    q.pop();

    cout << q.top() << endl;
}

void minHeapExample()
{
    priority_queue<
        int,
        vector<int>,
        greater<int>>
        q;

    q.push(1);
    q.push(2);
    q.emplace(4);

    cout << q.top() << endl;

    q.pop();

    cout << q.top() << endl;
}

/*
============================================================
7. SET
============================================================

set stores:

    - UNIQUE elements
    - SORTED elements
    - usually implemented using a balanced BST

Example:

insert:
    8 4 7 3 6

set becomes:

    {3, 4, 6, 7, 8}

Duplicate values are ignored.

Common:
    insert()
    find()
    erase()
    count()
    lower_bound()
    upper_bound()
*/

void setExample()
{
    set<int> st;

    st.insert(8);
    st.insert(4);
    st.insert(7);
    st.insert(3);
    st.insert(6);

    // {3,4,6,7,8}

    /*
    --------------------------------------------------------
    FIND
    --------------------------------------------------------
    */

    auto it = st.find(4);

    // it points to 4

    // If element does not exist:
    // iterator == st.end()

    auto it2 = st.find(10);

    if (it2 == st.end())
    {
        cout << "10 not found\n";
    }

    /*
    --------------------------------------------------------
    ERASE
    --------------------------------------------------------
    */

    st.erase(4);

    /*
    --------------------------------------------------------
    COUNT
    --------------------------------------------------------

    In set:
        count(x) = 1 if present
        count(x) = 0 if absent
    */

    cout << st.count(8) << endl;

    /*
    --------------------------------------------------------
    ERASE RANGE
    --------------------------------------------------------

    [it1, it2)

    it1 included
    it2 NOT included
    */

    auto it1 = st.find(3);
    auto it3 = st.find(7);

    st.erase(it1, it3);

    /*
    --------------------------------------------------------
    LOWER_BOUND
    --------------------------------------------------------

    First element >= x
    */

    auto lb = st.lower_bound(7);

    /*
    --------------------------------------------------------
    UPPER_BOUND
    --------------------------------------------------------

    First element > x
    */

    auto ub = st.upper_bound(7);
}

/*
============================================================
8. MULTISET
============================================================

multiset:
    - sorted
    - allows duplicates

Example:

8,4,7,3,3,3,8

becomes:

3 3 3 4 7 8 8
*/

void multisetExample()
{
    multiset<int> ms;

    ms.insert(8);
    ms.insert(4);
    ms.insert(7);
    ms.insert(3);
    ms.insert(3);
    ms.insert(3);
    ms.insert(8);

    // {3,3,3,4,7,8,8}

    /*
    erase(value)

    Removes ALL occurrences of that value.
    */

    ms.erase(8);

    /*
    count()

    Number of occurrences.
    */

    cout << ms.count(4) << endl;

    /*
    erase(iterator)

    Removes ONLY the element pointed to.
    */

    auto it = ms.find(3);

    if (it != ms.end())
        ms.erase(it);

    for (auto x : ms)
    {
        cout << x << " ";
    }

    cout << endl;
}

/*
============================================================
9. UNORDERED SET
============================================================

unordered_set:
    - UNIQUE elements
    - NOT sorted
    - implemented using hashing

Average:
    insert/find/erase -> O(1)

Worst case:
    O(n)

Use when:
    you need fast lookup
    and DON'T need sorted order.
*/

void unorderedSetExample()
{
    unordered_set<int> st;

    st.insert(10);
    st.insert(20);
    st.insert(10);

    // Duplicate 10 ignored.
}

/*
============================================================
10. MAP
============================================================

map stores:

    KEY -> VALUE

Properties:
    - keys are UNIQUE
    - keys are SORTED
    - usually implemented using balanced BST

Example:

    map<int,int> mpp;

key -> value

1 -> 2
3 -> 1
2 -> 4
*/

void mapExample()
{
    map<int, int> mpp;

    mpp[1] = 2;

    mpp.emplace(3, 1);

    mpp.insert({2, 4});

    /*
    --------------------------------------------------------
    MAP WITH PAIR AS VALUE
    --------------------------------------------------------
    */

    map<int, pair<int, int>> mpp2;

    mpp2[1] = {10, 20};

    /*
    --------------------------------------------------------
    PAIR AS KEY
    --------------------------------------------------------
    */

    map<pair<int, int>, int> mpp3;

    mpp3[{2, 3}] = 10;

    /*
    --------------------------------------------------------
    ITERATING MAP
    --------------------------------------------------------
    */

    for (auto it : mpp)
    {
        cout << it.first << " "
             << it.second << endl;
    }

    /*
    --------------------------------------------------------
    ACCESS VALUE
    --------------------------------------------------------
    */

    cout << mpp[1] << endl;

    /*
    IMPORTANT:

    mpp[5] when key 5 doesn't exist
    will CREATE key 5 with default value 0
    for int value.

    So don't use [] just to check existence.
    Use find().
    */

    /*
    --------------------------------------------------------
    FIND
    --------------------------------------------------------
    */

    auto it = mpp.find(3);

    if (it != mpp.end())
    {
        cout << it->first << " "
             << it->second << endl;
    }

    /*
    If key doesn't exist:

        mpp.find(key) == mpp.end()
    */

    /*
    Same useful functions:

        erase()
        count()
        lower_bound()
        upper_bound()
        size()
        empty()
        swap()
    */
}

/*
============================================================
11. MULTIMAP
============================================================

multimap:
    - duplicate keys allowed
    - keys remain sorted
    - one key can have multiple values

Example:

1 -> A
1 -> B
1 -> C

Unlike map:

map:
    key must be unique
*/

void multimapExample()
{
    multimap<int, string> mp;

    mp.insert({1, "A"});
    mp.insert({1, "B"});
    mp.insert({2, "C"});
}

/*
============================================================
12. UNORDERED MAP
============================================================

unordered_map:
    - UNIQUE keys
    - NOT sorted
    - hash table based
    - average O(1) lookup/insert/delete

map:
    sorted keys
    O(log n)

unordered_map:
    no sorting
    average O(1)
*/

void unorderedMapExample()
{
    unordered_map<int, string> mp;

    mp[1] = "A";
    mp[2] = "B";
}

/*
============================================================
13. SORT
============================================================

sort() is a built-in algorithm.

Array:

    sort(a, a+n);

Vector:

    sort(v.begin(), v.end());

Default:
    ascending order
*/

void sortExample()
{
    int a[] = {5, 2, 8, 1, 3};

    sort(a, a + 5);

    vector<int> v =
        {
            5, 2, 8, 1, 3};

    sort(v.begin(), v.end());

    // Descending
    sort(v.begin(), v.end(), greater<int>());
}

/*
============================================================
14. CUSTOM COMPARATOR
============================================================

Used when we want our OWN sorting rule.

Suppose:

    {1,2}
    {2,1}
    {4,1}

Requirement:

1. Sort by SECOND element ascending.
2. If second is same,
   sort FIRST element descending.

Expected:

    {4,1}
    {2,1}
    {1,2}
*/

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    // Different second elements
    if (p1.second < p2.second)
        return true;

    if (p1.second > p2.second)
        return false;

    // Second elements are same.
    // Now compare first element.

    if (p1.first > p2.first)
        return true;

    if (p1.first < p2.first)
        return false;

    return false;
}

void customComparatorExample()
{
    vector<pair<int, int>> a =
        {
            {1, 2},
            {2, 1},
            {4, 1}};

    sort(a.begin(), a.end(), comp);

    for (auto p : a)
    {
        cout << p.first << " "
             << p.second << endl;
    }
}

/*
IMPORTANT ABOUT COMPARATOR
--------------------------

comp(a,b) returns TRUE when:

    a should come BEFORE b

It does NOT mean:

    "swap a and b"

Think:

    comp(a,b) == true
        -> a comes before b

    comp(a,b) == false
        -> a should not come before b

*/

/*
============================================================
15. BUILT-IN POPCOUNT
============================================================

__builtin_popcount(x)

Returns number of SET BITS (1s) in binary representation.

Example:

7 = 111

number of 1s = 3

For int:
    __builtin_popcount()

For long long:
    __builtin_popcountll()
*/

void popcountExample()
{
    int num = 7;

    long long numo = 2345;

    int cnt = __builtin_popcount(num);

    int cnt2 = __builtin_popcountll(numo);

    cout << cnt << endl;
    cout << cnt2 << endl;
}

/*
============================================================
16. NEXT_PERMUTATION
============================================================

next_permutation()
generates the next lexicographical permutation.

Example:

    123
    132
    213
    231
    312
    321

Important:

next_permutation() returns:

    true  -> next permutation exists
    false -> no next permutation

When it returns false,
the sequence is reset to the smallest permutation.

For all permutations:

    do
    {
        ...
    }
    while(next_permutation(...));

IMPORTANT:
Start with SORTED string/vector if you want ALL
permutations.
*/

void permutationExample()
{
    string s = "muscle";

    // For all permutations in lexicographical order,
    // first sort:
    sort(s.begin(), s.end());

    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
}

/*
============================================================
17. MAX_ELEMENT / MIN_ELEMENT
============================================================

max_element()
returns an ITERATOR to the maximum element.

min_element()
returns an ITERATOR to the minimum element.

Therefore:

    *max_element(...)

gives the actual VALUE.

Without *:
    iterator

With *:
    value
*/

void maxMinExample()
{
    vector<int> a =
        {
            10, 45, 33, 34567,
            345, 234, 6, 56,
            4, 5, 65, 35, 3};

    int maxi =
        *max_element(a.begin(), a.end());

    int mini =
        *min_element(a.begin(), a.end());

    cout << maxi << " "
         << mini << endl;
}

/*
============================================================
18. OTHER IMPORTANT BUILT-IN ALGORITHMS
============================================================

These are worth knowing for interviews.

sort()
    -> sort elements

reverse()
    -> reverse range

max_element()
    -> maximum element iterator

min_element()
    -> minimum element iterator

count()
    -> count occurrences

find()
    -> find an element

accumulate()
    -> sum/running accumulation

binary_search()
    -> checks if element exists in sorted range

lower_bound()
    -> first position >= x

upper_bound()
    -> first position > x

swap()
    -> swap two values
*/

void otherAlgorithms()
{
    vector<int> v = {1, 2, 3, 4, 5};

    // reverse
    reverse(v.begin(), v.end());

    // count
    int cnt = count(v.begin(), v.end(), 3);

    // find
    auto it = find(v.begin(), v.end(), 4);

    // sum
    int sum = accumulate(v.begin(), v.end(), 0);

    // binary search
    // v must be sorted
    bool exists = binary_search(
        v.begin(),
        v.end(),
        3);

    // lower_bound
    auto lb = lower_bound(
        v.begin(),
        v.end(),
        3);

    // upper_bound
    auto ub = upper_bound(
        v.begin(),
        v.end(),
        3);
}

/*
============================================================
19. QUICK COMPARISON
============================================================

VECTOR
------
Dynamic array
Random access
Contiguous memory
Fast access: O(1)
End insertion: O(1) amortized


LIST
----
Doubly linked list
No random access
Fast insertion/deletion at known position


STACK
-----
LIFO
Only top accessible


QUEUE
-----
FIFO
Front removed
Back inserted


PRIORITY_QUEUE
--------------
Heap
Largest at top by default
Smallest at top using greater<int>


SET
---
Unique
Sorted
O(log n) operations


MULTISET
--------
Duplicates allowed
Sorted
O(log n)


UNORDERED_SET
-------------
Unique
Unsorted
Average O(1)


MAP
---
Key-value
Unique keys
Sorted keys
O(log n)


MULTIMAP
--------
Key-value
Duplicate keys allowed
Sorted keys


UNORDERED_MAP
-------------
Key-value
Unique keys
Unsorted
Average O(1)


============================================================
20. MOST IMPORTANT INTERVIEW DIFFERENCES
============================================================

SET vs UNORDERED_SET

set:
    unique
    sorted
    O(log n)

unordered_set:
    unique
    unsorted
    average O(1)


MAP vs UNORDERED_MAP

map:
    unique keys
    sorted
    O(log n)

unordered_map:
    unique keys
    unsorted
    average O(1)


MAP vs MULTIMAP

map:
    duplicate keys NOT allowed

multimap:
    duplicate keys allowed


VECTOR vs LIST

vector:
    dynamic array
    random access
    contiguous memory

list:
    doubly linked list
    no random access
    efficient insertion/deletion


STACK vs QUEUE

stack:
    LIFO

queue:
    FIFO


MAX HEAP vs MIN HEAP

priority_queue<int>
    -> MAX HEAP
    -> largest at top

priority_queue<int, vector<int>, greater<int>>
    -> MIN HEAP
    -> smallest at top


============================================================
21. ITERATOR CHEAT SHEET
============================================================

v.begin()
    -> first element

v.end()
    -> just AFTER last element

v.rbegin()
    -> last element

v.rend()
    -> just BEFORE first element


Example:

vector<int> v = {10,20,30};

begin()  -> 10
end()    -> after 30
rbegin() -> 30
rend()   -> before 10


============================================================
22. ERASE RANGE
============================================================

erase(first, last)

means:

    [first, last)

First included
Last NOT included

Example:

v.erase(v.begin()+1, v.begin()+4);

Removes indices:

    1
    2
    3

NOT index 4.


============================================================
23. LOWER_BOUND / UPPER_BOUND
============================================================

For sorted containers/ranges:

lower_bound(x)
    -> first element >= x

upper_bound(x)
    -> first element > x


Example:

set = {1,3,5,7,9}

lower_bound(5)
    -> 5

upper_bound(5)
    -> 7

lower_bound(6)
    -> 7

upper_bound(6)
    -> 7


============================================================
24. FINAL STL REVISION
============================================================

PAIR
    -> stores 2 related values

VECTOR
    -> dynamic array

LIST
    -> doubly linked list

STACK
    -> LIFO

QUEUE
    -> FIFO

PRIORITY_QUEUE
    -> heap / priority based access

SET
    -> unique + sorted

MULTISET
    -> duplicate + sorted

UNORDERED_SET
    -> unique + unsorted/hash

MAP
    -> unique key + sorted

MULTIMAP
    -> duplicate keys + sorted

UNORDERED_MAP
    -> unique key + unsorted/hash

SORT
    -> sorting

COMPARATOR
    -> custom sorting rule

POPCOUNT
    -> count set bits

NEXT_PERMUTATION
    -> next lexicographical permutation

MAX_ELEMENT
    -> iterator to maximum

MIN_ELEMENT
    -> iterator to minimum

*/