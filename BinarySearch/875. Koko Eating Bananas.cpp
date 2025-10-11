/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &piles, int mid, int h)
{
    // i will check if mid value is able to eaqt all in h hrs
    long long hours = 0;
    for (int pile : piles)
    {
        // ceil division
        hours += (pile + mid - 1) / mid;
    }
    return hours <= h;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int n = piles.size();
    sort(piles.begin(), piles.end());
    int low = 1, high = piles[n - 1];
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(piles, mid, h))
        {
            ans = min(mid, ans);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, h;
        cin >> n >> h;
        vector<int> piles(n);
        for (int i = 0; i < n; i++)
        {
            cin >> piles[i];
        }
        cout << minEatingSpeed(piles, h) << endl;
    }

    return 0;
}