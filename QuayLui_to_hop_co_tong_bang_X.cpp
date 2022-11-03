/*Cho mảng A[] gồm N số nguyên dương phân biệt và số X. Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. Các số trong mảng A[] có thể được sử dụng nhiều lần. Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không giảm các số. Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau: {2, 2, 2, 2}, {2, 2, 4}, {2, 6}, {4, 4}, {8}.

Input Format

Dòng thứ nhất là hai số N và X; dòng tiếp theo đưa vào N số của mmảng A[]; các số được viết cách nhau một vài khoảng trống

Constraints

1<=N<=20; 1<=X,A[i]<=100;

Output Format

In ra số tổ hợp thỏa mãn sau đó in ra các tổ hợp thỏa mãn trên từng dòng. Xem output để rõ hơn cách in. Trong trường hợp không có tổ hợp thỏa mãn thì in ra -1.

Sample Input 0

3 10
4 2 3 
Sample Output 0

5
{2 2 2 2 2}
{2 2 2 4}
{2 2 3 3}
{2 4 4}
{3 3 4}
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n , a[1001] , x[1001], s , ok;
vector<string>v;
void backtrack(int i , int sum , int pos)
{
    if(sum == s)
    {
        string res = "";
        res +="{";
        for(int j = 0 ; j < i ; j++)
        {
            res += to_string(x[j]) ;
            if(j != i - 1) res += " ";
            else res += "}";
        }
        v.push_back(res);
    }
    for(int j = pos ; j <= n ;j++)
    {
        if(sum + a[j] <= s)
        {
            x[i] = a[j];
            backtrack(i + 1 , sum + a[j] , j);
        }
    }
}

int main()
{
    cin >> n >> s;
    for(int i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a + 1 ,a + n + 1);
    backtrack(0 , 0 , 1);
    if(v.size() == 0)
    {
        cout << -1;
        return 0;
    }
    cout << v.size() << endl;
    for(string x : v)
    {
        cout << x << endl;
    }
}