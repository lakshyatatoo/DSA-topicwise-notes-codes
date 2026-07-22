// 1//pair
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     // pair<int, int> p = {1, 2};
//     // cout << p.first << " " << p.second << endl;
//     // nested pair(to store more than 2 variables in a pair)
//     // pair<int, pair<int, int>> p = {1, {3, 4}};
//     // cout << p.first << " " << p.second.first << "*" << p.second.second << endl;
//     // array of pairs
//     // pair<int, int> a[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
//     // cout << a[3].second << endl;
// }

// 2//vectors
// int main()
// {
// vector<int> p;
// p.push_back(1);
// p.emplace_back(3);
// vector of pair
//  vector<pair<int,int>> pr;
//  pr.push_back({1,2});
//  pr.emplace_back(1,3); //assumes 2 as pair,,also depends on type of vector
// vector<int> p(5, 69); // vector conatining 5 instaces of 69
// vector<int> q(p);//p copies in q
// vector<int> por = {1, 2, 3, 4, 5, 6, 7, 8, 9};
// vector<int>::iterator it = por.begin();
// cout << *(it + 4) << endl;
// vector<int>::iterator iti = por.end(); // points just after the last element of vector so
// iti-- is the last element
//  por.rend reverse end point to reverse means just before start of vector
// cout << por.back() << endl;
// auto
// automatical iterator for vector identifies the data type
// for (auto x : por) //for data type x variable in por print x
// {
//     cout << x << " ";
// }
// cout << endl;
// vector deletion
// por.erase(por.begin() + 1, por.begin() + 6);
// por.insert(por.begin(), 34); // single element is inserted
//     por.insert(por.begin() + 3, {4, 5, 6, 6});
//     for (auto y : por)
//     {
//         cout << y << " ";
//     }
//     cout << endl;
// copy an entire vector inside another
// vector<int> cpy(3, 92);
// por.insert(por.begin(), cpy.begin(), cpy.end());
//.size,.pop_back,.clear empty the vector,,.empty give true and false
// }

// 3//list
// same as vector but gives front operations as well
// dynaic in nature
// maintains a doubly linked list for the elements
// push_front,emplace_front fasterthan insert
//  list<int> ls;

// 4 //stack
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     stack<int> st;
//     st.push(100);
//     st.push(120);
//     st.push(103);
//     st.push(400);
//     st.push(150);
//     st.push(106);
//     cout << st.top() << endl;
//     st.pop(); // removes element at top of stack .
//     cout << st.top() << endl;
//     cout << st.size() << endl;
//     cout << st.empty() << endl; // check if empty or not
//     // st[2] not valid since it is not index based
//     stack<int> s1, s2;
//     s1.swap(s2);
// }

// 5 // queue
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     queue<int> q; // empty
//     q.push(1);
//     q.push(2);
//     q.emplace(4); // same as push
//     q.back() += 5; // last added element is at back ie 4
//     cout << q.front() << endl;
//     q.pop(); // remove first element of q
//     cout << q.front() << endl;
// }

// 6 //priority queue
// called MAX HEAP
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     priority_queue<int> q; // empty
//     q.push(1);
//     q.push(2);
//     q.emplace(4); // same as push
//     cout << q.top() << endl;
//     q.pop(); // remove topmost element of q
//     cout << q.top() << endl;
// }
// priority queue to store minimum element at the top
// called MIN HEAP
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     priority_queue<int, vector<int>, greater<int>> q; // empty
//     q.push(1);
//     q.push(2);
//     q.emplace(4); // same as push
//     cout << q.top() << endl;
//     q.pop(); // remove topmost element of q
//     cout << q.top() << endl;
// }

// 7 //

// Set
//  #include <bits/stdc++.h>
//  using namespace std; // majority are similar to
//  int main()
//  {
//
//      set<int> st;
//      st.insert(8);
//      st.insert(4);
//      st.insert(7);
//      st.insert(3);
//      st.insert(6); //{3,4,6,7,8},,,{3,6,7,8}
//      auto it = st.find(4);  // retruns it which points to the address of 4
//      auto it = st.find(10); // for element not there it will point to the st.end()
//      //
//      st.erase(4); // will maintain the order
//      st.count(8); // if element is ther eit will return 1 or else 0
//      auto it1 = st.find(3);
//      auto it2 = st.find(7);
//      st.erase(it1, it2); //[3,6,7) so 3 and 6 will erase
//      auto it = st.upper_bound(7); // iterator will point at 8
//      auto it = st.lower_bound(7); // iterator will point at 7
//  }

// MULTISET
//  #include <bits/stdc++.h>
//  using namespace std;
//  int main()
//  {
//      multiset<int> ms;
//      ms.insert(8);
//      ms.insert(4);
//      ms.insert(7);
//      ms.insert(3);
//      ms.insert(3);
//      ms.insert(3);
//      ms.insert(8);         //{3,3,4,7,8,8}
//      ms.erase(8);          // all occurences of 8 will be erased
//      ms.count(4);          // will return 1
//      ms.erase(ms.find(3)); // will erase only 3 first one as find points to the first occurence of any element like iterator
//                            //{3,4,7}
//      ms.erase(ms.find(3)); // will erase
//      for (auto ch : ms)
//          cout << ch << endl;
//  }

// UNORDERED SET
//  #include <bits/stdc++.h>
//  using namespace std;
//  int main(){
//              unordered_set<int> st;
//      }

// 8 // MAP
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     map<int, int> mpp;
//     map<int, pair<int, int>> mpp;
//     map<pair<int, int>, int> mppp;
//     mpp[1] = 2;
//     mpp.emplace(3, 1);
//     mpp.insert({2, 4});
//     mppp[{2, 3}] = 10; // storing for 3rd declaration
//     for (auto it : mpp)
//     {
//         cout << it.first << " " << it.second << endl;
//     }
//     cout << mpp[1]; // outs value for key 1
//     cout << mpp[5]; // returns null or 0 for key not available
//     auto it = mpp.find(3);        // iterator points to the address of key 3
//     cout << *(it).second << endl; // showing error bcz one mpp has 2 values
//     //for .find that is not there it points to the .end();
//     // upperbound lower bound,erase swap , size, emptty , are all same as above
// }
// multimap
// same as map nbut we can store dupllicate keys but in a sorted manner
// unordered map
// same as map but unique key with no sorted manner(randomised)

// 9 // algos,sorting myway comp,permutations in a string, max element of a array
// sort
// sort(a,a+n)//iterator
// sort(a.begin(),a.end())
//
// pair<int,int> a[]={{1,2},{2,1},{4,1}}
// what if we want to sort our way
// like sort in descending order by second element of pair
// if same second element then sort accordign to the first element in descedning
//
// it is done using comp - self written comparator
// sort(a,a+n,comp)
//
//
//
//
// sorting pair myway using COMP.
// #include <bits/stdc++.h>
// using namespace std;
// bool comp(pair<int, int> p1, pair<int, int> p2)
// {
//     if (p1.second < p2.second)
//         return true;
//     if (p1.second > p2.second)
//         return false; // here comp internally swaps p1 and p2
//     // if they are same
//     if (p1.first > p2.first)
//         return true;
//     if (p1.first < p2.first)
//         return false;
//     // basically we analye 2 pairs and comp internally swaps them
// }
// int main()
// {
//     vector<pair<int, int>> a = {{1, 2}, {2, 1}, {4, 1}};
//     sort(a.begin(), a.end(), comp);
//     for (auto ch : a)
//     {
//         cout << ch.first << " " << ch.second << endl;
//     }//sorted second element ascending and frist element descending
// }
//
//
//
//
// built-in pop-count
// retrun no of 1s in a binary count of a no
// 32 bit for int
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int num = 7;
//     long long numo = 2345;
//     int cnt = __builtin_popcount(num);
//     int cut = __builtin_popcountll(numo); // for long long numbers
//     cout << cnt << endl;
//     cout << cut << endl;
// }
//
//
//
// string permutation
// print all permutations of a string posisble  and returns a false at end
// and while loop breaks
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s = "muscle";
//     do
//     {
//         cout << s << endl;
//     } while (next_permutation(s.begin(), s.end()));
// }
//
//
//
//
// max element of a array
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a = {10, 45, 33, 34567, 345, 234, 6, 56, 4, 5, 65, 35, 3};
    int maxi = *max_element(a.begin(), a.end()); // gives the address
    // star gives the element value
    int mini = *min_element(a.begin(), a.end());
    cout << maxi << " " << mini << endl;
}
