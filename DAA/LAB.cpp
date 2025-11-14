/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

bool LinearSearch(vector<int> &a, int x)
{

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << (LinearSearch(a, x) ? "Present" : "Not Present");

        cout << endl;
    }

    return 0;
}
