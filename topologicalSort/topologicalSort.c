#include<stdio.h>
#define mx 1000
int queue[mx];
int visited[mx+1]={0};
int graph[mx+1][mx+1];
int indegre[mx+1]={0};
void topSort(int n)
{
    int front=-1,back=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(indegre[i]==0)
        {
            queue[++back]=i;
           
        }
    }
    
    
    
  //  printf("BFS ORDER: ");
    while(front!=back)
    {
        int current=queue[++front];
        printf("%d ",current);
        visited[current]=1;
        for(int i=0;i<n;i++)
        {
            if(graph[current][i]==1 && visited[i]==0)
            {
                indegre[i]--;
                
                if(indegre[i]==0 )
                {
                   // printf("%d ",i);
                    visited[i]=1;
                    queue[++back]=i;
                }
            }
            
        }
    }printf("\n");
}
int main()
{
    int n,e;
    scanf("%d %d",&n,&e);

    int cpunt=0;

    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        indegre[i]=0;
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
        indegre[v]++;
        

    }
    
    topSort(n);
    
}
