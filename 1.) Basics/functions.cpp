#include <bits/stdc++.h>
using namespace std;
// pass by value
//  void sum(int a)
//  {
//      cout << a << endl;
//      a += 20;
//      cout << a << endl;
//  }
//  int main()
//  {
//      int a;
//      cin >> a;
//      sum(a);
//      cout << a << endl;
//      ;
//  }

// pass by reference
void sum(int &a)
{
    cout << a << endl;
    a += 20;
    cout << a << endl;
}
int main()
{
    int a;
    cin >> a;
    sum(a);
    cout << a << endl;
    ;
}