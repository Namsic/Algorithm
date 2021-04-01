// 1753 - 최단경로

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& cost) {
	vector<int> dist(cost.size(), -1);
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while(!pq.empty())
	{
		int curIndex = pq.top().second;
		int curDistance = pq.top().first;
		pq.pop();
		if(dist[curIndex] != -1) continue;
		dist[curIndex] = -curDistance;

		for(int i = 0; i < cost[curIndex].size(); i++)
            if(dist[cost[curIndex][i].second] == -1)
			    pq.push(make_pair(curDistance - cost[curIndex][i].first, cost[curIndex][i].second));
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int V, E; cin >> V >> E;
    vector<vector<pair<int, int>>> cost = vector<vector<pair<int, int>>>(V);
    int k; cin >> k;
    
    while(E--) {
        int u, v, w; cin >> u >> v >> w;
        cost[u-1].push_back(make_pair(w, v-1));
    }
    
    vector<int> answer = dijkstra(k-1, cost);
    for(int i=0; i<answer.size(); i++) {
        if(answer[i] == -1)
            cout << "INF\n";
        else
            cout << answer[i] << '\n';
    }
    
	return 0;
}