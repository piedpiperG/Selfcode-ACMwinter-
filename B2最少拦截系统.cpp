#include<bits/stdc++.h>
using	namespace	std;
int	compare(int	a,int	b);//判断两数大小 
int	main()
{
	int	n;
	while(cin>>n)
	{
		int	arr[n];
		for(int	i=0;i<n;i++)
			cin>>arr[i];
		int	count=1;
		for(int	i=0;i<n-1;i++)
		{
			if(compare(arr[i],arr[i+1]))
				continue;	
			else
				count++;	
		}
		cout<<count<<endl;
	}
}
int	compare(int	a,int	b)
{
	if(a>=b)
		return	1;//可用 
	else
		return	0;//不可用 
}
