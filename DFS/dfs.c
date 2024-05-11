#include<stdio.h>
#define mx 100

int visited[mx+1];
int graph[mx+1][mx+1];
void dfs(int v,int n)
{
     printf("%d ",v);
    visited[v]=1;
   
        for(int i=0;i<n;i++)
        {
            if((graph[v][i]==1) && (!visited[i]))
            {
                dfs(i,n);
            }
        }
   
}
int main()
{
    int n,e;
    scanf("%d %d",&n,&e);

    for(int i=0;i<n;i++)
    {
        visited[i]=0;
      
        for(int j=0;j<n;j++)
        {

            graph[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        graph[u][v]=1;
        graph[v][u]=1;

    }
    int source;
    scanf("%d",&source);
    printf("DFS TRAVERSEL : ");
    dfs(source,n);
    
}
