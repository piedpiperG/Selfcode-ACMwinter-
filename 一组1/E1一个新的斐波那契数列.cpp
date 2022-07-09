#include<bits/stdc++.h>
using	namespace	std;
int	Fibs(int	n);
int	main()
{
	int	a;
	while(cin>>a)
	{
		if(Fibs(a)%3)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
}
int	Fibs(int	n)
{
	if(n==0)
		return	7;
	if(n==1)
		return	11;
	else
		return	Fibs(n-1)+Fibs(n-2);
}
