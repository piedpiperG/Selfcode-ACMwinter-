#include<bits/stdc++.h>
using	namespace	std;
#define	MAXN	510
int		uN,vN;//���������ֵ��� 
int		g[MAXN][MAXN];//�����Ӧ 
int		linker[MAXN];//�����Ӧ��· 
bool	used[MAXN];//�ڵ�ǰѭ���Ƿ��Ѿ���ռ�� 
bool	dfs(int	u);
int	hungary();
int	main()
{
	int	N;
	cin>>N; 
	while(N--)
	{
		scanf("%d%d",&uN,&vN);//�����������ֵ����� 
		memset(g,0,sizeof(g));
		int	u,v;
		while(vN--)//����ͼ 
		{
			scanf("%d%d",&u,&v);
			g[u][v]=1; 
		}
		printf("%d\n",uN-hungary());
	}
	return	0;
}
int	hungary()
{
	int	res=0;
	memset(linker,-1,sizeof(linker));

	for(int	i=1;i<=uN;i++)
	{
		memset(used,false,sizeof(used));
		if(dfs(i))
			res++;
	}
	return	res;
}
bool	dfs(int	u)
{
	for(int	v=1;v<=uN;v++)
		if(g[u][v]&&!used[v])
		{
			used[v]=true;
			if(linker[v]==-1||dfs(linker[v]))
			{
				linker[v]=u;
				return	true;
			}
		}
	return	false;
}
