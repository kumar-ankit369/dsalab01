#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int ssn;
    char name[20];
    char dept[20];
    char des[20];
    int sal;
    long int phno;
    struct Node *next;
    struct Node *prev;
};
struct Node *temp = NULL, *p = NULL, *head = NULL, *tail = NULL;
void create()
{
    int n;
    printf("\nHow many employees are there?- ");
    scanf("%d", &n);
    printf("\nEnter the employee details for %d employees:\n", n);
    for (int i = 1; i <= n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        printf("\nName: ");
        scanf("%s", temp->name);
        printf("Serial number: ");
        scanf("%d", &temp->ssn);
        printf("Department:  ");
        scanf("%s", temp->dept);
        printf("Designation: ");
        scanf("%s", temp->des);
        printf("Salary: ");
        scanf("%d", &temp->sal);
        printf("Phone number: ");
        scanf("%ld", &temp->phno);
        temp->prev = NULL;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
        }
        tail = temp;
    }
}
void addrear()
{
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("\nName: ");
    scanf("%s", temp->name);
    printf("Serial number: ");
    scanf("%d", &temp->ssn);
    printf("Department:  ");
    scanf("%s", temp->dept);
    printf("Designation: ");
    scanf("%s", temp->des);
    printf("Salary: ");
    scanf("%d", &temp->sal);
    printf("Phone number: ");
    scanf("%ld", &temp->phno);
    temp->prev = NULL;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
    }
    tail = temp;
}
void addfront()
{
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("\nName: ");
    scanf("%s", temp->name);
    printf("Serial number: ");
    scanf("%d", &temp->ssn);
    printf("Department:  ");
    scanf("%s", temp->dept);
    printf("Designation: ");
    scanf("%s", temp->des);
    printf("Salary: ");
    scanf("%d", &temp->sal);
    printf("Phone number: ");
    scanf("%ld", &temp->phno);
    temp->prev = NULL;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void delfront()
{
    if (head == NULL)
    {
        printf("\nNo link list");
    }
    else
    {
        p = head;
        printf("\nDeleted:%s ", p->name);
        printf("\nDeleted:%d", p->ssn);
        printf("\nDeleted:%s", p->dept);
        printf("\nDeleted:%s", p->des);
        printf("\nDeleted:%d", p->sal);
        printf("\nDeleted:%ld", p->phno);
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        else
        {
            tail = NULL;
        }
        free(p);
    }
}
void delrear()
{
    if (head == NULL)
    {
        printf("no link list\n");
    }
    else
    {
        p = tail;
        printf("\nDeleted:%s ", p->name);
        printf("\nDeleted:%d", p->ssn);
        printf("\nDeleted:%s", p->dept);
        printf("\nDeleted:%s", p->des);
        printf("\nDeleted:%d", p->sal);
        printf("\nDeleted:%ld", p->phno);
        tail = tail->prev;
        if (tail != NULL)
        {
            tail->next = NULL;
        }
        else
        {
            head = NULL;
        }
        free(p);
    }
}
void disfront()
{
    int count = 0;
    if (head == NULL)
    {
        printf("\nLink list empty");
    }
    else
    {
        p = head;
        printf("\nThe employee details are: ");
        while (p != NULL)
        {
            printf("\n\nName:%s", p->name);
            printf("\nSerial number:%d", p->ssn);
            printf("\nDepartment:%s", p->dept);
            printf("\nDesignation:%s", p->des);
            printf("\nSalary:%d ", p->sal);
            printf("\nPhone number:%ld ", p->phno);
            p = p->next;
            count++;
        }
        printf("\nThe number of employees are %d\n ", count);
    }
}
int main()
{

    printf("\nName:Anusha Govind\tUSN:1AY23CS032");
    int choice;
    while (choice != 7)
    {
        printf("\n1.Create\n2.Insert at front\n3.Insert at end\n4.Delete at front\n5.Delete at end\n6.Display\n7.Exit\n");
        printf("\nEnter your choice:");
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
            delfront();
            break;
        case 5:
            delrear();
            break;
        case 6:
            disfront();
            break;
        case 7:
            printf("\nExiting the program\n");
            exit(0);
        default:
            printf("\nInvalid choice!");
        }
    }
}