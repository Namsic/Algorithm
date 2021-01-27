#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<pair<string, int>> cache;
    for(int i=0; i<cities.size(); i++)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        bool cacheHit = false;
        for(int j=0; j<cache.size(); j++)
            if(cache[j].first == cities[i])
            {
                cacheHit = true;
                cache[j].second = i;
                answer += 1;
                break;
            }
        if(cacheHit)
            continue;
        
        answer += 5;
        if(!cacheSize) continue;
        if(cache.size() < cacheSize)
        {
            cache.push_back(make_pair(cities[i], i));
            continue;
        }
        int minIdx = 0;
        for(int j=1; j<cacheSize; j++)
            if(cache[j].second < cache[minIdx].second)
                minIdx = j;
        cache[minIdx] = make_pair(cities[i], i);
    }
    return answer;
}
