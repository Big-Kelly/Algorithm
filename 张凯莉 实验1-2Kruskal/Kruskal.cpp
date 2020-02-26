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
const int inf=0x3f3f3f3f;
const ll Inf=1e18+7;
const int maxn=1e4+5;
const int mod=1e9+7;

struct Kruskal
{
	//结构体存边
	struct edge
	{
		int u,v,w;
	}p[maxn];

	int tot;

	void add(int u,int v,int w)
	{
		p[++tot].v=v;
		p[tot].w=w;
		p[tot].u=u;
	}

	int fa[maxn],n;//并查集。

    void init()//初始化
    {
        tot=0;
        for(int i=1;i<=n;++i)	fa[i]=i;
    }

	//优先队列处理最短边
	struct cmp
	{
		bool operator()(const edge &a,const edge &b)
		{
			return a.w>b.w;
		}
	};
	priority_queue<edge,vector<edge>,cmp > q;

	//并查集
	int find(int x)
	{
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}

	void ba(int x,int y)
	{
		int px=find(x),py=find(y);
		fa[px]=py;
	}

	int ans=0,cnt=0;

	int kruskal()
	{
		for(int i=1;i<=tot;++i)	q.push(p[i]);//把所有的边放入优先队列
		while(cnt!=n-1)
		{
			edge x=q.top();
			q.pop();
			while(find(x.u)==find(x.v))	x=q.top(),q.pop();
			ba(x.u,x.v);
			cnt++;
			ans+=x.w;
		}
		return ans;
	}
};

int n,m;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	Kruskal k;
	scanf("%d %d",&n,&m);
	k.n=n;
	k.init();
	while(m--)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		k.add(u,v,w);
	}
	printf("%d\n",k.kruskal());
}
