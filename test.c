#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char hexValue[] = {
            0x48, 0x1, 0x65, 0x6c, 0x6c, 0x9, 0x6f, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x21,  // Hello World!
            0xA, // Newline
            0x7F, 0xFF, 0x20, 0x47, 0x6f, 0x6f, 0x64, 0x20, 0x42, 0x79, 0x65, 0x20, 0x57, 0x6f, 0x72, 0x6c, 0x64, 0x5, 0x2e, // Good Bye World.
            0xA, 0xA, 0x0, // Newlines and null terminator
    };

    if ((fd = open("test.txt", O_RDWR | O_CREAT, 0644)) < 0) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }

    if (write(fd, hexValue, strlen(hexValue)) != strlen(hexValue)) {
        fprintf(stderr, "Error writing to file\n");
    }
    for (int i = 0; i < strlen(hexValue); i++) {
        hexValue[i] = 'A';
    }
    hexValue[0] = 'X'; // cuz why not
    if (write(fd, hexValue, strlen(hexValue)) != strlen(hexValue)) {
        fprintf(stderr, "Error writing to file\n");
    }

    printf("Wrote to file\n");

    close(fd);
    return 0;

}