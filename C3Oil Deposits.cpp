#include<bits/stdc++.h>
using	namespace	std;
int	m,n;//ºá×Ý 
int	result;
char	Map[105][105];
int	dir[8][2]={0,1,1,1,1,0,1,-1,0,-1,-1,-1,-1,0,-1,1};
int	judge(int	x,int	y);
int	dfs(int	x,int	y);
int	main()
{
	while(scanf("%d %d",&m,&n)==2)
	{
		if(m==0&&n==0)
			break;
		memset(Map,0,sizeof(Map));
		result=0;
		for(int	i=0;i<m;i++)
			scanf("%s",Map[i]);
		for(int	i=0;i<m;i++)
		{
			for(int	j=0;j<n;j++)
			{
				if(dfs(i,j))
					result++;		
			}
		}
		/*for(int	i=0;i<m;i++)
		{	
			for(int	j=0;j<n;j++)
				cout<<Map[i][j]<<" ";
			cout<<endl;
		}*/
		printf("%d\n",result);		
	}
	return	0;
}
int	judge(int	x,int	y)
{
	if(x>=0&&x<m&&y>=0&&y<n&&Map[x][y]=='@')
		return	1;//ÓÐÓÍÌï 
	else
		return	0;
}
int	dfs(int	x,int	y)
{
	int	i,xx,yy;
	if(judge(x,y))
	{
		Map[x][y]='.';
		for(i=0;i<8;i++)
		{
			xx=x+dir[i][0];
			yy=y+dir[i][1];
			dfs(xx,yy);
		}
		return	1;
	}
	return	0;
}
