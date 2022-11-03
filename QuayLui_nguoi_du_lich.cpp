/*Cho n thành phố đánh số từ 1 đến n và các tuyến đường giao thông hai chiều giữa chúng, mạng lưới giao thông này được cho bởi mảng C[1…n, 1…n] ở đây C[i][j] = C[j][i] là chi phí đi đoạn đường trực tiếp từ thành phố i đến thành phố j. Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần và cuối cùng quay lại thành phố 1. Hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra.

Input Format

Dòng đầu tiên là số nguyên n – số thành phố; n dòng sau, mỗi dòng chứa n số nguyên thể hiện cho mảng 2 chiều C.

Constraints

1<=N<=15; 0<=C[i][j]<=100;

Output Format

In ra chi phí mà người đó phải bỏ ra

Sample Input 0

4
0 85 26 81 
85 0 77 97 
26 77 0 26 
81 97 26 0 
Sample Output 0

234
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n , a[20][20] , x[20], check[101] , cmin , ans , res;
void Backtrack(int i)
{
   for(int j = 2 ; j <= n ; j++)
   {
       if(check[j])
       {
           check[j] = 0;
           x[i] = j;
           res += a[x[i - 1]][j];
           if(i == n)
           {
               ans = min(ans , a[x[i]][1] + res);
           }
           if(res + (n - i + 1) * cmin <= ans)
           {
               Backtrack(i + 1);
           }
            res -= a[x[i - 1]][j]; 
            check[j] = 1;
       }
   }
}
int main()
{
    cin >> n;
    res = 0;
    cmin = 1e9 , ans = 1e9;
    for(int i = 1 ; i <= n ;i++) 
    {
        for(int j = 1 ; j <= n ;j++)
        {
            cin >> a[i][j] ;
            cmin = min(a[i][j], cmin);
        }
    }
    x[1] = 1;
    memset(check , 1 , sizeof(check));
    Backtrack(2);
    cout << ans;
}