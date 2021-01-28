#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int dot[200000] = {0,};
	dot[n] = 1;
	queue<int> q;
	q.push(n);

	while(!dot[k])
	{
		if(q.front() > 0 && !dot[q.front()-1])
		{
			dot[q.front()-1] = dot[q.front()] + 1;
			q.push(q.front()-1);
		}
		if(q.front()+1 < 200000 && !dot[q.front()+1])
		{
			dot[q.front()+1] = dot[q.front()] + 1;
			q.push(q.front()+1);
		}
		if(q.front()*2 < 200000 && !dot[q.front()*2])
		{
			dot[q.front()*2] = dot[q.front()] + 1;
			q.push(q.front()*2);
		}
		q.pop();
	}

	cout << dot[k]-1 << endl;
	cin >> n;
	return 0;
}
