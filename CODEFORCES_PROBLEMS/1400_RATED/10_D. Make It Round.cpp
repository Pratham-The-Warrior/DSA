#include <bits/stdc++.h>
using namespace std;

long long bestMultiplier(long long n, long long m)
{
  long long i = 1;

  auto countFactor = [&](long long x, int p)
  {
    int cnt = 0;
    while (x % p == 0)
    {
      x /= p;
      cnt++;
    }
    return cnt;
  };

  int c2 = countFactor(n, 2);
  int c5 = countFactor(n, 5);

  while (c2 < c5 && i * 2 <= m)
  {
    i *= 2;
    c2++;
  }
  while (c5 < c2 && i * 5 <= m)
  {
    i *= 5;
    c5++;
  }

  while (i * 10 <= m)
  {
    i *= 10;
  }

  i *= (m / i);

  return i;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
  {
    long long n, m;
    cin >> n >> m;
    cout << bestMultiplier(n, m) * n << '\n';
  }

  return 0;
}
