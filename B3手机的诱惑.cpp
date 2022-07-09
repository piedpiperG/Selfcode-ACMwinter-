#include<bits/stdc++.h>
using	namespace	std;
char	Map[12][12];
int		n,m,t,di,dj;
int		si,sj;
bool	escape;
int		dir[4][2]={1,0,0,1,-1,0,0,-1};
void	dfs(int	si,int	sj,int	cnt);
int	main()
{
	
	while(cin>>n>>m>>t)
	{
		if(n==0&&m==0&&t==0)
			break;
		int	Wall=0;
		for(int	i=0;i<n;i++)
			cin>>Map[i];
		for(int	i=0;i<n;i++)
		{
			for(int	j=0;j<m;j++)
			{
				if(Map[i][j]=='S')
				{
					si=i;
					sj=j;
				}
				else	if(Map[i][j]=='D')
				{
					di=i;
					dj=j;
				}
				else	if(Map[i][j]=='X')
					Wall++;
			}
		}
		if(n*m-Wall<=t)
		{
			cout<<"NO"<<endl;
			continue;
		}
		escape=0;
		Map[si][sj]=='X';
		dfs(si,sj,0);
		if (escape)
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return	0;
}
void	dfs(int	si,int	sj,int	cnt)
{
	int	i,temp;
	if(si>=n||sj>=m||si<0||sj<0)
		return;
	if(cnt==t&&si==di&&sj==dj)
	{
		escape=1;
		return;
	}
	if(escape)
		return;
	temp=(t-cnt)-abs(si-di)-abs(sj-dj);
	if(temp<0||temp%2==1)
		return;
	int	ki,kj;
	for(i=0;i<4;i++)
	{
		ki=si+dir[i][0];
		kj=sj+dir[i][1];
		if(ki>=n||kj>=m||ki<0||kj<0)
			continue;
		if(Map[ki][kj]!='X')
		{
			Map[ki][kj]='X';
			dfs(ki,kj,cnt+1);
			Map[ki][kj]='.';
		}
	}
	return;
}
