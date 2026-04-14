#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void towerOfHanoi(int n, int source, int auxiliary, int target)
{
    if (n == 1)
    {
        cout << source << " " << target << endl;
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, target, auxiliary);

    // Move nth disk to target
    cout << source << " " << target << endl;

    // Move n-1 disks from auxiliary to target
    towerOfHanoi(n - 1, auxiliary, source, target);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << (1 << n) - 1 << endl;
    towerOfHanoi(n, 1, 2, 3);

    return 0;
}