#include<bits/stdc++.h>
using	namespace	std;
int	n,Start,End;//楼层数，开始点，终点 
int	a[202];
int	vis[202];
struct	pos{
	int	level;//当前状态 
	int	steps;//走过的步数 
};
void	bfs();
int	main()
{
	int	i;
	while(~scanf("%d",&n))
	{
		if(n==0)
			break;
		scanf("%d%d",&Start,&End);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			vis[i]=0;
		}
		bfs();
	}
	return	0;	
}
void	bfs()
{
	pos	cur,nex;
	cur.level=Start;
	cur.steps=0;
	queue<pos>qu;
	qu.push(cur);
	vis[Start]=1;
	while(!qu.empty())
	{
		cur=qu.front();
		qu.pop();
		if(cur.level==End)
		{
			printf("%d\n",cur.steps);
			return;
		}
		nex.level=cur.level+a[cur.level];
		nex.steps=cur.steps+1;
		if(nex.level<=n)
		{
			if(vis[nex.level]==0)
			{
				vis[nex.level]=1;
				qu.push(nex);
			}
		}
		
		nex.level=cur.level-a[cur.level];
		nex.steps=cur.steps+1;
		if(nex.level>=1)
		{
			if(vis[nex.level]==0)
			{
				vis[nex.level]=1;
				qu.push(nex);
			}
		}
	}
	printf("-1\n");
	return;	
}






