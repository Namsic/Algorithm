// 1238 - 파티

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& load)
{
	vector<int> dist(load.size(), -1);
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int curIndex = pq.top().second;
		int curDistance = pq.top().first;
		pq.pop();
		if (dist[curIndex] != -1) continue;
		dist[curIndex] = -curDistance;

		for (int i = 0; i < load[curIndex].size(); i++)
			pq.push(make_pair(curDistance - load[curIndex][i].first, load[curIndex][i].second));
	}
	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x; cin >> n >> m >> x;
	vector<vector<pair<int, int>>> load1 = vector<vector<pair<int, int>>>(n);
	vector<vector<pair<int, int>>> load2 = vector<vector<pair<int, int>>>(n);

	while (m--)
	{
		int s, e, t; cin >> s >> e >> t;
		load1[s-1].push_back(make_pair(t, e-1));
		load2[e-1].push_back(make_pair(t, s-1));
	}

	vector<int> t1 = dijkstra(x-1, load1);
	vector<int> t2 = dijkstra(x-1, load2);
	int answer = 0;
	for (int i = 0; i < n; i++)
		if (t1[i] + t2[i] > answer)
			answer = t1[i] + t2[i];
	cout << answer << '\n';

	return 0;
}
