/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
typedef pair<int,ListNode*> pil;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pil  , vector<pil> , greater<pil>> pq;
        ListNode* ans = new ListNode(-1);
        ListNode* itrans = ans;
        for(int i =0 ; i < lists.size();i++){
            if(lists[i]!=NULL){
            pq.push({lists[i]->val , lists[i]});
            }
        }
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            itrans->next = top.second;
            itrans = itrans->next;
            if(top.second->next!=NULL){
                pq.push({top.second->next->val , top.second->next});
            }
        }
        return ans->next;
    }
};
