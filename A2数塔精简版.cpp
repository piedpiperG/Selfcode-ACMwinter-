#include<bits/stdc++.h>
using	namespace	std;
int	decide(int	a,int	b);//返回最大值 
int	main()
{
	int	N;
	cin>>N;
	while(N--)
	{
		int	n;
		cin>>n;
		long	long	arr[n][n];
		int	j=1;
		for(int	i=0;i<n;i++)
		{
			for(int	k=0;k<j;k++)
				cin>>arr[i][k];
			j++;
		}
		j=n-2; 
		for(int	i=n-2;i>=0;i--)
		{
			for(int	k=0;k<=j;k++)
				arr[i][k]=arr[i][k]+decide(arr[i+1][k],arr[i+1][k+1]);
			j--;
		} 
		cout<<arr[0][0]<<endl;
	}
}
int	decide(int	a,int	b)
{
	if(a>=b)
		return	a;
	else
		return	b;
}
