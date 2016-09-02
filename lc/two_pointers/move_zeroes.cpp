#include<vector>

void moveZeroes(std::vector<int>& nums) {
	int step = 0;
	for(int i=0; i<nums.size(); i++){
		if(nums[i]==0)
			step++;
		else if(step!=0){
			nums[i-step] = nums[i];
			nums[i] = 0;
		}
	}
}
