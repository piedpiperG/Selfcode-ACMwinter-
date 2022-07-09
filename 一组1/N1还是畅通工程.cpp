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
int	bin[5000];
int		findx(int	x);
void	merge(int	x,int	y);
int	main()
{
	int	n;
	while(cin>>n)
	{
		if(n==0)
			break;
		int	n1=n*(n-1)/2;
		int	count=0;
		for(int	i=0;i<n1;i++)
			cin>>arr[i].a>>arr[i].b>>arr[i].l;
		sort(arr,arr+n1,cmp);
		for(int	i=1;i<=n1;i++)
			bin[i]=i;
		for(int	i=0;i<n1;i++)
		{
			if(findx(arr[i].a)!=findx(arr[i].b))
			{
				merge(arr[i].a,arr[i].b);
				count=count+arr[i].l;
				//cout<<"×÷ÓÃ"<<endl;	
			}	
		}
		cout<<count<<endl;	
	}
	return	0;
}
int		findx(int	x)
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
