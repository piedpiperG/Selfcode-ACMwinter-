#include<bits/stdc++.h>
using	namespace	std;
int	decide(int	a,int	b);
int	main()
{
	int	N;
	cin>>N;
	while(N--)
	{
		int	n;
		cin>>n;//数塔层数 
		//输入程序 
		long	long	arr[n][n];//构建数塔 
		int	j=1;
		for(int	i=0;i<n;i++)
		{
			for(int	k=0;k<j;k++)
			{
				cin>>arr[i][k];
			}
			j++;
		}
		/*//测试输入数塔结果
		j=1;
		for(int	i=0;i<n;i++)
		{
			for(int	k=0;k<j;k++)
			{
				cout<<arr[i][k]<<" ";	
			}
			j++;
			cout<<endl;	
		}*/
		//构建结果数组
		j=n-2; 
		for(int	i=n-2;i>=0;i--)
		{
			for(int	k=0;k<=j;k++)
			{
				arr[i][k]=arr[i][k]+decide(arr[i+1][k],arr[i+1][k+1]);
			}
			j--;
		}
		/*//测试输出数塔结果
		cout<<"输出结果如下："<<endl; 
		j=1;
		for(int	i=0;i<n;i++)
		{
			for(int	k=0;k<j;k++)
			{
				cout<<arr[i][k]<<" ";	
			}
			j++;
			cout<<endl;	
		}*/
		//结果输出 
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
