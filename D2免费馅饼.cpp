#include<bits/stdc++.h>
using	namespace	std;
int	spemax(int	a,int	b,int	c);
int	arr[100000][12];//����ʱ�䣬����ص㣨0~11�� 
int	main()
{
	int	n;
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		
		memset(arr,0,sizeof(arr));
		int	loc,tim;
		int	mtim=0;
		for(int	i=0;i<n;i++)
		{
			scanf("%d%d",&loc,&tim);
			arr[tim][loc]++;
			mtim=max(mtim,tim);//������һ���ڱ�����ʱ��ʱ�� 
		}
		for(int	i=mtim-1;i>=0;i--)
		{
			for(int	k=0;k<=10;k++)
			{
				if(k==0)
					arr[i][k]=max(arr[i+1][k],arr[i+1][k+1])+arr[i][k];//��Ե������ʱλ����������ˣ�û���������������ݣ� 
				else
					arr[i][k]=spemax(arr[i+1][k-1],arr[i+1][k],arr[i+1][k+1])+arr[i][k];
			}
		}
		cout<<arr[0][5]<<endl;
	}
	return	0; 
}
int	spemax(int	a,int	b,int	c)
{
	int	t;
	t=a>b?(a>c?a:c):(b>c?b:c);
	return	t;
}
/*
for(int	i=0;i<=3;i++)
		{
			for(int	k=0;k<=10;k++)
				cout<<arr[k][i]<<" ";
			cout<<endl;
		}*/
