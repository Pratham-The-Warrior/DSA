/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
        int n;
        cin >> n;
        string s;
        cin >> s;

        /*--------------------------------------------------------------------------------------------------------
        // add buffer1 to ends

        // to be 1 it will mean
        // before 1=>that index i
        // all values of premutation <= i should be before this idx
        // basically if it is 1 all elements greater than idx should be before it and all greter than it after it

        1 2 3 4 *5 7 6 *8 *9 11 10

        101 => this substring not allowed

        5 _ 7

        11000111001

        1 2 5 4 3 6 7 8 10 9 11
        */
        // check if we find a substtring 101
        // if found output NO and continue
        // else if 1 output the index number (1 based)
        // if found zeroes reverse order of index for those zeroes
        // like if zeroes on index 3 4 5 => give value to those index as 5 4 3
        /*
        1 11000111001 1  //1 buffers
        1 2 5 4 3 6 7 8 10 9 11



        -------------------------------------------------------------------------------------------------------------*/

        s = '1' + s + '1';

        // check for "101"
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '1' && s[i] == '0' && s[i + 1] == '1')
            {
                ok = false;
                break;
            }
        }

        if (!ok)
        {
            cout << "NO" << endl;
            continue;
        }

        vector<int> ans(n);
        int val = 1;

        for (int i = 1; i <= n;)
        {
            if (s[i] == '1')
            {
                ans[i - 1] = val++;
                i++;
            }
            else
            {
                int j = i;
                while (j <= n && s[j] == '0')
                    j++;

                // fill reverse for zero block
                for (int k = j - 1; k >= i; k--)
                {
                    ans[k - 1] = val++;
                }

                i = j;
            }
        }

        cout << "YES" << endl;
        for (int x : ans)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}