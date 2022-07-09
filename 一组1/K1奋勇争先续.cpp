#include<bits/stdc++.h>
using	namespace	std;
struct	student{
	char	name[10];
	int		num;
	int		time;
}arr[1000];
bool	cmp(student	x,student	y)
{
	if(x.num==y.num){return	x.time<y.time;};
	return	x.num>y.num;
}
int	main()
{
	int	N;
	cin>>N;
	while(N--)
	{
		int	n;
		int	m;
		cin>>n>>m;
		for(int	i=0;i<n;i++)
		{
			cin>>arr[i].name;
			cin>>arr[i].num;
			cin>>arr[i].time;
		}
		sort(arr,arr+n,cmp);
		for(int	i=0;i<m;i++)
		{
			cout<<arr[i].name<<" "<<arr[i].num<<" "<<arr[i].time<<endl;
		}
	}
}
