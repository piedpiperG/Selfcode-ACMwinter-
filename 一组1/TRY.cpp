#include<bits/stdc++.h>
using namespace std;
int t[100005][15];//��ʾT��ʱ�ڱ����ڶ�Ӧ�����λ��
int main()
{
    int N,x,T,mt;//mt�Ǽ�¼���ʱ��
    while(~scanf("%d",&N)&&N){//�ڱ����ܸ���
        mt=0;
        memset(t,0,sizeof(t));//��ʼ������t
        for(int i=0;i<N;i++){
            cin>>x>>T;
            t[T][x]++;//��ʾ��ͬʱ����ı���
            mt=max(mt,T);//ȡ����ʱ��
        }
        for(int i=mt-1;i>=0;i--){//�ӵײ㿪ʼ������(����)
            for(int j=0;j<=10;j++){//ö������λ��
                if(j==0)t[i][j]=max(t[i+1][j],t[i+1][j+1])+t[i][j];//ֻ��ö������
                else t[i][j]=max(max(t[i+1][j],t[i+1][j+1]),t[i+1][j-1])+t[i][j];//�Ƚ���һ�������λ�õ������ȡ���
            }
        }
        cout<<t[0][5]<<endl;//������ϲ������T=0���м�Ľ��
    }
    return 0;
}
