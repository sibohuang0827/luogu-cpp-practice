/*
    Created: 10/22/2025
    Solved: 10/22/2025
*/ 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int apple_number, strength, chair_height, max_height;
struct apple { 
    int apple_height;
    int apple_strength;
};
vector<apple> apple_list;

bool cmp(apple a, apple b) {
    return a.apple_strength < b.apple_strength;
}

int main() {
    int max_reach;
    int picked_apple_num = 0;
    cin >> apple_number >> strength >> chair_height >> max_height;
    max_reach = chair_height + max_height;
    for (int i = 0; i < apple_number; i ++) {
        int temp_apple_height, temp_apple_strength;
        cin >> temp_apple_height >> temp_apple_strength;
        if (temp_apple_height <= max_reach) {
            apple_list.push_back({temp_apple_height, temp_apple_strength});
        }
    }
    sort(apple_list.begin(), apple_list.end(), cmp);
    for (int i = 0; i < apple_list.size(); i ++) {
        if (strength - apple_list[i].apple_strength >= 0) {
            strength -= apple_list[i].apple_strength;
            picked_apple_num ++;
        } else break;
    }
    cout << picked_apple_num << endl;
}