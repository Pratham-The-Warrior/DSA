#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*BRUTE FORCE*/

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        bool found = false;
        for (int i = 0; i < n && !found; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((a[j] % a[i]) % 2 == 0)
                {
                    cout << a[i] << " " << a[j] << endl;
                    found = true;
                    break;
                }
            }
        }

        if (!found)
        {
            cout << -1 << endl;
        }
    }

    return 0;
}

/*OPTIMIZED O(N)*/
/*

The LogicTwo Even Numbers: If the sequence contains any two even numbers $x$ and $y$ (where $x < y$), then $y \bmod x$ is always even.Proof: $y = qx + r$. If $y$ and $x$ are even, then $r = y - qx$ must be even because $Even - (q \times Even) = Even$.The Growth Constraint: If we don't have two even numbers, we have mostly odd numbers. For a pair of odd numbers $(x, y)$ to fail the condition (i.e., for $y \bmod x$ to be odd), $y$ must be at least $2x$. Specifically, since both are odd, $y \ge 2x + 1$ is usually required to keep the quotient
 even or the remainder odd.The "32" Rule: Because the sequence is strictly increasing and the maximum value is $10^9$, you cannot have more than ~31-32 numbers without triggering the condition. If $n$ is large, a valid pair must exist very close to the beginning of the sequence.

 Optimized $O(n)$ ApproachStep 1: Check if there are at least two even numbers. If yes, output the first two found.Step 2: If not, a valid pair must exist within a small distance of each other because the values cannot grow fast enough to avoid the condition for long. Checking each element against the next 100 elements is more than enough to guarantee finding a solution if one exists.


*/
