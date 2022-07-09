#include<bits/stdc++.h>
using	namespace	std;
#define	size	1005
int	arr[size];
int	ar[size];
int	main()
{
	int	n;
	while(cin>>n)
	{
		memset(arr,0,sizeof(arr));
		memset(ar,0,sizeof(ar));
		int	k=0;
		int	k2=0;
		while(k2<=n)
		{
			k2=pow(2,k);						
			ar[k]=k2;
			k++;							
		}
		//cout<<ar[1]<<endl;				
		k--;
		for(int	i=1;i<=n;i++)
		{
			for(int	m=0;m<k;m++)
			{
				if(i>=ar[m]&&arr[i-ar[m]]==0)
					arr[i]=1;	
			}		
		}
		if(arr[n]==1)
			cout<<"Kiki"<<endl;
		else	
			cout<<"Cici"<<endl;
		
		/*for(int	i=1;i<=n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		for(int	i=0;i<k;i++)
			cout<<ar[i]<<" ";
		cout<<endl;*/
	}
} 
