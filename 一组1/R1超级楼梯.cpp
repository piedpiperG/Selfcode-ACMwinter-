#include<bits/stdc++.h>
using	namespace	std;
int	main()
{
	int	N;
	cin>>N;
	while(N--)
	{
		int	m;
		cin>>m;
		int	a[m+2];
		a[0]=1;
		a[1]=1;
		for(int	i=2;i<m;i++)
			a[i]=a[i-1]+a[i-2];
		cout<<a[m-1]<<endl;
	}
}
