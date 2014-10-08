/*
Problem: Clone Graph
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
         
====================================================================================

Author: Yunping, qufang83@gmail.com
Date: 10/08/2014
Difficulty: **^
Review: ***
Solution: (My Own)
    1. Using a map from old node to new node.
    2. DFS copy.

*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> map;
        return cloneGraph_dfs(node, map);
    }

private:
    UndirectedGraphNode* cloneGraph_dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& map) {
        if (!node) return 0;
        
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        map[node] = newNode;
        
        for (auto nb:node->neighbors) {
            auto it = map.find(nb);
            if (it != map.end()) {
                newNode->neighbors.push_back((*it).second);
            } else {
                UndirectedGraphNode *new_nb = cloneGraph_dfs(nb, map);
                newNode->neighbors.push_back(new_nb);
            }
        }
        
        return newNode;
    }
};