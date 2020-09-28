#include <iostream>
#include <string>
#include <vector>


using namespace std;
string str;

bool check()
{
    vector <int> v;
    int end =0;
    int _size = str.size();
    int num[4] ={0,}; // []()
    for(int i=0;i<_size;i++){
        
        if(str[i]=='['){
            num[0]++;
            v.push_back(0);
        }
        else if(str[i]=='('){
            num[1]++;
            v.push_back(1);
        }
        else if(str[i]==']'){
            end= v.size();
            if(end ==0 || v[end-1] != 0)   return false;
            v.pop_back();
        }
        else if(str[i]==')'){
            end= v.size();
            if(end ==0 ||v[end-1] != 1)   return false;
            v.pop_back();
        }
    }
    if(v.size()!=0) return false;
    return true;
}

int main(void)
{
    cin >> str;
    
    if(check()==false){
        printf("0");
        return 0;
    }
    
    vector <string>  oper;
    int total=0;
    
    for(int i=0;i<str.size();i++){
        
        if(str[i]=='(') oper.push_back("(");
        else if(str[i]=='[') oper.push_back("[");
        else{
            int num=0;
            while(1){
                int _size = oper.size();
                string tmp = oper[_size-1];
                oper.pop_back();
                
                if(tmp.compare("[")==0){
                    if(num==0)  num=3;
                    else    num*=3;
                    oper.push_back(to_string(num));
                    break;
                }
                else if(tmp.compare("(")==0){
                    if(num==0) num=2;
                    else num*=2;
                    oper.push_back(to_string(num));
                    break;
                }
                else num+=stoi(tmp);
            }
        }
            
    }
    
    while(!oper.empty()){
        total+=stoi(oper[oper.size()-1]);
        oper.pop_back();
    }
    cout << total;
    return 0;
}

