#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 15
#define MAX_POSSIBLE_VALUE 15

int main() {
    srand(time(NULL));
    int *array = (int*) malloc(sizeof(int)*ARRAY_SIZE);
    int *countArray = (int*) malloc(sizeof(int)*ARRAY_SIZE-1);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = 1 + rand() / ((RAND_MAX+1u)/MAX_POSSIBLE_VALUE);
        countArray[i] = 0;
        printf("%d ", array[i]);
    }
    printf("\n");
    //populate counted array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        countArray[array[i]]++;
    }

    //print counted array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", countArray[i]);
    }
    printf("\n");

    //build sorted array
    register int j = 0;
    for (register int i = 0; i < ARRAY_SIZE; i++) {
        if (countArray[i]  != 0) {
            int temp = countArray[i];
            while (temp-- != 0)
                array[j++] = i;
        }
    }

    //print sorted array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
