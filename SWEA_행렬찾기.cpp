
#include <iostream>
#include <queue>
#include <vector>

#define MAX 100

using namespace std;

int map[MAX][MAX];
int visited[MAX][MAX]={0,};
int cnt=0;
int N;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct pos{
    int x,y;
};

struct INFO{
    int score, total, row, col;
};

void print()
{
    vector <INFO> chemical;
    
    cout << cnt << " ";
    
    for(int k=1;k<=cnt;k++){
        
        int row=0;
        int col=0;
        
        int flag =0;
        int total=0;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(visited[i][j]==k)    total++;
                if(flag==0 && visited[i][j]==k && col==0){
                    flag=1;
                    col++;
                }
                else if(flag && visited[i][j]==k)   col++;
            }
            flag=0;
        }

        row = total / col;
        int score =(total << 10)+(row << 5) + col ;
        chemical.push_back({score,total,row,col});
    }

    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt-1;j++){
            if(chemical[j].score > chemical[j+1].score){
                INFO tmp = chemical[j];
                chemical[j] = chemical[j+1];
                chemical[j+1] = tmp;
            }
        }
    }

    for(int i=0;i<cnt;i++){
        //cout << chemical[i].score <<  " ";
        cout <<chemical[i].row << " " << chemical[i].col <<" ";
    }
    cout << " \n";
    return ;
}


void BFS()
{
    queue <pos> q;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            
            if(visited[i][j]==0)    {
                visited[i][j] =-1;
                if(map[i][j] !=0 ){
                    q.push({i,j});
                    cnt++;
                }

            }
            
            while(!q.empty()){
                
                int x= q.front().x;
                int y= q.front().y;
                
                visited[i][j]=cnt;
                q.pop();
                
                for(int k=0;k<4;k++){
                    
                    int nx = x+ dx[k];
                    int ny = y+ dy[k];
                    
                    if(nx<0 || ny <0 || nx >= N || ny >= N) continue;
                    
                    if(map[nx][ny] !=0 && visited[nx][ny] ==0 ){
                        q.push({nx,ny});
                        visited[nx][ny]=cnt;
                    }
                }
                
            }
        }
    }
    print();
    return;
}

void init()
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)    visited[i][j]=0;
    }
    cnt =0;
    return ;
}

int main(void)
{
    int T;
    cin >> T;
    for(int k=0;k<T;k++){
        cin >> N;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> map[i][j];
            }
        }

        cout << "#" << k+1 <<" ";

    init();
    BFS();
    }
    return 0;
}

