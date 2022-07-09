#include<bits/stdc++.h>
using	namespace	std;
int	n;
int	num[10],vis[10];
void	dfs(int	steps);
int	main()
{
	while(~scanf("%d",&n))
	{
		memset(vis,0,sizeof(vis));
		dfs(1);
	}
	return	0;
}
void	dfs(int	steps)
{
	if(steps==n+1)
	{
		for(int	i=1;i<=n;i++)
			printf("%d ",num[i]);
		printf("\n");
		return;
	}
	for(int	i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			num[steps]=i;
			vis[i]=1;
			dfs(steps+1);
			vis[i]=0;	
		}		
	}	
}
