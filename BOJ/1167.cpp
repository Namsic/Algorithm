// 1167 - 트리의 지름

#include <iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

pair<int, int> findFar(int v, vector<vector<pair<int, int>>>& connect, int startIndex)
{
	queue<int> bfs;
	vector<int> length(v, 0);
	length[startIndex] = 1;
	bfs.push(startIndex);
	while (!bfs.empty())
	{
		int cursor = bfs.front();
		bfs.pop();
		for (int i = 0; i < connect[cursor].size(); i++)
		{
			if (length[connect[cursor][i].first]) continue;
			length[connect[cursor][i].first] = length[cursor] + connect[cursor][i].second;
			bfs.push(connect[cursor][i].first);
		}
	}

	int farIndex = 0;
	for (int i = 0; i < v; i++)
		if (length[i] > length[farIndex])
			farIndex = i;
	return make_pair(farIndex, length[farIndex]-1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v; cin >> v;
	vector<vector<pair<int, int>>> connect = vector<vector<pair<int, int>>>(v);
	
	int i = v;
	while (i--)
	{
		int idx;
		cin >> idx;
		while (true)
		{
			int opp, len;
			cin >> opp;
			if (opp == -1) break;
			cin >> len;
			connect[idx-1].push_back(make_pair(opp-1, len));
		}
	}
	int idx1 = findFar(v, connect, 0).first;
	cout << findFar(v, connect, idx1).second << '\n';

	return 0;
}
