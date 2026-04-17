#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
In a movie festival n movies will be shown. You know the starting and
ending time of each movie. What is the maximum number of movies you
can watch entirely?
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<ll, ll>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](auto &a, auto &b)
         { return a.second < b.second; }); // based on v[i].first when v[i].first is same in that case priortise lower v[i].second

    ll ans = 0;

    ll prev = 0;

    for (int i = 0; i < n; i++)
    {
        ll start = v[i].first;
        ll end = v[i].second;
        if (start >= prev)
        {
            prev = end;
            ans++;
        }
    }

    cout << ans;

    return 0;
}