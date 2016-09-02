#include<vector>

int lengthOfLIS(std::vector<int>& nums) {
	int n = nums.size();
	std::vector<int> min;
	std::vector<int>::iterator it;
	for(int i=0; i<n; i++){
		it = std::lower_bound(min.begin(), min.end(), nums[i]);
		if(it != min.end()){
			*it = nums[i];
		}
		else{
			min.push_back(nums[i]);
		}
	}
	return min.size();
}
