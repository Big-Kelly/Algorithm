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

struct Prime
{
	//链式前向星存边
	struct edge
	{
		int v,w,next;
	}p[maxn];

	int tot,head[maxn];

	void add(int u,int v,int w)
	{
		p[tot].v=v,p[tot].w=w,p[tot].next=head[u];
		head[u]=tot++;
	}

	int vis[maxn],n;//标记点是否在点集中。

    void init()//初始化
    {
        tot=0;
        memset(head,-1,sizeof head);
        memset(vis,0,sizeof vis);
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

	int ans=0;//最小生成树的权值和
	int cnt=0;//点集中点的个数

	int prime()
	{
		//在优先队列中放入第一个点所连的边
		vis[1]=1,cnt++;
		for(int i=head[1];i!=-1;i=p[i].next)	q.push(p[i]);
		//还有点没在点集中
		while(cnt!=n)
		{
			edge e=q.top();q.pop();
			//如果相连的点已经在点集中了
			while(vis[e.v]==1)	e=q.top(),q.pop();
			vis[e.v]=1,cnt++,ans+=e.w;//把该点放入点集,更新答案
			for(int i=head[e.v];i!=-1;i=p[i].next)
				if(!vis[p[i].v])	q.push(p[i]);//把该点所连的边放入优先队列
		}
		return ans;
	}
};

int n,m;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	Prime p;
	scanf("%d %d",&n,&m);
	p.n=n;
	p.init();
	while(m--)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		p.add(u,v,w);
		p.add(v,u,w);
	}
	printf("%d\n",p.prime());
}
