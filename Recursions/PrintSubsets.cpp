#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int> &arr, vector<int> &current, int index)
{
    // Show entry into the function
    cout << "Called with index = " << index << ", current = { ";
    for (int x : current)
        cout << x << " ";
    cout << "}" << endl;

    // Base case
    if (index == arr.size())
    {
        cout << "Reached end, print subset: { ";
        for (int x : current)
            cout << x << " ";
        cout << "}" << endl
             << endl;
        return;
    }

    // Case 1: Exclude current element
    cout << " Excluding element " << arr[index] << endl;
    printSubsets(arr, current, index + 1);

    // Case 2: Include current element
    cout << " Including element " << arr[index] << endl;
    current.push_back(arr[index]);
    printSubsets(arr, current, index + 1);

    // Backtrack
    cout << " Backtracking: removing " << arr[index] << endl;
    current.pop_back();
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> current;

    cout << "==== TRACE START ====\n";
    printSubsets(arr, current, 0);
    cout << "==== TRACE END ====\n";

    return 0;
}
