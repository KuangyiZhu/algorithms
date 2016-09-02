#include<vector>
#include<string.h>

int minPathSum(std::vector<std::vector<int>>& grid) {
	int n = grid.size();
	if(n==0)
		return 0;
	int m = grid[0].size();
	int dp[m];
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<n; i++){
		dp[0] = dp[0]+grid[i][0];
		for(int j=1; j<m; j++){
			if(i!=0)
				dp[j] = std::min(dp[j-1], dp[j]) + grid[i][j];
			else
				dp[j] = dp[j-1] + grid[i][j];
		}
	}
	return dp[m-1];
}

