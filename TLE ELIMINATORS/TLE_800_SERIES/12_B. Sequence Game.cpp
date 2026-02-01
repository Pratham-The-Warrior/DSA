/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> b(n);
        for (int j = 0; j < n; j++)
        {
            cin >> b[j];
        }
        vector<int> a;
        a.push_back(b[0]);
        for (int j = 1; j < n; j++)
        {
            if (b[j] >= b[j - 1])
            {
                a.push_back(b[j]);
            }
            else
            {
                a.push_back(b[j]);
                a.push_back(b[j]);
            }
        }
        int m = a.size();
        cout << m << endl;
        for (int j = 0; j < m; j++)
        {
            cout << a[j] << " ";
        }
        cout << endl;
    }
}