/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int l, int h, int mid)
{
    int n1 = mid - l + 1;
    int n2 = h - mid;

    vector<int> v1(n1), v2(n2);

    for (int i = 0; i < n1; i++)
    {
        v1[i] = a[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        v2[i] = a[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (v1[i] <= v2[j])
        {
            a[k] = v1[i];
            k++;
            i++;
        }
        else
        {
            a[k] = v2[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        a[k] = v1[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        a[k] = v2[j];
        k++;
        j++;
    }
}

void mergesort(vector<int> &a, int l, int h)
{

    if (l < h)
    {
        int mid = l + (h - l) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, h);
        merge(a, l, h, mid);
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
        mergesort(a, 0, n - 1);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }

    return 0;
}