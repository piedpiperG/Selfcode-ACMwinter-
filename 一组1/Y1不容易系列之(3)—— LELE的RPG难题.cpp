#include<bits/stdc++.h>
using	namespace	std;
int	main()
{
	long	long	arr[500];
	arr[1]=3;
	arr[2]=6;
	arr[3]=6;
	int	n;
	while(cin>>n)
	{
		for(int	i=4;i<=n;i++)
		{
			arr[i]=arr[i-1]+2*arr[i-2];
		}
		cout<<arr[n]<<endl;
	}
}
