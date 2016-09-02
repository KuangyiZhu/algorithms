#include<vector>
#include<queue>
#include<string.h>

bool canFinish(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
	std::vector<int> adj_list[numCourses];
	int indegree[numCourses];
	memset(indegree, 0, sizeof(indegree));
	for(int i=0; i<prerequisites.size(); i++){
		adj_list[prerequisites[i].second].push_back(prerequisites[i].first);
		indegree[prerequisites[i].first]++;
	}
	std::queue<int> no_incoming;
	for(int i=0; i<numCourses; i++){
		if(indegree[i]==0)
			no_incoming.push(i);
	}
	int count=0;
	while(!no_incoming.empty()){
		int v=no_incoming.front();
		no_incoming.pop();
		for(int i=0; i<adj_list[v].size(); i++){
			count++;
			if(--indegree[adj_list[v][i]]==0)
				no_incoming.push(adj_list[v][i]);
		}
	}
	if(count!=prerequisites.size())
		return false;
	return true;
}
