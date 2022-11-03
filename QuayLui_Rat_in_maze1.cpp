/*Cho một mê cung được mô tả dưới dạng một ma trận nhị phân có N hàng và N cột. Một con chuột bắt đầu tử ô (1, 1) và muốn di chuyển tới ô (N, N). Con chuột chỉ được di chuyển xuống dưới hoặc sang phải và chỉ được di chuyển tới ô nào đó nếu ô đó có giá trị là 1. Bạn hãy in ra các cách đi hợp lệ của con chuột, trong đó nếu con chuột đi sang phải thì nước đi được mô tả là chữ R, và nếu con chuột đi xuống dưới thì nước đi được mô tả là chữ D. Nếu con chuột không thể đi xuống ô (N, N) thì in ra -1. Chú ý trên mỗi đường đi con chuột chỉ có thể đi qua 1 ô nào đó đúng 1 lần.

Input Format

Dòng thứ nhất đưa vào N; N dòng tiếp theo mỗi dòng gồm N số;

Constraints

1<=N<=12; Dữ liệu đảm bảo ô (1, 1) là số 1.

Output Format

Đưa ra các đường đi hợp lệ theo thứ tự từ điển tăng dần trên từng dòng.

Sample Input 0

4
1 1 0 1 
1 1 1 1 
1 0 1 1 
1 1 1 1 
Sample Output 0

DDDRRR
DRRDDR
DRRDRD
DRRRDD
RDRDDR
RDRDRD
RDRRDD
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[101][101], x[1001], k, n , res;
string s = "";
void Backtrack(int i , int j)
{
    if(i == n - 1 && j == n - 1)
    {
        cout << s << endl;
        res = 1;
    }
    if(i + 1 < n && a[i + 1][j])
    {
        a[i + 1][j] = 0;
        s += "D";
        Backtrack(i + 1, j);
        a[i + 1][j] = 1;
        s.pop_back();
    }
    if(j + 1 < n && a[i][j + 1])
    {
        a[i][j + 1] = 0;
        s += "R";
        Backtrack(i , j + 1);
        a[i][j + 1] = 1;
        s.pop_back();
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n ;j++)
        {
            cin >> a[i][j];
        }
    }
    Backtrack(0 , 0);
    if(res == 0) cout << -1;
}