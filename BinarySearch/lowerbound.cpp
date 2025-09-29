/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

// LOWERBOUND :-> smallest index such that a[ind]>=x

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int l = 0, h = n - 1;

  while (l < h)
  {
    int mid = l + (h - l) / 2;
    if (a[mid] < k)
      l = mid + 1;
    else
      h = mid;
  }
  cout << l + 1 << endl;
}