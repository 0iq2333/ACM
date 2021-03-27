/*
 * @Author: NEFU_马家沟老三
 * @LastEditTime: 2020-08-03 10:56:11
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
#define mem(a, b) memset(a, b, sizeof(a))
const double PI = acos(-1.0);
const ll mod = 1e9 + 7;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

const int MAXN = 5;
const int Mod = 1e9+7;
struct Matrix
{
    int m[MAXN][MAXN];
};

Matrix mul(Matrix a,Matrix b){
    Matrix res;
    rep(i,1,MAXN)
        rep(j,1,MAXN)
            rep(k,1,MAXN)
                res.m[i][j] = (res.m[i][j] + a.m[i][k] * b.m[k][j] ) % Mod;
    return res;
}

Matrix fastm(Matrix a,int n){
    Matrix res;
    rep(i,1,MAXN)
        res.m[i][i] = 1;
    while (n)
    {
        if(n&1)
            res = mul(res, a);
        a = mul(a, a);
        n>>=1;
    }
     return res;
}
int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    return 0;
}