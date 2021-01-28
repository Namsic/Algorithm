using namespace std;

int solution(int n) {
    if(n <= 2)
        return n;
    
    int t1 = 1, t2 = 2;
    for(int i=3; i<=n; i++)
    {
        int tmp = (t1 + t2) % 1000000007;
        t1 = t2;
        t2 = tmp;
    }
    return t2;
}
