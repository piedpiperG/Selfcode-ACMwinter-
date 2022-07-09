#include<bits/stdc++.h>
using	namespace	std;
int	main()
{
	int	N;
	cin>>N;
	while(N--)
	{
		int	a,b;
		cin>>a>>b;
		int	c=b-a;
		long	long	arr[500];
		arr[1]=1;
		arr[2]=2;
		for(int	i=3;i<50;i++)
			arr[i]=arr[i-1]+arr[i-2];
		cout<<arr[c]<<endl;
	}
}
