#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
 
using namespace std;

int N;
vector <string> v;

int alphabet[26]={0,};
int visited[26]={0,};

int main(void)
{
    cin >> N;
    for(int i=0;i<N;i++){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    vector <pair<int,int>> order;
    
    for(int i=0;i<N;i++){
        string str = v[i];
        int _size = str.size();
        int idx = 1;
        for(int j=_size-1;j>=0;j--){
            visited[str[j]-65] += idx;
            idx *=10;
        }
    }
    for(int i=0;i<26;i++)
        if(visited[i] != 0) order.push_back({visited[i],i});
    
    sort(order.begin(),order.end());
    
    int num=9;
    for(int i=order.size()-1 ; i>=0;i--){
        if(alphabet[order[i].second]==0){
            alphabet[order[i].second]=num;
            if(num>0)   num--;
        }
    }
    int ans =0;
    for(int i=0;i<N;i++){
        string str = v[i];
        int _size = str.size();
        int idx = 1;
        for(int j=_size-1;j>=0;j--){
            ans += alphabet[str[j]-65] * idx;
            idx *= 10;
        }
    }
    cout <<ans;
    return 0;
    
}

