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

struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = start;
    while(ptr->next != NULL)
    ptr = ptr->next;
    ptr->next = new_node;
    return start;
}

int main(int argc, char *argv[]) {
    struct node *my_linked_list = create_ll();
    display(my_linked_list);
    my_linked_list = insert_end(my_linked_list);
    display(my_linked_list);
    return 0;
}