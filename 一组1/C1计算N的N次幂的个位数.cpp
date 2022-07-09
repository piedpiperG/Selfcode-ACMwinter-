#include<iostream>
using	namespace	std;
int	main()
{
	int	N;
	cin>>N;
	for(int	i=0;i<N;i++)
	{
		int	n=10;
		int	a[n];	
		int	x1,x2;
		cin>>x1;
		x2=x1%10;
		a[0]=x2;
		int	count;
		int	remain;
		for(int	i=1;;i++)
		{
			a[i]=(a[i-1]*x2)%10;
			if(a[i]==a[0])
			{
				count=i;
				break;
			}
		}
		remain=x1%count;
		if(remain)
			cout<<a[remain-1]<<endl;
		else
			cout<<a[count-1]<<endl;
	}
	
	
}

