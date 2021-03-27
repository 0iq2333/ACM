#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <bitset>
#include <cstdlib>
#include <cmath>
#include <set>
#include <list>
#include <deque>
#include <map>
#include <queue>
#include <iomanip>
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
const int N = 50050;
struct node{
    int to,w,net;
}e[N << 1];
int n,m,cnt,t,head[N];
int f[N][25],d[N],dis[N];
void init(){
    cnt = 0;
    rep(i,0,n+5){
        head[i] = 0;
        d[i] = 0;
        dis[i] = 0;
    }
}
void add(int u,int v,int w){
    e[++cnt].to = v,e[cnt].w = w,e[cnt].net = head[u],head[u] = cnt;
}
queue<int>que;
void bfs(){
    que.push(1),d[1] = 1;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int i = head[u]; i ; i = e[i].net){
            int v = e[i].to,w = e[i].w;
            if(d[v]) continue;
            d[v] = d[u] + 1;
            dis[v] = dis[u] + w;
            f[v][0] = u;
            for(int j = 1; j <= 22; j++){
                f[v][j] = f[f[v][j-1]][j-1];
            }
            que.push(v);
        }
    }
}
int query(int u,int v){
    if(d[u] > d[v]) swap(u,v);
    for(int i = 22 ; i >= 0 ; i--){//大的向小的找,找到最u的那一层
        if( d[f[v][i]] >= d[u]) v = f[v][i];
    }
    if(u == v) return u;
    for(int i = 22 ; i >= 0 ; i--){
        if( f[u][i] != f[v][i]){
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}
int main()
{
    //IOS
    //cin >> t;
    scanf("%d",&t);
    while(t--){
        init();
        //cin >> n >> m;
        scanf("%d%d",&n,&m);
        rep(i,1,n-1){
            int u,v,w;
            //cin >> u >> v >> w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        bfs();
        while(m--){
            int u,v;
            //cin >> u >> v;
            scanf("%d%d",&u,&v);
            int lca = query(u,v);
            int ans = dis[u] + dis[v] - 2 * dis[lca];
            cout << ans << "\n";
        }
    }
    return 0;
}