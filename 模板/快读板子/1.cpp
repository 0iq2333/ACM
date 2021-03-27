/*
 * @Author: NEFU_马家沟老三
 * @LastEditTime: 2020-08-05 21:15:02
 * @CSDN blog: https://blog.csdn.net/acm_durante
 * @E-mail: 1055323152@qq.com
 * @ProbTitle: 
 */ 
inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<1) + (x<<3) + (ch^48);
        ch = getchar();
    }
    return x * f;
}

void write(int x)//输出流
{
    if (x<0) {putchar('-');x=-x;}
    if (!x) {putchar(48);return;}
    if (!(x/10)){putchar(x%10+48);return;}
    write(x/10);putchar(x%10+48);
}


template<class T>inline void read(T &res)
{
char c;T flag=1;
while((c=getchar())<'0'||c>'9')if(c=='-')flag=-1;res=c-'0';
while((c=getchar())>='0'&&c<='9')res=res*10+c-'0';res*=flag;
}