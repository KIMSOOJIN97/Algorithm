//Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치

#include <iostream>
#include <vector>

using namespace std;

int N;
int score[20][20]={0,};
//  0은 start팀, 1은 link팀

int visited[20] = {0,};
int MIN=10000;

void calc()
{
    int start_score=0;
    int link_score=0;
    
    
    for(int i=0;i<N;i++){
        if(visited[i]){
            for(int j=0;j<N;j++){
                if(visited[j])  start_score +=  score[i][j];

            }
        }
        else{
            for(int j=0;j<N;j++){
                if(visited[j] ==0 )  link_score +=  score[i][j];

            }
        }

    }
    
    int diff=0;
    
    if( start_score > link_score)   diff = start_score - link_score;
    else    diff = link_score - start_score;
    
    if( MIN > diff)  MIN = diff;
    
}
void DFS(int cnt,int idx)
{
    if ( cnt == N/2){
        calc();
        return;
    }
    
    for(int i=idx;i<N;i++){
        if(visited[i] == 0 ){
            visited[i] = 1;
            DFS(cnt+1, i+1);
            visited[i] =0;
        }
    }
    
    
}

int main(void)
{
    cin >>N ;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin >> score[i][j];
    }
    
    DFS(0,0);
    cout << MIN;
    return 0;
    
}

