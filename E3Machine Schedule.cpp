#include<bits/stdc++.h>
using	namespace	std;
#define	MAXN	510
int		uN,vN;
int		g[MAXN][MAXN];
int		linker[MAXN];
bool	used[MAXN];
bool	dfs(int	u);
int	hungary()
{
	int	res=0;
	memset(linker,-1,sizeof(linker));

	for(int	i=0;i<uN;i++)
	{
		memset(used,false,sizeof(used));
		if(dfs(i))
			res++;
	}
	return	res;
}
int	main()
{
	int	k;
	while(scanf("%d",&uN)==1&&uN)
	{
		scanf("%d%d",&vN,&k);
		memset(g,0,sizeof(g));
		int	id,u,v;
		while(k--)
		{
			scanf("%d%d%d",&id,&u,&v);
			if(u!=0&&v!=0)
				g[u][v]=1; 
		}
		printf("%d\n",hungary());
	}
	return	0;
}
bool	dfs(int	u)
{
	for(int	v=0;v<vN;v++)
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
