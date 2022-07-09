#include<bits/stdc++.h>
using	namespace	std;
struct	food{
	int	v;
	int	c;
}arr[105];
int	dp[100005];
int	main()
{
	int	n;
	while(~scanf("%d",&n))	
	{
		int	m;
		memset(dp,0,sizeof(dp));
		for(int	i=1;i<=n;i++)
			scanf("%d%d",&arr[i].v,&arr[i].c);     
		scanf("%d",&m);
		for(int	i=1;i<=n;i++)
			for(int	j=arr[i].c;j<=m;j++)
				dp[j]=max(dp[j],dp[j-arr[i].c]+arr[i].v);
		printf("%d\n",dp[m]);
	}
}
