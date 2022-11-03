/*Cho dãy số a[] có n phần tử là các số nguyên dương khác nhau từng đôi một. Hãy liệt kê tất cả các dãy con có từ 2 phần tử trở lên của dãy a[] thỏa mãn tính chất tăng dần. Dãy con tạo được bằng cách lấy ra các phần tử trong dãy a[] nhưng vẫn giữ nguyên thứ tự ban đầu. Coi mỗi dãy con như một xâu ký tự với các phần tử cách nhau một khoảng trống, hãy liệt kê theo thứ tự từ điển

Input Format

Dòng đầu ghi số n (không quá 20); Dòng thứ 2 ghi n số của dãy a[]. Các số khác nhau từng đôi một và có giá trị không quá 100;

Constraints

2<=n<=20; 1<=a[i]<=100;

Output Format

Đưa ra các dãy con hợp lệ theo thứ tự từ điển tăng dần.

Sample Input 0

7
4 8 6 7 3 5 2 
Sample Output 0

3 5 
4 5 
4 6 
4 6 7 
4 7 
4 8 
6 7 
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n , a[21] , x[21];
vector<string>v;

void Backtrack(int i , int pos)
{
    if(i >= 2)
    {
        string res = "";
        for(int j = 0 ; j < i ; j++)
        {
            res += to_string(x[j]) + " ";
        }
        v.push_back(res);
    }
    for(int j = pos ; j < n ; j++)
    {
        if(a[j] > x[i - 1])
        {
            x[i] = a[j];
            Backtrack(i + 1, j + 1);
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    Backtrack(0 , 0);
    sort(v.begin(), v.end());
    for(string x : v) cout << x << endl;
}