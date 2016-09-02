#include<vector>

int missingNumber(std::vector<int>& nums) {
	int n=nums.size();
	int num=0;
	for(int i=0; i<n; i++){
		num+=i-nums[i];
	}
	num+=n;
	return num;
}
