#include <stdio.h>

//function prototype
void swapValue(int *a, int *b, int *c);
void swapArray(int *a, int *b, int size); 


int main() {
    int a = 1, b = 2, c = 3;
    printf("Before swap function: a=%d, b=%d, c=%d\n", a, b, c);
    swapValue(&a,&b,&c);
    printf("After swap function: a=%d, b=%d, c=%d\n", a, b, c);

    int arrayA[10] = {1,2,3,4,5,6,7,8,9,10}, arrayB[10] = {11,12,13,14,15,16,17,18,19,20};
    swapArray(arrayA, arrayB, 10);

    for(int i=0; i<10; i++){
        printf("%d ", arrayA[i]);
    }
    printf("\n");
    for(int i=0; i<10; i++){
        printf("%d ", arrayB[i]);
    }
    return 0;
}

void swapValue(int *a, int *b, int *c){
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}
void swapArray(int *a, int *b, int size){
    int temp;
    for(int i=0; i<size; i++){
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}