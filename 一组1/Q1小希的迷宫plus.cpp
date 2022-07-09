#include<bits/stdc++.h>
using	namespace	std;
struct	road{
	int	a;
	int	b;
}arr[100000];
//寻找最大值 
int		findmax(int	a,int	b)
{
	if(a>=b)
		return	a;
	else	
		return	b;
}
bool	cmp(road	x,road	y)
{
	return	findmax(x.a,x.b)>findmax(y.a,y.b);
}
//定义函数与全局变量 
int	bin[100000];
int	notice=0;
int	findx(int	x);
void	merge(int	x,int	y);
int	main()
{
	while(1)
	{
		int	count=0;
		int	max=0;
		notice=0;
		//输入道路信息 
		for(int	i=0;;i++)
		{
			cin>>arr[i].a>>arr[i].b;
			if(arr[i].a==0&&arr[i].b==0)
				break;
			if(arr[i].a==-1&&arr[i].b==-1)
				return	0;
			count++;
		}
		//寻找最大值 
		sort(arr,arr+count,cmp);
		max=findmax(arr[0].a,arr[0].b);
		//cout<<"max="<<max<<endl; 
		//初始化对应关系 
		for(int	i=1;i<=max;i++)
			bin[i]=i;
		//联通道路 (同时判断要联通的道路两侧是否已经联通，如已经联通的话，报错notice++）
		for(int	i=0;i<count;i++)
			merge(arr[i].a,arr[i].b);
		//判断是否出现多条分支情况
		int	compare[max];
		int	num=0;
		/*for(int	i=1;i<=max;i++)
			cout<<"findx(i)"<<findx(i)<<endl;*/
		int	m=0;
		for(int	i=1;i<=max;i++)
		{
			if(findx(i)==i)
			{
				m++;
				continue;
			}
			else
			{
				compare[i-m]=findx(i);
				num++;
			}
			
		}
		/*for(int	i=1;i<=num;i++)
			cout<<"compare[i]="<<compare[i]<<endl;*/
		for(int	i=1;i<num;i++)
		{
			int	temp;
			if(compare[i]!=compare[i+1])
			{
				notice++;
				//cout<<"notice ="<<notice<<endl; 
			}
		}
		//做出判断 
		if(notice)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
		//cout<<"notice ="<<notice<<endl;
		//重置对应关系 
		memset(bin,0,sizeof(bin));
	}
}
int	findx(int	x)
{
	int	r=x;
	while(bin[r]!=r)
		r=bin[r];
	return	r;
}
void	merge(int	x,int	y)
{
	int	fx,fy;
	fx=findx(x);
	fy=findx(y);
	//cout<<fx<<" "<<fy<<endl;
	if(fx!=fy)
		bin[fx]=fy;
	else	if(fx==fy)
		notice++;
	//cout<<"notice ="<<notice<<endl;
}
//?Riddler
