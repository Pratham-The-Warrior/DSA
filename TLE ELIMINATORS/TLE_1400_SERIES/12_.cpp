/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> s; // The target string
        cin >> n; // Number of available substrings
        vector<string> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        int target_len = s.length();
        vector<pair<int, int>> result;
        bool possible = true;
        int current_max_reach = 0;
        int i = 0;

        while (current_max_reach < target_len)
        {
            int best_end = -1;
            int best_id = -1;
            int best_start_pos = -1;

            // Check every available substring to see which extends our reach furthest
            for (int j = 0; j < n; j++)
            {
                // Find all occurrences of v[j] in s
                size_t pos = s.find(v[j], 0);
                while (pos != string::npos)
                {
                    int start = (int)pos;
                    int end = start + (int)v[j].length();

                    // It must start within our currently covered range
                    // and extend beyond our current reach
                    if (start <= current_max_reach && end > best_end)
                    {
                        best_end = end;
                        best_id = j + 1;            // 1-based index for the string
                        best_start_pos = start + 1; // 1-based index for the position
                    }
                    pos = s.find(v[j], pos + 1);
                }
            }

            // If we couldn't extend the reach at all, it's impossible
            if (best_end <= current_max_reach)
            {
                possible = false;
                break;
            }

            result.push_back({best_id, best_start_pos});
            current_max_reach = best_end;
        }

        if (!possible)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << result.size() << "\n";
            for (auto p : result)
            {
                cout << p.first << " " << p.second << "\n";
            }
        }
    }

    return 0;
}