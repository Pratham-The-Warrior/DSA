#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    long long n;
    cin >> n;

    // 4 7 44 47 74 77 444 447 474 477 744 747 774 777 4444 4447

    // i need O(1) or O(logn) solution as n <= 1e9

    // 3 37 3 27 3 367 3 27 3 267 3 27 ... 3667 3 27 3
    // at each position like
    // based in the number of digits we can get the number prior to it
    // like 4444 => 4digits => 8 + 4 + 2 + 1 => elements behind

    string s1 = to_string(n);
    int digits = s1.length();

    long long behind = (1LL << digits) - 1;

    // how many numbers did we jump over in this digit-block?
    long long fromhere = 0;
    for (int i = 0; i < digits; i++)
    {
        if (s1[i] == '7')
        {
            // If we see a '7', it means we skipped all lucky numbers
            // that had a '4' at this current position.
            // The number of combinations skipped is 2^(digits - 1 - i)
            int power = digits - 1 - i;
            fromhere += (1LL << power);
        }
    }
    cout << behind + fromhere << endl;
}