#include<iostream>
using	namespace	std;
int	min(int	a[],int	n);
int	gcd(int	a[],int	m,int	n);
int	main()
{
	int	n;
	int	gcd1;
	int	min1;
	int	fsum=1;
	int	re;
	cin>>n;
	int	ordinary[n];
	for(int	i=0;i<n;i++)
		cin>>ordinary[i];
	min1=min(ordinary,n);
	gcd1=gcd(ordinary,min1,n);
	//cout<<min1<<endl;
	//cout<<gcd1<<endl;
	for(int	i=0;i<n;i++)
		fsum*=ordinary[i];
	re=fsum;
	cout<<re<<endl;		
	for(int	i=0;i<n-1;i++)
		re=re/gcd1;
	cout<<re<<endl;
}
int	min(int	a[],int	n)
{
	int	min2=a[0];
	for(int	i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
			min2=a[i+1];
	}
	return	min2;
}
int	gcd(int	a[],int	m,int	n)
{
	int	x;
	for(int	i=1;i<=m;m++)
	{
		int	judge=1;
		for(int	j=0;j<n;j++)
		{
			if(a[j]%i!=0)
				judge=0;
		}
		if(judge==1)
			x=i;
	}
	return	x;
}	

