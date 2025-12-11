/* ************************************************
 *                                                *
 *       P     R     A     T     H     A     M    *
 *                                                *
 ************************************************ */
#include <bits/stdc++.h>
using namespace std;

void reverse(stack<int> &st)
{

    if (st.empty())
    {
        return;
    }

    int top = st.top();
    st.pop();
    reverse(st); // recursive

    stack<int> temp;

    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(top);

    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
}

// space optimized o(1)
void insertBottom(stack<int> &st, int element)
{

    if (st.empty())
    {
        st.push(element);
        return;
    }

    int top = st.top();
    st.pop();

    insertBottom(st, element);

    st.push(top);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverse(st);

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}