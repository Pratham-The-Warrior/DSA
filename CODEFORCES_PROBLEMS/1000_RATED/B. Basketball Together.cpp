#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long D;
    cin >> n >> D;

    vector<long long> P(n);
    for (int i = 0; i < n; i++)
        cin >> P[i];

    sort(P.rbegin(), P.rend()); // descending

    int i = 0;
    int j = n - 1;
    int teams = 0;

    while (i <= j)
    {
        long long need = (D + 1 + P[i] - 1) / P[i];

        if (i + need - 1 <= j)
        {
            teams++;
            i++;             // take strongest
            j -= (need - 1); // take weakest
        }
        else
        {
            break;
        }
    }

    cout << teams << "\n";
}