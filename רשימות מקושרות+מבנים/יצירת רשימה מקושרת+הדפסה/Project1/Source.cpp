#include<stdio.h>
#include<stdlib.h>
#define size 80
#include<string.h>
typedef struct Student {
	int student_id;
	char student_name[size];
	struct Student *next_struct;
};

Student *MakeStruct(int id, char name[])
{
	Student *new_student = (Student*)malloc(sizeof(Student));
	if (new_student == NULL)
	{
		printf("Error creating a new node student\n");
		exit(0);
	}
	new_student->student_id = id;
	strcpy(new_student->student_name, name);
	new_student->next_struct = NULL;

	return new_student;
}

void AddNewStruct(Student *head, Student *new_student)
{
	Student *current = head;
	while (current->next_struct)
	{
		current = current->next_struct;
	}
	current->next_struct = new_student;
}

void PrintList(Student *head,Student *next_student)
{
	Student *current = head;
	while (current->next_struct!=NULL)
	{
		printf("%s\n", current->student_name);
		printf("%d\n", current->student_id);
		current = current->next_struct;
		printf("\n");
		if (current->next_struct==NULL)
		{
			printf("%s\n", current->student_name);
			printf("%d\n", current->student_id);
		}
	}
	current->next_struct = next_student;
	


}
	


void main()
{
	Student *head;
	Student *new_student;
	int id,i;
	char name[size];

	printf("enter id\n");
	scanf_s("%d%*c", &id);
	printf("enter name\n");
	gets_s(name);
	printf("\n==============\n");
	head = MakeStruct(id, name);

	for (i = 0; i < 1; i++)//make a loop, creating the number of nodes(students) that we want,including creating the node we want to add
	{
		printf("enter id\n");
		scanf_s("%d%*c", &id);
		printf("enter name\n");
		gets_s(name);
		printf("\n==============\n");

		new_student = MakeStruct(id, name);//insert given data by user to the node that we want to add
		
		AddNewStruct(head, new_student);//add the latest node created into list
	}

	PrintList(head,new_student);


}







