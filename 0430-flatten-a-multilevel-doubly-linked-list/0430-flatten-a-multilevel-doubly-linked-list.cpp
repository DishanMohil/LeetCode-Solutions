/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;
        Node* nex;
        while(curr!=NULL){
            if(curr->child!=NULL){
                nex = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;
                while(curr->next!=NULL){
                curr = curr->next;
                }
                if(nex!=NULL){
                curr->next = nex;
                nex->prev = curr;
                }

            }
            
           curr = curr->next; 
        }
        return head;
    }
};