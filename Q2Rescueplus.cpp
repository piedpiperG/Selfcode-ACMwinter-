#include<bits/stdc++.h>
using	namespace	std;
#define	inf	0x3f3f3f3f
#define	size	205
int		m,n;//行纵
char	Map[size][size];
int		vis[size][size];
int		fa[size],fb[size];//朋友坐标(应对有多个朋友）
int		k=0;//朋友计数 
int		result;
int		aa,ab;//公主坐标
int		sa,sb;
int 	dir[4][2]= {{0,1},{0,-1},{1,0},{-1,0}};		
struct pos
{
    int a,b,steps;//横纵坐标，步数 
    friend bool operator<(pos t1,pos t2)
    {
        return t1.steps>t2.steps;
    }
};
int	bfs(int	sa,int	sb,int	aa,int	ab);
int	judge(int	a,int	b);//判断是否出界 
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0; i<n; i++)
        {
            scanf("%s",&Map[i]);
            for(int j=0; j<m; j++)
            {
                if(Map[i][j]=='a')
                {
                    aa=i;
                    ab=j;
                }
                if(Map[i][j]=='r')
                {
                    sa=i,sb=j;
                }
            }
        }
        int result=bfs(sa,sb,aa,ab);
        if(result!=-1)
        printf("%d\n",result);
        else{
            printf("Poor ANGEL has to stay in the prison all his life.\n");
        }
    }
    return 0;
}
int bfs(int sa,int sb,int aa,int ab)
{
    pos fr,ne;
    memset(vis,0,sizeof(vis));
    priority_queue<pos>q;
    while(!q.empty())
    {
        q.pop();
    }
    fr.a=sa,fr.b=sb,fr.steps=0;
    q.push(fr);
    vis[sa][sb]=1;
    while(!q.empty())
    {
        fr=q.top();
        q.pop();
        if(fr.a==aa&&fr.b==ab)
        {
            return fr.steps;
        }
        for(int i=0;i<4;i++)
        {
            ne.a=fr.a+dir[i][0];
            ne.b=fr.b+dir[i][1];
            ne.steps=fr.steps+1;
            if(Map[ne.a][ne.b]!='#'&&ne.a>=0&&ne.a<n&&ne.b>=0&&ne.b<m&&!vis[ne.a][ne.b])
            {
                if(Map[ne.a][ne.b]=='x')
                {
                    ne.steps++;
                    vis[ne.a][ne.b]=1;
                    q.push(ne);
                }
                else
                {
                    vis[ne.a][ne.b]=1;
                    q.push(ne);
                }
            }
        }
    }
    return -1;
}
