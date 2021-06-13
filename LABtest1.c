#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

struct details
{
    char name[N];
    int empid;
    char vac[N];
    struct details *next;
};

struct details *head;

void insertfront(char n[N], int id, char v[N])  
{  
    struct details *ptr; 
    ptr = (struct details *) malloc(sizeof(struct details *));  
    if(ptr == NULL)  
    {  
        printf("\nOverflow");  
    }   
    else  
    {  
        strcpy(ptr->name, n);
        ptr->empid = id;
        strcpy(ptr->vac, v);
        ptr->next = head;  
        head = ptr;  
        printf("\nDetails added");  
    }  
      
}  

void delete()  
{  
    struct details *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("\nUnderflow\n");  
    }  
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly entry of the list deleted\n");  
    }  
          
    else  
    {  
        ptr = head;   
        while(ptr->next != NULL)  
        {  
            ptr1 = ptr;  
            ptr = ptr ->next;  
        }  
        ptr1->next = NULL;  
        free(ptr);  
        printf("\nentry deleted\n");  
    }     
}  

void display()  
{  
    struct details *ptr;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("List empty");  
    }  
    else  
    {  
        printf("\nList:\n");   
        while (ptr!=NULL)  
        {  
            printf("\n%s",ptr->name);
            printf("\n%d",ptr->empid);
            printf("\n%s\n",ptr->vac);  
            ptr = ptr -> next;  
        }  
    }  
} 

/** void Lists(struct Queue *q, struct Queue *q1, struct Queue *q2)
{
    struct Qnode *temp;
    temp = q;
    while(temp->next!=NULL)
    {
        if (temp->vac =='Y')
        {
            enQueue(q1, temp->name, temp->empid, temp->vac);
        }
        if (Qnode->vac == 'N')
        {
            enQueue(q2, Qnode->name, temp->Qnode->empid, Qnode->vac);
        }
        temp=temp->next;
    }
} **/


int main()
{
    
    int option;

    while (1)
    {
        printf("\n\n1) Enter informantion\n");
        printf("2) Deleting latest details\n");
        printf("3) Create other lists, display and Exit\n\n");
        printf("Your option : ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
            {
                char name1[N];
                int id1;
                char vac1[N];
                printf("Name: ");
                scanf("%s", &name1);
                printf("Employee Id: ");
                scanf("%d", &id1);
                printf("Vacciniation Status: ");
                scanf("%s", &vac1);
                insertfront(name1, id1, vac1);
                break;
            }

            case 2:
            {
                delete();
                break;
            }
    
            case 3:
            {
                display();
                exit(0);
            }
        }
    }
    return 0;
}