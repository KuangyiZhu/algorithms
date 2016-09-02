#include<vector>
#include<string.h>

int minimumTotal(std::vector<std::vector<int>>& triangle) {
	int n = triangle.size();
	int dp[n];
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<n; i++){
		int j = triangle[i].size()-1;
		dp[j] = (j>=1?dp[j-1]:dp[j]) + triangle[i][j];
		j--;
		while(j>=0){
			if(j>=1&&dp[j-1]<dp[j])
				dp[j]=dp[j-1]+triangle[i][j];
			else
				dp[j]=dp[j]+triangle[i][j];
			j--;
		}
	}
	int minnum = dp[0];
	for(int i=1; i<n; i++){
		if(dp[i]<minnum)
			minnum = dp[i];
	}
	return minnum;
}
