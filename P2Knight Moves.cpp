#include<bits/stdc++.h>
using	namespace	std;
#define	size	100
char	c1,c2,c3;
int		a1,b1;
int		a2,b2;
struct	pos{
	int	a;//横向坐标 
	int	b;//纵向坐标
	int	steps; 
};
int	x[]={0,1,2,2,1,-1,-2,-2,-1};
int	y[]={0,2,1,-1,-2,-2,-1,1,2};
int	vis[size];
void	bfs();
int	judge(int	a,int	b);
int	main()
{
	while(~scanf("%c%d%c%c%d",&c1,&b1,&c3,&c2,&b2))
	{
		a1=c1-96;
		a2=c2-96;
		//cout<<a1<<b1<<a2<<b2<<endl;
		memset(vis,0,sizeof(vis));
		bfs();
		c3=getchar();
	}
	return	0;
}
void	bfs()
{
	pos	cur,nex;
	cur.a=a1;
	cur.b=b1;
	cur.steps=0;
	queue<pos>qu;
	qu.push(cur);
	vis[a1*10+b1]=1;
	while(!qu.empty())
	{
		cur=qu.front();
		qu.pop();
		if(cur.a==a2&&cur.b==b2)
		{
			printf("To get from %c%d to %c%d takes %d knight moves.\n",c1,b1,c2,b2,cur.steps);
			return;
		}
		for(int	i=1;i<=8;i++)
		{
			nex.a=cur.a+x[i];
			nex.b=cur.b+y[i];
			if(vis[10*nex.a+nex.b]==0&&judge(nex.a,nex.b))
			{
				nex.steps=cur.steps+1;
				vis[10*nex.a+nex.b]=1;
				qu.push(nex);
			}	
		}
	}
}
int	judge(int	a,int	b)
{
	if(a<1||a>8||b<1||b>8)
		return	0;
	else
		return	1;
}
