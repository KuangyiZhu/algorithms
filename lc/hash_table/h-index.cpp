#include<vector>
#include<string.h>

int hIndex(std::vector<int>& citations) {
	int n = citations.size();
	int counts[n+1];
	memset(counts, 0, sizeof(counts));
	int index = 0;
	for(int i=0; i<n; i++){
		index = citations[i]>n ? n : citations[i];
		counts[index]++;
	}
	int h = 0;
	for(int j=n; j>=0; j--){
		h += counts[j];
		if(h>=j){
			h = j;
			break;
		}
	}
	return h;
}
