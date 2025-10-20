#include <stdio.h>

void addMarks(int marks[], int *size, int n) {
    if (*size >= n) {
        printf("\nArray full.. Cannot add more marks !!\n");
        return;
    }
    int m;
    printf("\nEnter the Marks (0-100): ");
    if (scanf("%d", &m) != 1) {
        printf("Invalid input. Please enter a number.\n");
        int ch; while ((ch = getchar()) != '\n' && ch != EOF);
        return;
    }
    if (m < 0 || m > 100) {
        printf("Invalid marks. Must be between 0 and 100.\n");
        return;
    }
    marks[*size] = m;
    (*size)++;
    printf("Marks Added Successfully !!\n\n");
}

void displayMarks(int marks[], int size) {
    if (size == 0) {
        printf("\nNo marks found !!\n");
        return;
    }
    printf("\nMarks:\n");
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", i + 1, marks[i]); 
    }
}

double calcAverage(int marks[], int size) {
    if (size == 0) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < size; i++) sum += marks[i];
    return sum / size;
}

void printMinMax(int marks[], int size) {
    if (size == 0) {
        printf("No marks.\n");
        return;
    }
    int min = marks[0], max = marks[0];
    for (int i = 1; i < size; ++i) {
        if (marks[i] < min) min = marks[i];
        if (marks[i] > max) max = marks[i];
    }
    printf("Min = %d, Max = %d\n", min, max);
}

int main() {
    printf("\n\n\t !!! ****** Welcome To Menu Driven Student Marks Manager ****** !!!\n\n");

    int n = 0;
    int choice;
    int size = 0;

    printf("Please Enter the Maximum number of Students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid capacity. Exiting.\n");
        return 1;
    }

    int marks[n]; 
    do {
        printf("\n 1. Add Marks \n 2. Display Marks \n 3. Calculate Average \n 4. Search marks by Index \n 5. Find Max & Min Marks \n 6. Exit  \n\nEnter the Choice no: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        switch (choice) {
            case 1:
                addMarks(marks, &size, n);
                break;
            case 2:
                displayMarks(marks, size);
                break;
            case 3:
                if (size == 0) printf("Average = 0.00 (no marks)\n");
                else printf("Average = %.2f\n", calcAverage(marks, size));
                break;
            case 4: {
                if (size == 0) {
                    printf("No marks available to search.\n");
                    break;
                }
                int idx;
                printf("Enter the Student No (1-%d): ", size);
                if (scanf("%d", &idx) != 1) {
                    printf("Invalid input.\n");
                    int ch; while ((ch = getchar()) != '\n' && ch != EOF);
                    break;
                }
                if (idx >= 1 && idx <= size) {
                    printf("Student %d mark = %d\n", idx, marks[idx - 1]);
                } else {
                    printf("Invalid index.\n");
                }
                break;
            }
            case 5:
                printMinMax(marks, size);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}
