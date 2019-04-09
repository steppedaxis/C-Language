#include<stdlib.h>
#include<stdio.h>

typedef struct Node
{
	int num;
	Node *next;
}Node;

Node *make_node(int num)
{
	Node *new_node;
	new_node = (Node*)malloc(sizeof(Node));
	if (new_node==NULL)
	{
		printf("Error creating a new node\n");
		exit(0);
	}
	new_node->num = num;
	new_node->next = NULL;

	return new_node;
}

void add_node(Node *head, Node *new_node)
{
	Node *current=head;
	while (current->next!=NULL)
	{
		current = current->next;
	}
	current->next = new_node;
}

void printlist(Node *head)
{
	Node *current = head;
	while (current)
	{
		printf("%d ", current->num);
		current = current->next;
	}

}

void delete_value(int value, Node *head)
{
	Node *current = head, *prev = NULL,*next_head=NULL;
	while (current)
	{
		if (head->num == value)
		{
			next_head = head->next;
			free(head);
			head = next_head;
			break;
		}
		if (current->num==value)
		{
			if(prev == NULL)
			{
				head = current->next;
				free(current);
				break;
			}
			
			prev->next = current->next;
			free(current);
			break;
		}
		prev = current;
		current = current->next;
	}
	printlist(head);
}

void delete_list(Node *head)
{
	Node *current = head,*prev=NULL;
	while (current)
	{
		prev = current;
		current = current->next;
		free(prev);
		head = current;
	}
	printf("\nlist has been deleted!\n");
	printlist(head);
}



void main()
{
	{
		int i = 0;
		int arr[10] = { 1,2,3,4,5,6,7,8,9,-1 };
		while (arr[i++] + 1) {
			printf("%d\n", arr[i - 1]);
		}
	}



	int num,i,val,userchoice;
	Node *head;
	Node *new_node;
	while (true)
	{
		printf("\tMENU\n");
		printf("please enter a choice\n");
		printf("1)create list\n2)print your list\n3)delete a certin value\n4)delete your whole list\n5)exit\n");
		printf("\ninput: ");
		scanf("%d", &userchoice);

		switch (userchoice)
		{
		case 1:
			printf("enter num\n");
			scanf("%d", &num);

			head = make_node(num);

			for (i = 1; i < 3; i++)
			{
				printf("enter num\n");
				scanf("%d", &num);
				new_node = make_node(num);
				add_node(head, new_node);
			}
			system("CLS");
			printf("list created!\n");
			break;

		case 2:
			printlist(head);
			printf("\n\n");
			break;

		case 3:
			printf("\nenter value to be deleted from the list\n");
			scanf("%d", &val);
			delete_value(val, head);
			printf("\n\n");
			break;

		case 4:
			delete_list(head);
			printf("\n\n");
			break;

		case 5:
			printf("good bye!\n");
			exit(0);
			break;
		default:
			break;
		}
	}
	printf("\tMENU\n");
	printf("please enter a choice\n");
	printf("1)create list\n2)print your list\n3)delete a certin value\n4)delete your whole list\n5)exit\n");
	printf("\ninput: ");
	scanf("%d", &userchoice);
	
		switch (userchoice)
		{
		case 1:
			printf("enter num\n");
			scanf("%d", &num);

			head = make_node(num);

			for (i = 1; i < 3; i++)
			{
				printf("enter num\n");
				scanf("%d", &num);
				new_node = make_node(num);
				add_node(head, new_node);
			}
			system("CLS");
			printf("list created!\n");
			break;

		case 2:
			printlist(head);
			if (head==NULL)
			{
				printf("list is deleted,no head!\n");
				exit(0);
			}
			break;

		case 3:
			printf("\nenter value to be deleted from the list\n");
			scanf("%d", &val);
			delete_value(val, head);
			break;

		case 4:
			delete_list(head);
			break;

		case 5:
			printf("good bye!");
			exit(0);
			break;
		default:
			break;
		}
		
	




	
	
	




}