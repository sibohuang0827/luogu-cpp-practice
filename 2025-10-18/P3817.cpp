/*
    Created: 10/24/25
    Solved: 10/24/25
*/

#include <iostream>

using namespace std;

/*
    Variable Sheet:
    n = number of candy boxes
    x = given parameter
    c = total number of candy that need to be eaten
*/

long long n, x, c;
long long a[200005];

int main() 
{
    cin >> n >> x;
    for (long long i = 0; i < n; i++)  
    {
        cin >> a[i];
        if (a[i] + a[i - 1] > x) {
            c += a[i] + a[i - 1] - x;
            a[i] -= a[i] + a[i - 1] - x;
        }
    }
    cout << c << endl;
}