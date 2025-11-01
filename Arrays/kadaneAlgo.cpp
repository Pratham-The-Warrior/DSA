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

    // Kadane's Algorithm
    long long max_so_far = LLONG_MIN;
    long long current_sum = 0;

    for (int i = 0; i < n; i++)
    {
      current_sum += a[i];
      max_so_far = max(max_so_far, current_sum);
      if (current_sum < 0)
        current_sum = 0;
    }

    cout << max_so_far << "\n";
  }

  return 0;
}
