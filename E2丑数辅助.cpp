#include<bits/stdc++.h>
using	namespace	std;
#define	SIZE	423301
#define	INFI	9223372036854775805
long	long	arr[SIZE];
int comp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;// 从小到大排序
}
int	main()
{

	int	count=2;
	memset(arr,0,sizeof(arr));
	//第一组 
	for(int	i=1;i<=30;i++)
	{
		arr[count]=pow(2,i);
		count++;
	}
	for(int	i=1;i<=19;i++)
	{
		arr[count]=pow(3,i);
		count++;
	}
	for(int	i=1;i<=13;i++)
	{
		arr[count]=pow(5,i);
		count++;	
	}	
	for(int	i=1;i<=11;i++)
	{
		arr[count]=pow(7,i);
		count++;	
	}
	//第二组
	for(int	i=1;i<=30;i++)
		for(int	j=1;j<=30;j++) 
		{
			arr[count]=pow(2,i)*pow(3,j);
			count++;	
		}
	for(int	i=1;i<=30;i++)
		for(int	j=1;j<=30;j++)
		{
			arr[count]=pow(2,i)*pow(5,j);
			count++;	
		}
	for(int	i=1;i<=30;i++)
		for(int	j=1;j<=30;j++)
		{
			arr[count]=pow(2,i)*pow(7,j);
			count++;	
		}
	for(int	i=1;i<=19;i++)
		for(int	j=1;j<=19;j++)
		{
			arr[count]=pow(3,i)*pow(5,j);
			count++;	
		}
	for(int	i=1;i<=19;i++)
		for(int	j=1;j<=19;j++)
		{
			arr[count]=pow(3,i)*pow(7,j);
			count++;
		}
	for(int	i=1;i<=13;i++)
		for(int	j=1;j<=13;j++)
		{
			arr[count]=pow(5,i)*pow(7,j);
			count++;	
		}
	//第三组 
	for(int	i=1;i<=30;i++)
		for(int	j=1;j<=30;j++)
			for(int	k=1;k<=30;k++)
			{
				arr[count]=pow(2,i)*pow(3,j)*pow(5,k);
				count++;
			}
	for(int	i=1;i<=30;i++)
		for(int	j=1;j<=30;j++)
			for(int	k=1;k<=30;k++)
			{
				arr[count]=pow(2,i)*pow(3,j)*pow(7,k);
				count++;
			}
	for(int	i=1;i<=19;i++)
		for(int	j=1;j<=19;j++)
			for(int	k=1;k<=19;k++)
			{
				arr[count]=pow(7,i)*pow(3,j)*pow(5,k);
				count++;
			}
	for(int	i=1;i<=30;i++)
		for(int	j=1;j<=30;j++)
			for(int	k=1;k<=30;k++)
			{
				arr[count]=pow(2,i)*pow(7,j)*pow(5,k);
				count++;
			}
	//第四组 
	for(int	i=1;i<=24;i++)
		for(int	j=1;j<=24;j++)
			for(int	k=1;k<=24;k++)
				for(int	w=1;w<=24;w++)
				{
					arr[count]=pow(2,i)*pow(3,j)*pow(5,k)*pow(7,w);
					count++;
				}
	for(int	i=1;i<=SIZE;i++)
	{
		if(arr[i]<0||arr[i]>2000000000)
			arr[i]=INFI;
	}
	sort(arr,arr+SIZE+1);
	//cout<<count<<endl;
	arr[1]=1;
	for(int	i=1;i<=5842;i++)
		cout<<arr[i]<<",";
}
/*
for(int	i=1;i<=30;i++)
	cout<<arr[i]<<endl;
*/
