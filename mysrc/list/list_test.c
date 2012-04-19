
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node {
    int data;
    struct list_head list;
};

int main()
{
    int i;
    struct node* tmp;
    struct list_head* pos;
    struct node mylist;

    // init the head
    INIT_LIST_HEAD(&(mylist.list));
    printf("add list element\n");
    for(i=0;i<5;i++){
        tmp = malloc(sizeof(struct node));
        tmp->data = i;
        list_add(&(tmp->list),&(mylist.list));
    }
    printf("traversing the list using list_for_each()\n");
    list_for_each(pos,&(mylist.list)){
        tmp = list_entry(pos,struct node,list);
        printf("data=%d\n",tmp->data);
    }
    return 0;
}