#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    for(int i=0; i<citations.size(); i++)
        if(citations[citations.size()-1-i] <= i)
            return i;
    return citations.size();
}
