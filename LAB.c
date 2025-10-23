//Lab 1

//Q6.
#include <stdio.h>

void main()
{
    float r, volume, area;
    const float PI = 3.14159;
    printf("Enter radius: ");
    scanf("%f", &r);

    volume = (4.0 * PI * r * r * r) / 3.0;
    area = 4.0 * PI * r * r;

    printf("Volume of sphere is: %f\n", volume);
    printf("Surface Area of sphere is: %f\n", area);
    printf("\n");
}

//Q7.
#include <stdio.h>

void main()
{
    float F, C;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &F);

    C = (F - 32.0) * 5.0 / 9.0;

    printf("Temperature in Centigrade is: %f\n", C);
    printf("\n");
}

//Q8.
#include <stdio.h>

void main()
{
    int a = 30;
    int b = 10;
    int c = 5;
    int d = 15;
    float result1, result2, result3, result4;

    printf("a=%d, b=%d, c=%d, d=%d\n", a, b, c, d);

    // (i ) (a + b) * c / d
    result1 = (float)(a + b) * c / d;
    printf("(i ) (a + b) * c / d = %f\n", result1);

    // (ii) ((a + b) * c) / d
    result2 = (float)((a + b) * c) / d;
    printf("(ii) ((a + b) * c) / d = %f\n", result2);

    // (iii) a + (b * c) / d
    result3 = (float)a + (b * c) / d;
    printf("(iii) a + (b * c) / d = %f\n", result3);

    // (iv) (a + b) * (c / d)
    result4 = (float)(a + b) * ((float)c / d);
    printf("(iv) (a + b) * (c / d) = %f\n", result4);
}


//LAB6

//Q4.
#include <stdio.h>
#define MAX_SIZE 10

void main()
{
    int A[MAX_SIZE][MAX_SIZE];
    int i, j, temp, N;

    // Ask user for the size N
    printf("Enter the size N for the N x N matrix (Max %d): ", MAX_SIZE);
    scanf("%d", &N);

    if (N <= 0 || N > MAX_SIZE) {
        printf("Invalid size. Size must be between 1 and %d. Exiting.\n", MAX_SIZE);
        return;
    }

    // Input Matrix A
    printf("\nEnter elements of Matrix A (%d x %d):\n", N, N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("Enter element A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nOriginal Matrix A (Input):\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    // 1. Interchange Row 0 and Row (N-1) in Matrix A
    printf("\nMatrix A after swapping Row 0 and Row %d:\n", N - 1);
    for (j = 0; j < N; j++) {
        temp = A[0][j];
        A[0][j] = A[N - 1][j];
        A[N - 1][j] = temp;
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    // 2. Interchange Column 0 and Column (N-1) in Matrix A
    printf("\nMatrix A after swapping Column 0 and Column %d:\n", N - 1);
    for (i = 0; i < N; i++) {
        temp = A[i][0];
        A[i][0] = A[i][N - 1];
        A[i][N - 1] = temp;
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
}

//Q5.
#include <stdio.h>

void main()
{
    int N;
    int i;

    printf("Enter the number of students (N): ");
    scanf("%d", &N);

    // Using Variable Length Array (VLA)
    int STUDENTS_MARK[2][N];

    // Input Roll Numbers (Row 0)
    printf("Enter %d Roll Numbers:\n", N);
    for (i = 0; i < N; i++) {
        printf("Roll No %d: ", i + 1);
        scanf("%d", &STUDENTS_MARK[0][i]);
    }

    // Input Marks (Row 1 - one subject)
    printf("\nEnter %d Marks:\n", N);
    for (i = 0; i < N; i++) {
        printf("Mark for Roll No %d: ", STUDENTS_MARK[0][i]);
        scanf("%d", &STUDENTS_MARK[1][i]);
    }

    // Display STUDENTS_MARK
    printf("\nSTUDENTS_MARK (2xN):\n");

    // Display Roll Numbers (Row 0)
    for (i = 0; i < N; i++) {
        printf("%d\t", STUDENTS_MARK[0][i]);
    }
    printf(" <-- Roll Numbers\n");

    // Display Marks (Row 1)
    for (i = 0; i < N; i++) {
        printf("%d\t", STUDENTS_MARK[1][i]);
    }
    printf(" <-- Marks\n");
    printf("\n");
}


//Q6.#include <stdio.h>

void main()
{
    int N;
    int i, j;

    printf("Enter the number of students (N): ");
    scanf("%d", &N);

    // Using Variable Length Array (VLA): 4 rows (RollNo + 3 Subjects) and N columns (students)
    int STUDENTS_MARKS[4][N];

    // Input Roll Numbers (Row 0)
    printf("Enter %d Roll Numbers:\n", N);
    for (i = 0; i < N; i++) {
        printf("Roll No %d: ", i + 1);
        scanf("%d", &STUDENTS_MARKS[0][i]);
    }

    // Input Marks for 3 Subjects (Rows 1, 2, 3)
    for (i = 0; i < N; i++) {
        printf("\nEnter Marks for Roll No %d (3 subjects):\n", STUDENTS_MARKS[0][i]);
        // j=1 to 3 represent the three subject rows
        for (j = 1; j < 4; j++) {
            printf("Subject %d Mark: ", j);
            scanf("%d", &STUDENTS_MARKS[j][i]);
        }
    }

    // Display STUDENTS_MARKS
    printf("\nSTUDENTS_MARKS (4xN) Display:\n");

    // Display Column-wise (student-by-student)
    for (i = 0; i < N; i++) {
        printf("%d\t%d\t%d\t%d\n", 
            STUDENTS_MARKS[0][i], // Roll Number
            STUDENTS_MARKS[1][i], // Subject 1 Mark
            STUDENTS_MARKS[2][i], // Subject 2 Mark
            STUDENTS_MARKS[3][i]  // Subject 3 Mark
        );
    }
    printf("\n");
}

//LAB7 

//Q6.
#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 50
#define MAX_NAME_LEN 50

void main()
{
    int N;
    int i, j;
    char temp_name[MAX_NAME_LEN];

    printf("Enter the number of students (N - Max 50): ");
    scanf("%d", &N);

    if (N <= 0 || N > MAX_STUDENTS) {
        printf("Invalid number of students. Exiting.\n");
        return;
    }

    // Arrays to store student names
    char STUDENTS_NAMES[MAX_STUDENTS][MAX_NAME_LEN];
    char STUDENTS_NAMES_SORTED[MAX_STUDENTS][MAX_NAME_LEN];


    // --- Input Student Names ---
    for (i = 0; i < N; i++) {
        printf("Enter Name for Student %d: ", i + 1);
        scanf("%s", STUDENTS_NAMES[i]);
    }

    // --- Copy original names to the sorting array ---
    for (i = 0; i < N; i++) {
        strcpy(STUDENTS_NAMES_SORTED[i], STUDENTS_NAMES[i]);
    }

    // --- Sort STUDENTS_NAMES_SORTED (Bubble Sort) ---
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - 1 - i; j++) {
            // Compare the strings alphabetically
            if (strcmp(STUDENTS_NAMES_SORTED[j], STUDENTS_NAMES_SORTED[j + 1]) > 0) {
                // Swap the names using strcpy
                strcpy(temp_name, STUDENTS_NAMES_SORTED[j]);
                strcpy(STUDENTS_NAMES_SORTED[j], STUDENTS_NAMES_SORTED[j + 1]);
                strcpy(STUDENTS_NAMES_SORTED[j + 1], temp_name);
            }
        }
    }

    // --- Display Sorted Names ---
    printf("\nSTUDENTS_NAMES_SORTED (Alphabetical Order):\n");
    for (i = 0; i < N; i++) {
        printf("%s\n", STUDENTS_NAMES_SORTED[i]);
    }
}


//Lab8 

//4.#include <stdio.h>

// Function: generate nth Fibonacci term
int FIB(int n)
{
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } 
    else {
        return FIB(n - 1) + FIB(n - 2);
    }
}

void main()
{
    int N;
    int i;

    printf("Enter the number of Fibonacci terms (N) to print: ");
    if (scanf("%d", &N) != 1) return;

    if (N < 1) {
        printf("N must be a positive integer.\n");
        return;
    }
    
    printf("Fibonacci terms:\n");
    
    for (i = 0; i < N; i++) {
        printf("%d ", FIB(i));
    }
    
    printf("\n");
}

//Q5.#include <stdio.h>
#include <string.h>

void main()
{
    int N;
    int i;
    
    printf("Enter the number of students (N - Max 50): ");
    if (scanf("%d", &N) != 1) return;

    if (N <= 0 || N > 50) {
        printf("Invalid number of students.\n");
        return;
    }

    int roll_numbers[50];
    char students_names[50][50];

    printf("Student Data Input:\n");
    for (i = 0; i < N; i++) {
        printf("Student %d:\n", i + 1);
        printf("  Enter Roll No: ");
        scanf("%d", &roll_numbers[i]);
        printf("  Enter Name (no spaces): ");
        scanf("%s", students_names[i]);
    }
    
    printf("Student Names and Roll Numbers:\n");
    printf("Roll No\tName\n");
    printf("------------------\n");
    for (i = 0; i < N; i++) {
        printf("%d\t%s\n", roll_numbers[i], students_names[i]);
    }
}

//q6.
#include <stdio.h>
#include <string.h>

// Function: Calculate Average
void Calculate_Average(int STUDENTS_MARKS[4][50], int N, float AVERAGE[])
{
    int i, j;
    
    for (i = 0; i < N; i++) {
        int sum_of_marks = 0;
        // J=1 to 3 for the three subject marks
        for (j = 1; j <= 3; j++) {
            sum_of_marks += STUDENTS_MARKS[j][i];
        }
        AVERAGE[i] = (float)sum_of_marks / 3; 
    }
}

// Function: Find Topper
void Find_Topper(float AVERAGE[], int N, char STUDENTS_NAMES[50][50])
{
    int i;
    int topper_index = 0;
    float max_average = -1.0f;

    for (i = 0; i < N; i++) {
        if (AVERAGE[i] > max_average) {
            max_average = AVERAGE[i];
            topper_index = i;
        }
    }
    
    printf("The topper is : %s\n", STUDENTS_NAMES[topper_index]);
}


void main()
{
    int N;
    int i, j;
    
    printf("Enter the number of students (N - Max 50) for Analytics: ");
    if (scanf("%d", &N) != 1) return;

    if (N <= 0 || N > 50) {
        printf("Invalid number of students.\n");
        return;
    }

    int STUDENTS_MARKS[4][50];
    char STUDENTS_NAMES[50][50];
    float AVERAGE[50];

    // Input Roll No and Name
    for (i = 0; i < N; i++) {
        printf("Student %d (Analytics Input):\n", i + 1);
        printf("  Enter Roll No: ");
        scanf("%d", &STUDENTS_MARKS[0][i]);
        printf("  Enter Name (no spaces): ");
        scanf("%s", STUDENTS_NAMES[i]);
    }

    // Input Marks for 3 Subjects
    for (i = 0; i < N; i++) {
        printf("Enter Marks for Roll No %d (%s) (3 subjects):\n", STUDENTS_MARKS[0][i], STUDENTS_NAMES[i]);
        for (j = 1; j <= 3; j++) {
            printf("  Subject %d Mark: ", j);
            scanf("%d", &STUDENTS_MARKS[j][i]);
        }
    }

    // Calculation and Display
    Calculate_Average(STUDENTS_MARKS, N, AVERAGE);

    printf("\nAverage Marks Display:\n");
    printf("Roll No\tName\tAverage\n");
    printf("--------------------------------\n");
    for (i = 0; i < N; i++) {
        printf("%d\t%s\t%.2f\n", STUDENTS_MARKS[0][i], STUDENTS_NAMES[i], AVERAGE[i]);
    }
    
    printf("\nTopper Result:\n");
    Find_Topper(AVERAGE, N, STUDENTS_NAMES);
}

//Lab 9

//Q1.
#include <stdio.h>

void main()
{
    int N, i;
    int arr[100];
    int max_val;
    int *ptr;

    printf("Enter the number of elements (max 100): ");
    if (scanf("%d", &N) != 1 || N <= 0 || N > 100) return;

    printf("Enter %d integers:\n", N);
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize pointer to the first element
    ptr = arr;
    // Assume the first element is the maximum
    max_val = *ptr;

    for (i = 1; i < N; i++) {
        // Move pointer to the next element
        ptr++;
        if (*ptr > max_val) {
            max_val = *ptr;
        }
    }

    printf("The maximum number in the array is: %d\n", max_val);
}

//Q2.
#include <stdio.h>

void swap_numbers(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void main()
{
    int x, y;

    printf("Enter first number (x): ");
    if (scanf("%d", &x) != 1) return;
    
    printf("Enter second number (y): ");
    if (scanf("%d", &y) != 1) return;

    printf("\nBefore swap: x = %d, y = %d\n", x, y);

    // Pass addresses using &
    swap_numbers(&x, &y);

    printf("After swap: x = %d, y = %d\n", x, y);
}

//Q3.
#include <stdio.h>
#include <string.h>

struct student {
    char name[50];
    int roll_number;
    int marks1, marks2, marks3;
    int total;
    float average;
};

void main()
{
    struct student students[5];
    int i;
    int N = 5;

    printf("--- Enter Data for 5 Students ---\n");
    for (i = 0; i < N; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("  Name: ");
        scanf("%s", students[i].name);
        printf("  Roll Number: ");
        scanf("%d", &students[i].roll_number);
        printf("  Mark 1: ");
        scanf("%d", &students[i].marks1);
        printf("  Mark 2: ");
        scanf("%d", &students[i].marks2);
        printf("  Mark 3: ");
        scanf("%d", &students[i].marks3);

        // Calculate Total and Average
        students[i].total = students[i].marks1 + students[i].marks2 + students[i].marks3;
        students[i].average = (float)students[i].total / 3.0;
    }

    printf("\n--- Results ---\n");
    printf("Roll No\tName\tTotal\tAverage\n");
    printf("--------------------------------\n");
    for (i = 0; i < N; i++) {
        printf("%d\t%s\t%d\t%.2f\n",
               students[i].roll_number,
               students[i].name,
               students[i].total,
               students[i].average);
    }
}

//Q4.
#include <stdio.h>
#include <string.h>

// Nested Structure for Address
struct address {
    char street[50];
    char city[50];
    int zip_code;
};

// Main Structure for Student, including Address
struct student {
    char name[50];
    int roll_number;
    struct address addr; // Nested structure member
};

void main()
{
    struct student s;

    printf("--- Input Student Details ---\n");
    printf("Name: ");
    scanf("%s", s.name);
    printf("Roll Number: ");
    scanf("%d", &s.roll_number);
    
    printf("\n--- Input Address Details ---\n");
    printf("Street: ");
    scanf("%s", s.addr.street);
    printf("City: ");
    scanf("%s", s.addr.city);
    printf("Zip Code: ");
    scanf("%d", &s.addr.zip_code);

    printf("\n--- Display Student Details ---\n");
    printf("Name: %s\n", s.name);
    printf("Roll Number: %d\n", s.roll_number);
    printf("Address: %s St., %s, Zip: %d\n", 
           s.addr.street, 
           s.addr.city, 
           s.addr.zip_code);
}


//Q5.#include <stdio.h>
#include <string.h>

struct product {
    int product_id;
    char name[50];
    float price;
};

void main()
{
    int N;
    int i;
    struct product products[50];
    // Pointer to the first element of the array
    struct product *ptr = products; 

    printf("Enter the number of products (max 50): ");
    if (scanf("%d", &N) != 1 || N <= 0 || N > 50) return;

    printf("\n--- Input Product Details ---\n");
    for (i = 0; i < N; i++) {
        printf("\nProduct %d:\n", i + 1);
        printf("  ID: ");
        // Use -> operator with pointer
        scanf("%d", &(ptr + i)->product_id); 
        printf("  Name (no spaces): ");
        scanf("%s", (ptr + i)->name);
        printf("  Price: ");
        scanf("%f", &(ptr + i)->price);
    }

    printf("\n--- Display Product Details ---\n");
    printf("ID\tName\t\tPrice\n");
    printf("----------------------------------\n");
    for (i = 0; i < N; i++) {
        printf("%d\t%s\t\t%.2f\n",
               (ptr + i)->product_id,
               (ptr + i)->name,
               (ptr + i)->price);
    }
}

//Q6.
#include <stdio.h>
#include <string.h>

struct player {
    char name[50];
    char team[50];
    float batting_average;
};

void main()
{
    int N;
    int i, j;
    struct player players[50];
    struct player temp_player; // Used for swapping

    printf("Enter the number of players (max 50): ");
    if (scanf("%d", &N) != 1 || N <= 0 || N > 50) return;

    printf("\n--- Input Player Data ---\n");
    for (i = 0; i < N; i++) {
        printf("\nPlayer %d:\n", i + 1);
        printf("  Name: ");
        scanf("%s", players[i].name);
        printf("  Team Name: ");
        scanf("%s", players[i].team);
        printf("  Batting Average: ");
        scanf("%f", &players[i].batting_average);
    }

    // Bubble Sort based on batting_average (ascending)
    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - 1 - i; j++) {
            // Swap if current average is greater than the next one
            if (players[j].batting_average > players[j + 1].batting_average) {
                temp_player = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp_player;
            }
        }
    }
    
    printf("\n--- Sorted Player Data (by Batting Average) ---\n");
    printf("Avg\tName\t\tTeam\n");
    printf("--------------------------------\n");
    for (i = 0; i < N; i++) {
        printf("%.3f\t%s\t\t%s\n",
               players[i].batting_average,
               players[i].name,
               players[i].team);
    }
}


