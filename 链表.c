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

//合并两个有序链表，合并后仍然有序

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    struct ListNode* newlist = NULL;
    struct ListNode* curn = NULL;
    

    while (list1 && list2) {
        if (list1->val > list2->val) {
			if (newlist == NULL) {
				newlist = list2;
				curn = list2;
				list2 = list2->next;
			}
			else {
				curn->next = list2;
				list2 = list2->next;
				curn = curn->next;
			}
			
        }
        else {
			if (newlist == NULL) {
				newlist = list1;
				curn = list1;
				list1 = list1->next;
			}
			else {
				curn->next = list1;
				list1 = list1->next;
				curn = curn->next;
			}
        }
    }
	if (list1 != NULL) {
		curn->next = list1;
	}
	if (list2 != NULL) {
		curn->next = list2;
	}
   
    return newlist;
}

//先取比较取出一个节点

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    
    struct ListNode* newlist = NULL;
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    if (list1->val > list2->val) {
        newlist = list2;
        list2 = list2->next;
    }
    else {
        newlist = list1;
        list1 = list1->next;
    }
    struct ListNode* curn = newlist;

    while (list1 && list2) {
        if (list1->val > list2->val) {
            curn->next = list2;
            list2 = list2->next;
            curn = curn->next;
        }
        else {
            curn->next = list1;
            list1 = list1->next;
            curn = curn->next;
        }
    }
    if(list1 != NULL){
        curn->next = list1;
    }
    if(list2 != NULL){
        curn->next = list2;
    }
     
    return newlist;
}

//创建一个哨兵位的头结点

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    struct ListNode* curn;
    struct ListNode* newlist;
    newlist = curn = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    while (list1 && list2) {
        if (list1->val > list2->val) {
            curn->next = list2;
            list2 = list2->next;
            curn = curn->next;
        }
        else {
            curn->next = list1;
            list1 = list1->next;
            curn = curn->next;
        }
    }
    if(list1 != NULL){
        curn->next = list1;
    }
    if(list2 != NULL){
        curn->next = list2;
    }
    struct ListNode* first = newlist->next;
    free(newlist);

    return first;
}
