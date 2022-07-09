#include<bits/stdc++.h>
using	namespace	std;
#define	size	1005
int	arr[size];
int	ar[size];
int	main()
{
	ar[1]=1;
	ar[2]=2;
	for(int	i=3;i<16;i++)
		ar[i]=ar[i-1]+ar[i-2];
	int	n;
	int	a,b,c;
	int	a1,b1,c1;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		
		
	}
}
int	judge(int	n)
{
	memset(arr,0,sizeof(arr));			
	for(int	i=1;i<=n;i++)
	{
		for(int	m=0;m<16;m++)
		{
			if(i>=ar[m]&&arr[i-ar[m]]==0)
				arr[i]=1;	
		}		
	}
	if(arr[n]==1)
		return	1;
	else	
		return	0;
}
