/**
 * @file matrix_operations.c
 * @brief A simple C program demonstrating basic matrix and vector operations.
 *
 * This program allows a user to define a 3x3 matrix and a 3-element vector.
 * It includes functions to find values within these structures and to extract
 * a specific row from the matrix.
 */

#include <stdio.h>
#include <conio.h> 

#define ROWS 3
#define COLS 3
void input_matrix(int matrix[ROWS][COLS]);
void print_matrix(int matrix[ROWS][COLS]);
void print_vector(int vector[], int size);
void find_in_matrix(int matrix[ROWS][COLS], int value);
void find_in_vector(int vector[], int size, int value);
void get_matrix_row(int matrix[ROWS][COLS], int row, int row_out[]);


/**
 * @brief The main entry point for the program.
 * 
 * This function orchestrates the program flow. It initializes a matrix and vector,
 * prompts the user for input, and calls other functions to perform operations
 * like searching and data extraction.
 * @return int Returns 0 on successful completion.
 */
int main() {
    int matrix[ROWS][COLS];
    int vector[COLS];
    int row_to_extract[COLS];
    int value_to_find, row_index;

    input_matrix(matrix);
    print_matrix(matrix);

    printf("Enter vector elements:\n");
    for (int i = 0; i < COLS; i++) {
        printf("vector[%d]: ", i);
        scanf("%d", &vector[i]);
    }
    print_vector(vector, COLS);

    printf("\nEnter a value to find in the matrix: ");
    scanf("%d", &value_to_find);
    find_in_matrix(matrix, value_to_find);

    printf("\nEnter a value to find in the vector: ");
    scanf("%d", &value_to_find);
    find_in_vector(vector, COLS, value_to_find);

    printf("\nEnter a row index to extract (0-%d): ", ROWS - 1);
    scanf("%d", &row_index);
    get_matrix_row(matrix, row_index, row_to_extract);

    printf("Extracted row: ");
    print_vector(row_to_extract, COLS);

    printf("\nPress any key to exit...\n");
    _getch();

    return 0;
}

/**
 * @brief Populates a matrix with user-provided values.
 * 
 * @param matrix The 2D integer array to be filled.
 */
void input_matrix(int matrix[ROWS][COLS]) {
    printf("Enter the elements for a %d x %d matrix:\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

/**
 * @brief Prints a 2D matrix to the console in a formatted way.
 * 
 * @param matrix The 2D integer array to be printed.
 */
void print_matrix(int matrix[ROWS][COLS]) {
    printf("\nThe matrix is:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Prints a 1D vector to the console.
 * 
 * @param vector The integer array to be printed.
 * @param size The number of elements in the vector.
 */
void print_vector(int vector[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

/**
 * @brief Finds all occurrences of a value in a matrix and prints their positions.
 * 
 * @param matrix The 2D integer array to search within.
 * @param value The integer value to look for.
 */
void find_in_matrix(int matrix[ROWS][COLS], int value) {
    int found = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == value) {
                printf("Found %d at position (%d, %d)\n", value, i, j);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("%d was not found in the matrix.\n", value);
    }
}

/**
 * @brief Finds all occurrences of a value in a vector and prints their indices.
 * 
 * @param vector The integer array to search within.
 * @param size The number of elements in the vector.
 * @param value The integer value to look for.
 */
void find_in_vector(int vector[], int size, int value) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (vector[i] == value) {
            printf("Found %d at index %d\n", value, i);
            found = 1;
        }
    }
    if (!found) {
        printf("%d was not found in the vector.\n", value);
    }
}

/**
 * @brief Extracts a specified row from a matrix.
 * 
 * @param matrix The source 2D integer array.
 * @param row The index of the row to be extracted.
 * @param row_out An output array where the extracted row will be stored.
 */
void get_matrix_row(int matrix[ROWS][COLS], int row, int row_out[]) {
    if (row < 0 || row >= ROWS) {
        printf("Invalid row index.\n");
        return;
    }
    for (int j = 0; j < COLS; j++) {
        row_out[j] = matrix[row][j];
    }
}

