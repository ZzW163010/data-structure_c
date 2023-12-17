//具体题目要求见《数据结构》陈越,图(1)章节

//接下来用分别用dfs和bfs完成题目

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


//dfs



//创建图
#define RangeNumMax 50
#define lake 1
#define cro 0
typedef struct GNode{
  int Graph[11][11];
}G;

G* BulidGraph(int range){
    G* graph = (G*)malloc(sizeof(G));
    for(int i = 0; i < range; i++){
        for(int j = 0; j < range; j++){
            graph->Graph[i][j] = 1;
        }
    }
    graph->Graph[0][6] = 0;
    graph->Graph[1][6] = 0;
    graph->Graph[1][7] = 0;
    graph->Graph[2][7] = 0;
    graph->Graph[3][6] = 0;
    graph->Graph[3][7] = 0;
    graph->Graph[4][6] = 0;
    graph->Graph[5][5] = 0;
    graph->Graph[5][6] = 0;
    graph->Graph[6][5] = 0;
    graph->Graph[7][5] = 0;
    graph->Graph[8][6] = 0;
    graph->Graph[9][6] = 0;
    
    for(int i = 0; i < range; i++){
        for(int j = 0; j < range; j++){
            printf("%d", graph->Graph[i][j]);
        }
        printf("\n");
    }
    return graph;
}
//找路

//构建坐标

typedef struct Pos{
  int x;
  int y;
}Pos;

//判断是否可以走
bool IsPath(G* graph, Pos* p, int range){
    if(p->x < 0 || p->x >= range || p->x < 0 || p->x >= range ||
    graph->Graph[p->x][p->y] == 0){
        return true;
    }else{
        return false;
    }
}
//使用深度优先算法，找出口
bool dsf(G* g, Pos* p, int range){
    if(p->x < 0 || p->x >= range ||
    p->x < 0 || p->x >= range){
        return true;
    }
    
    g->Graph[p->x][p->y] = 1;

    //上
    Pos* next = p;
    next->x = p->x - 1;
    if(IsPath(g, next, range)){
        if(dsf(g, next, range)){
            return true;
        }
    }
    //下
    next = p;
    next->x = p->x + 1;
    if(IsPath(g, next, range)){
        if(dsf(g, next, range)){
            return true;
        }
    }
    //左
    next = p;
    next->y = p->y - 1;
    if(IsPath(g, next, range)){
        if(dsf(g, next, range)){
            return true;
        }
    }
    //右
    next = p;
    next->y = p->y + 1;
    if(IsPath(g, next, range)){
        if(dsf(g, next, range)){
            return true;
        }
    }
    // //左上
    // next = p;
    // next->x = p->x - 1;
    // next->y = p->y - 1;
    // if(IsPath(g, next, range)){
    //     if(dsf(g, next, range)){
    //         return true;
    //     }
    // }
    // //左下
    // next = p;
    // next->x = p->x + 1;
    // next->y = p->y - 1;
    // if(IsPath(g, next, range)){
    //     if(dsf(g, next, range)){
    //         return true;
    //     }
    // }
    // //右上
    // next = p;
    // next->x = p->x - 1;
    // next->y = p->y + 1;
    // if(IsPath(g, next, range)){
    //     if(dsf(g, next, range)){
    //         return true;
    //     }
    // }
    // //右下
    // next = p;
    // next->x = p->x + 1;
    // next->y = p->y + 1;
    // if(IsPath(g, next, range)){
    //     if(dsf(g, next, range)){
    //         return true;
    //     }
    // }
    
    return false;
}
int main(){
    G* graph = BulidGraph(11);
    Pos V = {5, 5};
    
    bool ret = dsf(graph, &V, 11);
    
    if(ret){
        printf("得救了");
    }else{
        printf("完了出不去了");
    }
}

//bfs



#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef struct Pos {
    int x;
    int y;
}Pos;

typedef Pos QDataType;

typedef struct QueueNode {
    struct QueueNode* next;
    QDataType data;
}QNode;
typedef struct Queue {
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


void QueueInit(Queue* pq) {
    assert(pq);
    pq->head = pq->tail = NULL;
}
void QueueDestory(Queue* pq) {
    assert(pq);

    QNode* cur = pq->head;
    while (cur) {
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
void QueuePop(Queue* pq) {
    assert(pq);
    assert(pq->head);
    if (pq->head->next == NULL) {
        free(pq->head);
        pq->head = pq->tail = NULL;
    }
    else {
        QNode* next = pq->head->next;
        free(pq->head);
        pq->head = next;
    }
}
QDataType QueueFront(Queue* pq) {
    assert(pq);
    assert(pq->head);

    return pq->head->data;
}
QDataType QueueBack(Queue* pq) {
    assert(pq);
    assert(pq->head);

    return pq->tail->data;
}
int QueueSize(Queue* pq) {
    assert(pq);
    int size = 0;
    QNode* cur = pq->head;
    while (cur) {
        ++size;
        cur = cur->next;
    }

    return size;
}
bool QueueEmpty(Queue* pq) {
    assert(pq);
    return pq->head == NULL;
}

//queue
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

//创建图
#define RangeNumMax 50
#define lake 1
#define cro 0
typedef struct GNode {
    int Graph[11][11];
}G;

Queue q;

G* BulidGraph(int range) {
    G* graph = (G*)malloc(sizeof(G));
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < range; j++) {
            graph->Graph[i][j] = 1;
        }
    }
    //graph->Graph[0][6] = 0;
    graph->Graph[1][6] = 0;
    graph->Graph[1][7] = 0;
    graph->Graph[2][7] = 0;
    graph->Graph[3][6] = 0;
    graph->Graph[3][7] = 0;
    graph->Graph[4][6] = 0;
    graph->Graph[5][5] = 0;
    graph->Graph[5][6] = 0;
    graph->Graph[6][5] = 0;
    graph->Graph[7][5] = 0;
    graph->Graph[8][6] = 0;
    graph->Graph[9][6] = 0;

    for (int i = 0; i < range; i++) {
        for (int j = 0; j < range; j++) {
            printf("%d", graph->Graph[i][j]);
        }
        printf("\n");
    }
    return graph;
}

bool bfs(G* g, Pos p, int range, Pos v) {

    if (p.x - 1 < 0 || p.x + 1 >= range || p.y - 1 < 0 || p.y + 1 >= range) {
        return true;
    }

    Pos next = p;
    g->Graph[p.x][p.y] = 1;

    //上
    next.x = next.x - 1;
    if (g->Graph[next.x][next.y] == 0) {
        QueuePush(&q, next);
        g->Graph[next.x][next.y] = 1;
    }
    //下
    next = p;
    next.x = next.x + 1;
    if (g->Graph[next.x][next.y] == 0) {
        QueuePush(&q, next);
        g->Graph[next.x][next.y] = 1;
    }
    //左
    next = p;
    next.y = next.y - 1;
    if (g->Graph[next.x][next.y] == 0) {
        QueuePush(&q, next);
        g->Graph[next.x][next.y] = 1;
    }
    //右
    next = p;
    next.y = next.y + 1;
    if (g->Graph[next.x][next.y] == 0) {
        QueuePush(&q, next);
        g->Graph[next.x][next.y] = 1;
    }
    //左上
    next = p;
    next.x = next.x - 1;
    next.y = next.x - 1;
    if (g->Graph[next.x][next.y] == 0) {
        QueuePush(&q, next);
        g->Graph[next.x][next.y] = 1;
    }
    //左下
    next = p;
    next.x = next.x + 1;
    next.y = next.y - 1;
    if (g->Graph[next.x][next.y] == 0) {
        QueuePush(&q, next);
        g->Graph[next.x][next.y] = 1;
    }
    //右上
    next = p;
    next.x = next.x - 1;
    next.y = next.y + 1;
    if (g->Graph[next.x][next.y] == 0) {
        QueuePush(&q, next);
        g->Graph[next.x][next.y] = 1;
    }
    //右下
    next = p;
    next.x = next.x + 1;
    next.y = next.y + 1;
    if (g->Graph[next.x][next.y] == 0) {
        QueuePush(&q, next);
        g->Graph[next.x][next.y] = 1;
    }

    //当遍历到最后一个坐标时，仍未找到出口，此时队列已经空了
    //故要加一个判空
    if (QueueEmpty(&q)) {
        return false;
    }

    Pos ret = QueueFront(&q);
    QueuePop(&q);

    //当找到出口时，返回true，要注意递归返回最终的情况

    if (bfs(g, ret, range, v) == true) {
        return true;
    }

    return false;
}
int main() {
    G* graph = BulidGraph(11);
    Pos v = { 5, 5 };
    QueueInit(&q);

    bool ret = bfs(graph, v, 11, v);

    if (ret) {
        printf("得救了");
    }
    else {
        printf("完蛋了");
    }
}

