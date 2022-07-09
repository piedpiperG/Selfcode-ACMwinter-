#include<bits/stdc++.h>
using	namespace	std;
int	bin[1003];
int	findx(int	x);
void	merge(int	x,int	y);
int	main()
{
	int	n,m;
	
	while(scanf("%d",&n),n)
	{
		scanf("%d",&m);
		int	x,y;
		int	count=-1;
		for(int	i=1;i<=n;i++)
			bin[i]=i;
		for(int	i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			merge(x,y);
		}
		for(int	i=1;i<=n;i++)
			if(bin[i]==i)
				count++;
		cout<<count<<endl;
		memset(bin,0,sizeof(bin));
	}
}
int	findx(int	x)
{
	int	r=x;
	while(bin[r]!=r)
		r=bin[r];
	return	r;
}
void	merge(int	x,int	y)
{
	int	fx,fy;
	fx=findx(x);
	fy=findx(y);
	if(fx!=fy)
		bin[fx]=fy;
}
