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

    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;

        vector<int> div;

        for (int i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                div.push_back(i);
                if (x / i != i)
                {
                    div.push_back(x / i);
                }
            }
        }

        cout << div.size() << endl;
    }

    return 0;
}