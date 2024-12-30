#include <stdio.h>

void towerofhanoi(int n, char source, char aux, char dest) {
    if (n == 1) {
        printf("\nMove disk 1 from %c to %c", source, dest);
        return;
    }
    towerofhanoi(n - 1, source, dest, aux);
    printf("\nMove disk %d from %c to %c", n, source, dest);
    towerofhanoi(n - 1, aux, source, dest);
}

int main() {
    int n;
    char source, aux, dest;
    printf("Name-Atul Raj\nUSN-1AY23CS045\n");

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Enter source: ");
    scanf(" %c", &source);

    printf("Enter auxiliary: ");
    scanf(" %c", &aux);

    printf("Enter destination: ");
    scanf(" %c", &dest);

    printf("\nThe sequence of moves involved in the Tower of Hanoi are:");
    towerofhanoi(n, source, aux, dest);
    printf("\n");
    return 0;
}