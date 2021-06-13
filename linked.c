#include<stdio.h>  
#include<stdlib.h>  

struct node   
{  
    int data;  
    struct node *next;   
};  

struct node *head;
 
void insertfront()  
{  
    struct node *ptr;  
    int a;  
    ptr = (struct node *) malloc(sizeof(struct node *));  
    if(ptr == NULL)  
    {  
        printf("\nOverflow");  
    }   
    else  
    {  
        printf("\nEnter value:\n");    
        scanf("%d", &a);    
        ptr->data = a;  
        ptr->next = head;  
        head = ptr;  
        printf("\nNode inserted");  
    }  
      
}  

void insertend()  
{  
    struct node *ptr,*temp;  
    int a;     
    ptr = (struct node*)malloc(sizeof(struct node));      
    if(ptr == NULL)  
    {  
        printf("\nOverflow");     
    }  
    else  
    {  
        printf("\nEnter value:\n");  
        scanf("%d",&a);  
        ptr->data = a;  
        if(head == NULL)  
        {  
            ptr -> next = NULL;  
            head = ptr;  
            printf("\nNode inserted");  
        }  
        else  
        {  
            temp = head;  
            while (temp -> next != NULL)  
            {  
                temp = temp -> next;  
            }  
            temp->next = ptr;  
            ptr->next = NULL;  
            printf("\nNode inserted");  
          
        }  
    }  
}  

void insertmid()  
{  
    int i, loc, a;   
    struct node *ptr, *temp;  
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOverflow");  
    }  
    else  
    {  
        printf("\nEnter element value:");  
        scanf("%d",&a);  
        ptr->data = a;  
        printf("\nEnter the location after which you want to insert:");  
        scanf("\n%d", &loc);  
        temp=head;  
        for(i=0;i<loc;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
          
        }  
        ptr ->next = temp ->next;   
        temp ->next = ptr;   
        printf("\nNode inserted");  
    }  
}  

void deletefront()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\nUnderflow\n");  
    }  
    else   
    {  
        ptr = head;  
        head = ptr->next;  
        free(ptr);  
        printf("\nNode deleted from the begining\n");  
    }  
}  
void deleteend()  
{  
    struct node *ptr,*ptr1;  
    if(head == NULL)  
    {  
        printf("\nUnderflow\n");  
    }  
    else if(head -> next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("\nOnly node of the list deleted\n");  
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
        printf("\nNode deleted from end\n");  
    }     
}  

void deletemid()  
{  
    struct node *ptr,*ptr1;  
    int loc,i;    
    printf("\n Enter the location of the node after which you want to perform deletion:\n");  
    scanf("%d", &loc);  
    ptr=head;  
    for(i=0;i<loc;i++)  
    {  
        ptr1 = ptr;       
        ptr = ptr->next;  
              
        if(ptr == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    ptr1 ->next = ptr ->next;  
    free(ptr);  
    printf("\nDeleted node is: %d ",loc+1);  
} 
  
void display()  
{  
    struct node *ptr;  
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
            printf("\n%d",ptr->data);  
            ptr = ptr -> next;  
        }  
    }  
} 

void main()
{
    insertfront();    
    insertfront();
    insertfront();
    insertmid();
    insertend();
    insertend();
    insertmid();
    display();
    deletefront();
    deleteend();
    display();
    deletemid();
    display();
}