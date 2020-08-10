#include <iostream>
#include <queue>
#include <cmath>

#define MAX 50
using namespace std;

int N , L , R;
int map[MAX][MAX]={0,};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main(void)
{
    int move=0;
    
    cin >> N >> L >> R;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }
    
    queue <pair<int,int>> q;
    
    while(1){
        int tmp[MAX][MAX]={0,};
        int visited[2501]={0,};
        int cnt =0;
        int flag =0;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                
                int num =0;
                
                if(tmp[i][j] == 0)
                {
                    cnt ++ ;
                    tmp[i][j] = cnt;
                    visited[cnt]+=map[i][j];
                    num++;
                    q.push(make_pair(i,j));
                
                
                    while(!q.empty()){
                        
                        int x = q.front().first;
                        int y = q.front().second;
                        
                        q.pop();
                        
                        for(int k =0;k<4 ;k ++){
                            int nx = x+dx[k];
                            int ny = y+dy[k];
                            
                            if( nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                            
                            int cmp = map[x][y] > map[nx][ny] ?  map[x][y] - map[nx][ny] : map[nx][ny] - map[x][y];

                            if(L <= cmp && cmp <= R && tmp[nx][ny] ==0 ){
                                flag=1;
                                q.push(make_pair(nx,ny));
                                tmp[nx][ny]=cnt;
                                visited[cnt]+=map[nx][ny];
                                num++;

                            }
                        }
                    }
                    visited[cnt] = trunc(visited[cnt]/num);
                }
            }
        }
        if(flag == 1)   move ++;
        else    break;
        
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                map[i][j] = visited[tmp[i][j]];
            }
        }
    }

    cout << move;
    
    return 0;
}

