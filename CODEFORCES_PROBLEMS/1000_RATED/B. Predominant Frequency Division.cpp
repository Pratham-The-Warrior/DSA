/*-------------------------------------------------------------
    NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        // Your code here
        int n;
        cin >> n;
        vector<int> a(n);
        int one = 0, two = 0, three = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // part1 => count(1) >= count(2)+count(3)
        // part2 => count(1)+count(2) >= count(3)
        // part3 => just non emepty

        // till we dont encounter 1 j++
        // when encouneterd this starts our first part and till
        // the nondition for first part is not satisfied make j++
        // once satisfied end first part
        // now part two starts till part two is not satisfied j++
        // now when two get completed end the loop

        // now if j<n-1 cout <<YES  (we have aatleast one number for part3)
        // else cout<<"NO"

        bool final_ans = false;

        {
            int j = 0;
            one = 0;
            two = 0;
            three = 0;
            bool part1_ok = false;
            while (j < n)
            {
                if (a[j] == 1)
                    one++;
                else if (a[j] == 2)
                    two++;
                else if (a[j] == 3)
                    three++;
                j++;
                if (one >= (two + three))
                {
                    part1_ok = true;
                    break;
                }
            }

            int one2 = 0, two2 = 0, three2 = 0;
            bool part2_ok = false;
            while (j < n)
            {
                if (a[j] == 1)
                    one2++;
                else if (a[j] == 2)
                    two2++;
                else if (a[j] == 3)
                    three2++;
                j++;
                if ((one2 + two2) >= three2)
                {
                    part2_ok = true;
                    break;
                }
            }
            if (part1_ok && part2_ok && j < n)
                final_ans = true;
        }

        {
            int j = 0;
            one = 0;
            two = 0;
            three = 0;
            bool part1_ok = false;
            while (j < n)
            {
                if (a[j] == 1)
                    one++;
                else if (a[j] == 2)
                    two++;
                else if (a[j] == 3)
                    three++;
                j++;
                if (one == (two + three))
                {
                    part1_ok = true;
                    break;
                }
            }

            int one2 = 0, two2 = 0, three2 = 0;
            bool part2_ok = false;
            while (j < n)
            {
                if (a[j] == 1)
                    one2++;
                else if (a[j] == 2)
                    two2++;
                else if (a[j] == 3)
                    three2++;
                j++;
                if ((one2 + two2) >= three2)
                {
                    part2_ok = true;
                    break;
                }
            }
            if (part1_ok && part2_ok && j < n)
                final_ans = true;
        }

        {
            int j = 0;
            one = 0;
            two = 0;
            three = 0;
            bool part1_ok = false;
            while (j < n)
            {
                if (a[j] == 1)
                    one++;
                else if (a[j] == 2)
                    two++;
                else if (a[j] == 3)
                    three++;
                j++;
                if (one >= (two + three))
                {
                    part1_ok = true;
                    break;
                }
            }

            int one2 = 0, two2 = 0, three2 = 0;
            bool part2_ok = false;
            while (j < n)
            {
                if (a[j] == 1)
                    one2++;
                else if (a[j] == 2)
                    two2++;
                else if (a[j] == 3)
                    three2++;
                j++;
                if ((one2 + two2) == three2)
                {
                    part2_ok = true;
                    break;
                }
            }
            if (part1_ok && part2_ok && j < n)
                final_ans = true;
        }

        {
            int j = 0;
            one = 0;
            two = 0;
            three = 0;
            bool part1_ok = false;
            while (j < n)
            {
                if (a[j] == 1)
                    one++;
                else if (a[j] == 2)
                    two++;
                else if (a[j] == 3)
                    three++;
                j++;
                if (one == (two + three))
                {
                    part1_ok = true;
                    break;
                }
            }

            int one2 = 0, two2 = 0, three2 = 0;
            bool part2_ok = false;
            while (j < n)
            {
                if (a[j] == 1)
                    one2++;
                else if (a[j] == 2)
                    two2++;
                else if (a[j] == 3)
                    three2++;
                j++;
                if ((one2 + two2) == three2)
                {
                    part2_ok = true;
                    break;
                }
            }
            if (part1_ok && part2_ok && j < n)
                final_ans = true;
        }

        if (final_ans)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
        cout << "\n";
    }

    return 0;
}

//
/*
    #include<bits/stdc++.h>
    using namespace std;

    int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int b1=0,b2=0,mn=1e9;
        bool flag=false;

        for(int i=1;i<=n;i++){
            int x;
            cin>>x;

            if(x==1)b1++;
            else b1--;

            if(x==3)b2--;
            else b2++;

            if(i>=2&&i<n&&mn<=b2)flag=true;

            if(i<=n-2&&b1>=0)mn=min(mn,b2);

        }

        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    }
*/