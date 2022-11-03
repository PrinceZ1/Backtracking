/*Cho ma trận A[M][N]. Nhiệm vụ của bạn là đếm tất cả các đường đi từ phần tử A[0][0] đến phần tử A[M-1][N-1]. Bạn chỉ được phép dịch chuyển xuống dưới hoặc sang phải phần tử liền kề với vị trí hiện tại.

Input Format

Dòng 1 là hai số M, N tương ứng với số hàng và số cột của ma trận; Dng tiếp theo đưa vào các phần tử của ma trận A[][]; các số được viết cách nhau một vài khoảng trống.

Constraints

1≤M, N, <=10; A[i][j]≤100;

Output Format

Đưa ra số cách di chuyển

Sample Input 0

3 5
4 6 8 3 1 
9 8 8 9 1 
10 6 3 4 5 
Sample Output 0

15
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[101][101], x[101][101], m, n , res;
int s = 0;
void Backtrack(int i , int j)
{
    if(i == n - 1 && j == m - 1)
    {
        ++res;
        return;
    }
    if(i + 1 < n && x[i + 1][j])
    {
        x[i + 1][j] = 0;
        Backtrack(i + 1, j);
        x[i + 1][j] = 1;
    }
    if(j + 1 < m && x[i][j + 1])
    {
        x[i][j + 1] = 0;
        Backtrack(i , j + 1);
        x[i][j + 1] = 1;
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < m ;j++)
        {
            cin >> a[i][j];
        }
    }
    memset(x, 1, sizeof(x));
    res = 0;
    a[0][0] = 0;
    Backtrack(0 , 0);
    cout << res;
}