/*
    Created: 10/22/2025
    Solved: 10/22/2025
*/ 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int number_of_contest;
struct contest {
    int start_time;
    int end_time;
};
vector<contest> contest_list;

bool compare(contest a, contest b) {
    return a.end_time < b.end_time;
}

int main() {
    int total_contest = 1;
    cin >> number_of_contest;
    for (int i = 0; i < number_of_contest; i ++) {
        contest temp;
        cin >> temp.start_time >> temp.end_time;
        contest_list.push_back(temp);
    }
    sort(contest_list.begin(), contest_list.end(), compare);
    int temp_end_time = contest_list[0].end_time;
    for (int i = 1; i < number_of_contest; i ++) {
        if (contest_list[i].start_time >= temp_end_time) {
            temp_end_time = contest_list[i].end_time;
            total_contest ++;
        }
    }
    cout << total_contest << endl;
    return 0;
}