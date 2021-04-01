// 1504 - 특정한 최단 경로

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& cost) {
	vector<int> dist(cost.size(), -1);
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (!pq.empty())
	{
		int curIndex = pq.top().second;
		int curDistance = pq.top().first;
		pq.pop();
		if (dist[curIndex] != -1) continue;
		dist[curIndex] = -curDistance;

		for (int i = 0; i < cost[curIndex].size(); i++)
			pq.push(make_pair(curDistance - cost[curIndex][i].first, cost[curIndex][i].second));
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n, e; cin >> n >> e;
    vector<vector<pair<int, int>>> cost = vector<vector<pair<int, int>>>(n);
    while(e--) {
        int a, b, c; cin >> a >> b >> c;
        cost[a-1].push_back(make_pair(c, b-1));
        cost[b-1].push_back(make_pair(c, a-1));
    }
    int v1, v2; cin >> v1 >> v2;
    
    vector<int> from_start = dijkstra(0, cost);
    if(from_start[n-1] == -1) {
        cout << "-1\n";
        return 0;
    }
    vector<int> from_end = dijkstra(n-1, cost);
    int between = dijkstra(v1-1, cost)[v2-1];
    int answer1 = from_start[v1-1] + between + from_end[v2-1];
    int answer2 = from_start[v2-1] + between + from_end[v1-1];
    cout << (answer1 < answer2 ? answer1 : answer2) << '\n';

	return 0;
}
