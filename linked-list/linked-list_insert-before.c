#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_ll()
{
    struct node *start = NULL;
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while(num != -1)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
                
        new_node->data = num;
        if(start == NULL)
        {            
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = NULL;
        }
                
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr != NULL)
    {        
        printf("\t %d", ptr->data);
                
        ptr = ptr->next;
    }
    return start;
}

struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->data != val)
    {
        preptr = ptr;
            
    ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}

int main(int argc, char *argv[]) {
    struct node *my_linked_list = create_ll();
    display(my_linked_list);
    my_linked_list = insert_before(my_linked_list);
    display(my_linked_list);
    return 0;
}