/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int Mex(vector<int> a)
{
  // return mex value of the vector a
}

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
    int count0 = 0;
    int count1 = 0;

    for (int i = 0; i < n; ++i)
    {
      int val;
      cin >> val;
      if (val == 0)
      {
        count0++;
      }
      else if (val == 1)
      {
        count1++;
      }
    }
    if (count0 == 0)
    {
      // MEX of everything is 0
      cout << "NO" << endl;
    }
    else if (count0 == 1)
    {
      // Placing 0 at index 0 makes prefix MEX >= 1 and suffix MEX = 0
      cout << "YES" << endl;
    }
    else
    {
      // If there are multiple 0s, we need at least one 1 to differentiate
      // MEX 1 from MEX >= 2.
      if (count1 > 0)
      {
        cout << "YES" << endl;
      }
      else
      {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}