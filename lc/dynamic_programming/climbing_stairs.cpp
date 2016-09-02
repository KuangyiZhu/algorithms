#include<string.h>

int climbStairs(int n) {
	int dp[n+1];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++){
		if(i>=3)
			dp[i] = dp[i-1] + dp[i-2];
		else
			dp[i] = i;
	}
	return dp[n];
}

