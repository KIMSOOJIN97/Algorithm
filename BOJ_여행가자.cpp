#include <iostream>
#include <vector>

#define MAX 200

using namespace std;

int map[MAX][MAX]={0,};
int parent[MAX];

vector <int> _path;

int N,M;

int find(int idx)
{
    if(idx == parent[idx])  return idx;
    else{
        parent[idx] = find(parent[idx]);
        return parent[idx];
    }
}

void unit(int idx1 ,int idx2)
{
    idx1 = find(idx1);
    idx2 = find(idx2);
    
    if(idx1 != idx2)
    {
        parent[idx2] = idx1;
    }
}
int main(void)
{
    scanf("%d %d", &N,&M);
    
    for(int i=0;i<N;i++){
        parent[i] = i;
        for(int j=0;j<N;j++)    scanf("%d",&map[i][j]);
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j] == 1)  unit(i,j);
        }
    }
    
    for(int i=0;i<M;i++){
        int v;
        scanf("%d",&v);
        _path.push_back(v-1);
    }
    
    for(int i=0;i<M-1;i++){
        if(find(_path[i]) != find(_path[i+1])){
            printf("NO");
            return 0;
        }
    }
    
    printf("YES");
    return 0;
    
}

