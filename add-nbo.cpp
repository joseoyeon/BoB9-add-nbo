#include <stdio.h> // for printf
#include <string.h>
#include <stdint.h>

int main(int argc, char*argv[]) {
    uint32_t n1, n2, sum;
    FILE *file1 = fopen(argv[1], "rb");
    FILE *file2 = fopen(argv[2], "rb");

    if(argc != 3) {
        printf("Usage : %s <filename1> <filename2>\n", argv[0]);
        return 0;
    }

    fread(&n1, sizeof(n1), 1, file1);
    sum = ((n1 & 0xff000000)>> 24) | ((n1 & 0x00ff0000) >> 8) | ((n1& 0x0000ff00) << 8) | ((n1& 0x000000ff) <<24);
    n1 = sum;
    printf("n1=0x%04x\n", n1);

    fread(&n2, sizeof(n2), 1, file2);
    sum = ((n2 & 0xff000000)>> 24) | ((n2 & 0x00ff0000) >> 8) | ((n2& 0x0000ff00) << 8) | ((n2& 0x000000ff) <<24);
    n2 = sum;
    printf("n2=0x%04x\n", n2);

    sum = n2 + n1;
    printf("sum=0x%04x\n", sum);
}
