#include<vector>

std::vector<int> singleNumber(std::vector<int>& nums) {
	std::vector<int> results;
	int xornums = 0;
	for(int i=0; i<nums.size(); i++){
		xornums ^= nums[i];
	}
	int mask = 1;
	while((xornums&mask) == 0){
		mask = mask<<1;
	}
	results.push_back(0);
	results.push_back(0);
	for(int i=0; i<nums.size(); i++){
		if(nums[i]&mask)
			results[0] ^= nums[i];
		else
			results[1] ^= nums[i];
	}
	return results;
}
