#include<bits/stdc++.h>
using	namespace	std;
#define size 2005
int mini(int a,int b)
{
    return a<=b?a:b;
}
int comp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;// ��С��������
}
int	cost[size][1005];//��Ʒ������ 
int	main()
{
	int	n,k;//������Ʒ���Ἰ��
	while(cin>>n>>k)
	{
		long	long	arr[size];
		int i,j;
		memset(arr,0,sizeof(arr));
		for(int	i=1;i<=n;i++)
			cin>>arr[i];
		qsort(arr+1,n,sizeof(arr[0]),comp);
		//��ʼ��������� 
		for(int	i=0;i<=n;i++)
			for(int	j=1;j<=k;j++)
				cost[i][j]= 2147483641;
		cost[0][0]=0;
		//��ʼ���� 
		for(j=2; j<=n; j++)//��Ʒ�� 
		{
            for(i=1; i*2<=j; i++)//���� 
			{
				cost[j][i]=mini(cost[j-1][i],cost[j-2][i-1]+(arr[j]-arr[j-1])*(arr[j]-arr[j-1]));
			}
		}
		
		/*for(j=2; j<=n; j++)//��Ʒ�� 
            for(i=1; i*2<=j; i++)//���� 
				cout<<"i="<<i<<"j="<<j<<" "<<cost[j][i]<<endl;
		cout<<endl;
		for(int	i=1;i<=n;i++)
			cout<<arr[i]<<endl;
		//cout<<"   "<<cost[3][2]<<endl;
		*/
		cout<<cost[n][k]<<endl;
	} 
}
