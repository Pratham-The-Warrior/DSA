/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
/*========================================================
  NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
  ======================================================== */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 *Complexity Analysis :-
 *Time = O(nloglogn)
 *space = O(n)
 */

void seive(int n)
{
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false; // 0 and 1 are not prime

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    int total = count(prime.begin(), prime.end(), true);
    cout << "Total Primes : " << total << endl;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    seive(n);

    return 0;
}