// Name: Karishma Khanna
// Date: 4/22/21
// Title: Lab 4: Developing multi-threaded applications
// Description: (Part 3) This program uses threads to perform a parallel matrix multiplication.

// Lab4 - skeleton for step 3
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h> // for the rand() function

//values of N, M, and L
#define N 2
#define M 3
#define L 2

pthread_t threads[N];

//A, B, C matrices
double matrixA[N][M], matrixB[M][L], matrixC[N][L];

//function prototypes
void initializeMatrix(int r,int c, double matrix[r][c]);
void *multiplyRow(void* arg);
void printMatrix(int r,int c, double matrix[r][c]);

int main() {
    int i;
    initializeMatrix(N, M, matrixA);  //initilaize matrixA with random values
    initializeMatrix(M, L, matrixB); //initialize matrixB with random values
    //create N threads, each multiplying row A by all columns of B to produce row of C
    for (i = 0; i < N; i++) {
        pthread_create(&threads[i], NULL, multiplyRow, (void*)(size_t)i); // create N threads and apply multiplyRow function
    }
    //Main thread waits for child threads to complete
    for (i = 0; i < N; i++) {
        pthread_join(threads[i],NULL);
    }
    //Print Matrix A, B, and C
    printf("\nMatrix A:\n");
    printMatrix(N, M, matrixA);
    printf("\nMatrix B:\n");
    printMatrix(M, L, matrixB);
    printf("\nMatrix C:\n");
    printMatrix(N, L, matrixC);
    return 0;
}

//Initialize matrixA and matrixB with random values
void initializeMatrix(int r, int c, double matrix[r][c]) { // code provided
    srand(time(NULL)); // seed for the rand function that uses computer clock
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            matrix[i][j] = rand() % 10; // use mod 10 to get smaller numbers from rand()
        }
    }
}

//thread function: multiply row of A by columns of B --> row of C
void* multiplyRow(void* arg) { // code provided
    int i = (int)(void*)arg; // typecast the arg back to an int i
    for (int j = 0; j < L; j++) {
        double temp = 0;
        for (int k = 0; k < M; k++) {
            temp += matrixA[i][k] * matrixB[k][j];
        }
        matrixC[i][j] = temp;
    }
    return 0;
}

//Print matrices
void printMatrix(int r,int c, double matrix[r][c]) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
        printf("%.0lf ", matrix[i][j]);
        printf("\n");
    }
}
