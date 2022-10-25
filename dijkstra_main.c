#include <stdio.h>          //printf
#include <string.h>        //memset

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[93m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"








#define ULIMIT   99
#define MAXN  1001
int g[MAXN][MAXN];
int visited[MAXN];
int dist[MAXN];

void print_dist(int n,int u, int v )
{
    int i;

    printf("================================\n");
    for( i = 1; i <=  v; i ++)
    {
        if( i == n)
            printf(ANSI_COLOR_RED"  %d"ANSI_COLOR_RESET, i);
        else
            printf(ANSI_COLOR_GREEN"  %d"ANSI_COLOR_RESET, i);
    }

    printf("\n");
    for( i = 1; i <=  v; i ++)
    {
        if( i == u)
            printf(ANSI_COLOR_YELLOW" %.2d"ANSI_COLOR_RESET, dist[i]);
        else
            printf(" %.2d", dist[i]);
    }

    printf("\n");
    printf("================================\n");

}

int find(int v)
{
    int i;
    int min = ULIMIT, min_v = 0;


    for(i = 0; i <=v ; i++)
    {   
        if( dist[i] < min && !visited[i])
        {   
            min = dist[i];
            min_v= i;
        }   
    }   
    
    return min_v;
}

void dijkstra(int start, int v)
{
    int i,j;
    
    memset(dist, ULIMIT,MAXN);
    dist[start]=0;
    visited[start]=1;

    printf("init \n");
    for(i = 1; i <= v ; i++)
        dist[i] = g[start][i];

    print_dist(start, 0 ,v);
    printf("\n\n\n");

    for (i = 1 ;i<=v ;i++)
    {
        int n = find(v);
        visited[n] = 1;

        for (j = 1; j <=v; j++)
        {
            if( !visited[j] && (dist[n] + g[n][j] < dist[j] ))
            {
                dist[j] = dist[n] + g[n][j];
                print_dist(n,j,v);
            }
        }
        printf("\n");
    }

    printf("\nresult \n");
    print_dist(0 ,0 ,v);

}

int main(int argc , char *argv[])
{
    int i,j;
    int V, E;
    int sn, en, val;
    printf("start\n");
    freopen("input2.txt","r",stdin);

    scanf("%d %d", &V, &E);
    printf("\t Vertex(노드 갯수) : %d, Edge(간선 갯수) : %d\n",V,E);
    for(i = 0; i <E ; i++)
    {
        scanf("%d %d %d", &sn, &en, &val);
        g[sn][en] = g[en][sn] = val;
    }

    for(i=1;i<=V;i++)
        for(j=1;j<=V;j++)
            if(i!=j&&!(g[i][j]))
                    g[i][j]=ULIMIT;

    for( i = 0 ; i <= V ; i++)
    {
        for( j = 0; j <= V; j++)
        {
            if (i == 0)
                printf(ANSI_COLOR_RED "  %d" ANSI_COLOR_RESET, j);
            else if (j == 0)
                printf(ANSI_COLOR_RED "  %d"ANSI_COLOR_RESET, i);
            else
                printf(" %.2d", g[i][j]);
        }
        printf("\n");

    }


    printf("--- Dijkstra ---\n");
    memset(visited, 0x00, sizeof(int)*MAXN);
    dijkstra(1,V);
    printf("\n--- END ---\n");

    return 0;
}