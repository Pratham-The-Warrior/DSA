/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int l, int h)
{
    int pivot = a[l];
    int i = l;
    int j = h;

    while (true)
    {
        while (a[i] < pivot)
        {
            i++;
        }

        while (a[j] > pivot)
        {
            j--;
        }

        if (i >= j)
        {
            return j;
        }

        swap(a[i], a[j]);
        i++;
        j--;
    }
}

void quickSort(vector<int> &a, int l, int h)
{

    if (l < h)
    {
        int pi = partition(a, l, h);
        quickSort(a, 0, pi);
        quickSort(a, pi + 1, h);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        quickSort(a, 0, n - 1);

        for (auto x : a)
        {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}