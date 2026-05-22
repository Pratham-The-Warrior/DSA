// /*-------------------------------------------------------------
//    NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
// ---------------------------------------------------------------*/

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// /*
// *PROBLEM STATEMENT
// You are given an array of n integers. Your task is to calculate for each window of k elements, from left to right, the minimum total cost of making all elements equal.
// You can increase or decrease each element with cost x where x is the difference between the new and the original value. The total cost is the sum of such costs.
// */

// multiset<ll> low, high;

// void balance()
// {
//     if (low.size() > high.size() + 1)
//     {
//         auto it = prev(low.end());
//         high.insert(*it);
//         low.erase(it);
//     }
//     else if (low.size() < high.size())
//     {
//         auto it = high.begin();
//         low.insert(*it);
//         high.erase(it);
//     }
// }

// void add(ll x)
// {
//     if (low.empty())
//     {
//         low.insert(x);
//     }
//     else
//     {
//         ll maxlow = *prev(low.end());
//         if (x <= maxlow)
//         {
//             low.insert(x);
//         }
//         else
//         {
//             high.insert(x);
//         }
//     }
//     balance();
// }

// void remove(ll x)
// {
//     auto itLow = low.find(x);

//     if (itLow != low.end())
//     {
//         low.erase(itLow);
//     }
//     else
//     {
//         auto itHigh = high.find(x);
//         high.erase(itHigh);
//     }
//     balance();
// }

// ll getMedian()
// {
//     return *prev(low.end()); // largest element in low set
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     ll n, k;
//     cin >> n >> k;

//     vector<ll> a(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     vector<ll> medians;

//     for (int i = 0; i < k; i++)
//     {
//         add(a[i]);
//     }

//     medians.push_back(getMedian());

//     for (int i = k; i < n; i++)
//     {
//         add(a[i]);
//         remove(a[i - k]);
//         medians.push_back(getMedian());
//     }

//     // now i have got the median the cost will be minimum
//     // when we will make every element in that window equal to the median of that window
//     vector<ll> ans;
//     int l = 0;
//     for (int i = 0; i <= n - k; i++)
//     {
//         ll temp = 0;
//         for (int j = i; j < i + k; j++)
//         {
//             temp += llabs(a[j] - medians[l]);
//         }
//         ans.push_back(temp);
//         l++;
//     }

//     for (auto x : ans)
//     {
//         cout << x << " ";
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

multiset<ll> low, high;
ll sumLow = 0, sumHigh = 0;

void balance()
{
    if (low.size() > high.size() + 1)
    {
        auto it = prev(low.end());
        ll val = *it;

        low.erase(it);
        sumLow -= val;

        high.insert(val);
        sumHigh += val;
    }
    else if (low.size() < high.size())
    {
        auto it = high.begin();
        ll val = *it;

        high.erase(it);
        sumHigh -= val;

        low.insert(val);
        sumLow += val;
    }
}

void add(ll x)
{
    if (low.empty())
    {
        low.insert(x);
        sumLow += x;
    }
    else
    {
        ll maxlow = *prev(low.end());
        if (x <= maxlow)
        {
            low.insert(x);
            sumLow += x;
        }
        else
        {
            high.insert(x);
            sumHigh += x;
        }
    }
    balance();
}

void remove(ll x)
{
    auto itLow = low.find(x);

    if (itLow != low.end())
    {
        sumLow -= x;
        low.erase(itLow);
    }
    else
    {
        auto itHigh = high.find(x);
        sumHigh -= x;
        high.erase(itHigh);
    }
    balance();
}

ll getMedian()
{
    return *prev(low.end());
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

    vector<ll> ans;

    // initial window
    for (int i = 0; i < k; i++)
    {
        add(a[i]);
    }

    for (int i = 0; i <= n - k; i++)
    {
        ll median = getMedian();

        ll cost = median * low.size() - sumLow + sumHigh - median * high.size();

        ans.push_back(cost);

        if (i + k < n)
        {
            add(a[i + k]);
            remove(a[i]);
        }
    }

    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}