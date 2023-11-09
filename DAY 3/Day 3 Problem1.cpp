#include <bits/stdc++.h> 

int memo[55][55];

int sum(const vector<int>& freq, int i, int j) {
  int total = 0;
  for (int k = i; k <= j; ++k) {
    total += freq[k];
  }
  return total;
}

int solve(const vector<int>& freq, int i, int j) {
  if (i > j) {
    return 0;
  }
  if (i == j) 
    return freq[i];
  

  int minCost = INT_MAX;
  if (memo[i][j] != -1) return memo[i][j];
  

  int freqSum = sum(freq, i, j);
  for (int k = i; k <= j; ++k) {
    minCost = min(minCost, solve(freq, i, k - 1) + solve(freq, k + 1, j));
  }

  memo[i][j] = minCost + freqSum;
  return memo[i][j];
}

int optimalCost(const vector<int>& keys, const vector<int>& freq, int n) {
  memset(memo, -1, sizeof(memo));
  return solve(freq, 0, n - 1);
}
