#include <iostream>
#include <queue>

#define MAX 101

using namespace std;


int N;
int map[MAX][MAX]={0,};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


// 적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 공백으로 구분해 출력한다.
//빨 초 구분 못해

void BFS()
{
    
    int tmp[MAX][MAX]={0,};
    int cnt =0;


    queue <pair<int,int>> q;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){

            if(tmp[i][j]==0)
            {
                q.push(make_pair(i,j));
                tmp[i][j]=1;
                cnt++;
            }
            
            while(!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                
                for(int k=0;k<4;k++){
                    int nx = x+ dx[k];
                    int ny = y+dy[k];
                    
                    if(nx <0 || ny <0 || nx >= N || ny >= N)    continue;
                    if(map[x][y] == map[nx][ny] && tmp[nx][ny]==0){
                        q.push(make_pair(nx,ny));
                        tmp[nx][ny]=1;
                    }
                }
            }
        }
    }
    cout << cnt << " ";

}

int main(void)
{
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char ch;
            cin >>ch;
            
            if(ch=='R')  map[i][j]=1;
            else if (ch== 'G')  map[i][j]=2;
            else map[i][j]=3;
                        
        }
    }
    
    BFS();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]==2)    map[i][j]=1;
        }
    }
    BFS();
    return 0;
    
}

