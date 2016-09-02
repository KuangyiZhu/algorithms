#include<vector>
#include<queue>

class MedianFinder {
public:
	// Adds a number into the data structure.
	void addNum(int num) {
		large_part.push(num);
		small_part.push(large_part.top());
		large_part.pop();
		if(small_part.size()-large_part.size()>=2){
			large_part.push(small_part.top());
			small_part.pop();
		}
	}

	// Returns the median of current data stream
	double findMedian() {
		if(small_part.size()>large_part.size())
			return small_part.top();
		else
			return (small_part.top()+large_part.top())/2.0;
	}
private:
	std::priority_queue<int> small_part;
	std::priority_queue<int, std::vector<int>, std::greater<int> > large_part;
};
