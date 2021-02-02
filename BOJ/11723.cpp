#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> m;

	string cmd;
	bitset<20> bitSet;
	bitSet.reset();

	int x;
	while(m--) {
		cin >> cmd;

		if(cmd == "all" || cmd == "empty") {
			cmd == "all"
			? bitSet.set()
			: bitSet.reset();
			continue;
		}

		int x;
		cin >> x;
		if(cmd == "add")
			bitSet[x-1] = 1;
		else if(cmd == "remove")
			bitSet[x-1] = 0;
		else if(cmd == "check")
			cout << bitSet[x-1] << '\n';
		else if(cmd == "toggle")
			bitSet.flip(x-1);
	}

	return 0;
}
