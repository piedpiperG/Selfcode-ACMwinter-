#include<bits/stdc++.h>
using	namespace	std;
struct	road{
	int	a;
	int	b;
	int	l;
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
	int	n,m;
	while(cin>>n>>m)
	{
		if(n==0)
			break;
		int	count=0;
		int	num=-1;
		for(int	i=0;i<n;i++)
			cin>>arr[i].a>>arr[i].b>>arr[i].l;
		sort(arr,arr+n,cmp);
		for(int	i=1;i<=m;i++)
			bin[i]=i;
		for(int	i=0;i<n;i++)
		{
			if(findx(arr[i].a)!=findx(arr[i].b))
			{
				merge(arr[i].a,arr[i].b);
				count=count+arr[i].l;
			}	
		}	
		for(int	i=0;i<n;i++)
			merge(arr[i].a,arr[i].b);
		for(int	i=1;i<=m;i++)
			if(bin[i]==i)
				num++;
		if(num==0)
			cout<<count<<endl;
		else
			cout<<'?'<<endl;
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
