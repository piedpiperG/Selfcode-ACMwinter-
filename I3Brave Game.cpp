#include<bits/stdc++.h>
using	namespace	std;
#define	size	1005
int	arr[size];
int	main()
{
	int	N;
	cin>>N;
	int	n,m;
	while(N--)
	{
		memset(arr,0,sizeof(arr));
		cin>>n>>m;
		if(n%(1+m)==0)
			cout<<"second"<<endl;
		else	
			cout<<"first"<<endl;
	}
}
