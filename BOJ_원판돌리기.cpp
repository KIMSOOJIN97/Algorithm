#include <iostream>
#define MAX 51

using namespace std;

int N,M;
int map[MAX][MAX]={0,};
int tmp[MAX][MAX]={0,};

int x ,d ,k;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void average()
{
    int sum=0;
    int cnt=0;
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++)
        {
            sum += map[i][j];
            if(map[i][j] !=0)   cnt++;
        }
    }
    double avg = double(sum) / double(cnt);
   // cout << avg << sum << cnt;
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++)
        {
            if(map[i][j] !=0){
                if(map[i][j] > avg) map[i][j]--;
                else if(map[i][j] < avg)    map[i][j]++;
            }
        }
    }
}
    
void remove()
{
    int flag =0;
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++)
        {
            for(int k=0;k<4;k++){
                
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if(nx<1 || ny <0 || nx > N || ny > M-1) continue;
                
                if(map[i][j] == map[nx][ny] && map[i][j] != 0){
                    tmp[i][j] = -1;
                    tmp[nx][ny] = -1;
                    flag =1;
                }
            }
            
            if( j==0 && map[i][j]!=0 && map[i][0] == map[i][M-1]){
                tmp[i][j] = -1;
                tmp[i][M-1] = -1;
                flag =1;
            }
        }
    }
    
    if(!flag)   average();
    else{
        for(int i=1;i<=N;i++){
            for(int j=0;j<M;j++)
            {
                if(tmp[i][j] == -1) map[i][j]=0;
            }
        }
    }
    
}

void round(int idx)
{
    if(d==0)//시계
    {
        for(int i=0;i<M;i++){
            if(i+k>=M)  tmp[idx][i+k-M] = map[idx][i];
            else    tmp[idx][i+k] = map[idx][i];
        }
    }
    else{
        for(int i=0;i<M;i++){
            if(i-k>=0)  tmp[idx][i-k] = map[idx][i];
            else    tmp[idx][i-k+M] = map[idx][i];
        }
    }
    
    for(int i=0;i<M;i++)
        map[idx][i] = tmp[idx][i];
}

void solve()
{
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++)
            tmp[i][j]=0;
    }
    //회전
    for(int i=1;i<=N;i++){
        if(i%x == 0 )   round(i);
    }
    remove();
    
}

int main(void)
{
    int  T;
    
    cin >> N >> M >> T;
    
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++)
            cin >> map[i][j];
    }
    
    for(int i=0;i<T;i++){
        cin >> x >> d >> k;
        
        solve();
    }
    
    int sum =0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            sum+=map[i][j];
        }
    }
    cout << sum;
    return 0;
    
    
}


