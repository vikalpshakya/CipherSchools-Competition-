#include <bits/stdc++.h>

int largestRectangle(vector<int>& h) {
    int n = h.size();
    stack<int> st;

    int maxr = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] >= h[i]) {
            int x = st.top();
            st.pop();
            int width;
            if (st.empty()) {
                width = i;
            } else {
                width = i - st.top() - 1;
            }
            int area = h[x] * width;
            maxr = max(maxr, area);
        }
        st.push(i);
    }

    while (!st.empty()) {
        int x = st.top();
        st.pop();
        int width;
        if (st.empty()) {
            width = n;
        } else {
            width = n - st.top() - 1;
        }
        int area = h[x] * width;
        maxr = max(maxr, area);
    }
    return maxr;
}
