#include <bits/stdc++.h>
class NStack {
    int *arr, *top, *next;
    int n, s;
    int freeSpot;
public:

    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        for (int i = 0; i < n; i++)
            top[i] = -1;
        for (int i = 0; i < s; i++)
            next[i] = i + 1;
        next[s - 1] = -1;
        freeSpot = 0;
    }

    bool push(int x, int m) {
        if (freeSpot == -1)
            return false;
        int index = freeSpot;
        freeSpot = next[index];
        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;
        return true;
    }

    int pop(int m) {
        if (top[m - 1] == -1)
            return -1;

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
};

