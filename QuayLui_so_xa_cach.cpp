/*Cho số nguyên dương N (2 < N <10). Một số nguyên dương K có N chữ số được gọi là số xa cách nếu thỏa mãn: K không chứa chữ số 0. Tất cả các chữ số từ 1 đến N đều xuất hiện trong K đúng 1 lần. Không có hai chữ số liên tiếp nào trong K có hiệu bằng 1.

Input Format

1 dòng duy nhất chứa số nguyên dương N

Constraints

3<=N<=9

Output Format

In ra các số thỏa mãn theo thứ tự tăng dần

Sample Input 0

4
Sample Output 0

2413
3142
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ant(char x , char y)
{
    return abs((x - '0') - (y - '0')) == 1;
}

bool check(string s)
{
    for(int i = 1 ; i < s.length() -1 ; i++)
    {
        if(ant(s[i] , s[i - 1]) || ant(s[i + 1] , s[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n ; cin >> n;
    string s = "";
    for(int i = 1 ; i <= n ;i++) s += to_string(i);
    vector<string> v;
    do
    {
        v.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    for(string x : v)
    {
        if(check(x)) cout << x << endl;
    }
}