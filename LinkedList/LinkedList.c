#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

// Add node
int addNode(int data)
{
    if (head == NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        head = tail = new;
    }
    else
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        tail->next = new;
        tail = new;
    }

    return 1;
}

// Add node head
int addNodeHead(int data)
{
    if (head == NULL)
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = NULL;

        tail = head = new;
    }
    else
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        new->next = head;

        head = new;
    }

    return 1;
}

// Linked list print
int print()
{
    printf("\nLinked Lists : \n");
    struct node *index = head;

    while (index != NULL)
    {
        printf("%d - ", index->data);
        index = index->next;
    }

    return 1;
}

// Delete node
int delete (int data)
{
    struct node *prev = NULL;
    struct node *index = head;

    // Linked List is empty
    if (head == NULL)
    {
        printf("Linked list is empty");
        return 1;
    }

    // Head delete
    if (head->data == data)
    {
        struct node *tmp = head;
        head = head->next;
        free(tmp);
        return 1;
    }
    // Linked list is not empty
    while (index != NULL && index->data != data)
    {
        prev = index;
        index = index->next;
    }
    // Data is not found
    if (index == NULL)
    {
        printf("Data not found");
        return 1;
    }
    prev->next = index->next; // Linking previous index and next index

    if (tail->data == data)
    {
        tail = prev;
    }

    free(index);

    return 1;
}

int main()
{

    addNode(10);
    addNode(14);
    addNode(16);
    addNode(25);
    addNodeHead(24);
    print();

    delete (16);
    print();

    delete (25);
    print();

    delete (24);
    delete (10);
    delete (14);
    print();
    return 1;
}