/* how was this generated? 

can you give me a nice academic example that shows me how to use manipulate 
files in c, specficailly only text files using fgetc, fgets, fscanf for reading
 and fputc, fputs and fprintf for writting? Add a nice menu so I can select
  what option to chose. I want to be able to input the name of the file. 
  
  Do your best!
*/

#include <stdio.h>
#include <stdlib.h>

void readCharByChar(char *filename);
void readLineByLine(char *filename);
void readWordByWord(char *filename);
void writeCharByChar(char *filename);
void writeLineByLine(char *filename);
void writeFormattedText(char *filename);

int main() {
    char filename[100];
    int choice;

    printf("Enter the name of the text file: ");
    scanf("%s", filename);

    do {
        printf("\n===== FILE MANIPULATION MENU =====\n");
        printf("1. Read file (character by character)\n");
        printf("2. Read file (line by line)\n");
        printf("3. Read file (word by word)\n");
        printf("4. Write to file (character by character)\n");
        printf("5. Write to file (line by line)\n");
        printf("6. Write to file (formatted text)\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Consume newline left in the buffer

        switch (choice) {
            case 1:
                readCharByChar(filename);
                break;
            case 2:
                readLineByLine(filename);
                break;
            case 3:
                readWordByWord(filename);
                break;
            case 4:
                writeCharByChar(filename);
                break;
            case 5:
                writeLineByLine(filename);
                break;
            case 6:
                writeFormattedText(filename);
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}

// Function to read file character by character
void readCharByChar(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    char ch;
    printf("\n--- File Content (Character by Character) ---\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

// Function to read file line by line
void readLineByLine(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    char line[256];
    printf("\n--- File Content (Line by Line) ---\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

// Function to read file word by word
void readWordByWord(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    char word[50];
    printf("\n--- File Content (Word by Word) ---\n");
    while (fscanf(file, "%49s", word) == 1) {
        printf("%s ", word);
    }
    printf("\n");

    fclose(file);
}

// Function to write to file character by character
void writeCharByChar(char *filename) {
    FILE *file = fopen(filename, "a"); // Append mode to keep old content
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    char ch;
    printf("Enter characters (Press ENTER to stop):\n");
    while ((ch = getchar()) != '\n') {
        fputc(ch, file);
    }
    fputc('\n', file); // Add newline after input

    fclose(file);
}

// Function to write to file line by line
void writeLineByLine(char *filename) {
    FILE *file = fopen(filename, "a"); // Append mode
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    char line[256];
    printf("Enter a line of text: ");
    fgets(line, sizeof(line), stdin);
    fputs(line, file);

    fclose(file);
}

// Function to write formatted text using fprintf
void writeFormattedText(char *filename) {
    FILE *file = fopen(filename, "a"); // Append mode
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    char name[50];
    int age;
    float gpa;

    printf("Enter name: ");
    scanf("%49s", name);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter GPA: ");
    scanf("%f", &gpa);

    fprintf(file, "Name: %s, Age: %d, GPA: %.2f\n", name, age, gpa);

    fclose(file);
}
