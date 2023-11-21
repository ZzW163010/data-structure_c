#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int BTDataType;

typedef struct BtrieNode {
	struct BtrieNode* left;
	struct BtrieNode* right;
	BTDataType data;
}BT;

typedef BT* QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);


void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;

	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->tail->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		++size;
		cur = cur->next;
	}

	return size;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}


//void TrieSize(BT* root, int *psize) {
//
//
//	if (root == NULL) {
//		return;
//	} 
//
//	(*psize)++;
//
//	TrieSize(root->left, psize);
//	TrieSize(root->right, psize);
//	
//}
int TrieSize(BT* root) {
	return root == NULL ? 0 : TrieSize(root->left) + TrieSize(root->right) + 1;
}
//void TrieLeefSize(BT* root, int * psize) {
//	if (root == NULL) {
//		return;
//	}
//	else if (root->left == NULL && root->right == NULL) {
//		(*psize)++;
//	}
//	TrieLeefSize(root->left, psize);
//	TrieLeefSize(root->right, psize);
//}
int TrieLeefSize(BT* root) {
	if (root == NULL)
		return 0;

	else if (root->left == 0 && root->right == 0) 
		return 1;

	return TrieLeefSize(root->left) + TrieLeefSize(root->right); 
}
void LeavOrder(BT* root) {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);
	QueuePush(&q, root->left);
	QueuePush(&q, root->right);
	printf("%d ", root->data);
	QueuePop(&q);

	while (QueueEmpty(&q) == false) {
		BT* ret = QueueFront(&q);
		if(ret -> left != NULL)
			QueuePush(&q, ret->left);
		if(ret->right != NULL)
			QueuePush(&q, ret->right);
		
		printf("%d ", ret->data);
		QueuePop(&q);
	}
	QueueDestory(&q);
}
void PrevOrder(BT* root) {

	if (root == NULL) {
		return;
	}
	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(BT* root) {
	if (root == NULL) {
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}
void PostOrder(BT* root) {
	if (root == NULL) {
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}
int main()
{
	BT* A = (BT*)malloc(sizeof(BT));
	assert(A);
	A->data = 1;
	A->left = NULL;
	A->right = NULL;
	
	BT* B = (BT*)malloc(sizeof(BT));
	assert(B);
	B->data = 2;
	B->left = NULL;
	B->right = NULL;
	
	BT* C = (BT*)malloc(sizeof(BT));
	assert(C);
	C->data = 3;
	C->left = NULL;
	C->right = NULL;

	BT* D = (BT*)malloc(sizeof(BT));
	assert(D);
	D->data = 4;
	D->left = NULL;
	D->right = NULL;

	BT* E = (BT*)malloc(sizeof(BT));
	assert(E);
	E->data = 5;
	E->left = NULL;
	E->right = NULL;

	BT* F = (BT*)malloc(sizeof(BT));
	assert(F);
	F->data = 6;
	F->left = NULL;
	F->right = NULL;

	A->left = B;
	B->left = C;
	B->right = D;
	A->right = E;
	C->right = F;

	/*PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	
	int ret1 = TrieSize(B);
	printf("\n%d", ret1);
	int ret2 = TrieLeefSize(A);
	printf("\n%d", ret2);*/
	LeavOrder(A);
}