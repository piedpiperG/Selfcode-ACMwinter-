#include<stdio.h>
#include<string.h>
int map[105][105],pre[105],vis[105];
int n,m;
int hungry(int u)
{
       int v;
       for(v=1;v<=m;v++)
       {
              if(map[u][v]&&vis[v]==0)
              {
                     vis[v]=1;
                     if(pre[v]==-1||hungry(pre[v]))
                     {
                            pre[v]=u;
                            return 1;
                     }
              }
       }
       return 0;
}
int nump()
{
       int ans=0,i;
       memset(pre,-1,sizeof(pre));
       for(i=1;i<=n;i++)
       {
             memset(vis,0,sizeof(vis));
             if(hungry(i))
                 ans++;
       }
       return ans;
}
int main()
{
       int i,j,c,r,k,num,cas=1,temp;
       while(scanf("%d%d%d",&n,&m,&k)!=EOF)
       {
              num=0;
              memset(map,0,sizeof(map));
              for(i=1;i<=k;i++)
              {
                     scanf("%d%d",&c,&r);
                     map[c][r]=1;
              }
              temp=nump();
             for(i=1;i<=n;i++)
               for(j=1;j<=m;j++)
               {
                      if(map[i][j]==1)
                      {
                             map[i][j]=0;
                             if(nump()<temp)
                               num++;
                             map[i][j]=1;
                      }
               }
              printf("Board %d have %d important blanks for %d chessmen.\n",cas++,num,temp);
       }
       return 0;
}
