#include <iostream>

using namespace std;

int visited[100];
int arr[100][100]={0,};
int map[100][100]={0,};
int N;

void DFS(int idx){
    for(int i=0;i<N;i++)
    {
        if(arr[idx][i] && visited[i] ==0 ){
            visited[i] =1;
            DFS(i);
        }
    }
}
int main(void)
{
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cin >> arr[i][j];
    }
    
    
    for(int i=0;i<N;i++){
        memset(visited , 0 , sizeof(visited));
        DFS(i);
        
        for(int j=0;j<N;j++){
            if(visited[j])  map[i][j] =1;
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout << map[i][j] << " ";
        cout << endl;
    }
    return 0;
    
}

