/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int temp)
{
    // Base condition: place temp if vector is empty or last element ≤ temp
    if (st.size() == 0 || st.top() >= temp)
    {
        st.push(temp);
        return;
    }

    // Otherwise, remove the last element and recurse
    int val = st.top();
    st.pop();
    insert(st, temp);

    // Restore the last element
    st.push(val);
}

void sort_recursive(stack<int> &st)
{
    // Base condition
    if (st.size() <= 1)
        return;

    int temp = st.top();
    st.pop();

    // Sort the smaller array
    sort_recursive(st);

    // Insert the last element in sorted order
    insert(st, temp);
}

int main()
{

    stack<int> st;
    st.push(4);
    st.push(34);
    st.push(7);
    st.push(1);
    st.push(0);

    sort_recursive(st);

    while (!st.empty())
    {
        cout << st.top() << endl;

        st.pop();
    }

    return 0;
}
