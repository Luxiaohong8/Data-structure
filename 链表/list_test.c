#include <stdio.h>
#include <stdlib.h>
typedef int Datatype;
typedef struct Node
{
    Datatype data;
    struct Node *next;
}Node,*first;

Node *initlist();
void add(Node *list, Datatype data);
void printList(Node *list);
void insert(Node *list,Datatype data, int position);
void removeAt(Node *list,int position);
void destroy(Node *list);
void listDestroy(Node *head);

int main(int argc, char const *argv[])
{
    Node *list=initlist();
    add(list,1);
    add(list,2);
    insert(list,3,2);
    printList(list);
    removeAt(list,2);
    printList(list);printf("%d",list==NULL);
    destroy(list);
    printf("%d",list==NULL);
    //listDestroy(list);
    //printList(list);
    return 0;
}

Node *initlist(){
    Node *first=(Node *)malloc(sizeof(Node));
    first->next=NULL;
    return first;
}

void add(Node *list, Datatype data){
    Node *pointer=list;
    Node *node=(Node *)malloc(sizeof(Node));
    node->data=data;
    
    while(pointer->next!=NULL){
        pointer=pointer->next;
    }

    pointer->next=node;
    node->next=NULL;
}

void printList(Node *list){
    if(list==NULL){
        printf("Empty list!");
        return;
    }

    Node *pointer=list->next;
    
    while(pointer!=NULL){
        printf("%d  ",pointer->data);
        pointer=pointer->next;
    }
    printf("\n");
}

void insert(Node *list,Datatype data, int position){
    Node *pointer=list;
    int i=0;
    while(i<position && pointer!=NULL){
        pointer=pointer->next;
        ++i;
    }

    if(position<0||pointer==NULL){
        return;
    }

    Node *node=(Node *)malloc(sizeof(Node));
    node->data=data;
    node->next=pointer->next;
    pointer->next=node;
}

void removeAt(Node *list,int position){
    Node *pointer=list;
    int i=1;
    while(i<position && pointer!=NULL){
        pointer=pointer->next;
        ++i;
    }

    if(position<1||pointer==NULL||pointer->next==NULL)
        return;

    Node *node=pointer->next;
    pointer->next=node->next;
    free(node);
}

//销毁列表
void destroy(Node *list){
    Node *p=list;    
    while(list!=NULL){
        p=list;
        list=list->next;
        free(p);  
        printf("______\n");   
    }
    printf("%d",list==NULL);
}
