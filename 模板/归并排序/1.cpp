#include <bits/stdc++.h>
using namespace std;
void merge(int *num, int L, int M, int R)
{
    //int L_size = M, R_size = R - M;
    int k = L - 1;
    queue<int> L_num, R_num;
    for (int i = L; i <= M; i++)
        L_num.push(num[i]);
    for (int i = M + 1; i <= R; i++)
        R_num.push(num[i]);
    while (!L_num.empty() && !R_num.empty())
    {
        if (L_num.front() <= R_num.front())
        {
            num[++k] = L_num.front();
            L_num.pop();
        }
        else
        {
            num[++k] = R_num.front();
            R_num.pop();
        }
    }
    while (!L_num.empty())
    {
        num[++k] = L_num.front();
        L_num.pop();
    }
    while (!R_num.empty())
    {
        num[++k] = R_num.front();
        R_num.pop();
    }
}
void merge_sort(int *num, int lift, int right)
{
    if (lift == right)
        return;
    else
    {
        int mid = lift + (right - lift) / 2;
        merge_sort(num, lift, mid);
        merge_sort(num, mid + 1, right);
        merge(num, lift, mid, right);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int num[105];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    merge_sort(num, 1, n);
    for (int i = 1; i <= n; i++)
        cout << num[i] << " ";
    return 0;
}