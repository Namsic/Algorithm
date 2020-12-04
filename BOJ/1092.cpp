#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, m;
    int res = 0;
    
    // input
    std::cin >> n;
    std::vector<int> crane(n);
    for (int i = 0; i < n; i++)
        std::cin >> crane[i];
    
    std::cin >> m;
    std::vector<int> box(m);
    for (int i = 0; i < m; i++)
        std::cin >> box[i];
    
    // preprocess
    std::sort(crane.begin(), crane.end());
    std::sort(box.begin(), box.end());

    // solve
    if (box.back() > crane.back()) {
        std::cout << "-1";
        return 0;
    }
    while (box.size() > 0){
        int cursor = box.size() - 1;
        for (int i=crane.size()-1; i>=0; i--) {
            while (box[cursor] > crane[i] && cursor >= 0)
                cursor--;
            if (cursor >= 0) {
                box.erase(box.begin() + cursor);
                cursor--;
            }
            if (cursor < 0) break;
        }
        res++;
    }
    std::cout << res;
    return 0;
}