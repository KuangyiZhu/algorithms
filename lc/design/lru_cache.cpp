#include<list>
#include<map>

class LRUCache{
private:
	int capacity;
	std::map<int, std::list<std::pair<int, int> >::iterator> cacheLoc;
	std::list<std::pair<int, int> > cache;
public:
	LRUCache(int capacity) {
		this->capacity=capacity;
	}
    
	int get(int key) {
		if(cacheLoc.count(key)){
			std::list<std::pair<int, int> >::iterator iter=cacheLoc[key];
			cache.splice(cache.begin(), cache, iter);
			return iter->second;
		}
		else{
			return -1;
		}
	}
    
	void set(int key, int value) {
		if(cacheLoc.count(key)){
			std::list<std::pair<int, int> >::iterator iter=cacheLoc[key];
			cache.splice(cache.begin(), cache, iter);
			iter->second=value;
			return;
		}
		if(cache.size()==capacity){
			int k=cache.back().first;
			cache.pop_back();
			cacheLoc.erase(k);
		}
		cache.push_front(std::make_pair(key, value));
		cacheLoc[key]=cache.begin();
	}
};
