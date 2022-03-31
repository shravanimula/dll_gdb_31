#include <stdio.h>
#include <stdlib.h>
struct stu
{
	int data;
	struct stu *link; 
};
void cll_add(struct stu **);
void sll_add(struct stu **);
void list_cll_or_not(struct  stu**,struct stu **);
void Display(struct stu **,struct stu **);
int main()
{
	struct stu *head=NULL;
	struct stu *head1=NULL;
	int choice,n,len;
	while(1)
	{
		printf("1.circularlist 2.slllist  3.check_cll_ornot 4.Display 5.exit\n");
		printf("enter ur choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: cll_add(&head);
				break;
			case 2: sll_add(&head1);
				break;
			case 3:list_cll_or_not(&head,&head1);
			       break;
			case 4: Display(&head,&head1);
				break;
			case 5:exit(0);
		}
	}
}
void cll_add(struct stu **head)
{
	struct stu *new,*temp=NULL;
	int i,len;
	printf("Enter the length of the linked list: \n");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		new=malloc(sizeof(struct stu *));
		printf("Enter elements in a list: ");
	 	scanf("%d",&new->data);
		new->link=NULL;
		if((*head)==NULL)
		{
			(*head)=temp=new;
		}
		else
		{
			temp->link=new;
			temp=new;
		}
		temp->link=(*head);
	}
}
void sll_add(struct stu **head1)
{
	struct stu *new,*temp=NULL;
	int i,len;
	printf("enter the length of list\n");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		new=malloc(sizeof(struct stu *));
		printf("Enter elements in a list: ");
		scanf("%d",&new->data);
		new->link=NULL;
		if((*head1)==NULL)
		{
			(*head1)=temp=new;
		}
		else
		{
			temp->link=new;
			temp=new;
		}
 	}  
}
void list_cll_or_not(struct stu **head,struct stu **head1)
{
	if((*head)==NULL)
	{
		printf("Circular list is empty\n");
        }
	else
	{
       		struct stu *temp_node=(*head);
      		while(temp_node->link!=(*head))
       		{
	   		printf("%d\t",temp_node->data);
	                temp_node=temp_node->link;
	         }
		printf("%d\n",temp_node->data);
		if((temp_node)->link==(*head))
		{
			printf("List is a Circular single list\n");
	      	}
		else
    		{
			printf("List is not a Circular single list\n");
		}
	}
	if((*head1)==NULL)
	{
		printf("SLL list is empty\n");
	}
	else
	{
		struct stu *temp_node1=(*head1);
		while((temp_node1->link)!=NULL)
		{
			printf("%d\t",temp_node1->data);
			temp_node1=temp_node1->link;
		}
		printf("%d\n",temp_node1->data);
    		if((temp_node1)->link==(*head1))
		{
			printf("List is a Circular single list\n");
		}
		else
		{
			printf("List is not a Circular single list\n");
		}
	}
}
void Display(struct stu **head,struct stu **head1)
{
	struct stu *ptr=NULL,*ptr1=NULL;
 	ptr=(*head);
	ptr1=(*head1);
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while((ptr->link)!=(*head))
		{
 			printf("%d\t",ptr->data);
                         ptr=ptr->link;
 		}
		printf("%d\n",ptr->data);
	}
	if(ptr1==NULL)
	{
		printf("Sll is List is empty\n");
	}
	else      	    	    		    
	{
		while((ptr1->link)!=NULL)
		{
			printf("%d\t",ptr1->data);
			ptr1=ptr1->link; 
		}
		printf("%d\n",ptr1->data);
	}
}
