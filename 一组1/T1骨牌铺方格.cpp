#include<bits/stdc++.h>
using	namespace	std;
int	main()
{
	long	long	a[50];
	a[1]=1;
	a[2]=2;
	int	n;
	while(cin>>n)
	{
		for(int	i=3;i<=n;i++)
			a[i]=a[i-1]+a[i-2];
		cout<<a[n]<<endl;		
	}
}
