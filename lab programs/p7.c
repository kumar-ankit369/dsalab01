#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	char USN[20];
	char Name[20];
	char Programme[20];
	int SEM;
	int Phno;
	struct Node *Next;
};

struct Node *Head = NULL, *temp = NULL, *p = NULL;
int count = 0;

void create()
{
	int i, n;
	printf("\nEnter Number of Students :");
	scanf("%d", &n);
	getchar();

	for (i = 1; i <= n; i++)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		printf("\nEnter data for Student %d: ", i);
		printf("\nEnter USN :");
		scanf("%s", temp->USN);
		getchar();
		printf("\nEnter Name :");
		fgets(temp->Name, sizeof(temp->Name), stdin);
		temp->Name[strcspn(temp->Name, "\n")] = 0;
		printf("\nEnter Programme :");
		fgets(temp->Programme, sizeof(temp->Programme), stdin);
		temp->Programme[strcspn(temp->Programme, "\n")] = 0;
		printf("\nEnter SEM :");
		scanf("%d", &temp->SEM);
		printf("\nEnter Phone No :");
		scanf("%d", &temp->Phno);
		temp->Next = NULL;
		count++;
		if (Head == NULL)
		{
			Head = temp;
		}
		else
		{
			temp->Next = Head;
			Head = temp;
		}
	}
}

void addfront()
{
	temp = (struct Node *)malloc(sizeof(struct Node));
	printf("\nEnter USN :");
	scanf("%s", temp->USN);
	getchar();
	printf("\nEnter Name :");
	fgets(temp->Name, sizeof(temp->Name), stdin);
	temp->Name[strcspn(temp->Name, "\n")] = 0;
	printf("\nEnter Programme :");
	fgets(temp->Programme, sizeof(temp->Programme), stdin);
	temp->Programme[strcspn(temp->Programme, "\n")] = 0;
	printf("\nEnter SEM :");
	scanf("%d", &temp->SEM);
	printf("\nEnter Phone No :");
	scanf("%d", &temp->Phno);
	temp->Next = NULL;
	count++;
	if (Head == NULL)
	{
		Head = temp;
	}
	else
	{
		temp->Next = Head;
		Head = temp;
	}
}

void addrear()
{
	temp = (struct Node *)malloc(sizeof(struct Node));
	printf("\nEnter USN :");
	scanf("%s", temp->USN);
	getchar();
	printf("\nEnter Name :");
	fgets(temp->Name, sizeof(temp->Name), stdin);
	temp->Name[strcspn(temp->Name, "\n")] = 0;
	printf("\nEnter Programme :");
	fgets(temp->Programme, sizeof(temp->Programme), stdin);
	temp->Programme[strcspn(temp->Programme, "\n")] = 0;
	printf("\nEnter SEM :");
	scanf("%d", &temp->SEM);
	printf("\nEnter Phone No :");
	scanf("%d", &temp->Phno);
	temp->Next = NULL;
	count++;
	if (Head == NULL)
	{
		Head = temp;
	}
	else
	{
		p = Head;
		while (p->Next != NULL)
		{
			p = p->Next;
		}
		p->Next = temp;
	}
}
void display()
{
	if (Head == NULL)
	{
		printf("\nNo Link List Available ");
	}
	p = Head;
	while (p != NULL)
	{
		printf("\nUSN:%s ", p->USN);
		printf("\nName:%s ", p->Name);
		printf("\nProgramme:%s ", p->Programme);
		printf("\nSEM:%d", p->SEM);
		printf("\nPhone No:%d", p->Phno);
		p = p->Next;
	}
	printf("\nNo of Students: %d", count);
}
void deletefront()
{
	if (Head == NULL)
	{
		printf("\nLink List is Empty ");
	}
	p = Head;
	printf("\ndeleted %s\n", p->Next->USN);
	printf("\n%s", p->Next->Name);
	printf("\n%s", p->Next->Programme);
	printf("\n%d", p->Next->SEM);
	printf("\n%d", p->Next->Phno);
	Head = Head->Next;
	free(p);
	count--;
}
void deleterear()
{
	if (Head == NULL)
	{
		printf("\nLink List is Empty ");
	}
	p = Head;
	while (p->Next->Next != NULL)
	{
		p = p->Next;
	}
	printf("\ndeleted %s\n", p->Next->USN);
	printf("\n%s", p->Next->Name);
	printf("\n%s", p->Next->Programme);
	printf("\n%d", p->Next->SEM);
	printf("\n%d", p->Next->Phno);
	free(p->Next);
	p->Next = NULL;
	printf("\ndeleted");
	count--;
}
int main()
{
    printf("Name-Atul Raj \nUSN-1AY23CS045");
	int choice = 1;
	while (choice != 0)
	{
		printf("\n**Menu*");
		printf("\n1. Create New List");
		printf("\n2. Add new data at the front");
		printf("\n3. Add new data at the rear");
		printf("\n4. Delete data from the front ");
		printf("\n5. Delete data from the rear");
		printf("\n6.  Display status of SLL");
		printf("\n0. Exit");
		printf("\nEnter your Choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			create();
			break;
		case 2:
			addfront();
			break;
		case 3:
			addrear();
			break;
		case 4:
			deletefront();
			break;
		case 5:
			deleterear();
			break;
		case 6:
			display();
			break;
		case 0:
			break;
		default:
			printf("Invalid Choice");
		}
	}
	printf("\nEnd of Program");
	return 0;
}