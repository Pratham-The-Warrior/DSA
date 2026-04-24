/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
 *Suppose you have an integer v
 *In one operation, you can: either set v=(v+1)mod32768 or set v=(2⋅v)mod32768
 *You are given n integers a1,a2,…,an.
 *What is the minimum number of operations you need to make each ai equal to 0
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 32768;

/*
a[i] --> 0

i feel backtracking may be used but path is not asked just ops is needed that also minimum
kind of bottom up DP... but looks like this will take more time..


v=(v+1)mod32768 => v must be like 111111.. all set bits in binary


if we observe here 32768 => 2^15 => 1000 0000 0000 0000

so the logic i found is

take a int mini_ans = INT_MAX;

for each a[i]
num = a[i]

if (num-1)%MOD == 0:
    cout<<0;


    int min_ops_1 = 0;
    int min_ops_2 = 0;
    int cnt = 0;
    while(cnt<min_ans){  //run till we can find minimum answer once it exceeds the min_ans no need to go further it is a terminating condition for loop
         int min_two_power_ahead = .. //this will have the power of 2 just ahead of a[i]
         min_ops_1 = min_two_power_ahead(num) - num-1; //go till power

         min_ans = min(min_ans,cnt + min_ops_1);

         num*=2;

         cnt++;
    }

    cout<<min_ans;



*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--)
    {
        int x;
        cin >> x;

        int ans = 1e9;

        for (int k = 0; k <= 15; k++) //*You only need to try up to 15 increments because you are trying to fix at most 15 bits (due to 215), and beyond that no new advantage appears.
        {                             //+1 ops

            int y = (k + x) % MOD;

            if (y == 0)
            {
                ans = min(ans, k);
                continue;
            }

            int temp = y;

            int t = __builtin_ctz(y);
            ; // t = number of trailing zeros in binary of y
            /*
            *           y = 40 → 101000₂ → t = 3

            *           So:

            *           y = (odd part) × 2^t
            */

            /*
             *Trailing zeros in binary directly represent how many times the number is divisible by 2—so removing them one by one reveals that count.
             */
            //*A number is divisible by 2^15 if its last 15 bits are all 0
            int ops = k + (15 - t); // already t bits are zero so 15-t extra is required
            ans = min(ans, ops);
        }
        cout << ans << " ";
    }

    return 0;
}