#include<vector>
#include<set>

bool containsDuplicate(std::vector<int>& nums) {
	std::set<int> flags;
	for(int i=0; i<nums.size(); i++){
		if(flags.count(nums[i]))
			return true;
		else
			flags.insert(nums[i]);
	}
	return false;
}
