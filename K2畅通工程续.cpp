#include<bits/stdc++.h>
using	namespace	std;
#define	size	201
#define	inf		0x3f3f3f3f
int	mini(int	a,int	b)
{
	return	a<=b?a:b;
}
int	 Map[size][size],dist[size],Visit[size];
int	main()
{
	int	n1,n2;//城镇数目，已修建道路数目
	int	a,b,dis;//道路数据 
	int	start,targe;//出发地与目的地 
	int	i,j,next;
	while(~scanf("%d%d",&n1,&n2))
	{
		int	Min;
		for(i=0;i<n1;i++)
		{
			Visit[i]=1;
			dist[i]=inf;
			for(j=0;j<n1;j++)
				Map[i][j]=inf;
		}//初始化城镇数组 
		while(n2--)
		{
			scanf("%d%d%d",&a,&b,&dis);
			Map[a][b]=min(Map[a][b],dis);//两地有多条路的情况下取最短路 
			Map[b][a]=Map[a][b];
		}
		scanf("%d%d",&start,&targe);
		dist[start]=0;
		Visit[start]=0;
		while(start!=targe)
		{
			Min=inf;
			for(i=0;i<n1;i++)
			{
				if(Map[start][i]!=inf)
					dist[i]=min(dist[i],Map[start][i]+dist[start]);
				if(Visit[i]&&dist[i]<Min)//判断出下一步应该走到哪个城镇 
				{
					next=i;
					Min=dist[i];
				}
			}
			if(Min==inf)//如果循环后最短的路径仍为inf，证明没有路可以到终点，直接break，省去接下来的运算 
				break;
			start=next;
			Visit[start]=0;
		}
		if(dist[targe]==inf)
			printf("%d\n",-1);
		else
			printf("%d\n",dist[targe]);
	}
	return	0;
}
