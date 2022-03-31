#include <stdio.h>
#include <stdlib.h>
struct stu
{
	int data;
	struct stu *link; 
};
struct stu *head=NULL;
struct stu *head1=NULL;
void create_cll();
void Display();
void list_cll_or_not();
void sllcreate();
int main()
{
	int choice,n;
	while(1)
	{
		printf("1.Create circularlinked list  2.Display  3.list_cll_or_not 4.sll create 5 .exit\n");
		printf("enter ur choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: create_cll();
				break;
			case 2: Display();
				break;
			case 3:list_cll_or_not();
			       break;
			case 4:sllcreate();
			       break;
			case 5:exit(0);
		}
	}
}
void create_cll()
{
	struct stu *new,*temp=NULL;
	int i,len;
	printf("Enter the length of the linked list: \n");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		new=malloc(sizeof(struct stu));
		printf("Enter elements in a list: ");
		scanf("%d",&new->data);
		new->link=NULL;
		if(head==NULL)
		{
			head=temp=new;
		}
		else
		{
			temp->link=new;
			temp=new;
		}
		temp->link=head;
	}  			        
}
void sllcreate()
{
	struct stu *new,*temp=NULL;
	int i,len;
	printf("Enter the length of the linked list: \n");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		new=malloc(sizeof(struct stu));
		printf("Enter elements in a list: ");
		scanf("%d",&new->data);
		new->link=NULL;
		if(head1==NULL)
		{
			head1=temp=new;
		}
		else
		{
			temp->link=new;
			temp=new;
		}
	}
}
void Display()
{
	struct stu *ptr=NULL,*ptr1=NULL;
	ptr=head;
	ptr1=head1;
	int c=1;
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while((ptr->link)!=head)
		{
			printf("%d\t",ptr->data);
			ptr=ptr->link;
			c++;
		}							          
		printf("%d\n",ptr->data);
	}		    
	printf("number of nodes =%d\n",c);
	c=1;
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
			c++;
		}
		printf("%d\n",ptr1->data);
	}
	printf("number of nodes =%d\n",c);
}

void list_cll_or_not()
{
	if(head==NULL)
	{
		printf("Circular list is empty\n");
	}
	else
	{
		struct stu *temp_node=head;
		while(temp_node->link!=head)
		{
			printf("%d\t",temp_node->data);
			temp_node=temp_node->link;
		}
      		printf("%d\n",temp_node->data);
		if((temp_node)->link==(head))
		{
			printf("List is a Circular single list\n");
		}
		else
		{
			printf("List is not a Circular single list\n");
		}
	}
	if(head1==NULL)
	{
		printf("SLL list is empty\n");
	}
	else
	{
		struct stu *temp_node=head1;			
		while(temp_node->link!=NULL)
		{
			printf("%d\t",temp_node->data);
			temp_node=temp_node->link;
		}
		printf("%d\n",temp_node->data);
		if((temp_node)->link==(head1))
		{
			printf("List is a Circular single list\n");
		}
		else
		{
			printf("List is not a Circular single list\n");
		}
	}
}
