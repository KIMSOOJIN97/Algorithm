#include <iostream>
#include <vector>
#include <string>

using namespace std;

int K;
char oper[10];

bool solve(vector <int> v)
{
    int _size= v.size();

    for(int i=0;i<_size-1;i++)
    {
        
        int num1 = v[i];
        int num2 = v[i+1];
        
        char op = oper[i];
        if(op == '<'){
            if(num1 > num2) return false;
        }
        else{
            if(num1 < num2) return false;
        }
    }
    
    return true;
}

int main(void)
{
    
    ios_base::sync_with_stdio(0);
    cin.tie();
    
    cin >> K;
    for(int i=0;i<K;i++)    cin >> oper[i];
    
    vector <int> max_v;
    for(int i=9;i>=9-K;i--)   max_v.push_back(i);
    
    while(1){
        if(solve(max_v))    break;
        prev_permutation(max_v.begin(),max_v.end());
    }
    
    vector <int> min_v;
    for(int i=0;i<=K;i++)   min_v.push_back(i);
    
    while(1){
        if(solve(min_v))    break;
        next_permutation(min_v.begin(),min_v.end());
    }
    
    for(int i=0;i<max_v.size();i++) cout<<max_v[i];
    cout << "\n";
    for(int i=0;i<min_v.size();i++) cout<<min_v[i];

    return 0;
    
}


