#include<bits/stdc++.h>
using	namespace	std;
int	main()
{
	long	long	arr[30];
	arr[1]=1;
	arr[2]=3;
	int	N;
	cin>>N;
	while(N--)
	{
		int	n;
		cin>>n;
		for(int	i=3;i<=n;i++)
			arr[i]=arr[i-1]+2*arr[i-2];
		cout<<arr[n]<<endl;
	}
}
