#include<bits/stdc++.h>
using	namespace	std;
#define	M	1005
#define	inf	0x3f3f3f3f
#define	x	1001
int	Map[M][M],dist[M],Visit[M];
int	main()
{
	int	t,s,d;//������������ͨ��ʽ����ȥ�ص� 
	int	i,j;//ѭ������
	int	a,b,dis;//·����Ϣ
	int	w,e;//���ڵص������λ�� 
	int	start,targe,next;//��ʼ��Ŀ��
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
		while(s--)
		{
			scanf("%d%d%d",&a,&b,&dis);
			Map[a][b]=min(Map[a][b],dis);
		}
		scanf("%d",&w);
		while(w--)
		{
			scanf("%d",&e);
			Map[0][e]=0;
		}
		start=0;
		targe=d;
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
		if(dist[targe]==inf)
			printf("%d\n",-1);
		else
			printf("%d\n",dist[targe]);
	}
}
