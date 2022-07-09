#include<bits/stdc++.h>
using	namespace	std;
bool	cmp(int	a,int	b)
{
	return	a>b;
}
int	main()
{
	int	n;
	while(cin>>n)
	{
		int	arr[n];
		for(int	i=0;i<n;i++)
			cin>>arr[i];
		//构造数组存储子序列 
		int	F[n];
		for(int	i=0;i<n;i++)
			F[i]=1;
		for(int	i=1;i<n;i++)
		{
			int	b[i];//存储对应前面每一个元素的子序列值
			memset(b,0,sizeof(b));
			for(int	j=i-1;j>=0;j--)
			{
				if(arr[i]>arr[j])
				{
					b[j]=F[j]+1;
				}
			}
			sort(b,b+i,cmp);
			if(b[0]!=0)
				F[i]=b[0];											
		}
		/*//验证子序列数组
		for(int	i=0;i<n;i++)
			cout<<F[i]<<" ";
		cout<<endl;*/ 
		sort(F,F+n,cmp);
		cout<<F[0]<<endl;
	}
}
