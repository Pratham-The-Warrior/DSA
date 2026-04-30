/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int mid, vector<int> &a)
{
    /*
    check the missing lements that are needed
    for a candidate 0 to mid-1
    if missing>elements left
    return false
    else return true
    */

    int n = a.size();
    vector<int> miss, extra;
    vector<bool> seen(mid + 1, false), used(n, false);

    for (int i = 0; i < n; i++)
    {
        if (a[i] < mid && !seen[a[i]])
        {
            seen[a[i]] = true;
            used[i] = true;
        }
    }

    for (int i = 0; i < mid; i++)
    {
        if (!seen[i])
        {
            miss.push_back(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            extra.push_back(a[i]);
        }
    }

    if (miss.size() > extra.size())
    {
        return false;
        // score cant be incresed more
    }

    int i = miss.size() - 1;
    int j = extra.size() - 1;

    while (i >= 0)
    {
        if (extra[j] <= 2 * miss[i])
        {
            return false;
        }
        i--;
        j--;
    }

    return true;
}

int mexMax(vector<int> &a)
{
    int n = a.size();
    int low = 1, high = n;
    int best = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(mid, a))
        {
            best = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        /*
        to maximize mex i need to
        make as long permutation as possible
        0 1 2 ....

        */

        /*
        to maximize the greedy failed
        so next approach is binary search ,
        nlogn will be fine
        and we can make a check function
        two primary checks , can the mid be formed or not
        */

        sort(a.begin(), a.end());

        cout << mexMax(a) << endl;
    }

    return 0;
}