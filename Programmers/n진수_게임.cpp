#include <string>
#include <vector>

using namespace std;

int base;

string dec2baseN(int num) {
    if(num == 0)
        return "0";
    
    string res = "";
    while(num > 0) {
        if (num % base < 10) 
            res = to_string(num % base) + res;
        else
            res = (char)(num % base + 55) + res;
        num /= base;
    }
    return res;
}

string solution(int n, int t, int m, int p) {
    base = n;
    string answer = "";
    string fullStr = "";
    int i=0;
    while(fullStr.length() < t*m) {
        fullStr += dec2baseN(i);
        i++;
    }
    for(int i=0; i<t; i++)
        answer += fullStr[m*i+p-1];
    return answer;
}
