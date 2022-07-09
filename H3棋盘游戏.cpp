#include<bits/stdc++.h>
using	namespace	std;
#define	MAXN	510
int		uN,vN;//����������Ů������
int		nan1[MAXN],nv[MAXN];//ͳ����Ů������ 
int		g[MAXN][MAXN];//�����Ӧ 
int		linker[MAXN];//Ů���Ķ�Ӧ���� 
bool	used[MAXN];//�ڵ�ǰ����ѭ�����Ƿ��Ѿ��Ӵ���Ů�� 
bool	dfs(int	u);
int	hungary();
int main()
{
       int i,j,u,v,k,num,cas=1,temp;
       while(scanf("%d%d%d",&uN,&vN,&k)!=EOF)
       {
            num=0;
            memset(g,0,sizeof(g));
            for(i=1;i<=k;i++)
            {
                cin>>u>>v;
                g[u][v]=1;
            }
            temp=hungary();
            for(i=1;i<=uN;i++)
               for(j=1;j<=vN;j++)
               {
            		if(g[i][j]==1)
                    {
                        g[i][j]=0;
                        if(hungary()<temp)
                        num++;
                        g[i][j]=1;
                    }
               }
              printf("Board %d have %d important blanks for %d chessmen.\n",cas++,num,temp);
       }
       return 0;
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
	for(int	v=1;v<=vN;v++)
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
