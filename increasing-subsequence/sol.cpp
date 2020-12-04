/**
*    author: lucasfcm9
*    created: 04.12.20 11:03:50
**/
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

const int inf = (int) 1e9;

int LIS(int n, vector<int>& as) {
  vector<int> lis(n + 1, inf);
  lis[0] = 0;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    auto it = lower_bound(lis.begin(), lis.end(), as[i]) - lis.begin();
    ans = max(ans, (int) it);
    lis[it] = as[i];
  }
  return ans;
}  

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << LIS(n, a) << '\n';
  return 0;
}
