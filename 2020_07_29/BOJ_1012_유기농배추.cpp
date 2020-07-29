#include <iostream>
#include <queue>

using namespace std;

//가로 M, 세로 N, 배추 수 K
int M,N,K;
int map[50][50]={0,};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


void BFS()
{
    int visited[50][50]={0,};

    queue <pair<int,int>> q;
    int cnt=0;
    
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]==1 && visited[i][j]==0){
                cnt++;
                visited[i][j]=cnt;
                q.push(make_pair(i, j));
                
            }
            
            while(!q.empty()){
                int x= q.front().first;
                int y= q.front().second;
                q.pop();
                
                for(int k=0;k<4;k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    
                    if(nx < 0 || ny <0 || nx >= M || ny >= N)   continue;
                    if(map[nx][ny] == 1 && visited[nx][ny]==0){
                        visited[nx][ny]=1;
                        map[nx][ny]=cnt;
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
    cout << cnt <<"\n";
    
}
void Init(int tmp[50][50])
{
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++)
            map[i][j]=tmp[i][j];
    }
}

int main(void)
{
    int T; // number of test case
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> M >> N >> K ;
        int tmp[50][50]={0,};
        for(int j=0;j<K;j++){
            int x,y;
            cin >> x >> y;
            tmp[x][y]=1;
        }
        Init(tmp);
        BFS();
    }
    return 0;
    
}

