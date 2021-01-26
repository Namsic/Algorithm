#include <vector>

using namespace std;

int minBuild(int left, int right, int w)
{
    if(left > right)
        return 0;
    
    int width = right - left + 1;
    int range = 2 * w + 1;
    return width % range
        ? width / range + 1
        : width / range;
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int tmp = 1;
    for(int station : stations)
    {
        answer += minBuild(tmp, station-w-1, w);
        tmp = station+w+1;
    }
    answer += minBuild(tmp, n, w);

    return answer;
}
