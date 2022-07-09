#include<bits/stdc++.h>
using	namespace	std;
double	equation(double	x);
int	main()
{
	int	n;
	cin>>n;
	double	y;
	double	left,right,mid;
	while(n--)
	{
		cin>>y;
		if(equation(0)<=y&&y<=equation(100))//判断方程是否有解 
		{
			left=0;
			right=100;
			while(right-left>1e-6)//精度控制 
			{
				mid=(left+right)/2;
				double	ans=equation(mid);
				if(ans>y)
					right=mid-1e-7;
				else
					left=mid+1e-7;
			}
			printf("%.4lf\n",(left+right)/2);
		}
		else
			cout<<"No solution!"<<endl;
	}
}
double	equation(double	x)
{
	return	8*pow(x,4.0)+7*pow(x,3.0)+2*pow(x,2.0)+3*x+6;
}
