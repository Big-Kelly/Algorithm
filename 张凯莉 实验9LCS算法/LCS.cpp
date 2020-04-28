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
#define pb push_back

using namespace std;
const int inf = 2e9 + 7;
const ll Inf = 1e18 + 7;
const int maxn = 5e3 + 5;
const ll mod = 998244353;

string x, y, ans;
int len1, len2;
int dp[maxn][maxn], del[maxn][maxn];

int main() {
	cin >> x >> y;
	len1 = x.length(), len2 = y.length();
	x = " " + x, y = " " + y;
	for (int i = 0; i <= len1; ++i)	dp[i][0] = 0;
	for (int i = 0; i <= len2; ++i)	dp[0][i] = 0;
	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; ++j) {
			if (x[i] == y[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					del[i][j] = 1;
					dp[i][j] = dp[i - 1][j];
				}
				else {
					del[i][j] = 2;
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
	}
	int i = len1, j = len2;
	ans = "";
	while (i && j) {
		if (!del[i][j]) {
			ans = x[i] + ans;
			i--, j--;
		}
		else if (del[i][j] == 1) {
			i--;
		}
		else {
			j--;
		}
	}
	cout << "LCS³¤¶È:" << dp[len1][len2] << endl;
	cout << "LCS:" << ans << endl;
}