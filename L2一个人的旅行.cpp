#include<bits/stdc++.h>
using	namespace	std;
#define	M	1005
#define	inf	0x3f3f3f3f
#define	x	1001
int	Map[M][M],dist[M],Visit[M];
int	main()
{
	int	t,s,d;//路，相邻城市，想去城市
	int	i,j;//循环用量
	int	a,b,dis;//路的信息
	int	c,e;//相邻与想去城市
	int	start,targe,next;//开始与目标
	int	Min; 
	while(~scanf("%d%d%d",&t,&s,&d))
	{
		for(i=0;i<=x;i++)
		{
			dist[i]=inf;
			Visit[i]=1;
			for(j=0;j<=x;j++)
				Map[i][j]=inf;
		}
		while(t--)
		{
			scanf("%d%d%d",&a,&b,&dis);
			Map[a][b]=min(Map[a][b],dis);
			Map[b][a]=Map[a][b];
		}
		while(s--)
		{
			scanf("%d",&c);
			Map[0][c]=Map[c][0]=0;	
		}
		while(d--)
		{
			scanf("%d",&e);
			Map[x][e]=Map[e][x]=0;	
		}
		start=0;
		targe=x;
		dist[start]=0;
		Visit[start]=0;
		while(start!=targe)
		{
			Min=inf;
			for(i=0;i<=x;i++)
			{
				if(Map[start][i]!=inf)
					dist[i]=min(dist[i],Map[start][i]+dist[start]);
				if(Visit[i]&&dist[i]<Min)
				{
					next=i;
					Min=dist[i];
				}
			}
			if(Min==inf)
				break;
			start=next;
			Visit[start]=0;
		}
		printf("%d\n",dist[targe]);
	}
}
