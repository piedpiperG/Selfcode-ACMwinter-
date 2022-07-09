#include<bits/stdc++.h>
using	namespace	std;
#define	size	2000000
#define	p		10000
#define	q		100
int	s,n,m;
void	bfs();
struct	pos{
	int	a;
	int	b;
	int	c;
	int	steps;
};
int	vis[size];
int	judge(int	a,int	b,int	c);
int	main()
{
	while(~scanf("%d%d%d",&s,&n,&m))
	{
		if(s==0&&n==0&&m==0)
			break;
		memset(vis,0,sizeof(vis));
		bfs();
	}
	return	0;
}
void	bfs()
{
	pos	cur,nex;
	cur.a=s;cur.b=0;cur.c=0;
	cur.steps=0;
	queue<pos>qu;
	qu.push(cur);
	vis[s*p]=1;
	while(!qu.empty())
	{
		cur=qu.front();
		qu.pop();
		if(judge(cur.a,cur.b,cur.c)==1)
		{
			printf("%d\n",cur.steps);
			return;
		}
		if(cur.a!=0)
		{
			if(cur.a<=n-cur.b)//1
			{
				nex.a=0;
				nex.b=cur.b+cur.a;
				nex.c=cur.c;
				nex.steps=cur.steps+1;
			}
			else
			{
				nex.a=cur.a-(n-cur.b);
				nex.b=n;
				nex.c=cur.c;
				nex.steps=cur.steps+1;	
			}
			if(vis[p*nex.a+q*nex.b+nex.c]==0)
			{
				vis[p*nex.a+q*nex.b+nex.c]=1;
				qu.push(nex);
			}
			
			if(cur.a<=m-cur.c)//2
			{
				nex.a=0;
				nex.b=cur.b;
				nex.c=cur.c+cur.a;
				nex.steps=cur.steps+1;
			}
			else
			{
				nex.a=cur.a-(m-cur.c);
				nex.b=cur.b;
				nex.c=m;
				nex.steps=cur.steps+1;	
			}
			if(vis[p*nex.a+q*nex.b+nex.c]==0)
			{
				vis[p*nex.a+q*nex.b+nex.c]=1;
				qu.push(nex);
			}
		}
		if(cur.b!=0)
		{
			if(cur.b<=s-cur.a)//3
			{
				nex.a=cur.a+cur.b;
				nex.b=0;
				nex.c=cur.c;
				nex.steps=cur.steps+1;
			}
			else
			{
				nex.a=s;
				nex.b=cur.b-(s-cur.a);
				nex.c=cur.c;
				nex.steps=cur.steps+1;	
			}
			if(vis[p*nex.a+q*nex.b+nex.c]==0)
			{
				vis[p*nex.a+q*nex.b+nex.c]=1;
				qu.push(nex);
			}
			
			if(cur.b<=m-cur.c)//4
			{
				nex.a=cur.a;
				nex.b=0;
				nex.c=cur.c+cur.b;
				nex.steps=cur.steps+1;
			}
			else
			{
				nex.a=cur.a;
				nex.b=cur.b-(m-cur.c);
				nex.c=m;
				nex.steps=cur.steps+1;	
			}
			if(vis[p*nex.a+q*nex.b+nex.c]==0)
			{
				vis[p*nex.a+q*nex.b+nex.c]=1;
				qu.push(nex);
			}
		}
		if(cur.c!=0)
		{
			if(cur.c<=s-cur.a)//5
			{
				nex.a=cur.a+cur.c;
				nex.b=cur.b;
				nex.c=0;
				nex.steps=cur.steps+1;
			}
			else
			{
				nex.a=s;
				nex.b=cur.b;
				nex.c=cur.c-(s-cur.a);
				nex.steps=cur.steps+1;	
			}
			if(vis[p*nex.a+q*nex.b+nex.c]==0)
			{
				vis[p*nex.a+q*nex.b+nex.c]=1;
				qu.push(nex);
			}
			
			if(cur.c<=n-cur.b)//6
			{
				nex.a=cur.a;
				nex.b=cur.b+cur.c;
				nex.c=0;
				nex.steps=cur.steps+1;
			}
			else
			{
				nex.a=cur.a;
				nex.b=n;
				nex.c=cur.c-(n-cur.b);
				nex.steps=cur.steps+1;	
			}
			if(vis[p*nex.a+q*nex.b+nex.c]==0)
			{
				vis[p*nex.a+q*nex.b+nex.c]=1;
				qu.push(nex);
			}
		}
	}
	cout<<"NO"<<endl;
	return;
}
int	judge(int	a,int	b,int	c)
{
	if(s%2==1)
		return	0;
	int	temp=s/2;
	if(a==temp&&b==temp)
		return	1;
	if(a==temp&&c==temp)
		return	1;
	if(c==temp&&b==temp)
		return	1;
	return	0;
}
