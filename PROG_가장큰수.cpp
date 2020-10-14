#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string str1, string str2)
{
    return str1 + str2 > str2 + str1  ? true : false;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector <string> num;
    
    for(int i=0;i<numbers.size();i++)   num.push_back(to_string(numbers[i]));
    sort(num.begin(),num.end(),comp);
    
    for(int i=0;i<num.size();i++)   answer+=num[i];
    if (answer[0] == '0')   return "0";
    return answer;
}

