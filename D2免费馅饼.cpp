#include<bits/stdc++.h>
using	namespace	std;
int	spemax(int	a,int	b,int	c);
int	arr[100000][12];//掉落时间，掉落地点（0~11） 
int	main()
{
	int	n;
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		
		memset(arr,0,sizeof(arr));
		int	loc,tim;
		int	mtim=0;
		for(int	i=0;i<n;i++)
		{
			scanf("%d%d",&loc,&tim);
			arr[tim][loc]++;
			mtim=max(mtim,tim);//求出最后一块馅饼掉落时的时间 
		}
		for(int	i=mtim-1;i>=0;i--)
		{
			for(int	k=0;k<=10;k++)
			{
				if(k==0)
					arr[i][k]=max(arr[i+1][k],arr[i+1][k+1])+arr[i][k];//边缘处理（此时位于塔的最左端，没有左中右三个数据） 
				else
					arr[i][k]=spemax(arr[i+1][k-1],arr[i+1][k],arr[i+1][k+1])+arr[i][k];
			}
		}
		cout<<arr[0][5]<<endl;
	}
	return	0; 
}
int	spemax(int	a,int	b,int	c)
{
	int	t;
	t=a>b?(a>c?a:c):(b>c?b:c);
	return	t;
}
/*
for(int	i=0;i<=3;i++)
		{
			for(int	k=0;k<=10;k++)
				cout<<arr[k][i]<<" ";
			cout<<endl;
		}*/
