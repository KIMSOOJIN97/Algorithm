/*
 . 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다.
 */

#include <iostream>
#include <queue>

#define MAX 200001

using namespace std;

int map[MAX]={0,};
int N,K;

int dx[2]={-1,1};

int BFS()
{
    queue <int> q;
    q.push(N);
    map[N]=1;
    
    while(!q.empty()){
        
        int x = q.front();
        q.pop();
        
        if(x == K)  return map[x]-1;
        
        for(int i=0;i<3;i++){
            int npos = x;
            if(i==2)    npos = x*2;
            else    npos= x+dx[i];
            
            if(npos <0 || npos >= MAX)  continue;
            if(i!=2 &&  (map[npos]!=0 && map[npos] <= map[x]+1))    continue;
            if(i==2 &&  (map[npos]!=0 && map[npos] <= map[x]))  continue;
            
            q.push(npos);
            
            if(i==2)    map[npos] = map[x];
            else    map[npos]= map[x]+1;
        }
    }
    
    return 0;
}
int main(void)
{
    cin >> N>> K;
    cout << BFS();
}

