#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_ARRAY_LENGTH 8

void processArray(int *array, int length) {
    // Example operation: print array
    printf("Array of length %d: ", length);
   /* for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }*/
    printf("\n");
}

int main() {
    FILE *file = fopen("/mnt/c/Users/empire/Downloads/c programs/data.txt", "r");
   /* if (file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }*/

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        int array[MAX_ARRAY_LENGTH];
        int length = 0;
        
        // Tokenize the line and parse integers
        char *token = strtok(line, " ");
        while (token != NULL && length < MAX_ARRAY_LENGTH) {
            array[length++] = atoi(token);
            token = strtok(NULL, " ");
        }
        
        // Process the parsed array
        processArray(array, length);
    }

    fclose(file);
    return 0;
}
