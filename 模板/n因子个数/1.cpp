/*
 * @Author: NEFU_马家沟老三
 * @LastEditTime: 2020-07-20 12:34:13
 * @CSDN blog: https://blog.csdn.net/acm_durante
 * @E-mail: 1055323152@qq.com
 * @ProbTitle: 
 */ 
#include <bits/stdc++.h>
using namespace std;
int fx(int x)
{
    int a = 0, re = 1;
    for (int i = 2; i * i <= x; i++)
    {
        a = 0;
        while (x % i == 0)
        {
            ++a;
            x /= i;
        }
        re *= (a + 1);
    }
    return x > 1 ? re * 2 : re;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << fx(n) << endl;
    return 0;
}