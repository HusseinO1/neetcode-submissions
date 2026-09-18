class Solution {
private:
    unordered_map<Node*, Node*> clonedNodes;

public:
    Node* cloneGraph(Node* node) {
        // Base case: empty graph
        if (!node) {
            return nullptr;
        }

        // If the node is already cloned, return the clone to prevent cycles
        if (clonedNodes.contains(node)) {
            return clonedNodes[node];
        }

        Node* copy = new Node(node->val);

        clonedNodes[node] = copy;

        // Recursively clone all neighbors and add them to the copy's list
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }

        return copy;
    }
};