#include<bits/stdc++.h>
using	namespace	std;
struct	road{
	int	a;
	int	b;
}arr[100000];
//Ѱ�����ֵ 
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
//���庯����ȫ�ֱ��� 
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
		//�����·��Ϣ 
		for(int	i=0;;i++)
		{
			cin>>arr[i].a>>arr[i].b;
			if(arr[i].a==0&&arr[i].b==0)
				break;
			if(arr[i].a==-1&&arr[i].b==-1)
				return	0;
			count++;
		}
		//Ѱ�����ֵ 
		sort(arr,arr+count,cmp);
		max=findmax(arr[0].a,arr[0].b);
		//cout<<"max="<<max<<endl; 
		//��ʼ����Ӧ��ϵ 
		for(int	i=1;i<=max;i++)
			bin[i]=i;
		//��ͨ��· (ͬʱ�ж�Ҫ��ͨ�ĵ�·�����Ƿ��Ѿ���ͨ�����Ѿ���ͨ�Ļ�������notice++��
		for(int	i=0;i<count;i++)
			merge(arr[i].a,arr[i].b);
		//�ж��Ƿ���ֶ�����֧���
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
		//�����ж� 
		if(notice)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
		//cout<<"notice ="<<notice<<endl;
		//���ö�Ӧ��ϵ 
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
