#include<bits/stdc++.h>
using	namespace	std;
void	swap(int	&a,int	&b);
int	main()
{
	int	N;
	cin>>N;
	while(N--)
	{
		int	a,b;
		int	max=-1;
		int	p[202]={0};
		int	n;
		cin>>n;
		for(int	i=0;i<n;i++)
		{
			cin>>a>>b;
			a=(a-1)/2;
			b=(b-1)/2;//将两边的屋子进行一致编号 
			swap(a,b);
		for(int	k=a;k<=b;k++)//记录走过的位置 
			p[k]++;
		}
		for(int	i=0;i<200;i++)
			if(p[i]>max)
				max=p[i];//选出走过位置的最大次数，即为搬运的次数 
		cout<<max*10<<endl;
		
	}
	return	0;
}
void	swap(int	&a,int	&b)
{
	if(a>b)
	{
		int	temp;
		temp=a;
		a=b;
		b=temp;
	}
}
