#include<bits/stdc++.h>
using	namespace	std;
int	lcm(long	int	m,long	int	n);
int	main()
{
	int	N;
	cin>>N;
	for(int	i=0;i<N;i++)
	{
		int	n;
		cin>>n;
		long	int	a[n];
		long	int	r;
		for(int	i=0;i<n;i++)
			cin>>a[i];
		r=a[0];
		for(int	i=0;i<n-1;i++)
		{
			r=lcm(r,a[i+1]);
		}
		cout<<r<<endl;
	}
}
int	lcm(long	int	m,long	int	n)
{
	long	int	x=m*n;
	long	int	y=m%n;
	while(y)
	{
		m=n;
		n=y;
		y=m%n;
	}
	return	x/n;
}
