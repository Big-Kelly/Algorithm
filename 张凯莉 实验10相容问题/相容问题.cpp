#include<bits/stdc++.h>
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
#define PLL pair<ll,ll>
#define PII pair<int,int>
#define bug printf("*********\n")
#define FIN freopen("input.txt","r",stdin);
#define FON freopen("output.txt","w+",stdout);
#define IO ios::sync_with_stdio(false),cin.tie(0)
#define ls root<<1
#define rs root<<1|1

using namespace std;
const int inf = 0x3f3f3f3f;
const ll Inf = 1e14 + 7;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

struct node
{
    int s, e;
}p[maxn];

bool cmp(const node& a, const node& b)
{
    return a.e < b.e;
}

int main()
{
    int n;
    while (~scanf("%d", &n), n)
    {
        for (int i = 1; i <= n; ++i)    scanf("%d %d", &p[i].s, &p[i].e);
        sort(p + 1, p + 1 + n, cmp);
        int ans = 0, tmp = -1;
        for (int i = 1; i <= n; ++i)
        {
            if (p[i].s >= tmp)    ans++, tmp = p[i].e;
        }
        printf("%d\n", ans);
    }
}
