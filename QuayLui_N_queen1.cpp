/*Cho một bàn cờ vua có kích thước n * n. Vấn đề đặt ra rằng, có n quân hậu, bạn cần đếm số cách đặt n quân hậu này lên bàn cờ sao cho với 2 quân hậu bất kì, chúng không “ăn” nhau.

Input Format

Dòng duy nhất chứa n là kích thước của bàn cờ.

Constraints

1<=N<=12

Output Format

In ra số cách xếp hậu hợp lệ

Sample Input 0

8
Sample Output 0

92
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c[101] , d1[101] , d2[101] ,m, n , res;
int s = 0;
void Backtrack(int i)
{
   for(int j = 1 ; j <= n ; j++)
   {
       if(!c[j] && !d1[i - j + n] && !d2[i + j - 1])
       {
           c[j] = d1[i - j + n] = d2[i + j - 1] = 1;
           if(i == n)
           {
               ++res;
           }
           Backtrack(i + 1);
           c[j] = d1[i - j + n] = d2[i + j - 1] = 0;
       }
   }
}

int main()
{
    cin >> n;
    res = 0;
    Backtrack(1);
    cout << res;
}