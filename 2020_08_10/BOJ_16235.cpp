#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX 10

using namespace std;

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int N,M,K;
int map[MAX][MAX];
int nutrient[MAX][MAX];

vector <int> tree[MAX][MAX];

void SpringSummer()
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            //나무가 없는 경우
            if(tree[i][j].size() == 0)  continue;
            
            int add =0;
            vector <int> temp;
            
            sort(tree[i][j].begin() , tree[i][j].end());
            int num = tree[i][j].size();
            
            for(int k=0;k<num;k++){
                if(tree[i][j][k] <= map[i][j]){
                    map[i][j] = map[i][j] - tree[i][j][k];
                    temp.push_back(tree[i][j][k]+1);
                }
                else{
                    add = add + tree[i][j][k]/2;
                    M--;
                }
            }
            
            tree[i][j].clear();
            
            for(int k=0;k<temp.size();k++)
                tree[i][j].push_back(temp[k]);
            
            map[i][j] += add;
        }
    }
}

void FallWinter()
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            
            int num = tree[i][j].size();
            
            for(int k=0;k<num;k++){
                
                if(tree[i][j][k]%5 != 0 || tree[i][j][k] == 0 ) continue;
                
                for(int l=0;l<8;l++){
                    
                    int nx = i + dx[l];
                    int ny = j + dy[l];
                    
                    if( nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                    tree[nx][ny].push_back(1);
                    M++;
                }
            }
            
            map[i][j] += nutrient[i][j];
        }
    }
}
int main(void)
{
    
    cin >> N >> M >> K;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin >> nutrient[i][j];
    }
    
    for(int i=0;i<M;i++)
    {
        int x,y,age;
        cin >> x >> y >> age;
        tree[x-1][y-1].push_back(age);
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            map[i][j]=5;
    }
    
    for(int i=0;i<K;i++){
        
        SpringSummer();
        FallWinter();

    }
    
    cout << M;
    
    return 0;
}

