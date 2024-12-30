#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int coff, xexp, yexp, zexp;
    struct node *next;
};

struct node *poly1 = NULL, *poly2 = NULL, *temp, *p;

struct node *createnode()
{
    int c, x, y, z;
    printf("\nEnter coefficient, exponents of x,y,z: ");
    scanf("%d%d%d%d", &c, &x, &y, &z);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->coff = c;
    temp->xexp = x;
    temp->yexp = y;
    temp->zexp = z;
    temp->next = NULL;
    return temp;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("Polynomial is empty.\n");
        return;
    }
    p = head;
    do
    {
        if (p->coff >= 0)
        {
            printf("+%dx^%dy^%dz^%d ", p->coff, p->xexp, p->yexp, p->zexp);
        }
        else
        {
            printf("%dx^%dy^%dz^%d ", p->coff, p->xexp, p->yexp, p->zexp);
        }
        p = p->next;
    } while (p != head);
    printf("\n");
}

double evaluate(struct node *head)
{
    if (head == NULL)
    {
        printf("Polynomial is empty.\n");
        return 0;
    }
    int x, y, z;
    double sum = 0;
    printf("\nEnter the values of x,y,z:");
    scanf("%d%d%d", &x, &y, &z);
    p = head;
    do
    {
        sum += (p->coff * pow(x, p->xexp) * pow(y, p->yexp) * pow(z, p->zexp));
        p = p->next;
    } while (p != head);
    printf("Sum of the polynomial: %lf\n", sum);
    return sum;
}

void sum(double sum1, double sum2)
{
    double s = sum1 + sum2;
    printf("Sum of two polynomials: %lf\n", s);
}

void freePolynomial(struct node *head)
{
    if (head == NULL)
        return;
    struct node *current = head;
    struct node *nextNode;
    do
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != head);
}

int main()
{
    int n1;
    double sum1, sum2;
    printf("Name-Atul Raj\nUSN-1AY23CS045");
    printf("\nHow many terms in polynomial 1= ");
    scanf("%d", &n1);
    for (int i = 1; i <= n1; i++)
    {
        struct node *newnode = createnode();
        if (poly1 == NULL)
        {
            poly1 = newnode;
            newnode->next = poly1;
        }
        else
        {
            p = poly1;
            while (p->next != poly1)
            {
                p = p->next;
            }
            newnode->next = poly1;
            p->next = newnode;
        }
    }
    printf("Displaying polynomial 1: ");
    display(poly1);
    sum1 = evaluate(poly1);

    int n2;
    printf("\nHow many terms in polynomial 2= ");
    scanf("%d", &n2);
    for (int i = 1; i <= n2; i++)
    {
        struct node *newnode = createnode();
        if (poly2 == NULL)
        {
            poly2 = newnode;
            newnode->next = poly2;
        }
        else
        {
            p = poly2;
            while (p->next != poly2)
            {
                p = p->next;
            }
            newnode->next = poly2;
            p->next = newnode;
        }
    }
    printf("Displaying polynomial 2: ");
    display(poly2);
    sum2 = evaluate(poly2);
    sum(sum1, sum2);
    return 0;
}