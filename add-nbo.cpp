#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t file_read(char* fileName){
    uint32_t A;
    FILE* file = fopen(fileName, "rb");
    if(fread(&A, 1, sizeof(uint32_t), file) == 0){
        fclose(file);
        printf("Error\n");
        exit(1);
    }
    fclose(file);

    return A;
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 0;
    }
    uint32_t a, b, sum;

    a = file_read(argv[1]);
    b = file_read(argv[2]);

    a = ntohl(a);
    b = ntohl(b);

    sum = a + b;

    printf("%d(0x%2x) + %d(0x%2x) = %d(0x%2x)\n", a, a, b, b, sum, sum);

    return 0;
}
