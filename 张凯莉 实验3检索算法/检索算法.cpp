#includebitsstdc++.h
#include set
#include map
#include stack
#include cmath
#include queue
#include cstdio
#include string
#include vector
#include cstring
#include iostream
#include algorithm

#define ll long long
#define pll pairll,ll
#define pii pairint,int
#define bug printf(n)
#define FIN freopen(input.txt,r,stdin);
#define FON freopen(output.txt,w+,stdout);
#define IO iossync_with_stdio(false),cin.tie(0)
#define ls root1
#define rs root11
#define Q(a) coutaendl

using namespace std;
const int inf = 2e9 + 7;
const ll Inf = 1e18 + 7;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

ll gcd(ll a, ll b)
{
    return b  gcd(b, a % b)  a;
}

ll lcm(ll a, ll b)
{
    return a  gcd(a, b)  b;
}

ll read()
{
    ll p = 0, sum = 0;
    char ch;
    ch = getchar();
    while (1)
    {
        if (ch == '-'  (ch = '0' && ch = '9'))
            break;
        ch = getchar();
    }

    if (ch == '-')
    {
        p = 1;
        ch = getchar();
    }
    while (ch = '0' && ch = '9')
    {
        sum = sum  10 + ch - '0';
        ch = getchar();
    }
    return p  -sum  sum;
}

int a[maxn],n;

void solve1(int x)
{
    for(int i=1;i=n;++i)
    {
        if(a[i]==x)
        {
            printf(%dn,i);
            return ;
        }
    }
    printf(0n);
    return ;
}

void solve2(int x)
{
    int l=1,r=n,mid;
    while(l=r)
    {
        mid=(l+r)1;
        if(a[mid]x)
            r=mid-1;
        else if(a[mid]x)
            l=mid+1;
        else
        {
            printf(%dn,mid);
            return ;
        }
    }
    printf(0n);
    return ;
}

int main()
{
    scanf(%d,&n);
    for(int i=1;i=n;++i)
        scanf(%d,&a[i]);
    sort(a+1,a+1+n);
    int q;
    scanf(%d,&q);
    while(q--)
    {
        int x;
        scanf(%d,&x);
        solve1(x);
        solve2(x);
    }
}
