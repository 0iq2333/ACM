#include <bits/stdc++.h>
using namespace std;
int dp[205][35];
int path[1005];//记录当前价值的标号
pair<int, int> p[35];
void printf_path(int *path, int s)//逆序路径
{
    while (s)
    {
        cout << path[s] << " ";
        s -= p[path[s]].second;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].first >> p[i].second;
    for (int i = 1; i <= n; i++) //前n个物品
        for (int j = 0; j <= m; j++)
        {
            if (p[i].first > j)
                dp[j][i] = dp[j][i - 1];
            else
            {
                if (dp[j - p[i].first][i - 1] + p[i].second > dp[j][i - 1])
                {
                    dp[j][i] = dp[j - p[i].first][i - 1] + p[i].second;
                    path[dp[j][i]] = i;
                }
                else
                    dp[j][i] = dp[j][i - 1];
            }
        }
    cout << dp[m][n] << endl;
    printf_path(path, dp[m][n]);
    return 0;
}