#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>  // For clock() function
#include "student.h"
#include "course.h"
#include "hashtable.h"
#include "bst.h"

// Function to load students and measure insertion time
void load_students_and_test(const char* filename, HashNode* student_table[]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        return;
    }

    char line[256];
    int total_students = 0;
    clock_t start = clock();  // Start the clock for insertion time

    while (fgets(line, sizeof(line), file)) {
        int student_id;
        char name[50];
        sscanf(line, "%d,%s", &student_id, name);

        // Insert into hash table
        Student* student = create_student(student_id, name);
        insert_hash(student_table, student->student_id, (int)student);
        total_students++;
    }

    clock_t end = clock();  // End the clock for insertion time
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Inserted %d students in %.2f seconds\n", total_students, time_taken);

    fclose(file);
}

// Function to load courses and measure insertion time
void load_courses_and_test(const char* filename, BSTNode** course_root) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s.\n", filename);
        return;
    }

    char line[256];
    int total_courses = 0;
    clock_t start = clock();  // Start the clock for insertion time

    while (fgets(line, sizeof(line), file)) {
        int course_id;
        char course_name[50];
        sscanf(line, "%d,%s", &course_id, course_name);

        // Insert into BST
        *course_root = insert_bst(*course_root, course_id);
        total_courses++;
    }

    clock_t end = clock();  // End the clock for insertion time
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Inserted %d courses in %.2f seconds\n", total_courses, time_taken);

    fclose(file);
}

// Function to test retrieval of students and measure time
void test_student_retrieval(HashNode* student_table[], int num_students) {
    clock_t start = clock();  // Start the clock for retrieval time

    for (int i = 1; i <= num_students; i++) {
        Student* s = (Student*)search_hash(student_table, i);
        if (s == NULL) {
            printf("Student ID %d not found.\n", i);
        }
    }

    clock_t end = clock();  // End the clock for retrieval time
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Retrieved %d students in %.2f seconds\n", num_students, time_taken);
}

// Function to test retrieval of courses and measure time
void test_course_retrieval(BSTNode* course_root, int num_courses) {
    clock_t start = clock();  // Start the clock for retrieval time

    for (int i = 101; i < 101 + num_courses; i++) {
        if (search_bst(course_root, i) == NULL) {
            printf("Course ID %d not found.\n", i);
        }
    }

    clock_t end = clock();  // End the clock for retrieval time
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Retrieved %d courses in %.2f seconds\n", num_courses, time_taken);
}

int main() {
    // Initialize the Hash Table and BST
    HashNode* student_table[TABLE_SIZE] = { NULL }; // Hash Table for students
    BSTNode* course_root = NULL;                  // BST for courses

    // Load and test insertions
    load_students_and_test("students_data.csv", student_table);
    load_courses_and_test("courses_data.csv", &course_root);

    // Test retrieval performance
    test_student_retrieval(student_table, 10000);  // Test retrieval for 10,000 students
    test_course_retrieval(course_root, 100);       // Test retrieval for 100 courses

    return 0;
}
