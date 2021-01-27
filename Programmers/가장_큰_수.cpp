#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool strCompare(string str1, string str2) {
    return str1 + str2 > str2 + str1;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    for(int i=0; i<numbers.size(); i++)
        nums.push_back(to_string(numbers[i]));
    
    sort(nums.begin(), nums.end(), strCompare);
    
    if(nums[0] == "0")
        return "0";
    
    for(int i=0; i<nums.size(); i++)
        answer += nums[i];

    return answer;
}
