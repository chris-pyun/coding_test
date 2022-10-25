#include <stdio.h>          //printf
#include <string.h>        //memset

#define MAXN 1001
int g[MAXN][MAXN];
int visited[MAXN];



void dfs1(int start, int v)
{
    int i;

    visited[start] = 1;
    printf("%d ", start );
    for(i = 1; i <= v; i++)
    {
        if(( g[ start ][ i ] == 1 ) && (visited[ i ] == 0))
        {
            dfs1(i, v);
        }
    }
}

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_YELLOW   "\x1b[93m"
#define ANSI_COLOR_BLUE     "\x1b[34m"
#define ANSI_COLOR_MAGENTA  "\x1b[35m"
#define ANSI_COLOR_CYAN     "\x1b[36m"
#define ANSI_COLOR_RESET    "\x1b[0m"


void print_deq(int *q,int v, int f)
{
    int i;
    printf("\ndeq q[%d]: %d \t\t |",f, q[f]);
    for(i = 0; i < v ; i++)
    {
        if( i == f )
            printf(ANSI_COLOR_YELLOW" %d "ANSI_COLOR_RESET"|",q[i]);
        else
            printf(" %d |",q[i]);
    }
    printf("  \n");
}
void print_inq(int *q,int v, int r)
{
    int i;
    printf("inq q[%d]: %d \t\t |",r, q[r]);
    for(i = 0; i < v ; i++)
    {
        if( i == r )
            printf(ANSI_COLOR_RED" %d "ANSI_COLOR_RESET"|",q[i]);
        else
            printf(" %d |",q[i]);
    }
    printf("  \n");
}

void bfs_debug(int start, int v)
{
    int front = 0;
    int rear = 1;
    int pop, q[MAXN];
    int i;

    q[0] = start;
print_inq(q, v, rear -1);
    visited[start] = 1;
//    printf("%d ", start);

    while( front < rear )
    {
        pop = q[ front++ ];
print_deq(q, v, front -1);
        for(i = 1; i <=  v;  i++)
        {
            if( g[ pop ][ i ] && (visited[ i ] == 0))
            {
                visited[i] = 1;
//                printf("%d ", i);
                q[ rear++ ] = i;
print_inq(q, v, rear -1);
            }
        }

    }

}

void bfs1(int start, int v)
{

    int front =0, rear =1;
    int pop, q[MAXN];
    int i;


    q[0] = start;
    visited[start] = 1;
    printf("%d ", start);

    while (front < rear)
    {
        pop = q[ front ++ ];
        for( i = 1; i <= v ; i++)
        {
            if( g[pop][i] && !visited[ i ])
            {

                visited[i] =1;
                printf("%d ", i);
                q[ rear++ ] = i;
            }
        }
    }
}

int main(int argc , char *argv[])
{
    int i,j;
    int V, E;
    int sn, en;
    printf("start\n");
    freopen("input.txt","r",stdin);

    scanf("%d %d", &V, &E);
    printf("\t Vertex(노드 갯수) : %d, Edge(간선 갯수) : %d\n",V,E);
    for(i = 0; i <E ; i++)
    {
        scanf("%d %d", &sn, &en);
        g[sn][en] = g[en][sn] = 1;
    }


    for( i = 0; i < V; i++)
    {
        for( j = 0; j < E; j++)
        {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }


    printf("--- DFS ---\n");
    dfs1(1, V);
    printf("\n--- END ---\n");
    memset(visited, 0x00, sizeof(int) * MAXN);
    printf("--- BFS ---\n");
    //bfs1(1, V);
    //memset(visited, 0x00, sizeof(int) * MAXN);
    //printf("\n");
    bfs_debug(1, V);
    printf("\n--- END ---\n");

    return 0;
}