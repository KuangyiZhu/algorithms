#include<string>
#include<map>

class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		isLeaf = false;
	}
	std::map<char, TrieNode*> children;
	bool isLeaf;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(std::string word) {
		TrieNode* node = root;
		for(int i=0; i<word.length(); i++){
			if(node->children[word[i]]==NULL){
				node->children[word[i]] = new TrieNode();
			}
			node = node->children[word[i]];
		}
		node->isLeaf = true;
	}

	// Returns if the word is in the trie.
	bool search(std::string word) {
		TrieNode* node = root;
		for(int i=0; i<word.length(); i++){
			if(node->children.count(word[i])){
				node = node->children[word[i]];
			}
			else{
				return false;
			}
		}
		return node->isLeaf;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(std::string prefix) {
		TrieNode* node = root;
		for(int i=0; i<prefix.length(); i++){
			if(node->children.count(prefix[i])){
				node = node->children[prefix[i]];
			}
			else{
				return false;
			}
		}
		return true;
	}

private:
	TrieNode* root;
};
