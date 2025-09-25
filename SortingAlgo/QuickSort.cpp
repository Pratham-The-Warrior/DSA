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

// Partition function (Lomuto scheme)
int partition2(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // pivot element
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Iterative QuickSort
void quickSortIterative(vector<int> &arr, int low, int high)
{
    // Create an explicit stack
    vector<int> stack(high - low + 1);

    int top = -1;

    // Push initial low and high values
    stack[++top] = low;
    stack[++top] = high;

    // Pop elements until stack is empty
    while (top >= 0)
    {
        high = stack[top--];
        low = stack[top--];

        // Partition the array
        int p = partition2(arr, low, high);

        // If left side has more than one element, push it
        if (p - 1 > low)
        {
            stack[++top] = low;
            stack[++top] = p - 1;
        }

        // If right side has more than one element, push it
        if (p + 1 < high)
        {
            stack[++top] = p + 1;
            stack[++top] = high;
        }
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
        vector<int> a(n), b;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        b = a;
        quickSort(a, 0, n - 1);
        quickSortIterative(b, 0, n - 1);

        for (auto x : a)
        {
            cout << x << " ";
        }
        cout << endl;
        for (auto x : b)
        {
            cout << x << " ";
        }

        cout << endl;
    }

    return 0;
}