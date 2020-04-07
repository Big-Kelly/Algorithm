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
#define Q(a) cout<<a<<endl

using namespace std;
const int inf = 2e9 + 7;
const ll Inf = 1e18 + 7;
const int maxn = 1e6 + 5;
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

void insertsort(int a[], int l, int r)//从小到大排序
{
	int i, j, key;
	for (i = l + 1; i <= r; ++i)
	{
		key = a[i];
		for (j = i - 1; j >= l && key < a[j]; --j)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

int partition(int a[], int l, int r, int pivot)
{
	int x, i = l - 1, j;
	for (j = l; j < r; ++j)
	{
		if (a[j] == pivot)	swap(a[j], a[r]);
	}
	x = a[r];
	for (j = l; j < r; ++j)
	{
		if (a[j] <= x)
		{
			++i;
			swap(a[i], a[j]);
		}
	}
	swap(a[r], a[i + 1]);
	return i + 1;
}

int select(int a[], int l, int r, int k)
{
	int group, i, left, right, mid;
	int pivot, p, lnum;
	if (r - l + 1 <= 5)
	{
		insertsort(a, l, r);
		return a[l + k - 1];
	}
	group = (r - l + 1 + 5) / 5;
	for (i = 0; i < group; ++i)
	{
		left = l + 5 * i;
		right = (l + 5 * i + 4) > r ? r : l + 5 * i + 4;
		mid = (left + right) / 2;
		insertsort(a, left, right);
		swap(a[l + i], a[mid]);
	}
	pivot = select(a, l, l + group - 1, (group + 1) / 2);
	p = partition(a, l, r, pivot);
	lnum = p - l;
	if (k == lnum + 1)
		return a[p];
	else if (k <= lnum)
		return select(a, l, p - 1, k);
	else
		return select(a, p + 1, r, k - lnum - 1);
}

int a[maxn];
int n, k;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i)	scanf("%d", &a[i]);
	printf("%d\n", select(a, 1, n, k));
}