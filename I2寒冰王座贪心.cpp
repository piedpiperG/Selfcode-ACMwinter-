#include<bits/stdc++.h>
using	namespace	std;
int	main()
{
	int	N;
	cin>>N;
	while(N--)
	{
		int	n;
		scanf("%d",&n);
		int	c;
		int	r=n;
		if(n>=350)
			c=1;
		else	if(n<350&&n>=200)
			c=2;
		else	if(n<200&&n>=150)
			c=3;
		else	if(n<150)
			c=4;
		switch(c){
			case	1:
				r=r%350;
				if(r<150)
					break;
			case	2:
				r=r%200;
				if(r<150)
					break;
			case	3:
				r=r%150;
		}		
		printf("%d\n",r);
	}
}
