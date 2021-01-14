#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX 300001

using namespace std;

struct diamond{
    int weight, value;
};

int bag[MAX]={0,};
int N,K;

bool comp(diamond & a, diamond & b)
{
    return a.weight < b.weight;
}

int main(void)
{
    vector <diamond> v;
    priority_queue <int> q;
    
    cin >> N >> K;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a>>b;
        v.push_back({a,b});
    }
    for(int i=0;i<K;i++)    cin >> bag[i];
    
    sort(v.begin(),v.end(),comp);
    sort(bag,bag+K);
    
    int idx =0;
    long long int res=0;

    for(int i=0;i<K;i++){
        int weight = bag[i];
        while(idx < N ){
            if(v[idx].weight <= weight){
                q.push(v[idx].value);
                idx++;
            }
            else    break;
        }
        if(q.size()==0 )  continue;
        res+=q.top();
        q.pop();
    }
    cout << res;
    return 0;
}

