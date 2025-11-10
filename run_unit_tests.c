#include <stdio.h>
#include <string.h> 
#define ROWS 3
#define COLS 3
int find_in_matrix(int matrix[ROWS][COLS], int value);
int find_in_vector(int vector[], int size, int value);
void get_matrix_row(int matrix[ROWS][COLS], int row, int row_out[]);
void test_get_matrix_row();
void test_find_in_vector();
void test_find_in_matrix();

/**
 * @brief This is the main function for our TEST PROGRAM.
 *
 * It acts as a test runner, executing each unit test one by one.
 */
int main() {
    printf("--- Running Unit Tests for Your Program ---\n");

    test_get_matrix_row();
    test_find_in_vector();
    test_find_in_matrix();

    printf("\n--- All tests have finished. ---\n");
    return 0;
}

// ==========================================================
//  HERE ARE THE ACTUAL TESTS
// ==========================================================

/**
 * @brief This function tests if get_matrix_row works correctly.
 */
void test_get_matrix_row() {
    printf("\nTESTING: get_matrix_row function...\n");
    int matrix[ROWS][COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int expected_output[COLS] = {4, 5, 6}; 
    int actual_output[COLS]; 
    get_matrix_row(matrix, 1, actual_output); 
    if (memcmp(expected_output, actual_output, sizeof(expected_output)) == 0) {
        printf("  [PASSED] The correct row was extracted.\n");
    } else {
        printf("  [FAILED] The row was NOT extracted correctly.\n");
    }
}

/**
 * @brief This function tests if find_in_vector works correctly.
 */
void test_find_in_vector() {
    printf("\nTESTING: find_in_vector function...\n");
    int vector[] = {10, 20, 30, 40, 50};
    if (find_in_vector(vector, 5, 30) == 1) {
        printf("  [PASSED] Found value 30 in the vector.\n");
    } else {
        printf("  [FAILED] Did NOT find value 30.\n");
    }
    if (find_in_vector(vector, 5, 99) == 0) {
        printf("  [PASSED] Correctly did not find value 99.\n");
    } else {
        printf("  [FAILED] Found value 99 when it should not exist.\n");
    }
}

/**
 * @brief This function tests if find_in_matrix works correctly.
 */
void test_find_in_matrix() {
    printf("\nTESTING: find_in_matrix function...\n");
    int matrix[ROWS][COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    if (find_in_matrix(matrix, 5) == 1) {
        printf("  [PASSED] Found value 5 in the matrix.\n");
    } else {
        printf("  [FAILED] Did NOT find value 5.\n");
    }
    if (find_in_matrix(matrix, 100) == 0) {
        printf("  [PASSED] Correctly did not find value 100.\n");
    } else {
        printf("  [FAILED] Found value 100 when it should not exist.\n");
    }
}


// ==========================================================
//  MY ORIGINAL FUNCTIONS (MODIFIED TO BE TESTABLE)
// ==========================================================

int find_in_matrix(int matrix[ROWS][COLS], int value) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == value) {
                return 1;
            }
        }
    }
    return 0;
}

int find_in_vector(int vector[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (vector[i] == value) {
            return 1;
        }
    }
    return 0;
}

void get_matrix_row(int matrix[ROWS][COLS], int row, int row_out[]) {
    if (row < 0 || row >= ROWS) {
        return;
    }
    for (int j = 0; j < COLS; j++) {
        row_out[j] = matrix[row][j];
    }
}
