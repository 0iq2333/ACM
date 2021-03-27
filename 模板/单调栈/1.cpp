/*
 * @Author: NEFU_马家沟老三
 * @LastEditTime: 2020-09-05 10:16:46
 * @CSDN blog: https://blog.csdn.net/acm_durante
 * @E-mail: 1055323152@qq.com
 * @ProbTitle: 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define lowbit(x) ((x) & -(x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define mem(a, b) memset(a, b, sizeof(a))
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double PI = acos(-1.0);
const int N = 3e6+5;
int a[N],cnt = 0,b[N];
int ans[N];
int main()
{
    int n;
    scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n){
        int pos = b[cnt];
        if(cnt == 0 || a[pos] > a[i]) b[++cnt] = i;
        else{
            while (cnt && a[ b[cnt] ] < a[i] )
            {
                ans[ b[cnt] ] = i;
                cnt--;
            }
            b[++cnt] = i;
        }
    }
    rep(i,1,n) printf("%d ",ans[i]);
    return 0;
}