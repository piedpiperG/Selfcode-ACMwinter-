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
int main(){
	int	n;
	while(~scanf("%d",&n))
	{
		memset(g,0,sizeof(g)); 
		for(int i=0;i<n;++i)
		{
			int a,b,c;
			scanf("%d: (%d)",&a,&b);
			while(b--)
			{
				scanf("%d",&c);
				g[a][c]=1;						
			}
			uN=vN=n;
		}
		cout<<n-hungary()/2<<endl;
	} 
	return 0;
}
int	hungary()
{
	int	res=0;
	memset(linker,-1,sizeof(linker));

	for(int	i=0;i<uN;i++)
	{
		memset(used,false,sizeof(used));
		if(dfs(i))
			res++;
	}
	return	res;
}
bool	dfs(int	u)
{
	for(int	v=0;v<vN;v++)
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
