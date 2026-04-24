/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
* find a such that this becomes true a>=0 (a|b)−(a&c)=d

*This question we can observe that
the bits of b,c,d,a will be independent as there would be no borrow genrated by any bit subtraction
that is becoz in a case 0 - 1 where a borrow is genrated in that case to make sure a&1==1 we need to make sure the nit is set in a
that implies the bit will get set in a|b too so basically that case is not possible

so simply for each bit od d check if we can find a valid bit assignment

b  c  a    d
1  1  0    1
1  1  1    0
1  0  0/1  1
0  1       1 => -1
1  0       0 => -1
0  1  1    0
0  0  1    1
0  0  0    0




*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string numToBinary(ll n)
{
    string s = "";

    while (n > 0)
    {
        s = char((n % 2) + '0') + s;
        n /= 2;
    }

    while (s.size() < 64)
    {
        s = '0' + s;
    }
    return s;
}

ll binaryToNum(string s)
{
    ll res = 0;
    for (int i = 0; i < 64; i++)
    {
        if (s[i] == '1')
        {
            res |= (1LL << (63 - i));
        }
    }
    return res;
}

// 24
// s += 110000

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
        ll b, c, d;
        cin >> b >> c >> d;

        string aa = "";
        string bb = numToBinary(b);
        string cc = numToBinary(c);
        string dd = numToBinary(d);

        bool ok = true;

        for (int i = 0; i < 64; i++)
        {
            // bit by bit cindition check

            // 1 1 0 -> a = 1
            if (bb[i] == '1' && cc[i] == '1' && dd[i] == '0')
            {
                aa += '1';
            }
            // 1 1 1 -> a = 0
            else if (bb[i] == '1' && cc[i] == '1' && dd[i] == '1')
            {
                aa += '0';
            }
            // 1 0 1 -> a = 0 (or 1, choosing 0)
            else if (bb[i] == '1' && cc[i] == '0' && dd[i] == '1')
            {
                aa += '0';
            }
            // 1 0 0 -> impossible
            else if (bb[i] == '1' && cc[i] == '0' && dd[i] == '0')
            {
                ok = false;
                break;
            }
            // 0 1 1 -> impossible
            else if (bb[i] == '0' && cc[i] == '1' && dd[i] == '1')
            {
                ok = false;
                break;
            }
            // 0 1 0 -> a = 0 (or 1, choosing 0)
            else if (bb[i] == '0' && cc[i] == '1' && dd[i] == '0')
            {
                aa += '0';
            }
            // 0 0 1 -> a = 1
            else if (bb[i] == '0' && cc[i] == '0' && dd[i] == '1')
            {
                aa += '1';
            }
            // 0 0 0 -> a = 0
            else if (bb[i] == '0' && cc[i] == '0' && dd[i] == '0')
            {
                aa += '0';
            }
        }

        if (!ok)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << binaryToNum(aa) << endl;
        }
    }

    return 0;
}