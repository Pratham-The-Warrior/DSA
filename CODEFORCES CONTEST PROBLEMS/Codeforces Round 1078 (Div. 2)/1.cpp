#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        cout << n - n / w << endl;
    }
}
