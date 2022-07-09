#include<bits/stdc++.h>
using	namespace	std;
struct	rice{
	int	v;
	int	c;
	int	n;
}arr[105];
int	dp[105];
int	main()
{
	int	N;
	cin>>N;
	while(N--)
	{
		int	m,n;//含有的资金总数，大米的种类
		cin>>m>>n;
		memset(dp,0,sizeof(dp));
		for(int	i=1;i<=n;i++)
			cin>>arr[i].c>>arr[i].v>>arr[i].n;
		for(int	i=1;i<=n;i++)
		{
			for(int	j=m;j>=arr[i].c;j--)
			{
				for(int	k=1;k<=arr[i].n&&j>=k*arr[i].c;k++)
					dp[j]=max(dp[j],dp[j-k*arr[i].c]+k*arr[i].v);
			}
		}
		cout<<dp[m]<<endl;
	}
	return	0;
}
