// armstrong no if cube sum of digits of number are equal to the number
// class Solution {
//   public:
//     bool armstrongNumber(int n) {
//
//         int sum=0;
//         int m=n;
//         while(n>0){
//             int d=n%10;
//             n=n/10;
//             sum=sum+(d*d*d);
//         }
//         return (sum==m);
//     }
// };