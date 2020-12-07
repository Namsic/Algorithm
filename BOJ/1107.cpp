#include <iostream>
#include <vector>
#include <algorithm>

int length(int);
int generate_near_num(int, std::vector<int>&, int);

int main(){
    // input
    int n, m;
    int res = 0;
    std::cin >> n;
    std::cin >> m;
    std::vector<int> err_btn(m);
    for (int i = 0; i < m; i++)
        std::cin >> err_btn[i];
    
    // solve
    int dir = abs(n - 100);
    int near = generate_near_num(n, err_btn, dir);
    if (near == -1) {
        std::cout << dir;
        return 0;
    }
    int nav = length(near) + abs(n - near);

    
    if(nav < dir) std::cout << nav;
    else std::cout << dir;
    return 0;
}

bool can_press(int num, std::vector<int> &err_btn) {
    if (num < 0) return false;
    if (num == 0)
        return find(err_btn.begin(), err_btn.end(), 0) == err_btn.end();
    while (num > 0) {
        if (find(err_btn.begin(), err_btn.end(), num % 10) != err_btn.end()) return false;
        num /= 10;
    }
    return true;
}

int generate_near_num(int ch, std::vector<int> &err_btn, int max_try) {
    int i = 0;
    while(i <= max_try) {
        if (ch - i >= 0 && can_press(ch - i, err_btn)) return ch - i;
        if (can_press(ch + i, err_btn)) return ch + i;
        i++;
    }
    return -1;
}

int length(int num) {
    if (num == 0)
        return 1;
    int len = 0;
    while (num > 0) {
        num /= 10;
        len++;
    }
    return len;
}