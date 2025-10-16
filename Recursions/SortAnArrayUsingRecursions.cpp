/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &a, int temp)
{
    // Base condition: place temp if vector is empty or last element ≤ temp
    if (a.size() == 0 || a.back() <= temp)
    {
        a.push_back(temp);
        return;
    }

    // Otherwise, remove the last element and recurse
    int val = a.back();
    a.pop_back();
    insert(a, temp);

    // Restore the last element
    a.push_back(val);
}

void sort_recursive(vector<int> &a)
{
    // Base condition
    if (a.size() <= 1)
        return;

    int temp = a.back();
    a.pop_back();

    // Sort the smaller array
    sort_recursive(a);

    // Insert the last element in sorted order
    insert(a, temp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort_recursive(a);

    for (auto x : a)
        cout << x << " ";

    return 0;
}
