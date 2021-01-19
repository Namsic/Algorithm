#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx = 0;
    while(idx < progresses.size())
    {
        int tmp = idx;
        while(progresses[idx] < 100)
            for(int i=idx; i<progresses.size(); i++)
                progresses[i] += speeds[i];
        while(idx < progresses.size() && 
              progresses[idx] >= 100)
            idx++;
        answer.push_back(idx - tmp);
    }
    return answer;
}
