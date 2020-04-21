#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf = 2e9 + 7;
const ll Inf = 1e18 + 7;
const int maxn = 3e3 + 5;
const int mod = 1e9 + 7;

int f[maxn][maxn], s[maxn][maxn];
int p[maxn];
int n;

int main() {
	scanf("%d", &n);
	for (i = 0; i <= n; ++i)	scanf("%d", &p[i]), f[i][i] = 0;
	for (int len = 2; len <= n; ++len) {
		for (int i = 1; i + len - 1 <= n; ++i) {
			int j = i + len - 1;
			f[i][j] = inf;
			s[i][j] = 0;
			for (int k = i; k < j; ++k) {
				int res = f[i][k] + f[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (res < f[i][j]) {
					f[i][j] = res;
					s[i][j] = k;
				}
			}
		}
	}
	printf("%d\n", f[1][n]);
}