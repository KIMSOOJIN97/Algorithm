#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 51

//0은 빈 칸, 1은 집, 2는 치킨집이다.
// M개를 고르고, 나머지 치킨집은 모두 폐업시켜야

int N,M;
int map[MAX][MAX]={0,};
int visited[14] = {0,};

int SUM = 999999;

vector <pair<int,int>> chicken;
vector <pair<int,int>> house;



void DFS(int cnt, int idx)
{
    if( cnt == M){
        
        int each_sum =0;
        
        for(int i=0;i<house.size();i++){
            
            int hx = house[i].first;
            int hy = house[i].second;
            
            int MIN_DIS =99;
            
            for(int j=0;j<chicken.size();j++){
                
                if(visited[j]){
                int cx = chicken[j].first;
                int cy = chicken[j].second;


                int dx = cx > hx ? cx - hx : hx-cx;
                int dy = cy > hy ? cy - hy : hy-cy;
                
                if(dx+dy < MIN_DIS)   MIN_DIS = dx+dy;
                }
            }
            each_sum += MIN_DIS;
        }
        if(each_sum < SUM)  SUM = each_sum;
        return;
    }
    
    if (idx == chicken.size())
             return;
    
    visited[idx] = 1;
    DFS(cnt+1,idx+1);
    visited[idx] = 0;
    DFS(cnt, idx+1);
}

int main(void)
{
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
        {
            cin >> map[i][j];
            
            if(map[i][j] == 2)  chicken.push_back(make_pair(i,j));
            else if (map[i][j]==1)  house.push_back(make_pair(i,j));
        }
    }
    
    DFS(0,0);
    cout << SUM;
    return 0;
    
}

