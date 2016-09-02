#include<vector>
#include<string.h>

int rob(std::vector<int>& nums) {
	int n = nums.size();
	if(!n)
		return 0;
	int dp[n+1];
	memset(dp, 0, sizeof(dp));
	int max = 0;
	for(int i=0; i<n; i++){
		if(i>2)
			dp[i] = std::max(dp[i-2], dp[i-3]) + nums[i];
		else
		dp[i] = (i>1?dp[i-2]:0) + nums[i];
		if(dp[i]>max)
			max = dp[i];
	}
	return max;
}
