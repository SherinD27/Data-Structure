#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n, i;
    float total = 0.0;
    struct Employee *emp;

    // Input number of employees
    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    emp = (struct Employee *)malloc(n * sizeof(struct Employee));

    // Check allocation
    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input employee details
    printf("\nEnter details of each employee:\n");
    for (i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &emp[i].id);

        printf("Name: ");
        scanf("%s", emp[i].name);

        printf("Salary: ");
        scanf("%f", &emp[i].salary);

        total += emp[i].salary;
    }

    // Output total annual salary expenditure
    printf("\nTotal Annual Salary Expenditure = %.2f\n", total);

    // Free the allocated memory
    free(emp);

    return 0;
}
