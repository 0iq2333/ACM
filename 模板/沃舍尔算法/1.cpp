/*
 * @Author: NEFU_马家沟老三
 * @LastEditTime: 2020-05-08 17:05:35
 * @CSDN blog: https://blog.csdn.net/acm_durante
 * @E-mail: 1055323152@qq.com
 * @ProbTitle: 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
int n;
char x;
int a[105][105];
void printf_ans()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j];
            if (j == n)
                cout << endl;
            else
                cout << ' ';
        }
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            a[i][j] = x - '0';
        }
    for (int i = 1; i <= n; i++) //列
    {
        for (int j = 1; j <= n; j++) //行
            if (a[j][i])             //加到第j行
                for (int k = 1; k <= n; k++)
                    a[j][k] |= a[i][k];
        cout << "M" << i << "==" << endl;
        printf_ans();
    }
    cout << "ans==" << endl;
    printf_ans();
    return 0;
}