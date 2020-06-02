//#include<bits/stdc++.h>
#include<time.h>
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
#define pb push_back
#define PI acos(-1.0)

using namespace std;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18 + 7;
const int maxn = 100 + 5;
const ll mod = 1e9 + 7;
const double eps = 1e-6;

inline ll read() {
	bool f = 0;
	ll x = 0; char ch = getchar();
	while (ch < '0' || ch>'9') { if (ch == '-')f = 1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); }
	return f ? -x : x;
}

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}

int n, m, cnt;
int mp[maxn][maxn], vis[maxn], ans;

void init() {
	memset(mp, -1, sizeof mp);
	memset(vis, 0, sizeof vis);
	ans = 0;
}

bool check(int x, int col) {
	for (int i = 1; i <= n; ++i) {
		if (mp[x][i]) {
			if (vis[i] == col) return 0;
		}
	}
	return 1;
}

void dfs(int x) {
	if (x > n) {
		cout << ++ans << " : ";
		for (int i = 1; i <= n; ++i) {
			cout << vis[i] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= m; ++i) {
		vis[x] = i;
		if (check(x, i))	dfs(x + 1);
	}
}

int main() {
	init();//初始化
	cin >> n >> m >> cnt;//输入点数，颜色数，边数
	while (cnt--) {
		int u, v;
		cin >> u >> v;
		mp[u][v] = mp[v][u] = 1;//建立关系
	}
	dfs(1);
	if (!ans) {
		cout << "NO" << endl;
	}
}

