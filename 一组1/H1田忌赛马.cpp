#include<bits/stdc++.h>
using	namespace	std;
int	main()
{
	int	n;
	while(cin>>n)	
	{
		if(n==0)
			break;
		int	t[n],k[n];
		for(int	i=0;i<n;i++)
			cin>>t[i];
		for(int	i=0;i<n;i++)
			cin>>k[i];
		sort(t,t+n);
		sort(k,k+n);
		int	count=0;
		int	m=0;//��ʼ�����������λ�ã���ʾ��һ���Ѿ������������ˣ������ظ� 
		for(int	i=0;i<n;i++)
		{
			for(int	j=m;j<n;j++)
			{
				if(t[i]>k[j])//����������������κ͹�����ǿ������бȽϣ���Ӯ���������һ 
				{
					count++;
					m=j+1;
					break;
				}
			}
		}
		cout<<200*(2*count-n)<<endl;
	}
} 
