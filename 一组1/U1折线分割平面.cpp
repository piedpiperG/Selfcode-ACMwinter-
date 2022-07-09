#include<bits/stdc++.h>
using	namespace	std;
int	main()
{
	long	long	a[10000];
	a[1]=2;
	int	N;
	cin>>N;
	while(N--)
	{
		int	n;
		cin>>n; 
		for(int	i=2;i<=n;i++)
			a[i]=a[i-1]+4*(i-1)+1;
		cout<<a[n]<<endl;	
	}
}
