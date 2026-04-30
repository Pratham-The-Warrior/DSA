/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
*PROBLEM STATEMENT
You are given an array of n integers.
Your task is to calculate the median of each window of k elements, from left to right.
The median is the middle element when the elements are sorted.
If the number of elements is even, there are two possible medians and we assume that the median is the smaller of them.
*/

multiset<ll> low, high;

void balance()
{
    if (low.size() > high.size() + 1)
    {
        auto it = prev(low.end());
        high.insert(*it);
        low.erase(it);
    }
    else if (low.size() < high.size())
    {
        auto it = high.begin();
        low.insert(*it);
        high.erase(it);
    }
}

void add(ll x)
{
    if (low.empty())
    {
        low.insert(x);
    }
    else
    {
        ll maxlow = *prev(low.end());
        if (x <= maxlow)
        {
            low.insert(x);
        }
        else
        {
            high.insert(x);
        }
    }
    balance();
}

void remove(ll x)
{
    auto itLow = low.find(x);

    if (itLow != low.end())
    {
        low.erase(itLow);
    }
    else
    {
        auto itHigh = high.find(x);
        high.erase(itHigh);
    }
    balance();
}

ll getMedian()
{
    return *prev(low.end()); // largest element in low set
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < k; i++)
    {
        add(a[i]);
    }

    cout << getMedian() << " ";

    for (int i = k; i < n; i++)
    {
        add(a[i]);
        remove(a[i - k]);
        cout << getMedian() << " ";
    }

    return 0;
}
