#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int maxA = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxA = max(maxA, a[i]);
    }

    vector<int> freq(maxA + 1, 0);

    for (int x : a)
    {
        freq[x]++;
    }

    for (int g = maxA; g >= 1; g--)
    {
        int count = 0;

        for (int j = g; j <= maxA; j += g)
        {
            count += freq[j];
            if (count >= 2)
            {
                cout << g << endl;
                return 0;
            }
        }
    }

    return 0;
}