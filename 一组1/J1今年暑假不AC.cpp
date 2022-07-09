#include<bits/stdc++.h>
using	namespace	std;
struct	show{
	int	a;	int	b;//开始时间与结束时间 
}arr[100];
bool	cmp(show	x,show	y)
{
	if(x.b==y.b){return	x.a<y.a;};
	return	x.b<y.b;
}
int	main()
{
	int	n;
	while(cin>>n)
	{
		if(n==0)
			break;
		for(int	i=0;i<n;i++)
			cin>>arr[i].a>>arr[i].b;
		int	count=1;
		int	m=0;
		sort(arr,arr+n,cmp);
		/*for(int	i=0;i<n;i++)
			cout<<arr[i].a<<" "<<arr[i].b<<endl;*/
		for(int	j=1;j<n;j++)
		{
			for(int	i=1;i<n;i++)
			{
				if(arr[m+i].a>=arr[m].b)
				{
					count++;
					m=m+i;
					break;
				}
			}
		}						//用双循环解决作用域问题，我真tm有点天才 (确保每一个节目的可能性都得到保障） 
		cout<<count<<endl;
	}
	return	0;
}
