//Student Result Analysis • Store the roll number, name, and marks in five subjects for N students using structures. 
//• Calculate the total, percentage, and grade of each student. 
//• Display the class topper, students who failed in one or more subjects, and the class average.
#include <stdio.h>

struct student
{
    int roll;
    char name[20];
    float marks[5];
    float total;
    float percentage;
    char grade;
};

int main()
{
    int n, i, j;
    int topper = 0;
    float class_total = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct student s[n];

    for(i = 0; i < n; i++)
    {
        printf("\nEnter roll number: ");
        scanf("%d", &s[i].roll);

        printf("Enter name: ");
        scanf("%s", s[i].name);

        s[i].total = 0;

        for(j = 0; j < 5; j++)
        {
            printf("Enter marks: ");
            scanf("%f", &s[i].marks[j]);
            s[i].total = s[i].total + s[i].marks[j];
        }

        s[i].percentage = s[i].total / 5;

        if(s[i].percentage >= 90)
            s[i].grade = 'A';
        else if(s[i].percentage >= 80)
            s[i].grade = 'B';
        else if(s[i].percentage >= 70)
            s[i].grade = 'C';
        else if(s[i].percentage >= 60)
            s[i].grade = 'D';
        else
            s[i].grade = 'F';

        class_total = class_total + s[i].total;
    }

    for(i = 1; i < n; i++)
    {
        if(s[i].total > s[topper].total)
            topper = i;
    }

    printf("\n--- Student Results ---\n");

    for(i = 0; i < n; i++)
    {
        printf("\nRoll: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal: %.2f", s[i].total);
        printf("\nPercentage: %.2f%%", s[i].percentage);
        printf("\nGrade: %c\n", s[i].grade);

        for(j = 0; j < 5; j++)
        {
            if(s[i].marks[j] < 40)
            {
                printf("Failed in one or more subjects\n");
                break;
            }
        }
    }

    printf("\n--- Class Topper ---\n");
    printf("Name: %s\n", s[topper].name);
    printf("Roll: %d\n", s[topper].roll);

    printf("\nClass Average: %.2f\n", class_total / n);

    return 0;
}