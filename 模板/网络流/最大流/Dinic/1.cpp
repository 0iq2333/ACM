/*
 * @Author: NEFU_马家沟老三
 * @LastEditTime: 2020-11-06 20:48:09
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
const int inf = 1 << 29, N = 50010, M = 300010;
struct edge{
    int v,w,next;
}e[M];
int head[N],d[N],now[N];//now 当前弧优化
int n,m,s,t,tot,maxflow;
queue<int>q;

void add(int u,int v,int w){
    e[++tot].v = v, e[tot].w = w, e[tot].next = head[u], head[u] = tot;
    e[++tot].v = u, e[tot].w = 0, e[tot].next = head[v], head[v] = tot;
}
bool bfs(){//广搜构造分层图
    mem(d,0);
    while(q.size()) q.pop();
    q.push(s);
    d[s] = 1;
    now[s] = head[s];
    while(q.size()){
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = e[i].next){
            int v = e[i].v, w = e[i].w;
            if(d[v] == 0 && w){//残量不为0，并且当前为分配深度
                q.push(v);
                now[v] = head[v];
                d[v] = d[u] + 1;//下一层
                if(v == t) return 1;
            }
        }
    }
    return 0;
}

int dfs(int u,int flow){
    if(u == t) return flow;
    int rest = flow, k, i;//rest剩余的流
    for(i = now[u]; ~i && rest ; i = e[i].next){
        int v = e[i].v , w = e[i].w; 
        if(w && d[v] == d[u] + 1){//不是权值为0的边，并且v 是 u 的下一层
            k = dfs(v,min(rest ,w));
            if(!k) d[v] = 0;//从v出发的流是0，则可以进行剪枝
            e[i].w -= k;
            e[i^1].w += k;
            rest -= k;  
        }
    }
    now[u] = i;//当前弧优化,榨取完成，避免从u再一次走到i
    return flow - rest;//已经传送出去的流量,下一步继续传送
}
int dinic(int s,int t){
    int res = 0,flow = 0;
    maxflow = 0;
    while(bfs()){
        while(flow = dfs(s,inf)) res += flow;
    }
    return res;
}
int main()
{
    tot = 1;
    mem(head,-1);
    return 0;
}