#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;
typedef struct Stack {
    STDataType* a;
    int top;
    int capacity;
} ST;

void StackInit(ST* ps) {
    assert(ps);

    ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
    if (ps->a == NULL) {
        printf("malloc fail\n");
        exit(-1);
    }

    ps->capacity = 4;
    ps->top = 0;
}

void StackDestory(ST* ps) {
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = ps->capacity = 0;
}

// 入栈
void StackPush(ST* ps, STDataType x) {
    assert(ps);

    // 满了-》增容
    if (ps->top == ps->capacity) {
        STDataType* tmp = (STDataType*)realloc(ps->a,
                                               ps->capacity * 2 * sizeof(STDataType));
        if (tmp == NULL) {
            printf("realloc fail\n");
            exit(-1);
        } else {
            ps->a = tmp;
            ps->capacity *= 2;
        }
    }

    ps->a[ps->top] = x;
    ps->top++;
}

// 出栈
void StackPop(ST* ps) {
    assert(ps);
    // 栈空了，调用Pop，直接中止程序报错
    assert(ps->top > 0);

    //ps->a[ps->top - 1] = 0;
    ps->top--;
}

STDataType StackTop(ST* ps) {
    assert(ps);
    // 栈空了，调用Top，直接中止程序报错
    assert(ps->top > 0);

    return ps->a[ps->top - 1];
}

int StackSize(ST* ps) {
    assert(ps);

    return ps->top;
}

bool StackEmpty(ST* ps) {
    assert(ps);

    return ps->top == 0;
}
//stack
////////////////////////////////////////////////////////////////////////////////////
typedef struct Pos {
    int x;
    int y;
} Ps;

bool IsPath(int** maze, int r, int c, Ps next) {
    if (next.x >= 0 && next.x < r && next.y >= 0
            && next.y < c && maze[next.x][next.y] == 0
       ) {
        return true;
    }

    return false;
}
bool GetMazePath(int** maze, int r, int c, Ps cur, ST* path) {
    if (cur.x == r - 1 && cur.y == c - 1) {
        return true;
    }

    Ps next;
    next = cur;
    maze[cur.x][cur.y] = 2;

    //上
    next.x = cur.x - 1;
    if (IsPath(maze, r, c, next)) {
        if (GetMazePath(maze, r, c, next, path)) {
            StackPush(path, next.y);
            StackPush(path, next.x);
            return true;
        }
    }
    //下
    next = cur;
    next.x = cur.x + 1;
    if (IsPath(maze, r, c, next)) {
        if (GetMazePath(maze, r, c, next, path)) {
            StackPush(path, next.y);
            StackPush(path, next.x);
            return true;
        }
    }

    //左
    next = cur;
    next.y = cur.y - 1;
    if (IsPath(maze, r, c, next)) {
        if (GetMazePath(maze, r, c, next, path)) {
            StackPush(path, next.y);
            StackPush(path, next.x);
            return true;
        }
    }

    //右
    next = cur;
    next.y = cur.y + 1;
    if (IsPath(maze, r, c, next)) {
        if (GetMazePath(maze, r, c, next, path)) {
            StackPush(path, next.y);
            StackPush(path, next.x);
            return true;
        }
    }

    return false;
}
int main() {
    int r = 0, c = 0;
    ST path;
    StackInit(&path);

    while (~scanf("%d%d", &r, &c)) {
        int** maze = (int**)malloc(sizeof(int*) * r);

        for (int i = 0; i < r; i++) {
            maze[i] = (int*)malloc(sizeof(int) * c);
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%d", &maze[i][j]);
            }
        }

        Ps entry;
        entry.x = 0;
        entry.y = 0;

        GetMazePath(maze, r, c, entry, &path);

        printf("(%d,%d)\n", 0, 0);
        while (!StackEmpty(&path)) {
            printf("(%d,", StackTop(&path));
            StackPop(&path);
            printf("%d)\n", StackTop(&path));
            StackPop(&path);
        }
        for (int i = 0; i < r; i++) {
            free(maze[i]);
        }
        free(maze);
        maze = NULL;

    }
    return 0;
}
