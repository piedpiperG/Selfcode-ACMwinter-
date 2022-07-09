#include<bits/stdc++.h>
using	namespace	std;
#define	inf	0x3f3f3f3f
#define	size	205
int		m,n;//行纵
char	Map[size][size];
int		vis[size][size];
int		fa[size],fb[size];//朋友坐标(应对有多个朋友）
int		k=0;//朋友计数 
int		result[size];//不同朋友的不同成绩
int		aa,ab;//公主坐标
int		dir[4][2]={1,0,0,1,-1,0,0,-1};		
struct	pos{
	int	a;//横坐标 
	int	b;//纵坐标
	int	steps;//走的步数 
};
int	bfs(int	sa,int	sb);
int	judge(int	a,int	b);
int	main()
{
	while(~scanf("%d%d",&m,&n))
	{
		k=0;
		memset(Map,0,sizeof(Map));
		memset(vis,0,sizeof(vis));
		memset(fa,0,sizeof(fa));
		memset(fb,0,sizeof(fb));
		for(int	i=0;i<size;i++)
			result[i]=inf;
		for(int	i=0;i<m;i++)
			scanf("%s",Map[i]);
		for(int	i=0;i<m;i++)
		{
			for(int	j=0;j<n;j++)
			{
				if(Map[i][j]=='#')
					vis[i][j]=1;
				if(Map[i][j]=='a')
				{
					aa=i;
					ab=j;
				}
				if(Map[i][j]=='r')
				{
					fa[k]=i;
					fb[k]=j;
					k++;
				}
			}
		}
		for(int	i=0;i<k;i++)
		{
			result[i]=bfs(fa[i],fb[i]);
			for(int	i=0;i<m;i++)
				for(int	j=0;j<n;j++)
				{
					if(Map[i][j]!='#')
						vis[i][j]=0;
				}
			
		}
		sort(result,result+size);
		if(result[0]<inf)
			printf("%d\n",result[0]);
		else
			printf("Poor ANGEL has to stay in the prison all his life.\n");
	}	
}
int	bfs(int	sa,int	sb)
{
	pos	cur,nex;
	cur.a=sa;
	cur.b=sb;
	cur.steps=0;
	queue<pos>qu;
	qu.push(cur);
	vis[cur.a][cur.b]=1;
	while(!qu.empty())
	{
		cur=qu.front();
		qu.pop();
		if(cur.a==aa&&cur.b==ab)
		{
			return	cur.steps;
		}
		for(int	i=0;i<4;i++)
		{
			nex.a=cur.a+dir[i][0];
			nex.b=cur.b+dir[i][1];
			if(vis[nex.a][nex.b]==0&&judge(nex.a,nex.b))
			{
				if(Map[nex.a][nex.b]=='x')
					nex.steps=cur.steps+2;
				else	
					nex.steps=cur.steps+1;
				vis[nex.a][nex.b]=1;
				qu.push(nex);	
			}
		}
	}
	return	inf;
}
int	judge(int	a,int	b)
{
	if(a<0||a>=m||b<0||b>=n)
		return	0;
	return	1;
}
