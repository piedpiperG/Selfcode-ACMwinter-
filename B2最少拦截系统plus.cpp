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
		//��������洢������ 
		int	F[n];
		for(int	i=0;i<n;i++)
			F[i]=1;
		for(int	i=1;i<n;i++)
		{
			int	b[i];//�洢��Ӧǰ��ÿһ��Ԫ�ص�������ֵ
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
		/*//��֤����������
		for(int	i=0;i<n;i++)
			cout<<F[i]<<" ";
		cout<<endl;*/ 
		sort(F,F+n,cmp);
		cout<<F[0]<<endl;
	}
}
