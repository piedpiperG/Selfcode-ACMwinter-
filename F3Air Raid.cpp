#include<bits/stdc++.h>
using	namespace	std;
#define	MAXN	510
int		uN,vN;//城镇数，街道数 
int		g[MAXN][MAXN];//矩阵对应 
int		linker[MAXN];//城镇对应的路 
bool	used[MAXN];//在当前循环是否已经被占用 
bool	dfs(int	u);
int	hungary();
int	main()
{
	int	N;
	cin>>N; 
	while(N--)
	{
		scanf("%d%d",&uN,&vN);//城镇数量，街道数量 
		memset(g,0,sizeof(g));
		int	u,v;
		while(vN--)//构建图 
		{
			scanf("%d%d",&u,&v);
			g[u][v]=1; 
		}
		printf("%d\n",uN-hungary());
	}
	return	0;
}
int	hungary()
{
	int	res=0;
	memset(linker,-1,sizeof(linker));

	for(int	i=1;i<=uN;i++)
	{
		memset(used,false,sizeof(used));
		if(dfs(i))
			res++;
	}
	return	res;
}
bool	dfs(int	u)
{
	for(int	v=1;v<=uN;v++)
		if(g[u][v]&&!used[v])
		{
			used[v]=true;
			if(linker[v]==-1||dfs(linker[v]))
			{
				linker[v]=u;
				return	true;
			}
		}
	return	false;
}
