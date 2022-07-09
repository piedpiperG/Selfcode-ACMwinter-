#include<bits/stdc++.h>
using	namespace	std;
int	main()
{
	long	long	arr[40];
	arr[1]=3;
	arr[2]=8;
	int	n;
	while(cin>>n)
	{
		for(int	i=3;i<=n;i++)
			arr[i]=2*(arr[i-1]+arr[i-2]);
		cout<<arr[n]<<endl;
	}
}
