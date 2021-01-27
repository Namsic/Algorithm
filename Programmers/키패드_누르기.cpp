#include <string>
#include <vector>

using namespace std;

int getDistance(int num1, int num2) {
    num1--;
    num2--;
    int h = num1 % 3 > num2 % 3
        ? num1 % 3 - num2 % 3
        : num2 % 3 - num1 % 3;
    int v = num1 / 3 > num2 / 3
        ? num1 / 3 - num2 / 3
        : num2 / 3 - num1 / 3;
    return h + v;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftHand = 10, rightHand = 12;
    
    for(int i=0; i<numbers.size(); i++) {
        int n = (numbers[i]) ? numbers[i] : 11;
        if(n % 3 == 1) {
            answer += "L";
            leftHand = n;
            continue;
        }else if(n % 3 == 0) {
            answer += "R";
            rightHand = n;
            continue;
        }
        int ld = getDistance(leftHand, n);
        int rd = getDistance(rightHand, n);
        if(ld < rd) {
            answer += "L";
            leftHand = n;
        } else if(ld > rd) {
            answer += "R";
            rightHand = n;
        } else if(hand == "left") {
            answer += "L";
            leftHand = n;
        } else {
            answer += "R";
            rightHand = n;
        }
    }
    
    return answer;
}
