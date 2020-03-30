//#include<bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define bug printf("*********\n")
#define FIN freopen("input.txt","r",stdin);
#define FON freopen("output.txt","w+",stdout);
#define IO ios::sync_with_stdio(false),cin.tie(0)
#define ls root<<1
#define rs root<<1|1
#define Q(a) cout<<a<<endl

using namespace std;
const int inf = 0x3f3f3f3f;
const ll Inf = 1e18 + 7;
const int maxn = 1e4 + 5;
const int mod = 1e9 + 7;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

ll read()
{
    ll p = 0, sum = 0;
    char ch;
    ch = getchar();
    while (1)
    {
        if (ch == '-' || (ch >= '0' && ch <= '9'))
            break;
        ch = getchar();
    }

    if (ch == '-')
    {
        p = 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        sum = sum * 10 + ch - '0';
        ch = getchar();
    }
    return p ? -sum : sum;
}

struct node
{
    int x, y;
}p[maxn];

bool cmp(const node& a, const node& b)
{
    return a.x < b.x;
}

bool cmp2(const int& a, const int& b)
{
    return p[a].y < p[b].y;
}

double dis(const node& a, const node& b)
{
    double x = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return sqrt(x);
}

int n;

double getMin(int l, int r)
{
    if (l == r)    return inf;
    if (r - l == 1)  return dis(p[r], p[l]);
    if (r - l == 2)
    {
        double d1, d2, d3;
        d1 = dis(p[l], p[l + 1]);
        d2 = dis(p[l], p[r]);
        d3 = dis(p[l + 1], p[r]);
        return min(d1, min(d2, d3));
    }
    int mid = l + r >> 1;
    double dl, dr;
    dl = getMin(l, mid);
    dr = getMin(mid + 1, r);
    double res = min(dl, dr);
    vector<int>vec;
    for (int i = l; i <= mid; ++i)
    {
        if (p[mid + 1].x - p[i].x <= res)  vec.push_back(i);
    }
    for (int i = mid + 1; i <= r; ++i)
    {
        if (p[i].x - p[mid].x <= res)    vec.push_back(i);
    }
    sort(vec.begin(), vec.end(), cmp2);
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = i + 1; j < vec.size(); ++j)
        {
            if (p[vec[j]].y - p[vec[i]].y <= res)
            {
                res = min(res, dis(p[vec[i]], p[vec[j]]));
            }
            else break;
        }
    }
    return res;

}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d %d", &p[i].x, &p[i].y);
    }
    sort(p + 1, p + 1 + n, cmp);
    printf("%.2f\n", getMin(1, n));
}