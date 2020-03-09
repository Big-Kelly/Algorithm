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
#define ls root<<1
#define rs root<<1|1
#define pk push_back
#define Q(a) cout<<a<<endl

using namespace std;
const int inf = 2e9 + 7;
const ll Inf = 1e18 + 7;
const int maxn = 500 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-7;

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

struct Floyd
{
	int n;
	int mp[maxn][maxn];

	void init()
	{
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
			{
				if (i == j)	mp[i][j] = 0;
				else mp[i][j] = inf;
			}
	}
	void floyd()
	{
		for (int k = 1; k <= n; ++k)
		{
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= n; ++j)
				{
					mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
				}
			}
		}
	}
};

int main()
{
	Floyd f;
	int n, m;
	scanf("%d %d", &n, &m);
	f.n = n;
	f.init();
	while (m--)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		f.mp[u][v] = f.mp[v][u] = w;
	}
	f.floyd();
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		cout << f.mp[u][v] << endl;
	}
}