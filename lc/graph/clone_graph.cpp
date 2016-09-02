#include<cstdlib>
#include<vector>
#include<map>

struct UndirectedGraphNode {
	int label;
	std::vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode* dfs(UndirectedGraphNode *node, std::map<UndirectedGraphNode*, UndirectedGraphNode*>& nmap){
	if(nmap.count(node))
		return nmap[node];
	UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
	nmap[node]=new_node;
	for(int i=0; i<node->neighbors.size(); i++){
		new_node->neighbors.push_back(dfs(node->neighbors[i], nmap));
	}
	return new_node;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if(node==NULL)
		return NULL;
	std::map<UndirectedGraphNode*, UndirectedGraphNode*> nmap;
	return dfs(node, nmap);
}
