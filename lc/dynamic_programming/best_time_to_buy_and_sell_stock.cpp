#include<vector>

/*simplest*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for(int i = prices.size() - 1; i >= 0; i--) {
            for(int j = i - 1; j >=0; j--) {
                if((prices[i] - prices[j]) > max)
                    max = prices[i] - prices[j];
            }
        }
        return max;
    }
};

/*O(1) yet intuitive*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_from_right = 0;
        int min_from_left = prices[0];
        size_t minidx = 0;
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < min_from_left)
                min_from_left = prices[i];
                minidx = i;
                max_from_right = min_from_left;
        }
        
        for(int i = minidx; i < prices.size(); i++) {
            if(prices[i] > max_from_right) {
                max_from_right = prices[i];
            }
        }
        
        return max_from_right - min_from_left;
    }
};


/*compact*/
int maxProfit(std::vector<int>& prices) {
	int n=prices.size();
	if(!n)
		return 0;
	int min=prices[0], max=0, earn=0;
	for(int i=1; i<n; i++){
		earn=prices[i]-min;
		if(prices[i]<min)
			min=prices[i];
		if(earn>max)
			max = earn;
	}
	return max;
}



