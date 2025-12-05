#include <stdio.h>
#include <stdlib.h>

int *GetMatrix(int *numRows, int *numCols) {
    int *matrix;

    scanf("%d %d", numRows, numCols);

   matrix = (int *)malloc((*numRows) * (*numCols) * sizeof(int));
    if (matrix == NULL) {
        printf("Allocation FAILED.\n");
        exit(0);
    }

     for (int rowIndex = 0; rowIndex < *numRows; rowIndex++) {
        for (int colIndex = 0; colIndex < *numCols; colIndex++) {
            scanf("%d", &matrix[rowIndex * (*numCols) + colIndex]);
        }
    }

    return matrix;
}

int main() {
    int *matrixData;
    int numRows, numCols;

    matrixData = GetMatrix(&numRows, &numCols);

   for (int rowIndex = 0; rowIndex < numRows; rowIndex++) {
        for (int colIndex = 0; colIndex < numCols; colIndex++) {
            printf("%d ", matrixData[rowIndex * numCols + colIndex]);
        }
        printf("\n");
    }

     free(matrixData);
    matrixData = NULL;

    return 0;
}
