#include<vector>
#include<string.h>

std::vector<int> findOrder(int numCourses, std::vector<std::pair<int, int>>& prerequisites) {
	std::vector<int> adj_list[numCourses];
	int indegree[numCourses];
	memset(indegree, 0, sizeof(indegree));
	for(int i=0; i<prerequisites.size(); i++){
		adj_list[prerequisites[i].second].push_back(prerequisites[i].first);
		indegree[prerequisites[i].first]++;
	}
	std::vector<int> order;
	for(int i=0; i<numCourses; i++){
		if(indegree[i]==0)
			order.push_back(i);
	}
	for(int i=0; i<order.size(); i++){
		for(int j=0; j<adj_list[order[i]].size(); j++){
			if(--indegree[adj_list[order[i]][j]]==0)
				order.push_back(adj_list[order[i]][j]);
		}
	}
	if(order.size()==numCourses)
		return order;
	else
		return std::vector<int>();
}
