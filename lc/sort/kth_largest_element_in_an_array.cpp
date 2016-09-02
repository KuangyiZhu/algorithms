#include<vector>
#include<queue>

int findKthLargest(std::vector<int>& nums, int k) {
	std::priority_queue<int,  std::vector<int>, std::greater<int> > q;
	for(int i=0; i<nums.size(); i++){
		if(q.size()<k){
			q.push(nums[i]);
		}
		else if(nums[i]>q.top()){
			q.pop();
			q.push(nums[i]);
		}
	}
	return q.top();
}
