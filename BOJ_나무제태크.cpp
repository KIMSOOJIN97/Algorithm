#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 11

using namespace std;

int N,M,K;
int A[MAX][MAX]={0,};//추가되는 양분
int nutrient[MAX][MAX]={0,}; // 현재 양분
vector<int> map[MAX][MAX];

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void SpringSummer()
{
    int visited[MAX][MAX]={0,}; // 현재 양분

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            
            int _size = map[i][j].size();
            
            if(_size==0)    continue;
            else if(_size > 1)  sort(map[i][j].begin(), map[i][j].end());
            
            int idx=0;
            while(idx < _size){
                if(map[i][j][idx] <= nutrient[i][j]) {
                    nutrient[i][j]-=map[i][j][idx];
                    map[i][j][idx]++;
                }
                else    break;
                idx++;
            }
            
            if(idx != _size){
                
                for(int k=_size-1; k>=idx ; k--){
                    nutrient[i][j] += map[i][j][k]/2;
                    map[i][j].pop_back();
                    M--;
                }
            }
        }
    }
}

void FallWinter()
{
    int num = M;
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<= N;j++){
            if(map[i][j].size() ==0)    continue;
            
            for(int k=0;k<map[i][j].size();k++){
                int age = map[i][j][k];
                
                if(age%5 == 0){
                    for(int l=0;l<8;l++){
                        int nx = i + dx[l];
                        int ny = j + dy[l];
                        
                        if(nx < 1 || ny < 1 || nx > N || ny > N)    continue;
                        
                        map[nx][ny].push_back(1);
                        M++;
                    }
                }
            }
        }
    }

    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)   nutrient[i][j]+=A[i][j];
    }
}

int main(void)
{
    scanf("%d %d %d",&N,&M,&K);
    
    for(int i=1;i<=N;i++){
        for(int j=1; j<= N;j++) scanf("%d",&A[i][j]);
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1; j<= N;j++) nutrient[i][j]=5;
    }
    
    for(int i=0;i<M;i++)
    {
        int x,y,age;
        scanf("%d %d %d",&x,&y,&age);
        map[x][y].push_back(age);
    }
    
    for(int i=0;i<K;i++){
        SpringSummer();
        FallWinter();
    }
    
    printf("%d",M);
    return 0;
    
}

