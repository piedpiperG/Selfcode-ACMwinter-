#include<bits/stdc++.h>
using	namespace	std;
struct	bage{
	int	value;//ÿ����ͷ��Ӧ��ֵ 
	int	cost; //ÿ����ͷ��Ӧ��� 
}w[1005];
long	long	DP[1005];//��ǰ��i����Ʒ����������Ϊj������ֵ
int	main()
{
	int	N;
	cin>>N;
	while(N--)
	{
		int	n,m;//��ͷ�������������  
		
		memset(DP,0,sizeof(DP)); 
		cin>>n>>m;
		for(int	i=1;i<=n;i++)
			cin>>w[i].value;
		for(int	i=1;i<=n;i++)
			cin>>w[i].cost;
		for(int	i=1;i<=n;i++)
			for(int	j=m;j>=w[i].cost;j--)
				DP[j]=max(DP[j],DP[j-w[i].cost]+w[i].value);
		cout<<DP[m]<<endl;
	}
}
/*for(int	i=1;i<=n;i++)
		{
			for(int	j=1;j<=m;j++)
				cout<<"i "<<i<<"j "<<j<<"DP"<<DP[i][j]<<" ";
			cout<<endl;
		}*/
