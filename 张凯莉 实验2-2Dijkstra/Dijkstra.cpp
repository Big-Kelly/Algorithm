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
#define pll pair<ll,ll>
#define pii pair<int,int>
#define bug printf("*********\n")
#define FIN freopen("input.txt","r",stdin);
#define FON freopen("output.txt","w+",stdout);
#define IO ios::sync_with_stdio(false),cin.tie(0)
#define ls rt<<1
#define rs rt<<1|1
#define pb push_back
#define Q(a) cout<<a<<endl

using namespace std;
const int inf = 2e9 + 7;
const ll Inf = 1e18 + 7;
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;

int gcd(int a, int b)
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

struct Dijkstra
{
	int n;
	int dis[maxn], vis[maxn];
	int mp[maxn][maxn];

	void dijkstra(int s)
	{
		memset(dis, inf, sizeof dis);
		memset(vis, 0, sizeof vis);
		dis[s] = 0;
		for (int i = 1; i <= n; ++i)
		{
			int min_p = -1, minn = inf;
			for (int j = 1; j <= n; ++j)
			{
				if (!vis[j] && dis[j] < minn)
				{
					min_p = j;
					minn = dis[j];
				}
			}
			for (int j = 1; j <= n; ++j)
			{
				if (dis[j] > dis[min_p] + mp[min_p][j])
				{
					dis[j] = dis[min_p] + mp[min_p][j];
				}
			}
			vis[min_p] = 1;
		}
	}
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	Dijkstra d;
	d.n = n;
	memset(d.mp, inf, sizeof d.mp);
	while (m--)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		d.mp[u][v] = d.mp[v][u] = w;
	}
	d.dijkstra(1);
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int ask;
		scanf("%d", &ask);
		printf("%d\n", d.dis[ask]);
	}
}
