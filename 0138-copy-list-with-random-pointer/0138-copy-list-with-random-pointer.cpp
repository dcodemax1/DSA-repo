/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertInBetween(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }
    }

    void connectRandom(Node* head) {
        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = temp->next;
            if (temp->random) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = NULL;
            }
            temp = temp->next->next;
        }
    }

    Node* connectNext(Node* head) {
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        Node* temp = head;

        while (temp != NULL) {
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }

    Node* copyRandomList(Node* head) {
        insertInBetween(head);
        connectRandom(head);
        return connectNext(head);
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Brute Force
/*
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;

        Node* temp = head;
        while (temp != NULL) {
            Node* copyNode = new Node(temp->val);
            mp[temp] = copyNode;
            temp = temp->next;
        }

        temp = head;
        while (temp != NULL) {
            Node* copyNode = mp[temp];
            copyNode->next = mp[temp->next];
            copyNode->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};
*/