#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#define NAME_LEN 24

typedef struct studentNode {
    int id;
    char first[NAME_LEN];
    char last[NAME_LEN];
    struct studentNode *next;
} StudentNode;

StudentNode *createNode(int id, const char *first, const char *last);
int insertFront(StudentNode **head, int id, const char *first, const char *last);
void printList(const StudentNode *head);
int deleteValue(StudentNode **head, int id);
void clearList(StudentNode **head);

#endif
