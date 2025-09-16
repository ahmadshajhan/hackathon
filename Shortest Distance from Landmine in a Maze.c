#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 4
int maze[N][M] = {
    {1,0,1,1},
    {1,1,-1,1},
    {1,1,1,1},
    {0,-1,1,1}
};

int dist[N][M];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

typedef struct {
    int x,y;
} Point;

Point queue[100];
int front=0, rear=0;

void enqueue(Point p){ queue[rear++]=p; }
Point dequeue(){ return queue[front++]; }
int isEmpty(){ return front==rear; }

void bfs() {
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            dist[i][j] = (maze[i][j]==-1)?-1:9999;

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(maze[i][j]==0){ dist[i][j]=0; enqueue((Point){i,j}); }

    while(!isEmpty()) {
        Point p=dequeue();
        for(int k=0;k<4;k++) {
            int nx=p.x+dx[k], ny=p.y+dy[k];
            if(nx>=0&&ny>=0&&nx<N&&ny<M && maze[nx][ny]!=-1) {
                if(dist[nx][ny] > dist[p.x][p.y]+1) {
                    dist[nx][ny] = dist[p.x][p.y]+1;
                    enqueue((Point){nx,ny});
                }
            }
        }
    }
}

int main() {
    bfs();
    printf("Distance from nearest landmine:\n");
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(dist[i][j]==-1) printf("X ");
            else printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
}
