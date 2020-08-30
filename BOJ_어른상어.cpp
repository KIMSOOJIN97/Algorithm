#include <iostream>
#include <vector>

#define MAX 21

using namespace std;


struct SHARK{
    int x,y,dir;
    bool die;
    
};

int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1};

int N,M,K;
int map[MAX][MAX];
int tm[MAX][MAX]={0,};
int idx[MAX][MAX]={0,};

int priority[401][5][5]={0,};

SHARK shark[401];


void move()
{
    int tmp[MAX][MAX]={0,};
    int tm_tmp[MAX][MAX]={0,};
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(tm[i][j]!=0)    tm_tmp[i][j] = tm[i][j];
            else    tm_tmp[i][j] = 0;
        }
    }
    
    
    for(int i=1;i<=M;i++)
    {
        if(shark[i].die)    continue;
        
        int x = shark[i].x;
        int y = shark[i].y;
        int dir = shark[i].dir;
        
        int flag=0;
        
        for(int j=1;j<5;j++){
            
            int ndir = priority[i][dir][j];
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];
            
            
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N )    continue;
            else if(idx[nx][ny] != 0 && tm_tmp[nx][ny] !=0){
                continue;
            }
            else{
                flag =1;

                if(tmp[nx][ny] != 0){
                    int num = tmp[nx][ny];
                    if(num > i) {
                        tmp[nx][ny]=i;
                        shark[num].die = true;
                    }
                    else{
                        shark[i].die=true;
                        break;
                    }
                }
                else    tmp[nx][ny]=i;
                
                shark[i].x = nx;
                shark[i].y = ny;
                shark[i].dir = ndir;
                
                tm[nx][ny] = K+1;
                idx[nx][ny] = i;
                
                break;
            }
        }
        
        if(!flag)
        {
            for(int j=1;j<5;j++){
                
                int ndir = priority[i][dir][j];
                int nx = x + dx[ndir];
                int ny = y + dy[ndir];
                
                if(nx < 0 || ny < 0 || nx >= N || ny >= N)    continue;
                if(idx[nx][ny] == i){
                    
                    tmp[nx][ny] = i;
                    
                    shark[i].x = nx;
                    shark[i].y = ny;
                    shark[i].dir = ndir;
                    
                    tm[nx][ny] = K+1;
                    idx[nx][ny] = i;
                    
                    break;
                                        
                }
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            map[i][j] =tmp[i][j];
        }
    }
    
    
    
}

void time(){
    
    for(int i=0;i<N;i++){
        for(int j=0; j<N;j++){
            if(tm[i][j] > 0){
                tm[i][j]--;
                if(!tm[i][j])   idx[i][j]=0;
            }
        }
    }
}

bool check()
{
    int num=0;
    for(int i=0;i<N;i++){
        for(int j=0; j<N;j++){
            if(map[i][j] > 0)   num++;
        }
    }
    
    if(num==1)  return  true;
    return false;
    
}
void solve()
{
    int cnt =0;
    while(cnt <= 1000){

        cnt++;
        move();
        time();

        if(check()) break;
    }
    if(cnt > 1000)  cout << "-1";
    else    cout << cnt;
}
int main(void)
{

    cin >> N >> M >> K;
    
     for(int i=0;i<N;i++){
         for(int j=0;j<N;j++){
             int num;
             cin >>num;
             if(num != 0){
                 tm[i][j] = K;
                 idx[i][j] = num;
                 map[i][j] = num;

                 shark[num].x = i;
                 shark[num].y = j;
             }
         }
     }
    
    int d;
    for(int i=1;i<=M;i++){
        cin >> d;
        shark[i].dir = d;
        shark[i].die = false;
    }
    
    for(int i=1;i<=M;i++){
        for(int j=1;j<5;j++){
            for(int k=1;k<5;k++){
                int num;
                cin >> num;
                priority[i][j][k] = num;
                
            }
        }
    }
    solve();
    
    return 0;
    
}

