#include<stdio.h>
#define mx 1000
int queue[mx];
int visited[mx+1]={0};
int graph[mx+1][mx+1];
void bfs(int v,int n)
{
    int front=-1,back=-1;
    visited[v]=1;
    queue[++back]=v;
    printf("BFS ORDER: ");
    while(front!=back)
    {
        int current=queue[++front];
        printf("%d ",current);

        for(int i=0;i<n;i++)
        {
            if((graph[current][i]==1) && (!visited[i]))
            {
                visited[i]=1;
                queue[++back]=i;
            }
        }
    }printf("\n");
}
int main()
{
    int n,e;
    scanf("%d %d",&n,&e);

    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        queue[i]=0;
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
    bfs(source,n);
    
}
