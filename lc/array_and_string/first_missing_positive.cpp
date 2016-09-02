#include<vector>
#include<algorithm>

int firstMissingPositive(std::vector<int>& nums) {
	nums.push_back(0);
	int n=nums.size();
	for(int i=0; i<n; i++){
		if(nums[i]>0&&nums[i]<n&&nums[i]!=i&&nums[nums[i]]!=nums[i]){
			std::swap(nums[i], nums[nums[i]]);
			i--;
		}
	}
	int num=n;
	for(int i=1; i<n; i++){
		if(nums[i]!=i){
			num=i;
			break;
		}
	}
	return num;
}

