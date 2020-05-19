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

int n, x;
priority_queue<int, vector<int>, greater<int> >q;

int main() {
	while (cin >> n) {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> x;
			q.push(x);
		}
		while (q.size() > 1) {
			x = q.top();
			q.pop();
			x += q.top();
			q.pop();
			q.push(x);
		}
		if (!q.empty()) {
			ans = q.top();
			q.pop();
		}
		cout << ans << endl;
	}
}