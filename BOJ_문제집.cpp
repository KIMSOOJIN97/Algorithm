#include <iostream>
#include <queue>
#include <vector>

#define MAX 32001

using namespace std;

int N,M;
int Degree[MAX];

vector <int> v[MAX];

int main(void)
{
    priority_queue<int,vector<int>,greater<int>> q;

    scanf("%d %d",&N,&M);
    
    for(int i=0;i<M;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        
        Degree[b]++;
        v[a].push_back(b);
    }
    
    for(int i=1;i<=N;i++){
        if(Degree[i]==0)    q.push(i);
    }
    
    while(!q.empty()){
        
        int tmp = q.top();
        q.pop();
        
        printf("%d ",tmp);
        
        for(int i=0;i<v[tmp].size();i++)
        {
            int num = v[tmp][i];
            Degree[num]--;

            if(Degree[num] ==0)   q.push(num);
        }
    }
    return 0;
}

