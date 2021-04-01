// 1629 - 곱셈

#include<iostream>
using namespace std;

long rec(int a, int b, int c) {
    if(b == 1)
        return a % c;
    long tmp = rec(a, b/2, c);
    tmp = (tmp * tmp) % c;
    if(b % 2)
        tmp = (tmp * (a % c)) % c;
    return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int a, b, c; cin >> a >> b >> c;
    
    cout << rec(a, b, c) << '\n';

	return 0;
}
