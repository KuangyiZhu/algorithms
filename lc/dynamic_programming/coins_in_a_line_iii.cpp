#include<vector>
#include<string.h>
#include<algorithm>

int firstWillGetMax(std::vector<int> coins){
  int n = coins.size();
  int sums[n+1];
  sums[0] = 0;
  for(int i=1; i<=n; i++){
    sums[i] = sums[i-1] + coins[i-1];
  }
  int dp[n][n];
  memset(dp, 0, sizeof(dp));
  for(int i=n-1; i>=0; i--){
    for(int j=i; j<n; j++){
      if(i==j){
        dp[i][j] =coins[i];
      }
      else{
        dp[i][j] = sums[j+1] - sums[i] - std::min(dp[i+1][j], dp[i][j-1]);
      }
    }
  }
  return dp[0][n-1];
}
