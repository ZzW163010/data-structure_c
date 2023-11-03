//反转链表

struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL)
        return NULL;
    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = head->next;
    while(n2 != NULL){
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        if(n2 != NULL){
            n3 = n2->next;
        }
    }
    return n1;
}

//链表的中间结点

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* cur = head;
    int count = 0;
    while(cur){
        count++;
        cur = cur->next;
    }
    int pos = 0;
    pos = count / 2 + 1;
    cur = head;
    for(int i = 1; i < pos; i++){
        cur = cur->next;
    }
    return cur;
}

//快慢指针法

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while(fast && fast->next){      //通过控制条件结束的先后，实现双结束条件
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
