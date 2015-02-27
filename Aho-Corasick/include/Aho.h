/*
	@author : pangbolike
	email : 335108411@qq.com

	The AHO algorithm and a more effort method
	A new method for memory malloc

	To be continued...
*/
#IFNDEF _AHO_H_
#DEFINE _AHO_H_

#include <cstring>

#DEFINE NODE_NUM 16

namespace AHO
{

	//struct for key-tree node
	struct TrieNode{
		int cnt;
		TrieNode *next[NODE_NUM];
		TrieNode(){
			cnt = 0;
			memset(next,NULL,sizeof(next));
		}
	};

	//class for AHO
	class Aho
	{
	private:
		TrieNode *root;
		int MAX_AHO_NODE_NUM;
		int pos;
		TrieNode *TrieTree;


	};

};


#ENDIF