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
    int n, m;
    cin >> n >> m;
    vector<int> limit(n + 1, n + 1);
    for (int i = 0; i < m; i++)
    {
      int x, y;
      cin >> x >> y;
      if (x > y)
        swap(x, y);
      limit[x] = min(limit[x], y);
    }

    int min_right = n + 1;
    int ans = 0;

    for (int i = n; i >= 1; i--)
    {
      min_right = min(limit[i], min_right);
      ans += min_right - i;
    }

    cout << ans << endl;
  }

  return 0;
}