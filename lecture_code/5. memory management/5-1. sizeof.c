#include <stdio.h>

// sizeof(arg): give size of arg in bytes 
// NOT number of elements

// short arr[]: equivalent to short arr*, as argument

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsizeof-array-argument"
void mystery(short arr[], int len){
    printf("%d ", len);
    printf("%zu\n", sizeof(arr)); // array decay to pointer
}
#pragma GCC diagnostic pop

int main(){
    // 1 bit = 1b, 8b = 1 byte
    // shorts: 16b (2 bytes), pointers: 64b (8 bytes) regardless of contents
    short nums[] = {1, 2, 3, 99, 100};
    // sizeof(arg) returns size_t, use `%zu`: size_t unsigned
    printf("%zu ", sizeof(nums)); // total array size 
    mystery(nums, sizeof(nums) / sizeof(short)); // # elements 
    return 0;
}