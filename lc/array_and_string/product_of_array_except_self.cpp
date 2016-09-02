#include<vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
	std::vector<int> results;
	results.push_back(1);
	for(int i=1; i<nums.size(); i++){
		results.push_back(results[i-1]*nums[i-1]);
	}
	int p = 1;
	for(int i=nums.size()-1; i>=0; i--){
		results[i] *= p;
		p *= nums[i];
	}
	return results;
}
