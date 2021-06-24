// 4344 - 평균은 넘겠지

#include <iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int c; cin >> c;
    while(c--) {
        int n; cin >> n;
        float avg = 0.0f;
        vector<int> scores(n);
        while(n--) {
            cin >> scores[n];
            avg += scores[n];
        }
        avg /= scores.size();
        n = 0;
        for(int i=0; i<scores.size(); i++)
            if(scores[i] > avg)
                n++;

        cout << fixed; cout.precision(3);
        cout << (float)n/scores.size() * 100 << "%\n";
    }

    return 0;
}
