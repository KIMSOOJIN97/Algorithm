#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200020

using namespace std;

struct ball{
    int weight, color, idx;
};

int ans[MAX]={0,};
int C[MAX]={0,};
int S[MAX]={0,};
int N;
bool comp(ball &a, ball &b) {

    if (a.weight==b.weight) return a.color < b.color;

    return a.weight < b.weight;
}
int main(void)
{
    vector <ball> v;

    cin >> N;
    for(int i=0;i<N;i++){
        int weight,color;
        cin >> color >> weight;
        v.push_back({weight,color,i});
    }
    sort(v.begin(),v.end(),comp);
    
    int sum=0;
    
    for(int i=0;i<N;i++){
        
        int weight = v[i].weight;
        int color = v[i].color;
        int idx = v[i].idx;
        
        C[color]+=weight;
        S[weight]+=weight;
        sum+=weight;
        
        ans[idx]= sum - C[color] - S[weight] +weight;
        if(i!=0 && (v[i-1].color == color) && (v[i-1].weight == weight))    ans[idx] = ans[v[i-1].idx];
    }
    
    for(int i=0;i<N;i++)    cout << ans[i] <<"\n";
    return 0;
}

