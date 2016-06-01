//Ravi Chaganti
//ID: 260469339
#include<stdio.h>
#include <stdlib.h>
char input;
int ascii;
void clear (void) {                                             //this method clears the buffer system to get rid of the \n
        while ((input = getchar()) != '\n' && input != EOF);
}

void main(int argc, char *argv[]) {

        if (argc == 1) {                                //if there is only 1 argument passed through command line
                printf("Welcome to ASCII: ");
                while (1) {                             //infinite loop
                        printf("\n--> ");
                        input = getchar();
                        ascii = input;
                        clear();
                        if (ascii == 48) {              //if input's ascii code is 48 (i.e. 0), then exit the infinite loop and the code.
                                printf("ASCII: 48");
                                printf("\nDone\n");
                                exit(0);
                        }
                        printf("ASCII: %d",ascii);
                }
        }

        else {                                          //for passing multiple arguments in command line
                int i = 1;
                for (i; i <  argc; i++) {
                        printf("-->%c\n", *argv[i]);
                        printf("ASCII: ");
                        printf("%d\n", *argv[i]);
                }
                printf("Done\n");
        }
}

