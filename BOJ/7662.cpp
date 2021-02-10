#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;

	while(t--)
	{
		map<long long, int> m;
		map<long long, int>::iterator iter;
		int k; cin >> k;
		while(k--)
		{
			char cmd; cin >> cmd;
			int n; cin >> n;
			if(cmd == 'D' && !m.empty())
			{
				iter = n == 1 ? --m.end() : m.begin();
				iter->second--;
				if(!iter->second)
					iter = m.erase(iter);
			}
			else if(cmd == 'I')
			{
				if(m.count(n))
					m[n]++;
				else
					m[n] = 1;
			}
		}
		if(m.empty())
			cout << "EMPTY\n";
		else
			cout << (--m.end())->first << " " << m.begin()->first << '\n';
	}

	return 0;
}
