/*Cho mảng A[] gồm n phần tử, hãy xác định xem có thể chia mảng A[] thành 2 tập sao cho tổng của 2 tập bằng nhau hay không?

Input Format

Dòng đầu tiên là số nguyên n; Dòng thứ 2 gồm n số nguyên của mảng A[]

Constraints

1<=n<=20; 1<=A[i]<=100;

Output Format

In ra 1 nếu có thể chia mảng thành 2 phần bằng nhau, ngược lại in 0.

Sample Input 0

5
9 9 4 4 5 
Sample Output 0

0
Sample Input 1

4
1 2 3 4
Sample Output 1

1
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n ; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int sum = accumulate(a , a + n , 0);
    if(sum % 2 != 0)
    {
        cout << 0;
    }
    else
    {
        sum /= 2;
        bool dp[sum + 1];
        memset(dp , 0 , sizeof(dp));
        dp[0] = 1;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = sum ; j >= a[i] ; j--)
            {
                if(dp[j - a[i]])
                {
                    dp[j] = 1;
                }
            }
        }
        if(dp[sum]) cout << 1;
        else cout << 0;
    }
}