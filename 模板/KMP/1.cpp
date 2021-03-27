/*
 * @Author: NEFU_马家沟老三
 * @LastEditTime: 2020-09-20 12:21:50
 * @CSDN blog: https://blog.csdn.net/acm_durante
 * @E-mail: 1055323152@qq.com
 * @ProbTitle: 
 */
#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;
int kmp[MAXN]; //记录不符合之后跳转到第几位
int la, lb, j; //j就相当于匹配到了第几位
char a[MAXN], b[MAXN];
int main()
{
    cin >> a + 1; //原字符串
    cin >> b + 1; //要匹配到的字符串
    la = strlen(a + 1);
    lb = strlen(b + 1);
    for (int i = 2; i <= lb; i++)
    {
        while (j && b[i] != b[j + 1]) //此处判断j是否为0的原因在于，如果回跳到第一个字符就不用再回跳了
            j = kmp[j];               //通过自己匹配自己来得出每一个点的kmp值
        if (b[j + 1] == b[i])
            j++;
        kmp[i] = j; //i+1失配后应该如何跳
        
    }
    j = 0;
    for (int i = 1; i <= la; i++)
    {
        while (j&& b[j + 1] != a[i]) //如果失配 ，那么就不断向回跳，直到可以继续匹配
            j = kmp[j];
        if (b[j + 1] == a[i]) //如果匹配成功，那么对应的模式串位置++
            j++;
        if (j == lb) //继续匹配
        {
            cout << i - lb + 1 << endl;
            j = kmp[j];
        }
    }
    for (int i = 1; i <= lb; i++)
        cout << kmp[i] << " ";
    return 0;
}