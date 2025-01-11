#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
#define BUFSIZE 256

    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    char perm[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-_/";
    char *fileName = argv[1];    
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    // Ensure that the user supplied a valid file name
    for (int i = 0; i < strlen(fileName); i++) {
        if (strchr(perm, fileName[i]) == NULL) {
            fprintf(stderr, "Invalid file name.\n");
            return -1;
        }
    }
    // Ensure that the file exists
    if (access(fileName, F_OK) == -1) {
        fprintf(stderr, "File does not exist.\n");
        return -1;
    }

    char cmd[BUFSIZE] = {0};
    sprintf(cmd,"wc -c < %s", fileName);
    system(cmd);
}
