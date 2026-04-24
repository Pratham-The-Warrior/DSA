/*-------------------------------------------------------------
   NEVER GIVE UP THE SOLUTION MAY BE JUST AROUND THE CORNER
---------------------------------------------------------------*/

/*
*PROBLEM STATEMENT
A positive integer x is called a power of two if it can be represented as x=2y , where y
is a non-negative integer. So, the powers of two are 1,2,4,8,16...

You are given two positive integers n and k.
Your task is to represent n as the sum of exactly k powers of two.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    /*
    see i can do it this way
    like if k==4 and n==10
    check how many bits are set in n
    1010
    currently 2 extra needed are 2
    so i think i can do it like check for each bit which is currentlt set
    in how mnay power of two we ccan decompose it
    like 1000 bit we can devide it => 111 bits i.e(1<<bit-1)
    add this into our sum += 3
    now again check for each of this bits one by one how many we can divide
    and add count to sum till sum!=k

    NO will be in case where given k value < less than original set bits(becoz that much are must needed)
    and also when k>n
    */

    // this think can be nicely simulated using maxheap i.e priority_queue

    priority_queue<ll> pq;

    for (int i = 0; i < 60; i++)
    {
        if (n & (1LL << i))
        {
            pq.push(1ll << i);
        }
    }

    if (k < pq.size() || k > n)
    {
        cout << "NO";
        return 0;
    }

    while ((ll)pq.size() < k)
    {
        ll top = pq.top();
        pq.pop();
        if (top == 1)
        {
            break; // all elements divided but i dont think this condition will ever come
        }
        pq.push(top / 2);
        pq.push(top / 2);
    }

    if (pq.size() != k)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}