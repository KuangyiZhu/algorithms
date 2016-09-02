#include<vector>

int maxSubArray(std::vector<int>& nums) {
	int sum=nums[0], max=nums[0];
	for(int i=1; i<nums.size(); i++){
		if(sum>0)
			sum += nums[i];
		else
			sum = nums[i];
		if(sum > max)
			max = sum;
	}
	return max;
}

