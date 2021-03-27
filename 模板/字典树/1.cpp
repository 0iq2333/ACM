/*
 * @Author: NEFU_马家沟老三
 * @LastEditTime: 2020-09-09 21:58:54
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
int trie[1001][26],tot = 1;
bool End[1001];
void insert(char *str){
    int len = strlen(str),p = 1;
    for(int i  = 0; i < len; i++){
        int ch = str[i] - 'a';
        if(trie[p][ch] == 0) trie[p][ch] = ++tot;
        p = trie[p][ch];
    }
    End[p] = 1;
}
bool search(char* str){
    int len = strlen(str),p = 1;
    for(int i = 0; i < len; i++){
        int ch = str[i] - 'a';
        p = trie[p][ch];
        if(p == 0) return 0;
    }
    return End[p];
}
int main()
{
    
    return 0;
}