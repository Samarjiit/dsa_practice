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
class Solution {
public:
    ListNode* mergeTwoSortedll(ListNode* l1 ,ListNode* l2){

        if(!l1)return l2;
        if(!l2)return l1;

        if(l1->val<l2->val){
            l1->next=mergeTwoSortedll(l1->next,l2);
            return l1;
        }else{
            l2->next=mergeTwoSortedll(l1,l2->next);
            return l2;
        }
        return NULL;
    }

    ListNode*partitionandmerge(int start,int end,vector<ListNode*>&lists){
        if(start>end)return NULL;
        if(start==end)return lists[start];

        int mid=start+(end-start)/2;
        ListNode* l1=partitionandmerge(start,mid,lists);
        ListNode* l2=partitionandmerge(mid+1,end,lists);
        return mergeTwoSortedll(l1,l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
       int k=lists.size();
       if(k==0) return NULL;

       return partitionandmerge(0,k-1,lists);
    }
};