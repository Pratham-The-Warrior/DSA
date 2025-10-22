/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char source, char target, char auxiliary)
{
    // Base case: Only one disk to move
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " → " << target << endl;
        return;
    }
    // Step 1: Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, target);

    // Step 2: Move the largest disk from source to target
    cout << "Move disk " << n << " from " << source << " → " << target << endl;

    // Step 3: Move the n-1 disks from auxiliary to target
    towerOfHanoi(n - 1, auxiliary, target, source);
}

int main()
{

    int n;
    cin >> n;

    cout << "Steps :-" << endl;

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}