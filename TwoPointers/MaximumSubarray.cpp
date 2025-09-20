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
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }

    // kadane algo will be used
    // At every element nums[i], we need to decide:
    // Should we continue the subarray we’ve been building? Or should we start fresh from this element?

    int max_sum = a[0], curr_sum = a[0];

    for (int i = 1; i < n; i++)
    {
      curr_sum = max(a[i], curr_sum + a[i]);
      max_sum = max(max_sum, curr_sum);
    }

    cout << max_sum << endl;
  }

  return 0;
}