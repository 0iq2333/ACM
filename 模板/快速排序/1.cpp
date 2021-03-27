#include <bits/stdc++.h>
#define Swap(x, y) (tmp = x, x = y, y = tmp)
using namespace std;
int a[10005], tmp;
int partition_find(int left, int right)
{
    int i = left;
    int temp = a[right];
    for (int j = left; j < right; j++)
    {
        if (a[j] < temp)
        {
            Swap(a[j], a[i]);
            i++;
        }
    }
    Swap(a[i], a[right]);
    return i;
}
void quick_sort(int left, int right)
{
    if (left < right)
    {
        int m = partition_find(left, right); //划分
        quick_sort(left, m - 1);             //左
        quick_sort(m + 1, right);            //右
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    quick_sort(1, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}