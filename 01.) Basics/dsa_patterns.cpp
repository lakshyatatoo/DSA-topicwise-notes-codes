// outer loop count no of rows
// inner loop focus on columns adnconnect them to rows
// observe symmetry
//  p1
//   ^^^
//   ^^^
//   ^^^
//  #include <bits/stdc++.h>
//  using namespace std;
//  int main()
//  {
//      int n;
//      cin >> n;
//      for (int i = 0; i < n; i++)
//      {
//          for (int j = 0; j < n; j++)
//          {
//              cout << "*";
//          }
//          cout << endl;
//      }
//  }

// p2
//  *
//  * *
//  * * *
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int q = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             cout << "*" << " ";
//         }
//         cout << endl;
//     }
// }

// p3
// 1
// 12
// 123
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int q = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout << j << " ";
//         }
//         cout << endl;
//     }
// }

// p4
// 1
// 22
// 333
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int q = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout << i << " ";
//         }
//         cout << endl;
//     }
// }

// p5
// ***
// **
// *
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {

//         for (int j = n; j > i; j--)
//         {
//             cout << "*" << " ";
//         }
//         cout << endl;
//     }
// }

// p6
// 123
// 12
// 1
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     for (int i = 1; i <= n; i++)
//     {

//         for (int j = i; j <= n; j++)
//         {
//             cout << j << " ";
//         }
//         cout << endl;
//     }
// }

// p7
//   *
//  ***
// *****
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {

//         for (int j = 0; j < n - i - 1; j++)
//         {
//             cout << " ";
//         }
//         for (int z = 0; z < (2 * i) + 1; z++)
//         {
//             cout << "*";
//         }
//         for (int m = 0; m < n - i-1; m++)
//         {
//             cout << " ";
//         }
//         cout << endl;
//     }
// }

// p8
// *****
//  ***
//   *
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {

//         for (int j = 0; j < i; j++)
//         {
//             cout << " ";
//         }
//         for (int j = 0; j < 2 * n - ((2 * i) + 1); j++)
//         {
//             cout << "*";
//         }
//         for (int j = 0; j < i; j++)
//         {
//             cout << " ";
//         }
//         cout << endl;
//     }
// }

// p9
//   *
//  ***
// *****
// *****
//  ***
//   *
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {

//         for (int j = 0; j < n - i - 1; j++)
//         {
//             cout << " ";
//         }
//         for (int j = 0; j < (2 * i) + 1; j++)
//         {
//             cout << "*";
//         }
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             cout << " ";
//         }
//         cout << endl;
//     }

//     for (int i = 0; i < n; i++)
//     {

//         for (int j = 0; j < i; j++)
//         {
//             cout << " ";
//         }
//         for (int j = 0; j < 2 * n - ((2 * i) + 1); j++)
//         {
//             cout << "*";
//         }
//         for (int j = 0; j < i; j++)
//         {
//             cout << " ";
//         }
//         cout << endl;
//     }
// }

// p10
// *
// **
// ***
// **
// *

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     for (int i = 1; i <= (2 * n) - 1; i++)
//     {
//         int stars = i; // star same as row no
//         if (i > n)
//             stars = (2 * n) - i;
//         for (int j = 1; j <= stars; j++)
//         {
//             cout << "*" << " ";
//         }
//         cout << endl;
//     }
// }

// p11
// 1
// 0 1
// 1 0 1
// 0 1 0
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {

//     int n;
//     cin >> n;
//     int start = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (i % 2 == 0)
//             start = 1;
//         else
//         {
//             start = 0;
//         }

//         for (int j = 0; j <= i; j++)
//         {
//             cout << start << " ";
//             start = 1 - start;
//         }
//         cout << endl;
//     }
// }

// p12
// 1      1
// 12    21
// 123  321
// 12344321
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int spaces = 2 * (n - 1);
//     for (int i = 1; i <= n; i++)
//     {

//         for (int j = 1; j <= i; j++)
//         {
//             cout << j;
//         }
//         for (int j = 1; j <= spaces; j++)
//         {
//             cout << " ";
//         }
//         for (int j = i; j >= 1; j--)
//         {
//             cout << j;
//         }

//         cout << endl;
//         spaces -= 2;
//     }
// }

// p13
// 1
// 2 3
// 4 5 6
// 7 8 9 10
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int num = 1;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout << num << " ";
//             num += 1;
//         }
//         cout << endl;
//     }
// }

// p14
// a
// ab
// abc
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         for (char ch = 'A'; ch <= 'A' + i; ch++)
//         {
//             cout << ch << " ";
//         }
//         cout << endl;
//     }
// }

// p15
// abcde
// abcd
// abc
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch++)
//         {
//             cout << ch << " ";
//         }
//         cout << endl;
//     }
// }

// p16
// a
// bb
// ccc
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     char ch = 'A';
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout << ch;
//                 }
//         ch++;
//         cout << endl;
//     }
// }

// p17
//   a
//  aba
// abcba
// abcdcba
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < (n - i) - 1; j++)
//         {
//             cout << " ";
//         }
//         char ch = 'A';
//         int breakpoint = ((2 * i) + 1) / 2;
//         for (int j = 0; j < (2 * i) + 1; j++)
//         {
//             cout << ch;
//             if (j < breakpoint)
//                 ch++;
//             else
//                 ch--;
//         }
//         {
//         }
//         for (int j = 0; j < (n - i) - 1; j++)
//         {
//             cout << " ";
//         }
//         cout << endl;
//     }
// }

// p18
// e
// de
// cde
// bcde
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {

//         for (char ch = 'E' - i; ch <= 'E'; ch++)
//         {

//             cout << ch;
//         }

//         cout << endl;
//     }
// }

// p19
//
//
//
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int spaces = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 1; j <= n - i; j++)
//         {
//             cout << "*";
//         }
//         for (int j = 0; j < spaces; j++)
//         {
//             cout << " ";
//         }
//         for (int j = 1; j <= n - i; j++)
//         {
//             cout << "*";
//         }
//         spaces += 2;
//         cout << endl;
//     }
//     int inis = (2 * n) - 2;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout << "*";
//         }
//         for (int j = 0; j < inis; j++)
//         {
//             cout << " ";
//         }
//         for (int j = 1; j <= i; j++)
//         {
//             cout << "*";
//         }
//         inis -= 2;
//         cout << endl;
//     }
// }

// p20
// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int spaces = (2 * n) - 2;
//     for (int i = 1; i <= (2 * n) - 1; i++)
//     {
//         int stars = i;
//         if (i > n)
//             stars = (2 * n) - i;
//         for (int j = 1; j <= stars; j++)
//         {
//             cout << "*";
//         }
//         for (int j = 0; j < spaces; j++)
//         {
//             cout << " ";
//         }
//         for (int j = 1; j <= stars; j++)
//         {
//             cout << "*";
//         }
//         if (i < n)
//             spaces -= 2;
//         else
//             spaces += 2;
//         cout << endl;
//     }
//     int newspaces = 2;
// }

// p21
// ******
// *    *
// *    *
// *    *
// *    *
// ******
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {

//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {

//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 if (i == 1 || i == n || j == 1 || j == n)
//                     cout << "*";
//                 else
//                     cout << " ";
//             }
//         }

//         cout << endl;
//     }
// }
// else
// {
//     cout << "*";
//     for (int j = 1; j <= n - 2; j++)
//     {
//         cout << " ";
//     }
//     cout << "*";
// }

// p22
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < (2 * n) - 1; i++)
//     {
//         for (int j = 0; j < (2 * n) - 1; j++)
//         {
//             int left = j;
//             int top = i;
//             int right = (2 * n - 2) - j;
//             int bottom = (2 * n - 2) - i;

//             cout << (n - min(min(bottom, top), min(left, right)));
//         }
//         cout << endl;
//     }
// }