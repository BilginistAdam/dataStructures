#include <stdio.h>
#include <stdlib.h>

/* Typedef */
/**
 * @brief Linked List typedef struct 
 * 
 */
typedef struct n
{
    int data;
    struct n * next;
}node;

/* Function Prototype */
void waitUserInputExit(void);
void display(node * r);
node * addData(node * r, int data);
node * deleteData(node * r, int data);
int getNumberOfData(node *r);

/* Variables */
int counter = 0;

int main(){
    
    /* Create a linked list. */
    node * root = NULL;
    printf("Create a new linked list! (root)\n");

    /* Add data on linked list. */
    root = addData(root, 400);
    root = addData(root, 40);
    root = addData(root, 4);
    root = addData(root, 500);
    root = addData(root, 50);
    root = addData(root, 5);
    root = addData(root, 4);
    root = addData(root, 3);

    /* Show all datas on linked list. */
    display(root);

    /* Get number of data on linked list*/
    counter = getNumberOfData(root);

    /* Delete data on linked list. */

    root = deleteData(root, 3);
    root = deleteData(root, 500);
    root = deleteData(root, 900);
    root = deleteData(root, 50);

    /* Show all datas on linked list. */
    display(root);

    /* Get number of data on linked list. */
    counter = getNumberOfData(root);

    waitUserInputExit();
    return EXIT_SUCCESS;
}

/**
 * @fn waitUserOnputExit();
 * 
 * @brief This func. shows exit message.
 * 
 */
void waitUserInputExit(void){
    printf("Program is waiting user input for exit! Press Enter ...");
    while(getchar() != '\n');
    getchar();
}

/**
 * @fn display(node * r);
 * 
 * @brief This func. displays data on linked list.
 * 
 * @param r 
 */
void display(node * r){
   
    printf("/*** Linked List ***/ \n/* ");
    while (r->next != NULL)
    {
         printf("%d - ", r->data);
        r = r ->next;
    }
    printf(" %d - NULL */\n", r->data);
}

/**
 * @fn addData(node * r, int data);
 * 
 * @brief This func. adds new data on linked list with sequentially from the lowest number to the biggest number.
 * 
 * @param r 
 * @param data 
 * @return node* 
 */
node * addData(node * r, int data){
    if (r == NULL)
    {   
        /* Linked list equals to NULL*/
        r = (node *)malloc(sizeof(node));
        r -> next = NULL;
        r -> data = data;
        printf("Your data (%d) added on linked list!\n", data);
        return r;
    }else if(r->data > data){
        /* If data is lower than the first data of root,adds data */
        node * temp = (node *)malloc(sizeof(node));
        temp->next = r;
        temp->data = data;
        printf("Your data (%d) added on linked list!\n", data);
        return temp;
    }
    /* If data is biggest or intermediate value on linked list, adds data. */
    node * iter = r;
    while (iter->next != NULL && iter->next->data < data)
    {
        iter = iter -> next;
    }
    node * temp = (node *)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> data = data;
    printf("Your data (%d) added on linked list!\n", data);
    return r;   
}

/**
 * @fn  deleteData(node * r, int data);
 * @brief This func. deletes data on Linked List.
 * 
 * @param r 
 * @param data 
 * @return node* 
 */
node * deleteData(node * r, int data){
    node * iter = r;
    node * temp;
    if(r->data == data){
        /* If data is first data on linked list, deletes data */
        temp = r;
        r = r->next;
        free(temp);
        printf("Your data (%d) deleted on Linked List!\n", data);
        return r;
    }
    while (iter->next != NULL && iter->next->data != data)
    {
        iter = iter->next;
    }
    if(iter->next == NULL){
        /* if data isn't able to found on linked list, return alert message*/ 
        printf("Your data (%d) isn't able to found on linked list.\n", data);
        return r;
    }
    /* Delete data on linked list */
    temp = iter -> next;
    iter -> next = iter->next->next;
    free(temp);
    printf("Your data (%d) deleted on Linked List!\n", data);
    return r;
}

/**
 * @fn  getNumberOfData(node * r);
 * @brief Get the Number Of Data on linked list.
 * 
 * @param r 
 * @return int 
 */
int getNumberOfData(node *r){
    int counter = 0;
    while (r->next != NULL)
    {
        counter++;
        r  = r->next;
    }
    counter++;
    printf("Number of data on linked list : %d\n", counter);
    return counter;
}