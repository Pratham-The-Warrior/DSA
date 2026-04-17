#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> val(n);
        long long temp = k;

        if (k % 2 == 0)
        { // even case
            for (int i = 0; i < n - 1 && k > 0; i++)
            {
                if (s[i] == '1')
                {
                    val[i] = 0;
                }
                else
                {
                    val[i] = 1;
                    k--;
                }
            }
            if (k > 0)
            {
                val[n - 1] = k; // excess value to last
            }
        }
        else
        { // odd case
            for (int i = 0; i < n - 1 && k > 0; i++)
            {
                if (s[i] == '1')
                {
                    val[i] = 1;
                    k--;
                }
                else
                {
                    val[i] = 0;
                }
            }
            if (k > 0)
            {
                val[n - 1] = k; // excess value to last
            }
        }

        string ans = "";
        k = temp;

        if (k % 2 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (val[i] % 2 == 0)
                {
                    ans += s[i];
                }
                else
                {
                    if (s[i] == '1')
                    {
                        ans += '0';
                    }
                    else
                    {
                        ans += '1';
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (val[i] % 2 != 0)
                {
                    ans += s[i];
                }
                else
                {
                    if (s[i] == '1')
                    {
                        ans += '0';
                    }
                    else
                    {
                        ans += '1';
                    }
                }
            }
        }
        cout << ans << endl;
        for (auto c : val)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}
