// brute
//  //basic also right but here we target tc of less than o(n);

// brt
//  class Solution {
//  public:
//      void print_divisors(int n) {

//         vector<int> divon;

//         for (int i = 1; i * i <= n; i++) {
//             if (n % i == 0) {
//                 divon.push_back(i);
//                 if (i != n / i) {
//                     divon.push_back(n / i);
//                 }
//             }
//         }

//         sort(divon.begin(), divon.end());

//         for (auto x : divon) {
//             cout << x << " ";
//         }
//     }
// };
