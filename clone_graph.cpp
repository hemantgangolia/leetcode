/*
https://oj.leetcode.com/problems/clone-graph/

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
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
        if (!node) return node;
        
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> my_map;
        UndirectedGraphNode* graphCopy = new UndirectedGraphNode(node->label);
        my_map[node] = graphCopy;
        
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while (!q.empty()) {
            UndirectedGraphNode* t = q.front();
            q.pop();
            
            for (int i = 0; i < t->neighbors.size(); i++) {
                UndirectedGraphNode* n = t->neighbors[i];
                if (my_map.find(n) == my_map.end()) {
                    UndirectedGraphNode * f = new UndirectedGraphNode (n->label);
                    my_map[t]->neighbors.push_back(f);
                    my_map[n] = f; 
                    q.push(n);
                } else {
                    my_map[t]->neighbors.push_back(my_map[n]);
                }
            }
        }
        return graphCopy;
    }
};
