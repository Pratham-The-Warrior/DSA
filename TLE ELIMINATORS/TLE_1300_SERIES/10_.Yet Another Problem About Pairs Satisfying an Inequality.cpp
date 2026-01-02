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

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    vector<int> valid;
    long long ans = 0;

    for (int j = 0; j < n; j++)
    {
      // a[j] < j+1
      if (a[j] <= j)
      {
        // count i such that i+1 < a[j]  => i < a[j]-1
        ans += lower_bound(valid.begin(), valid.end(), a[j] - 1) - valid.begin();
        valid.push_back(j);
      }
    }

    cout << ans << "\n";
  }

  return 0;
}

/*************************OPTIMIZED**********************/

/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);

//   int t;
//   cin >> t;
//   while (t--)
//   {
//     int n;
//     cin >> n;

//     vector<long long> a(n);
//     for (int i = 0; i < n; i++)
//       cin >> a[i];

//   }

//   return 0;
// }
