#include<bits/stdc++.h>
using	namespace	std;
struct	show{
	int	a;	int	b;//��ʼʱ�������ʱ�� 
}arr[100];
bool	cmp(show	x,show	y)
{
	if(x.b==y.b){return	x.a<y.a;};
	return	x.b<y.b;
}
int	main()
{
	int	n;
	while(cin>>n)
	{
		if(n==0)
			break;
		for(int	i=0;i<n;i++)
			cin>>arr[i].a>>arr[i].b;
		int	count=1;
		int	m=0;
		sort(arr,arr+n,cmp);
		/*for(int	i=0;i<n;i++)
			cout<<arr[i].a<<" "<<arr[i].b<<endl;*/
		for(int	j=1;j<n;j++)
		{
			for(int	i=1;i<n;i++)
			{
				if(arr[m+i].a>=arr[m].b)
				{
					count++;
					m=m+i;
					break;
				}
			}
		}						//��˫ѭ��������������⣬����tm�е���� (ȷ��ÿһ����Ŀ�Ŀ����Զ��õ����ϣ� 
		cout<<count<<endl;
	}
	return	0;
}
