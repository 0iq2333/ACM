#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
struct node
{
    string value; //结点值
    node *l, *r;  //指向左右结点
    node()        //初始化
    {
        l = r = NULL;
    }
};
void pre_order(node *root) //先序遍历
{
    if (root != NULL) //根据题干来添加判断，并进行输出和递归
    {
        cout << root->value << endl; //输出结点值
        pre_order(root->l);          //递归左子树
        pre_order(root->r);          //递归右子树
    }
}
void in_order(node *root) //中序遍历
{
    if (root != NULL) //根据题干来添加判断，并进行输出和递归
    {
        in_order(root->l);           //递归左子树
        cout << root->value << endl; //输出结点值
        in_order(root->r);           //递归右子树
    }
}
void post_order(node *root) //后序遍历
{
    if (root != NULL) //根据题干来添加判断，并进行输出和递归
    {
        post_order(root->l);         //递归左子树
        post_order(root->r);         //递归右子树
        cout << root->value << endl; //输出结点值
    }
}
void create_tree(node *&root) //二叉树的建立
{
    char ch;
    cin >> ch; //输入先序遍历
    if (ch != '#')
    {
        root = new node;      //动态申请内存，结束后要释放
        root->value = ch;     //读入
        create_tree(root->l); //建立左子树
        create_tree(root->r); //建立右子树
    }
}
node *find_node(node *&root, string aim) //若查找到返回其指针
{
    node *p;
    if (root == NULL) //空树
        return NULL;
    else if (root->value == aim) //找到该值
        return root;
    else //暂时未找到，递归进行查找
    {
        p = find_node(root->l, aim); //查找左树
        if (p != NULL)
            return p;
        else
            return find_node(root->r, aim); //查找右树
    }
}
int high_node(node *root) //二叉树的高度
{
    int l_high, r_high;
    if (root == NULL) //空树
        return 0;
    else
    {
        l_high = high_node(root->l);
        r_high = high_node(root->r);
        return max(l_high + 1, r_high + 1);
    }
}
void remove_tree(node *root) //二叉树的释放空间
{
    if (root == NULL)
        return;
    remove_tree(root->l);
    remove_tree(root->r);
    delete root;
}
int main()
{
    ios::sync_with_stdio(false);

    return 0;
}