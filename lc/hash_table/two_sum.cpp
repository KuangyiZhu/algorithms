#include<vector>
#include<map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
	std::map<int, int> value_to_index;
	std::vector<int> res;
	for(int i=0; i<nums.size(); i++){
		if(value_to_index.count(target-nums[i])){
			res.push_back(value_to_index[target-nums[i]]);
			res.push_back(i);
		}
		value_to_index[nums[i]]=i;
	}
	return res;
}

