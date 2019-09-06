#include <stdio.h>
#include <stdlib.h>
 
/* a node of the doubly linked list */
struct node
{
  int data;
  struct node *next;
  struct node *prev;    
};


 struct node* newNode(struct node* head,int data){
	 struct node *p,*temp= (struct node*)malloc(sizeof(struct node));
	 temp->data=data;
	 temp->next=NULL;
	 temp->prev=NULL;
	 if(head ==NULL)
	 return temp;
	 p=head;
	 while(p->next!=NULL){
	 p=p->next;}
	 p->next=temp;
	 temp->prev=p;
	 return head; 
	 }
void reverse(struct node **head_ref);

void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
  printf(" ");
} 

 int main()
{
  int t,x,n,i;

  printf("enter the number of test case\n\n");

  scanf("%d",&t);

  while(t--)
  {
  /* Start with the empty list */
  struct node *temp,*head = NULL;

  printf("ENTER THE ELEMENTS IN THE LINKED LIST\n\n");

  scanf("%d",&n);

    printf("ENTER THE DATA OF THE LINKED LIST\n\n");

  for(i=0;i<n;i++){
  scanf("%d",&x);
  head=newNode(head, x);
  }
  reverse(&head);  

  printList(head);
  while(head->next!=NULL)
  {
	  temp=head;
	  head=head->next;
	  free(temp);
	  }       
	}
	return 0;
}


void reverse(struct node **head_ref)
{
   // Your code goes here
   
   struct node *temp, *swap, *prev;
   
   temp = *head_ref;
   
   while(temp!=NULL){

       prev = temp;
       temp = temp->next;

        swap = prev->prev;
        prev->prev= prev->next;
        prev->next = swap; 
   }
   
   *head_ref = prev;
   
}