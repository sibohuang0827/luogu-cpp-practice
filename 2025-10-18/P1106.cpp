#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string number;
    int deleteDigitCount;

    cin >> number;
    cin >> deleteDigitCount;

    // greedy algorithm
    for (int i = 1; i < number.length() && deleteDigitCount > 0; i++)
    {
        if (number[i - 1] > number[i]) 
        {
            number.erase(i - 1,1);
            i = 0;
            deleteDigitCount--;
        }
    }

    // solve ascending order problem
    while (deleteDigitCount > 0) 
    {
        number.pop_back();
        deleteDigitCount--;
    }

    // delete leading zeros
    int startIndex = 0;
    for (int i = 0; i < number.length(); i++) 
    {
        if (number[i] == '0') 
        {
            startIndex ++;
        } 
        else 
        {
            break;
        }
    }

    // handle all zeroes case
    if (startIndex == number.length())
    {
        cout << "0";
    }
    else 
    {
        cout << number.substr(startIndex);
    }
}