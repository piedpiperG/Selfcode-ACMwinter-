#include<bits/stdc++.h>
using	namespace	std;
int	main()
{
	long	int	a;
	while(cin>>a)
	{
		long	int	b[8]={1,2,0,2,2,1,0,1};
		if(b[a%8])
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}
}
