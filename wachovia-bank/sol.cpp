/**
*    author: lucasfcm9
*    created: 04.12.20 09:43:05
**/
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 60;
const int MAXM = 1010;

long long dp[MAXN][MAXM];

template <typename T>
long long Solve(int i, int m, int M, vector<pair<T, T>>& as) {
  if (i < 0) {
    return 0;
  }
  if (dp[i][m] != -1) {
    return dp[i][m];
  }
  long long ans = Solve(i - 1, m, M, as);
  auto weight = as[i].first;
  auto value = as[i].second;

  if (weight <= m) {
    ans = max(ans, Solve(i - 1, m - weight, M, as) + value);
  }

  dp[i][m] = ans;
  return ans;
}

template <typename T>
long long Knapsack(int M, vector<pair<T, T>>& as) {
  memset(dp, -1, sizeof dp);
  return Solve((int) as.size() - 1, M, M, as);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int m, n;
    cin >> m >> n;
    vector<pair<int, int>> as(n);
    for (int i = 0; i < n; i++) {
      cin >> as[i].first >> as[i].second;
    }
    // as[i].first = weight of the bag
    // as[i].second = value of the bag

    cout << "Hey stupid robber, you can get " << Knapsack(m, as) << ".\n";
  }
  return 0;
}
