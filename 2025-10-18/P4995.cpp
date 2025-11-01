#include <iostream>
#include <algorithm>
using namespace std;

int stones[305];
int stonesMaxOrder1[305];
int stonesMaxOrder2[305];

long long calculateEnergy(int stoneList[], int listLength) {
    long long totalEnergy = 0;
    totalEnergy += (long long)stoneList[0] * stoneList[0];
    for (int i = 1; i < listLength; i++) {
        long long diff = stoneList[i-1] - stoneList[i];
        totalEnergy += diff * diff;
    }
    return totalEnergy;
}

int main() {
    // input
    int numberOfStones;
    cin >> numberOfStones;
    for (int i = 0; i < numberOfStones; i++) {
        cin >> stones[i];
    }

    // algorithm: greedy. Do one max-min and min-max order. Find max value between these two.
    sort(stones, stones + numberOfStones);
    
    /*
    order 1: max-min
    example: [3,4,9,7] -> [3,4,7,9] -> [9 - 3, 7 - 4] [9,3,7,4]
    */

    int leftIndex = 0;
    int rightIndex = numberOfStones - 1;
    int index = 0;

    while (leftIndex <= rightIndex) {
        stonesMaxOrder1[index++] = stones[rightIndex--];
        if (leftIndex <= rightIndex) {
            stonesMaxOrder1[index++] = stones[leftIndex++];
        }
    }

    /*
    order 2: min-max
    example: [3,4,9,7] -> [3,4,7,9] -> [3 - 9, 4 - 7] -> [3,9,4,7]
    */

    leftIndex = 0;
    rightIndex = numberOfStones - 1;
    index = 0;

    while (leftIndex <= rightIndex) {
        stonesMaxOrder2[index++] = stones[leftIndex++];
        if (leftIndex <= rightIndex) {
            stonesMaxOrder2[index++] = stones[rightIndex--];
        }
    }

    cout << max(calculateEnergy(stonesMaxOrder1, numberOfStones), calculateEnergy(stonesMaxOrder2, numberOfStones));

    return 0;
}