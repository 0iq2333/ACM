#include <bits/stdc++.h>
using namespace std;
int type[10] = {0, 1, 5, 10, 25, 50};
int Min[255];
int Min_path[255];
void solve()
{
    for (int i = 0; i < 255; ++i)
        Min[i] = INT_MAX;
    Min[0] = Min_path[0] = 0;
    for (int i = 1; i <= 5; i++)
        for (int j = type[i]; j <= 250; j++)
        {
            if (Min[j] > Min[j - type[i]] + 1)
            {
                Min[j] = Min[j - type[i]] + 1;
                Min_path[j] = type[i];
            }
        }
}
void printf_ans(int *Min_path, int s)
{
    while (s)
    {
        cout << Min_path[s] << " ";
        s -= Min_path[s];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    solve();
    int s;
    cin >> s;
    cout << Min[s] << endl;
    printf_ans(Min_path, s);
    return 0;
}