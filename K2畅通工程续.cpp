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
	int	n1,n2;//������Ŀ�����޽���·��Ŀ
	int	a,b,dis;//��·���� 
	int	start,targe;//��������Ŀ�ĵ� 
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
		}//��ʼ���������� 
		while(n2--)
		{
			scanf("%d%d%d",&a,&b,&dis);
			Map[a][b]=min(Map[a][b],dis);//�����ж���·�������ȡ���· 
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
				if(Visit[i]&&dist[i]<Min)//�жϳ���һ��Ӧ���ߵ��ĸ����� 
				{
					next=i;
					Min=dist[i];
				}
			}
			if(Min==inf)//���ѭ������̵�·����Ϊinf��֤��û��·���Ե��յ㣬ֱ��break��ʡȥ������������ 
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
