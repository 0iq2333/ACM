/*
 * @Author: NEFU_马家沟老三
 * @LastEditTime: 2020-08-26 23:20:25
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
const ll mod = 1e9 + 7;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
template<class T>inline void read(T &res)
{
char c;T flag=1;
while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
}
const int N = 1e5+5;
int a[N];
int dp[N][25];
void ST_perwork(int l,int r){
    for(int i = 1;i <= r; i++) 
        dp[i][0] = a[i];
    int t = log(r) / log(2);
    for(int j = 1; j <= t; j++)//分成的块
        for(int i = 1; i <= r - ( 1<<(j) ) + 1;i++){
            dp[i][j] = max(dp[i][j-1] , dp[i + (1<<(j - 1))][j - 1] ) ;
        }//枚举左端点
}
int ST_query(int l,int r){
    int cnt = log(r - l + 1) / log(2);
    return max(dp[l][cnt],dp[r - ( 1 << (cnt)) + 1][cnt]);
}
int main()
{
    int n,m;
    read(n);read(m);
    rep(i,1,n) read(a[i]);
    ST_perwork(1,n);
    while (m--)
    {
        int l,r;
        read(l),read(r);
        printf("%d\n",ST_query(l,r));
    }
    return 0;
}