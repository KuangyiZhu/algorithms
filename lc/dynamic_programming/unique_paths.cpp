#include<string.h>

int uniquePaths(int m, int n) {
	int dp[m];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i=0; i<n; i++){
		for(int j=1; j<m; j++){
			dp[j] += dp[j-1];
		}
	}
	return dp[m-1];
}

