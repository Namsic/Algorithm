#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool compareEndtime(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second == p2.second
		? p1.first < p2.first
		: p1.second < p2.second;
}

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> time;
	for(int i=0; i<n; i++)
	{
		int startTime, endTime;
		cin >> startTime >> endTime;
		time.push_back(make_pair(startTime, endTime));
	}

	sort(time.begin(), time.end(), compareEndtime);

	int answer = 0;
	int curEnd = 0;
	for(int i=0; i<time.size(); i++)
	{
		if(curEnd > time[i].first) continue;
		answer++;
		curEnd = time[i].second;
	}

	cout << answer;
	return 0;
}
