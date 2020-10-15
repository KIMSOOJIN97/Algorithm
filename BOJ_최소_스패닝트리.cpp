#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10000

using namespace std;

int parent[MAX]={0,};

class Edge{
    
public:
    int start;
    int end;
    int dis;
    
    Edge(int s, int e, int d)
    {
        this->start = s;
        this->end = e;
        this->dis = d;
    }
    
    bool operator < (Edge&e)
    {
        return this->dis < e.dis;
    }
};

int Find(int idx)
{
    if(idx == parent[idx])  return idx;
    else{
        parent[idx] = Find(parent[idx]);
        return parent[idx];
    }
}

void Union(int idx1, int idx2)
{
    idx1 = Find(idx1);
    idx2= Find(idx2);
    if(idx1  != idx2)   parent[idx2] = idx1;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int V,E;
    cin >> V >> E;
    
    vector <pair<int, pair<int, int>>> v(E);

    for(int i=1;i<=V;i++)   parent[i] = i;
    
    for(int i=0;i<E;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        
        v.push_back(make_pair(c, make_pair(a,b)));
    }
    
    sort(v.begin(),v.end());
    int ans=0;
    
    for(int i=0;i<v.size();i++){
        
        int tmp1 = v[i].second.first;
        int tmp2 = v[i].second.second;
        
        if(Find(tmp1) != Find(tmp2)){
            Union(tmp1,tmp2);
            ans+= v[i].first;
        }
    }
    
    cout << ans;
    
    return 0;
    
}

