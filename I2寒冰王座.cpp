#include<bits/stdc++.h>
using	namespace	std;
int	dp[100000];
int	main()
{
	int	arr[4]={0,150,200,350};
	int	N;
	cin>>N;
	while(N--)
	{
		int	n;
		cin>>n;
		memset(dp,0,sizeof(dp));
		for(int	i=1;i<=3;i++)
			for(int	j=arr[i];j<=n;j++)
				dp[j]=max(dp[j],dp[j-arr[i]]+arr[i]);
		cout<<n-dp[n]<<endl;
	}
}
