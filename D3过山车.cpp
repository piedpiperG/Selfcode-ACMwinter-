#include<bits/stdc++.h>
using	namespace	std;
#define	MAXN	510
int		uN,vN;//男生人数，女生人数 
int		g[MAXN][MAXN];//矩阵对应 
int		linker[MAXN];//女生的对应男生 
bool	used[MAXN];//在当前男生循环中是否已经接触此女生 
bool	dfs(int	u);
int	hungary();
int	main()
{
	int	k;
	while(scanf("%d",&k)==1&&k)
	{
		scanf("%d%d",&uN,&vN);
		memset(g,0,sizeof(g));
		int	u,v;
		while(k--)
		{
			scanf("%d%d",&u,&v);
			g[u][v]=1; 
		}
		printf("%d\n",hungary());
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
	for(int	v=1;v<=vN;v++)
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
