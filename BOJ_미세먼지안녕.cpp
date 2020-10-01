#include <iostream>

#define MAX 50

using namespace std;

int map[MAX][MAX]={0,};

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int N, M, T;
int cx=0;

void spread()
{
    int visited[MAX][MAX]={0,};

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            
            if(map[i][j] < 5 )  continue;
            int cnt= 0;
            
            for(int k=0;k<4;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if(nx <0 || ny <0 || nx >= N || ny >= M ||map[nx][ny] == -1)    continue;
                cnt++;
                visited[nx][ny] += map[i][j]/5;
            }
            
            if(cnt == 0)   continue;
            map[i][j] = map[i][j] - (map[i][j]/5)*cnt;
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==-1)   continue;
            map[i][j]+=visited[i][j];
        }
    }
}

void move()
{
    int tmp1,tmp2,tmp3;
    
    tmp1 = map[cx][M-2];
    tmp2 = map[N-2][M-1];
    tmp3 = map[N-1][1];
    
    for(int i=M-2;i>1;i--)  map[cx][i] = map[cx][i-1];
    for(int i=N-2;i>cx;i--) map[i][M-1] = map[i-1][M-1];
    for(int i=1;i<M-1;i++)  map[N-1][i] = map[N-1][i+1];
    for(int i=cx+1;i<N-1;i++)   map[i][0] = map[i+1][0];
    
    map[cx][1]=0;
    map[cx][M-1]=tmp1;
    map[N-1][M-1] = tmp2;
    map[N-1][0]=tmp3;
    
    tmp1= map[cx-1][M-2];
    tmp2 = map[1][M-1];
    tmp3 = map[0][1];

    for(int i=M-2;i>1;i--)  map[cx-1][i] = map[cx-1][i-1];
    for(int i=1 ; i< cx-1 ; i++)  map[i][M-1] = map[i+1][M-1];
    for(int i=1;i<M-1;i++)  map[0][i] = map[0][i+1];
    for(int i=cx-2;i>0;i--)   map[i][0] = map[i-1][0];
    
    map[cx-1][1]=0;
    map[cx-1][M-1]=tmp1;
    map[0][M-1] = tmp2;
    map[0][0] = tmp3;
    
}

int main(void)
{
    scanf("%d %d %d",&N,&M,&T);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]==-1){
                cx = i;
            }
        }
    }
    
    for(int i=0;i<T;i++){
        spread();
        move();
    }
    
    int cnt =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]>0) cnt+=map[i][j];
        }
    }
    
    printf("%d",cnt);
    return 0;
    
}

