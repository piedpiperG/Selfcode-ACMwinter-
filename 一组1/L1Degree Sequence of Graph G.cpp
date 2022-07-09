#include<bits/stdc++.h>
using	namespace	std;
int	judge(int	a[],int	n);
bool	cmp(int	a,int	b)
{
	return	a>b;
}
int	main()
{
	int	N;
	cin>>N;
	while(N--)
	{
		int	n;
		cin>>n;
		int	a[n+1];
		int	k=1;
		for(int	i=0;i<n;i++)						
			cin>>a[i];
		sort(a,a+n,cmp);
		for(int	j=0;j<n;j++)
		{
			for(int	i=1;i<=a[j];i++)
			{
				a[j+i]=a[j+i]-1;
			}
			if(judge(a,n))
			{
				k=0;
				break;
			}
			sort(a+j+1,a+n,cmp);
		}
		/*for(int	i=0;i<n;i++)
			cout<<a[i]<<endl;*/
		if(k)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}
int	judge(int	a[],int	n)
{
	for(int	i=0;i<n;i++)
	{
		if(a[i]<0)
			return	1;//±¨¸æÎªÊ§°Ü 
	}
	return	0; 
}
