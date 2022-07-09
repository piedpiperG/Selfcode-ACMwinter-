#include<bits/stdc++.h>
using	namespace	std;
struct	cat{
	double	a,b;
	double	c;
}arr[1000];
bool	cmp(cat	x,cat	y)
{
	return	x.c>y.c;
}
int	main()
{
	int	m,n;
	while(cin>>m>>n)
	{
		double	count=0;
		if(m==-1&&n==-1)
			break;
		for(int	i=0;i<n;i++)
			cin>>arr[i].a>>arr[i].b;
		for(int	i=0;i<n;i++)
			arr[i].c=arr[i].a/arr[i].b;
		sort(arr,arr+n,cmp);
		for(int	i=0;i<n;i++)
		{
			if(m<arr[i].b)
			{
				count=count+(m/arr[i].b)*arr[i].a;
				break;
			}
			else
				count=count+arr[i].a;
				m=m-arr[i].b;
			if(m-0<0.0001)
				break;
		}
		//count=(int)(count*10000+0.5)/10000.0;
		count*=1000;
		count=(int)(count+0.5);
		count/=1000;
		printf("%.3f\n",count);
	}
	return	0;
}
/*测试排序功能 插入sort函数后 for(int	i=0;i<n;i++)
		{
			cout<<arr[i].a<<endl; 
		}*/
