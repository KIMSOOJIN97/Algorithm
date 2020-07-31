#include <iostream>
#include <vector>

using namespace std;

vector <int> visited;
vector <int> v;

int K=1;

// K개으 숫자 중에서 6개만 선택하는 경우의 수

void DFS(int cnt , int idx)
{
    if(cnt == 6 ){
        for(int i=0;i<6;i++)
            cout << visited[i] << " ";
        cout << "\n";
        return ;
        
    }
    
    for(int i=idx;i<K;i++){
        visited.push_back(v[i]);
        DFS(cnt+1,i+1);
        visited.pop_back();
    }
}

int main(void)
{
    
    while(1){
        
        cin >> K;
        if(K==0)    break;
        

        //벡터 초기화
        while(!v.empty())   v.pop_back();
        
        for(int i=0;i<K;i++){
            int idx;
            cin >> idx;
            v.push_back(idx);
        }
        
        DFS(0,0);
        cout <<"\n";
    }
    return 0;
}

