/*
 * @Author: NEFU_马家沟老三
 * @LastEditTime: 2020-11-16 20:06:23
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
const int MAXN = 100050,MAXM = 100050,inf = 0x3f3f3f3f;
struct node{
    int to,next,cap,flow;
}e[MAXM<<1];
int tot,head[MAXN],gap[MAXN],cur[MAXN],dep[MAXN];
void init(){
    tot = 0;
    mem(head,-1);
}

void add(int u,int v,int w,int rw){
    e[tot].to = v,e[tot].cap = w,e[tot].flow = 0,e[tot].next = head[u],head[u] = tot++;
    e[tot].to = u,e[tot].cap = rw,e[tot].flow = 0,e[tot].next = head[v],head[v] = tot++;
}

int q[MAXN];

void bfs(int s,int t){
    mem(dep,-1);
    mem(gap,0);
    gap[0] = 1;
    int front = 0,rear = 0;
    dep[t] = 0;
    q[rear++] = t;
    while(front != rear){
        int u = q[front++];
        for(int i = head[u]; ~i; i = e[i].next){
            int v = e[i].to;
            if(dep[v] != -1) continue;
            q[rear++] = v;
            dep[v] = dep[u] + 1;
            gap[dep[v]]++;
        }
    }
}
int sta[MAXN];
int sap(int s,int t,int N){
    bfs(s,t);
    memcpy(cur,head,sizeof(head));
    int top = 0;
    int u = s;
    int ans = 0;
    while(dep[s] < N){
        if(u == t){
            int Min = inf;
            int inser;
            for(int i = 0; i < top; i++){
                if(Min > e[sta[i]].cap - e[sta[i]].flow){
                    Min = e[sta[i]].cap - e[sta[i]].flow;
                    inser = i;
                }
            }
            for(int i = 0; i < top; i++){
                e[sta[i]].flow += Min;
                e[sta[i]^1].flow -= Min;
            }
            ans += Min;
            top = inser;
            u = e[sta[top]^1].to;
            continue;
        }
        bool flag = 0;
        int v;
        for(int i = cur[u]; ~i ; i = e[i].next){
            v = e[i].to;
            if(e[i].cap - e[i].flow && dep[v] + 1 == dep[u]){
                flag = 1;
                cur[u] = i;
                break;
            }
        }
        if(flag){
            sta[top++] = cur[u];
            u = v;
            continue;
        }
        int Min = N;
        for(int i = head[u]; ~i ; i = e[i].next){
            if(e[i].cap - e[i].flow && dep[e[i].to] < Min){
                Min = dep[e[i].to];
                cur[u] = i;
            }
        }
        gap[dep[u]]--;
        if(!gap[dep[u]]) return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if(u != s) u = e[sta[--top]^1].to;
    }
    return ans;
}

int main()
{

    return 0;
}