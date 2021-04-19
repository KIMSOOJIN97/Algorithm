#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long calc(long long a,long long b, char op)
{
    if(op == '-')   return a-b;
    else if(op == '+')  return a+b;
    else    return a*b;
}

long long solution(string expression) {
    long long answer = 0;
    vector <char> oper_list =  { '*', '+', '-' };
    vector <long long> number;
    vector <char> oper;
    string num = "";
    

    for(int i=0;i<expression.size();i++)
    {
        if(expression[i] == '+' || expression[i] =='*' || expression[i] == '-')
        {
            oper.push_back(expression[i]);
            number.push_back(atoi(num.c_str()));
            num="";
        }
        else    num+= expression[i];  
    }
    number.push_back(atoi(num.c_str()));
    long long _max =0;
    do{
        vector <char> tmp_oper = oper;
        vector <long long> tmp_num = number;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<tmp_oper.size();j++)
            {
                if(tmp_oper[j] == oper_list[i])
                {
                    tmp_num[j] = calc(tmp_num[j],tmp_num[j+1],oper_list[i]);
                    tmp_num.erase(tmp_num.begin()+j+1);
                    tmp_oper.erase(tmp_oper.begin()+j);
                    j--;
                }
            }
        } 
        if(_max < abs(tmp_num[0]))   _max = abs(tmp_num[0]);
    }while(next_permutation(oper_list.begin(),oper_list.end()));
    answer = _max;
    return answer;
}
