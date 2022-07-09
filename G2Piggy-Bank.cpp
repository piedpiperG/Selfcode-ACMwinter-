#include<bits/stdc++.h>
using	namespace	std;
#define	INFI	0x3f3f3f3f
#define	SIZE	10005
struct	coin{
	int	v;//价值 
	int	c;//所耗体积 
}arr[600];
int	mini(int	a,int	b)
{
	return	a<=b?a:b;
}
int	dp[SIZE];
int	main()
{
	int	N;
	cin>>N;
	while(N--)
	{
		int	E,F;
		scanf("%d%d",&E,&F);
		//初始化dp数组 
		memset(dp,0,sizeof(dp));
		int	m=F-E;//所能承受体积
		for(int	i=1;i<=m;i++)
			dp[i]=INFI; 
		int	n;
		cin>>n;
		for(int	i=1;i<=n;i++)
			cin>>arr[i].v>>arr[i].c;															
		for(int	i=1;i<=n;i++)
			for(int	j=arr[i].c;j<=m;j++)
				dp[j]=mini(dp[j],dp[j-arr[i].c]+arr[i].v);
		if(dp[m]<INFI) 
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[m]);
		else 
			printf("This is impossible.%d\n",dp[m]);
	}
}
