#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
#define lowbit(x) ((x) & -(x))
#define lson p << 1 , l, mid 
#define rson p << 1 | 1, mid + 1, r
#define mem(a, b) memset(a, b, sizeof(a))
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double PI = acos(-1.0);
const int N = 1e5 +50;
struct SegmentTree{
    int l,r;
    ll sum,add;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add
}tree[N << 2];
int a[N];
void build(int p,int l,int r){
    l(p) = l;
    r(p) = r;
    if(l == r){
        sum(p) = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    sum(p) = sum(p<<1) + sum(p<<1|1);
}
void spread(int p){
    if(add(p)){
        sum(p<<1) += add(p) * (r(p<<1) - l(p<<1) + 1);
        sum(p<<1|1) += add(p) * (r(p<<1|1) - l(p<<1|1) + 1);
        add(p<<1) += add(p);
        add(p<<1|1) += add(p);
        add(p) = 0;
    }
}
void change(int p,int l,int r,int d){
    if(l <= l(p) && r >= r(p)){
        sum(p) += (ll)d * (r(p) - l(p) + 1) ;
        add(p) += d;
        return;
    }
    spread(p);
    int mid = l(p) + r(p) >> 1;
    if(l <= mid) change(p<<1,l,r,d);
    if(r > mid) change(p<<1|1,l,r,d);
    sum(p) = sum(p<<1) + sum(p<<1|1);
}
ll ask(int p,int l,int r){
    if(l <= l(p) && r(p) <= r){
        return sum(p);
    }
    ll res = 0;
    spread(p);
    int mid = l(p) + r(p) >> 1;
    if(l <= mid) res += ask(p<<1,l,r);
    if(mid > r) res += ask(p<<1|1,l,r);
    return res;
}
int main()
{
    IOS
    return 0;
}
