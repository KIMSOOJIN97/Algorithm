#include <iostream>
#include <vector>

#define MAX 8

using namespace std;

struct pos{
    int x,y;
};

int N,M;
int map[MAX][MAX];

int virus_x[64]={0,};
int virus_y[64]={0,};
int virus=0;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int MAX_AREA = 0;

vector <pos> empty;


int BFS()
{
    
    int visited[MAX][MAX];
    int x,y;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            visited[i][j] = map[i][j];
    }
    

    int tmp_vir = virus;
    
    for(int i=0;i<tmp_vir;i++){
        x = virus_x[i];
        y = virus_y[i];
        for(int k=0;k<4;k++){
            
            int nx = x+dx[k];
            int ny = y+dy[k];
                
            if(nx < 0 || ny <0 || nx >= N || ny >= M || visited[nx][ny] != 0)   continue;
            visited[nx][ny] = -1;
            virus_x[tmp_vir]=nx;
            virus_y[tmp_vir]=ny;
            tmp_vir++;
        }
    }
    
    
    int cnt =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j]==0)    cnt++;
        }
    }
    
    return cnt;
    
}

int main(void)
{

    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            
            if(map[i][j] == 2) {
                virus_x[virus] = i;
                virus_y[virus] = j;
                virus++;
            }
            else if(map[i][j]==0)   empty.push_back({i,j});
        }
    }
    
    int size = empty.size();
    
    
    for(int i=0;i<size-2;i++){
        for(int j=i+1;j<size-1;j++){
            for(int k=j+1;k<size;k++){
                

                map[empty[i].x][empty[i].y] = 1;
                map[empty[j].x][empty[j].y] = 1;
                map[empty[k].x][empty[k].y] = 1;
                
                int cnt = BFS();
                if( MAX_AREA < cnt) MAX_AREA = cnt;

                map[empty[i].x][empty[i].y] = 0;
                map[empty[j].x][empty[j].y] = 0;
                map[empty[k].x][empty[k].y] = 0;
            }
        }
    }
    
    cout << MAX_AREA;

    return 0;
    
}

