#include<vector>

class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const std::vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
	int nextVal;
	bool isPeaked;
	bool hasNext_;
public:
	PeekingIterator(const std::vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		isPeaked = false;
		hasNext_ = Iterator::hasNext();
	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		if(!isPeaked){
			isPeaked = true;
			nextVal = Iterator::next();
		}
		return nextVal;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		if(isPeaked){
			isPeaked = false;
			hasNext_ = Iterator::hasNext();
		}
		else{
			nextVal = Iterator::next();
			hasNext_ = Iterator::hasNext();
		}
		return nextVal;
	}

	bool hasNext() const {
		return hasNext_;
	}
};
