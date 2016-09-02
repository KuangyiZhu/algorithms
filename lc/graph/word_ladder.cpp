#include<string>
#include<unordered_set>
#include<queue>

int ladderLength(std::string beginWord, std::string endWord, std::unordered_set<std::string>& wordList) {
	std::queue<std::pair<std::string, int>> q;
	q.push(std::make_pair(beginWord, 1));
	wordList.insert(endWord);
	int len=0;
	while(!q.empty()){
		std::pair<std::string, int> p=q.front();
		q.pop();
		for(int i=0; i<p.first.size(); i++){
			char c=p.first[i];
			for(int j=0; j<26; j++){
				p.first.replace(i, 1, 1, char('a'+j));
				if(wordList.count(p.first)){
					if(p.first==endWord){
						return p.second+1;
					}
					q.push(std::make_pair(p.first, p.second+1));
					wordList.erase(p.first);
				}
			}
			p.first.replace(i, 1, 1, c);
		}
	}
	return len;
}
