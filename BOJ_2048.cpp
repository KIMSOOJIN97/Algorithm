#include <iostream>
#define MAX 20

using namespace std;

int map[MAX][MAX]={0,};
int N;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int MAX_NUM=0;

void copy_map(int tmp1[MAX][MAX], int tmp2[MAX][MAX])
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)    tmp2[i][j] = tmp1[i][j];
    }
}

void move(int dir)
{
    int tmp[MAX][MAX]={0,};
    
    for(int i=0;i<N;i++){
        
        int idx;
            
        if(dir == 0){

            idx =0;
            
            for(int j=0;j<N;j++){
                
                if(map[j][i]!=0){
                    tmp[idx][i]= map[j][i];
                    idx++;
                }
            }
        }
        else if(dir == 1){
            idx= N-1;
            
            for(int j=N-1;j>=0;j--){
                
                if(map[i][j]!=0){
                    tmp[i][idx] = map[i][j];
                    idx--;
                }
            }
        }
        
        else if(dir == 2){
            idx= N-1;
            
            for(int j=N-1;j>=0;j--){
                
                if(map[j][i]!=0){
                    tmp[idx][i] = map[j][i];
                    idx--;
                }
            }
        }
        
        else{
            idx = 0;
            for(int j=0;j<N;j++){
                if(map[i][j]  !=0){
                    tmp[i][idx] = map[i][j];
                    idx++;
                }
            }
        }
    }
    copy_map(tmp,map);
}

void add(int dir)
{
    for(int i=0; i<N; i++){
        int idx;
        
        if(dir == 0){
            idx = 0;
            
            while(1){
                
                if(idx >= N-1)    break;
                if(map[idx][i] == map[idx+1][i]){
                    map[idx][i] *=2;
                    map[idx+1][i] =0;
                    idx = idx+ 2;
                }
                else    idx = idx+1;
            }
        }
        else if(dir == 1)
        {
            idx = N-1;
            
            while(1){
                
                if(idx <= 0 )   break;
                
                if(map[i][idx] == map[i][idx-1]){
                    
                    map[i][idx] *= 2;
                    map[i][idx-1]= 0;
                    idx -= 2;
                }
                else    idx -=1;
            }
        }
        else if(dir ==2)
        {
            idx = N-1;
            
            while(1){
                if(idx <= 0 )   break;
                
                if(map[idx][i] == map[idx-1][i]){
                    map[idx][i] *= 2;
                    map[idx-1][i]= 0;
                    idx -= 2;
                }
                else    idx -=1;
            }
        }
        else{
            
            idx = 0;
            
            while(1){
                
                if(idx >= N-1)    break;
                if(map[i][idx] == map[i][idx+1]){
                    map[i][idx] *=2;
                    map[i][idx+1] =0;
                    idx = idx+ 2;
                }
                else    idx = idx+1;
            }
        }
    }
}


void DFS(int cnt)
{
    if(cnt == 5){
        int num =0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)    if(map[i][j]>num)   num = map[i][j];
        }
        
        if(num>MAX_NUM) MAX_NUM = num;
        
        return ;
        
    }
    
    for(int i=0;i<4;i++){
        int tmp[MAX][MAX];
        copy_map(map,tmp);
        move(i);
        add(i);
        move(i);
        DFS(cnt+1);
        copy_map(tmp, map);
    }
}

int main(void)
{
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> map[i][j];
        }
    }
    
    DFS(0);
    cout << MAX_NUM;
    return 0;
}

