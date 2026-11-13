#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studentList.h"




StudentNode *createNode(int id, const char *first, const char *last){
    StudentNode *node = malloc(sizeof(*node));
    
    if ( node == NULL ){ return NULL; }         // assignmnet failed

    node->id = id;
    strncpy(node->first, first, sizeof( node->first - 1 ));
    strncpy(node->last, last, sizeof( node->last - 1 ));
    
    node->first[ sizeof( node->first - 1 ) ] = '\0';
    node->last[ sizeof( node->last - 1 ) ] = '\0';

    node->next = NULL;

    return node;
}



int insertFront(StudentNode **head, int id, const char *first, const char *last){
    StudentNode *temp = createNode( id, first, last );
    if ( temp == NULL ){ return 1; }
    temp->next = *head;
    *head = temp; 

    return 0;
}



void printList(const StudentNode *head){
    if( head != NULL ){
        printf("id:\t\t%d\nfirst:\t%s\nlast:\t%s\n", head->id, head->first, head->last);
        printList(head->next);
    }
}



int deleteValue(StudentNode **head, int id){
    if ( (*head)->next->id != id ){
        deleteValue( &(*head)->next, id );
    }
    else{
        (*head)->next = (*head)->next->next;
    }
}


void clearList(StudentNode **head){}
