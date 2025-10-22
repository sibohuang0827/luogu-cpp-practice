/*
    Created: 10/22/2025
    Solved: 10/22/2025
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int group_price_limit, number_of_gift;
vector<int> gift_list;

int main() {
    int min_gift_group = 0;
    cin >> group_price_limit >> number_of_gift;
    gift_list.resize(number_of_gift);
    for (int i = 0; i < number_of_gift; i ++) {
        cin >> gift_list[i];
    }
    sort(gift_list.begin(), gift_list.end());
    int left_i = 0;
    int right_i = gift_list.size() - 1;
    while (left_i <= right_i) {
        if (gift_list[left_i] + gift_list[right_i] <= group_price_limit) {
            min_gift_group ++;
            left_i ++;
            right_i --;
        } else {
            min_gift_group ++;
            right_i --;
        }
    }
    cout << min_gift_group << endl;
    return 0;
}