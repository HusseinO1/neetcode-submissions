class Solution {
public:
    unordered_map<Node*, Node*> nodes;
    
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        if(nodes.contains(head)) return nodes[head];

        Node* copy = new Node(head->val);

        nodes[head] = copy;

        copy->next = copyRandomList(head->next);
        copy->random = copyRandomList(head->random);

        return copy;
    }
};