#include<vector>

int search(std::vector<int>& nums, int target) {
	int i=0, j=nums.size()-1;
	int m;
	while(i<j){
		m=(i+j)/2;
		if(nums[i]<=target){
			if(nums[m]<nums[i])
				j=m;
			else if(nums[m]<target)
				i=m+1;
			else
				j=m;
		}
		else{
			if(nums[m]>=nums[i])
				i=m+1;
			else if(nums[m]<target)
				i=m+1;
			else
				j=m;
		}
	}
	if(nums[i]==target)
		return i;
	return -1;
}

