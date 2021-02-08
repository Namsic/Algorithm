#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	priority_queue<int, vector<int>, less<int>> pq;

	for(int i=0; i<n; i++)
	{
		int x; cin >> x;
		if(x)
			pq.push(x);
		else if(pq.empty())
			cout << 0 << '\n';
		else
		{
			cout << pq.top() << '\n';
			pq.pop();
		}
	}
	
	return 0;
}
