/*
 * @Author: NEFU_马家沟老三
 * @LastEditTime: 2020-11-07 12:35:24
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
const int MAXN = 10000, MAXM = 100000, inf = 0x3f3f3f3f;
struct edge{
    int v,next,cap,flow,cost;
}e[MAXM];
int head[MAXN],tot,pre[MAXN],dis[MAXN];
bool vis[MAXN];
int N;//节点总个数,编号从0 - N - 1
void init(int n){
    N = n;
    tot = 1;
    mem(head,-1);
}

void add(int u,int v,int cap,int cost){
    e[++tot].v = v, e[tot].cap = cap, e[tot].cost = cost, e[tot].flow = 0, e[tot].next = head[u], head[u] = tot;
    e[++tot].v = u, e[tot].cap = 0, e[tot].cost = -cost, e[tot].flow = 0, e[tot].next = head[v], head[v] = tot;
}

bool spfa(int s,int t){
    queue<int>q;
    rep(i,0,N-1){//初始化
        dis[i] = inf;
        vis[i] = 0;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for(int i = head[i]; ~i ; i = e[i].next){
            int v = e[i].v;
            if(e[i].cap > e[i].flow && dis[v] > dis[u] + e[i].cost){
                dis[v] = dis[u] + e[i].cost;
                pre[v] = i;
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                } 
            }
        }
    }
    if(pre[t] == -1) return 0;
    else return 1;
}

int minCostMaxflow(int s,int t,int &cost){
    int flow = 0;
    cost = 0;    
    while(spfa(s,t)){
        int Min = inf;
        for(int i = pre[t]; ~i; i = pre[e[i^1].v]){
            if(Min > e[i].cap - e[i].flow)
                Min = e[i].cap - e[i].flow;
        }
        for(int i = pre[t]; ~i; i = pre[e[i^1].v]){
            e[i].flow += Min;
            e[i^1].flow -= Min;
            cost += e[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}
int main()
{
    
    return 0;
}