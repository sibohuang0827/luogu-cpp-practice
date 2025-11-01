#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1000005;
int N, M;
int pos[MAXN], ans;

bool Judge(int dis) // We want to know if the the distance between two cows is bigger or equal than dis
{
    int num_of_cows; 
    int last_cow_pos;
    num_of_cows = 1;
    last_cow_pos = 0;
    for (int i = 1; i < N; i++) 
    {
        if (pos[i] - pos[last_cow_pos] >= dis) // This would be a suitable pos
        {
            num_of_cows++;
            last_cow_pos=i;
        }
    }
    if (num_of_cows >= M) 
    {
        return true;
    } else 
    {
        return false;
    } 
}

int main() 
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) 
    {
        cin >> pos[i];
    }
    sort(pos, pos + N);
    int L = 1, R = pos[N - 1] - pos[0]; // Initial answer range [L,R]
    while (L <= R) 
    {
        int mid = (L + R)/2;
        if (Judge(mid)) // if mid = valid answer, this means [L, mid-1] all would not work. Therefore, we see if the right side have better answers 
        {
            ans = mid;
            L = mid + 1;
        } 
        else // if mid = invalid answer, this means [mid, R] all would not work. Therefore, we see if the left side have better answers
        {
            R = mid - 1;
        }
    }
    cout << ans;
}