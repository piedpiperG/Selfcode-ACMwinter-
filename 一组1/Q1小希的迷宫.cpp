#include<bits/stdc++.h>
using	namespace	std;
struct	road{
	int	a;
	int	b;
}arr[100000];
int	bin[5000];
int		findmax(int	a,int	b)
{
	if(a>=b)
		return	a;
	else	
		return	b;
}
bool	cmp(road	x,road	y)
{
	return	findmax(x.a,x.b)>findmax(y.a,y.b);
}
int	findx(int	x);
void	merge(int	x,int	y);
int	main()
{
	while(1)
	{
	
	int	count=0;
	int	max=0;
	int	decide=0;
	for(int	i=0;;i++)
	{
		cin>>arr[i].a>>arr[i].b;
		if(arr[i].a==0&&arr[i].b==0)
			break;
		if(arr[i].a==-1&&arr[i].b==-1)
			return	0;
		count++;
	}
	sort(arr,arr,cmp);
	max=findmax(arr[0].a,arr[0].b);
	if(max-1>=count)
		decide=1;
	for(int	i=1;i<=count;i++)
		bin[i]=i;
	for(int	i=0;i<count;i++)
		merge(arr[i].a,arr[i].b);
	for(int	i=0;i<count-1;i++)
		if(bin[i]!=bin[i+1]&&bin[i]!=i&&bin[i+1]!=i+1)
			decide=1;
	if(decide==1)
		cout<<"No"<<endl;
	else	if(decide==0)
		cout<<"Yes"<<endl;
	cout<<"max ="<<max<<endl;
	cout<<"count ="<<count<<endl;
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
