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
		int	m=0;//开始搜索国王马的位置，表示上一次已经搜索到这里了，避免重复 
		for(int	i=0;i<n;i++)
		{
			for(int	j=m;j<n;j++)
			{
				if(t[i]>k[j])//将田忌最弱的马依次和国王最强的马进行比较，若赢了则计数加一 
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
