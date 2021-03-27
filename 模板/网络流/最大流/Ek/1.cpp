/*
 * @Author: NEFU_马家沟老三
 * @LastEditTime: 2020-11-07 11:54:12
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
const int inf = 1 << 29 , N = 2010, M = 20010;
struct edge{
    int v,w,next;
}e[M];
int head[N],vis[N],incf[N],pre[N],tot;

void add(int u,int v,int w){
    e[++tot].v = v,e[tot].w = w,e[tot].next = head[u], head[u] = tot;
    e[++tot].v = u,e[tot].w = 0,e[tot].next = head[v], head[v] = tot;
}

bool bfs(int s,int t){//单源增广路
    mem(vis,0);
    queue<int>q;
    q.push(s); vis[s] = 1;
    incf[s] = inf;//增光路上各边的最小剩余容量
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = head[u]; ~i ; i = e[i].next){
            int v = e[i].v, w = e[i].w;
            if(w){
                if(vis[v]) continue;
                incf[v] = min(incf[u],w);//更新增光路上的边最小的容量
                pre[v] = i;//记录前驱，便于找到最长路的实际方案
                q.push(v),vis[v] = 1;
                if(v == t) return 1;
            }
        }
    }
    return 0;
}

int update(int s,int t){
    int u = t;
    while(u != s){
        int i = pre[u];
        e[i].w -= incf[t];
        e[i^1].w += incf[t];
        u = e[i^1].v;   
    }
    return incf[t];
}
int main()
{
    mem(head,-1);
    tot = 1;
    int maxflow = 0,s,t;
    while(bfs(s,t)) maxflow += update(s,t);
    return 0;
}