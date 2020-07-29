#include <iostream>
#include <queue>

using namespace std;

int N,M;
int map[8][8]={0,};
int visited[8][8]={0,};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int MAX=0;
//0은 빈 칸, 1은 벽, 2는 바이러스가
//벽 3개 설치 , 안전 영역 최댓값 구하기


void BFS()
{
    int tmp[8][8];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            tmp[i][j]=map[i][j];
    }
    
    queue <pair<int,int>> q;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            
            if(tmp[i][j]==2)    q.push(make_pair(i, j));
            
            while(!q.empty()){
                
                int x = q.front().first;
                int y = q. front().second;
                
                q.pop();
                
                for(int k=0;k<4;k++){
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    if(nx<0 || ny <0 || nx >= N || ny >= M) continue;
                    if(tmp[nx][ny] == 0){
                        q.push(make_pair(nx, ny));
                        tmp[nx][ny]=2;
                    }
                }
            }
        }
    }
    
    int cnt =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(tmp[i][j]==0)    cnt++;
        }
    }
    if(MAX < cnt)   MAX =cnt;
    
}
           
void DFS(int cnt){
    if(cnt == 3){
        BFS();
        return;
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j]==0 && map[i][j] == 0 ){
                visited[i][j]=1;
                map[i][j] = 1;
                DFS(cnt+1);
                map[i][j]=0;
                visited[i][j]=0;
            }
        }
    }
}

int main(void)
{
    cin >> N >>M ;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
        }
    }
    
    DFS(0);
    cout << MAX;
    return 0;
}

