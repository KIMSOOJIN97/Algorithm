#include <iostream>
#include <queue>
#define MAX 1000001

using namespace std;

/* S -> G , 못가면 use the stair 출력 */
int F,S,G,U,D;
int visited[MAX]={0,};
int dpos[2] = {0,};


void BFS(){

    queue <int> q;
    q.push(S);
    visited[S]=1;
    while(!q.empty()){
        
        int pos = q.front();
        q.pop();
        
        if(pos == G){
            cout << visited[pos]-1;
            return;
        }
        
        for(int i=0;i<2;i++){
            int npos = pos + dpos[i];
            
            if(npos < 1 || npos > F ||visited[npos]!=0)    continue;
            
            visited[npos] = visited[pos]+1;
            q.push(npos);
        }
    }
    
    cout << "use the stairs";
    return;

}

int main(void)
{
    cin >>F >> S >> G >> U >> D;
    dpos[0] = U;
    dpos[1] = -1*D;
    BFS();
    return 0;
}
