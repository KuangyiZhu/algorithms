#include<sys/time.h>
#include<cstddef>
#include<unistd.h>

class TokenBucket{
private:
	long last_ts;
	int capacity;
	double tokensPerSecond;
	double tokens;

	long getTimestamp(){
		struct timeval tp;
		gettimeofday(&tp, NULL);
		return tp.tv_sec * 1000 + tp.tv_usec / 1000;
	}

public:
	TokenBucket(int capacity, double tokensPerSecond){
		this->capacity = capacity;
		this->tokensPerSecond = tokensPerSecond;
		this->last_ts = getTimestamp();
		this->tokens = 0;
	}

	bool take(){
		long curr_ts = getTimestamp();
		double diff_time = curr_ts - last_ts;
		last_ts = curr_ts;
		tokens += diff_time * tokensPerSecond / 1000;
		if(tokens > capacity){
			tokens = capacity;
		}
		if(tokens < 1){
			return false;
		}
		tokens--;
		return true;
	}

};
