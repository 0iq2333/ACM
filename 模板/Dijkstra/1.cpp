#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, a, n) for (int i = n; i >= a; i--)
const double PI = acos(-1.0);
const int Inf = 0x3f3f3f;
int Map[1005][1005];      //c存入邻接矩阵
int vis[1005], dis[1005]; //vis是否走过，dis从起点到i的距离
int n, m;                 //n个点，m条边
void Init()
{
    memset(Map, Inf, sizeof(Map));
    for (int i = 1; i <= n; i++)
    {
        Map[i][i] = 0;
    }
}

void Getmap()
{
    int u, v, w;
    for (int t = 1; t <= m; t++)
    {
        //cin >> u >> v >> w; //u->v间的距离w
        scanf("%d%d%d",&u,&v,&w);
        if (Map[u][v] > w)  //建立邻接矩阵
        {
            Map[u][v] = w;
            Map[v][u] = w;
        }
    }
}

void Dijkstra(int u)
{
    memset(vis, 0, sizeof(vis));
    for (int t = 1; t <= n; t++) //将u当做起点，从u到t的距离
    {
        dis[t] = Map[u][t];
    }
    vis[u] = 1;
    for (int t = 1; t < n; t++)
    {
        int minn = Inf, temp;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && dis[i] < minn) //从u->i 未走过，并且当前距离比较小，更新权值
            {
                minn = dis[i];
                temp = i;
            }
        } //temp为当前的最优解
        vis[temp] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (Map[temp][i] + dis[temp] < dis[i]) //dis[temp]=dis[u->temp],
            {                                      //temp为中间点，看是否要更新
                dis[i] = Map[temp][i] + dis[temp];
            }
        }
    }
}
int main()
{
    Init(); //Map的初始化
    //cin >> n >> m; //n个点，m条边
    scanf("%d%d", &n, &m);
    Getmap();    //输入地图
    Dijkstra(n); //迪杰斯特拉算法
    printf("%d",dis[1]);
    return 0;
}