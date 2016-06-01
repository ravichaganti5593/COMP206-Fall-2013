//Ravi Chaganti
//ID: 260469339

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char selection;
char input[50];			//temporary 1d array 
char matrix[50][50];		//2d matrix
char transposition[2500];	//2d matrix transposed to 1d array
char encryptArray[2500];	//encrypted array
char decryptArray[2500];	//decrypted array
int i;
int j;
int k;
int number;
int number1;


void clear(void) {                                                              //this method clears the buffer system to get rid of the \n
        while ((selection = getchar()) != '\n' && selection != EOF);
}

void initialize() {                                 //this method initializes input[50], matrix[50][50], transposition[2500], encryptArray[2500] and decryptArray[2500]
        for (i = 0; i < 50; i++) {
                input[i] = ' ';
                for (j = 0; j < 50; j++) {
                        matrix[j][i] = ' ';
                }
        }
        for (i = 0; i < 2500; i++) {
                transposition[i] = ' ';
                encryptArray[i] = ' ';
                decryptArray[i] = ' ';
        }
}
void inputText() {                      //this method takes input and stores the characters in the 2d matrix
        clear();
        i = 0;
        while (i < 50) {
                printf("Enter text: ");
                gets(input);
                if (strcmp(input,"\0") == 0) {          //checks if input is enter, then it will break the while loop and go back to the main menu
                        break;
                }
                else {
                        for (j = 0; j < 50; j++) {
                                matrix[j][i] = input[j];            //stores characters from the temporary input[50] to the 2d matrix[50][50]
                                input[j] = ' ';                     //initializes again with blank spaces
                        }
                }
                i++;
        }
}

void transpose() {                          //this method will transpose the 2d matrix[50][50] into a 1d array of transposition[2500]
        int i = 0;
        while (i < 2500) {
                for (j = 0; j < 50; j++) {
                        for (k = 0; k < 50; k++) {
                                transposition[i] = matrix[j][k];
                                i++;
                        }
                }
        }
}

void encrypt() {                        //this method will encrypt the 1d array of transposition[2500] by a number entered by the user
        transpose();            //calling the transpose method
        printf("Enter a number to operate the Grid Caesar Cipher: ");
        scanf("%d", &number);
        int fromZero;
        int temp;

        for (i = 0; i < 2500; i++) {
            if (transposition[i] > 96 && transposition[i] < 123) {      //if element is a lower case alphabet
                fromZero = transposition[i] - 'a';
                temp = (fromZero + number) % 26;
                encryptArray[i] = temp + 'a';
            }
            else if (transposition[i] > 64 && transposition[i] < 91) {     //if element is an upper case alphabet
                fromZero = transposition[i] - 'A';
                temp = (fromZero + number) % 26;
                encryptArray[i] = temp + 'A';
            }
        }
        printf("\nGrid Caesar Cipher: \n ================= \n");
        for (i = 0; i < 2500; i++) {
                printf("%c", encryptArray[i]);              //displays all the elements in the encryptArray[2500]
        }
}

void decrypt() {                                    //this method will decrypt 1d encryptArray[2500] by a number entered by the user
	for (i = 0; i < 50; i++) {
		for (j = 0; j < 50; j++) {
			matrix[j][i] = ' ';                     //this will initialize the 2d matrix[50][50] again with blank spaces
		}
	}
    printf("Enter a number to decrypt: ");
    scanf("%d",&number1);
    int fromZero, temp;

    for (i = 0; i < 2500; i++) {
        if (encryptArray[i] > 96 && encryptArray[i] < 123) {        //if element is a lower case alphabet
            fromZero = encryptArray[i] + 7;
            temp = (fromZero - number1) % 26;
            decryptArray[i] = temp + 'a';
        }
        else if (encryptArray[i] > 64 && encryptArray[i] < 91) {    //if element is an upper case alphabet
            fromZero = encryptArray[i] + 'A';
            temp = (fromZero - number1) % 26;
            decryptArray[i] = temp + 'A';
        }
    }

    i = 0;
    while(i < 2500) {                                 //this is to convert the 1d decryptArray[2500] back to the 2d matrix[50][50]
        for (j = 0; j < 50; j++) {
            for (k = 0; k < 50; k++) {
                matrix[j][k] = decryptArray[i];
                i++;
            }
        }
    }
    for (i = 0; i < 50; i++) {
        for (j = 0; j < 50; j++) {
            printf("%c",matrix[j][i]);      //prints out the 2d matrix[50][50] after decryption
        }
        printf("\n");
    }
}


void main() {

        while (1) {			//running an infinite loop

                printf("\nMAIN MENU\n========");
                printf("\n1. Input Text\n2. Encrypt\n3. Decrypt\n4. Exit\n");
                printf("Selection: ");
                scanf("%c",&selection);

                if (selection == '1') {
                        initialize();       //calls the initialize method
                        inputText();        //calls the inputText method
                }

                else if (selection == '2') {
                     encrypt();             //calls encrypt method
                     clear();               //clears buffer
                }

                else if (selection == '3') {
                        decrypt();          //calls the decrypt method
                        clear();            //clears buffer
                }

                else if (selection == '4') {
                        exit(0);            //exits the program
                }

                else {
                        printf("Wrong selection. Press either 1 or 2 or 3 or 4");
                        clear();            //clears buffer
                }
        }
}



