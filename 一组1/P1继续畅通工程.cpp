#include<bits/stdc++.h>
using	namespace	std;
struct	road{
	int	a,b;
	int	l,c;//价格及开通状态 
}arr[5000];
bool	cmp(road	x,road	y)
{
	return	x.l<y.l;
}
int	bin[100];
int	findx(int	x);
void	merge(int	x,int	y);
int	main()
{
	int	n;
	while(cin>>n)
	{
		if(n==0)
			break;
		int	m=n*(n-1)/2;
		int	count=0;
		for(int	i=0;i<m;i++)
			cin>>arr[i].a>>arr[i].b>>arr[i].l>>arr[i].c;
		sort(arr,arr+m,cmp);
		for(int	i=1;i<=m;i++)
			bin[i]=i;
		for(int	i=0;i<m;i++)
		{
			if(arr[i].c==1)
				merge(arr[i].a,arr[i].b);
		}
		for(int	i=0;i<m;i++)
		{
			if(findx(arr[i].a)!=findx(arr[i].b))
			{
				merge(arr[i].a,arr[i].b);
				count=count+arr[i].l;
			}	
		}
		cout<<count<<endl;
		memset(bin,0,sizeof(bin));
	}
	return	0;
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
