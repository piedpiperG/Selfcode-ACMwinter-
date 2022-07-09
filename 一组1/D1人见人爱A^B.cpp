#include<iostream>
using	namespace	std;
int	power(long	long	int	a,long	long	int	n);
int	main()
{
	long	long	int	a,b;
	while(cin>>a>>b)
	{
		long	long	int	re;
		if(a==0&&b==0)
			break;
		re=power(a,b)%1000;
		cout<<re<<endl;
	}
	return	0;
}
int	power(long	long	int	a,long	long	int	n)
{
	long	long	int	ans=1;
	while(n)
	{
		if(n%2)
			ans=(ans*a)%1000;
		a=(a*a)%1000;
		n=n/2;
	}
	return	ans;
}
