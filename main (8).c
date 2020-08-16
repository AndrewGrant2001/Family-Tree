/******************************************************************************
Name: Andrew Grant
Course: COMP-1410
Assignment 3 - Family Tree Program
*******************************************************************************/

//standard libaries included for written code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <errno.h>
#include <conio.h>

#define SIZE 25 //can be changed to any size. Set lower for faster run times.
#define SIZESecondary 20 //can be changed to any size. Set lower for faster run times.

//struct to keep each persons information
typedef struct {
    char firstName[SIZESecondary];
    char lastName[SIZESecondary];
    int age;
    int aliveOrDead; //0 is dead, 1 is alive
    char partner[SIZESecondary];
    char parent1[SIZESecondary];
    char parent2[SIZESecondary];
    char child1[SIZESecondary];
    char child2[SIZESecondary];
    char child3[SIZESecondary];
    char child4[SIZESecondary];
    char child5[SIZESecondary];
}Person;

void addPerson(Person arr_Person[SIZE]); //function to add person

void editPerson(Person arr_Person[SIZE]); //function to edit person

void printPeople(Person arr_Person[SIZE]); //function to print all people

void deletePeople(Person arr_Person[SIZE]); //function to delete a person

void addPartner(Person arr_Person[SIZE]); //function to add a partner relationship

void addParent(Person arr_Person[SIZE]); //function to add a child, parent relationship

void printRelations(Person arr_Person[SIZE]); //function to print relations of person

void loadFile(Person arr_Person[SIZE]); //function to load family tree

void printToFile(Person arr_Person[SIZE]); //function to print family tree to file

int main()
{
    Person arr_Person[SIZE];//creating an array of structures
    char input[1];//for menu inputting
    
    /*This loop is to initalize all char arrays to null character
      Also puts age and alive or dead to impossible numbers used for outputting and checking*/
    for(int i = 0; i < SIZE; i++){
        arr_Person[i].age = -122;
        arr_Person[i].aliveOrDead = -22;
        
        for(int j = 0; j < SIZESecondary; j++){
                arr_Person[i].firstName[j] = '\0';
                arr_Person[i].lastName[j] = '\0';
                arr_Person[i].partner[j] = '\0';
                arr_Person[i].parent1[j] = '\0';
                arr_Person[i].parent2[j] = '\0';
                arr_Person[i].child1[j] = '\0';
                arr_Person[i].child2[j] = '\0';
                arr_Person[i].child3[j] = '\0';
                arr_Person[i].child4[j] = '\0';
                arr_Person[i].child5[j] = '\0';
        }
    }
    
    printf("Welcome to 'The Family Tree' Program\n");//welcome message
    
    //do loop to run until user wishes to exit program
    do {
        //system("clear"); used to clear screen after each loop through
        //outputting the Menu
        puts("Menu: ");
        puts("A: Add a new Person");
        puts("B: Edit a Person's info");
        puts("C: Set a Person as a parent of another person");
        puts("D: Set a Person as a partner of another person");
        puts("E: List all People");
        puts("F: Print all relationships of a person");
        puts("G: Remove a Person");
        puts("H: Save the family tree into a file"); 
        puts("I: Load a family tree from a file"); 
        puts("J: To Exit Program");
        puts("---------------------------");
        
        scanf("\n%s", input);//receives menu selection from user, only uses first character
        
        //if statements to call proper function
        if (*input == 'A' || *input == 'a'){
            addPerson(arr_Person);//calling function to add person
        }
        else if (*input == 'B' || *input == 'b') {
            editPerson(arr_Person);//calling function to edit person
        }
        else if (*input == 'C' || *input == 'c'){
            addParent(arr_Person);//calling function to add parent relationship
        }
        else if (*input == 'D' || *input == 'd'){
            addPartner(arr_Person);//calling function to add partner relationship
        }
        else if (*input == 'E' || *input == 'e') {
            printPeople(arr_Person);//calling function to print all people
        }
        else if (*input == 'F' || *input == 'f'){
            printRelations(arr_Person);//calling function to print relations of person
        }
        else if (*input == 'G' || *input == 'g'){
            deletePeople(arr_Person);//calling function to delete person
        }
        else if (*input == 'H' || *input == 'h'){
            printToFile(arr_Person);//calling function to print to file
        }
        else if (*input == 'I' || *input == 'i'){
            loadFile(arr_Person);//calling function to load file of info
        }
        else if (*input == 'J' || *input == 'j'){
            goto Exit;//using goto to exit program
        }
        else {
            printf("Invalid Input of %c\n", *input);//if invalid character entered
        }
    } while(1);
    
    Exit:
        puts("Have a Good Day!\n");//exit message
}

void printToFile(Person arr_Person[SIZE]){
    //declaring variables
    FILE *outFile;
    char fileName[10];
    
    //prompt
    printf("Enter file to be printed to: ");
    scanf("%s", fileName);
    
    outFile = fopen(fileName, "w"); //opening file
    
    //if to catch if file is not found
    if(outFile == NULL)
    {
       printf("The Text file cannot be written to!\n");
    }
    else{
        //loop to output family tree to file
        for(int i = 0; i < SIZE; i++){
            if (arr_Person[i].age != -122){
                fprintf(outFile, "%s %s %d %d Parent: ", arr_Person[i].firstName, arr_Person[i].lastName, 
                                       arr_Person[i].age, arr_Person[i].aliveOrDead);
                if (arr_Person[i].parent1[0] != '\0'){
                    fprintf(outFile, "%s , ", arr_Person[i].parent1);
                }
                else {
                    fprintf(outFile, "%s , ", "None");
                }
                if (arr_Person[i].parent2[0] != '\0'){
                    fprintf(outFile, "%s Child: ", arr_Person[i].parent2);
                }
                else {
                    fprintf(outFile, "%s Child: ", "None");
                }
                if (arr_Person[i].child1[0] != '\0'){
                    fprintf(outFile, "%s , ", arr_Person[i].child1);
                }
                else {
                    fprintf(outFile, "%s , ", "None");
                }
                if (arr_Person[i].child2[0] != '\0'){
                    fprintf(outFile, "%s , ", arr_Person[i].child2);
                }
                else {
                    fprintf(outFile, "%s , ", "None");
                }
                if (arr_Person[i].child3[0] != '\0'){
                    fprintf(outFile, "%s , ", arr_Person[i].child3);
                }
                else {
                    fprintf(outFile, "%s , ", "None");
                }
                if (arr_Person[i].child4[0] != '\0'){
                    fprintf(outFile, "%s , ", arr_Person[i].child4);
                }
                else {
                    fprintf(outFile, "%s , ", "None");
                }
                if (arr_Person[i].child5[0] != '\0'){
                    fprintf(outFile, "%s Partner: ", arr_Person[i].child5);
                }
                else {
                    fprintf(outFile, "%s Partner: ", "None");
                }
                if (arr_Person[i].partner[0] != '\0'){
                    fprintf(outFile, "%s \n", arr_Person[i].partner);
                }
                else{
                    fprintf(outFile, "%s \n", "None");
                }
            }
        }
        fprintf(outFile, "End");//used when loading file to stop loading
    }
    fclose(outFile);//close file
}

void loadFile(Person arr_Person[SIZE]){
    //declaring variables
    FILE *f1;
    char fileName[10];
    
    //prompt
    printf("Enter file to be loaded: ");
    scanf("%s", fileName);
    
    f1 = fopen(fileName, "r");//opening file
    
    //if statement to catch error
    if(f1 == NULL)
    {
       printf("Error: %s\n", strerror(errno));
    }
    else {
        //loop to load a family tree into system
        for(int i = 0; i < SIZE; i++){
            if(arr_Person[i].firstName[0] == '\0'){
                fscanf(f1, "%s %s %d %d Parent: %s , %s Child: %s , %s , %s , %s , %s Partner: %s", 
                arr_Person[i].firstName, arr_Person[i].lastName, 
                &arr_Person[i].age, &arr_Person[i].aliveOrDead, 
                arr_Person[i].parent1, arr_Person[i].parent2, 
                arr_Person[i].child1, arr_Person[i].child2,
                arr_Person[i].child3, arr_Person[i].child4,
                arr_Person[i].child5, arr_Person[i].partner);
                if(!strncmp(arr_Person[i].firstName, "End", 3)){
                    goto Next;
                }
            }
        }
        
        //if none is retrieved clear the array to null characters
        Next:
        for(int i = 0; i < SIZE; i++){
            if(!strncmp(arr_Person[i].partner, "None", 4)){
                for(int j = 0; j < SIZESecondary; j++)
                    arr_Person[i].partner[j] = '\0';
            }
            if(!strncmp(arr_Person[i].parent1, "None", 4)){
                for(int j = 0; j < SIZESecondary; j++)
                    arr_Person[i].parent1[j] = '\0';
            }
            if(!strncmp(arr_Person[i].parent2, "None", 4)){
                for(int j = 0; j < SIZESecondary; j++)
                    arr_Person[i].parent2[j] = '\0';
            }
            if(!strncmp(arr_Person[i].child1, "None", 4)){
                for(int j = 0; j < SIZESecondary; j++)
                    arr_Person[i].child1[j] = '\0';
            }
            if(!strncmp(arr_Person[i].child2, "None", 4)){
                for(int j = 0; j < SIZESecondary; j++)
                    arr_Person[i].child2[j] = '\0';
            }
            if(!strncmp(arr_Person[i].child3, "None", 4)){
                for(int j = 0; j < SIZESecondary; j++)
                    arr_Person[i].child3[j] = '\0';
            }
            if(!strncmp(arr_Person[i].child4, "None", 4)){
                for(int j = 0; j < SIZESecondary; j++)
                    arr_Person[i].child4[j] = '\0';
            }
            if(!strncmp(arr_Person[i].child5, "None", 4)){
                for(int j = 0; j < SIZESecondary; j++)
                    arr_Person[i].child5[j] = '\0';
            }
            if(!strncmp(arr_Person[i].firstName, "End", 3)){
                for(int x = i; x < SIZE; x++){
                    arr_Person[x].age = -122;
                    arr_Person[x].aliveOrDead = -22;
                
                    for(int j = 0; j < SIZESecondary; j++){
                            arr_Person[x].firstName[j] = '\0';
                            arr_Person[x].lastName[j] = '\0';
                            arr_Person[x].partner[j] = '\0';
                            arr_Person[x].parent1[j] = '\0';
                            arr_Person[x].parent2[j] = '\0';
                            arr_Person[x].child1[j] = '\0';
                            arr_Person[x].child2[j] = '\0';
                            arr_Person[x].child3[j] = '\0';
                            arr_Person[x].child4[j] = '\0';
                            arr_Person[x].child5[j] = '\0';
                    }
                }
            }
        }
        
        //output
        puts("People loaded into system: (relationships are loaded as well)");
        puts("-------------------------------------------------------------");
        printPeople(arr_Person);
        puts("-------------------------------------------------------------");
        fclose(f1);
    }
}

void addParent(Person arr_Person[SIZE]){
    //declaring variables
    char name[SIZESecondary], name2[SIZESecondary];
    
    //loop to initalize to null characters
    for(int i = 0; i < SIZE; i++){
        name[i] = '\0';
        name2[i] = '\0';
    }
    
    //variable and prompt
    int j;
    printf("Enter child's first name: ");
    scanf("%s", name);
    
    //loop to find spot in struct
    for(j = 0; j < SIZE; j++){
        if(strcmp(name, arr_Person[j].firstName) == 0){
            break;
        }
    }
    
    //second prompt
    int i;
    printf("Enter their parent's first name: ");
    scanf("%s", name2);
    
    //if statement to catch dublicate name entering
    if (!strcmp(name, name2)){
        puts("You cannot enter the same name twice!");
    }
    else {
        //loop to find second person in struct
        for(i = 0; i < SIZE; i++){
            if(strcmp(name2, arr_Person[i].firstName) == 0){
                break;
            }
        }
        
        //if statement to catch error
        if((j == SIZE) || (i == SIZE)){
            puts("At least one Person was not found in storage!");
        }
        else{
            if((arr_Person[j].parent1[0] != '\0' && arr_Person[j].parent2[0] != '\0') || 
                (arr_Person[i].child1[0] != '\0' && arr_Person[i].child2[0] != '\0' &&
                arr_Person[i].child3[0] != '\0' && arr_Person[i].child4[0] != '\0' &&
                arr_Person[i].child5[0] != '\0')){
                    puts("Storage is full for at least one person.");
            }
            else{
                if(arr_Person[j].parent1[0] == '\0'){
                    for(int x = 0; x < SIZESecondary; x++){
                        arr_Person[j].parent1[x] = name2[x];
                    }
                    printf("%s is %s's child and %s is %s parent.\n", name, name2, name2, name);
                }
                else {
                    for(int x = 0; x < SIZESecondary; x++){
                        arr_Person[j].parent2[x] = name2[x];
                    }
                    printf("%s is %s's child and %s is %s parent.\n", name, name2, name2, name);
                }
                if(arr_Person[i].child1[0] == '\0'){
                    for(int x = 0; x < SIZESecondary; x++){
                        arr_Person[i].child1[x] = name[x];
                    }
                }
                else if(arr_Person[i].child2[0] == '\0'){
                    for(int x = 0; x < SIZESecondary; x++){
                        arr_Person[i].child2[x] = name[x];
                    }
                }
                else if(arr_Person[i].child3[0] == '\0'){
                    for(int x = 0; x < SIZESecondary; x++){
                        arr_Person[i].child3[x] = name[x];
                    }
                }
                else if(arr_Person[i].child4[0] == '\0'){
                    for(int x = 0; x < SIZESecondary; x++){
                        arr_Person[i].child4[x] = name[x];
                    }
                }
                else{
                    for(int x = 0; x < SIZESecondary; x++){
                        arr_Person[i].child5[x] = name[x];
                    }
                }
            }
        }
    }
}

void printRelations(Person arr_Person[SIZE]){
    //declaring variables
    char name[SIZESecondary];
    int j; 
    
    //prompt
    printf("Enter person's name: ");
    scanf("%s", name);
    
    //loop to find name in struct
    for(j = 0; j < SIZE; j++){
        if(strcmp(name, arr_Person[j].firstName) == 0){
            break;
        }
    }
    
    //if statements to print all relations of person
    if (j != SIZE){
        puts("--------------------------");
        if (arr_Person[j].partner[0] != '\0'){
            printf("%s is partner of %s\n", arr_Person[j].firstName, arr_Person[j].partner);
        }
        else{
            printf("%s has no partner in the system.\n", arr_Person[j].firstName);
        }
        if (arr_Person[j].child1[0] != '\0'){
            printf("%s is %s's child.\n", arr_Person[j].child1, arr_Person[j].firstName);
        }
        if (arr_Person[j].child2[0] != '\0'){
            printf("%s is %s's child.\n", arr_Person[j].child2, arr_Person[j].firstName);
        }
        if (arr_Person[j].child3[0] != '\0'){
            printf("%s is %s's child.\n", arr_Person[j].child3, arr_Person[j].firstName);
        }
        if (arr_Person[j].child4[0] != '\0'){
            printf("%s is %s's child.\n", arr_Person[j].child4, arr_Person[j].firstName);
        }
        if (arr_Person[j].child5[0] != '\0'){
            printf("%s is %s's child.\n", arr_Person[j].child5, arr_Person[j].firstName);
        }
        if (arr_Person[j].child1[0] == '\0' && arr_Person[j].child2[0] == '\0' && 
            arr_Person[j].child3[0] == '\0' && arr_Person[j].child4[0] == '\0' &&
            arr_Person[j].child5[0] == '\0'){
            printf("%s has no children in the system.\n", arr_Person[j].firstName);  
        }
        if (arr_Person[j].parent1[0] != '\0'){
            printf("%s is %s's parent.\n", arr_Person[j].parent1, arr_Person[j].firstName);
        }
        if (arr_Person[j].parent2[0] != '\0'){
            printf("%s is %s's parent.\n", arr_Person[j].parent2, arr_Person[j].firstName);
        }
        if(arr_Person[j].parent1[0] == '\0' && arr_Person[j].parent2[0] == '\0'){
            printf("%s has no parents in the system.\n", arr_Person[j].firstName);
        }
        puts("--------------------------");
    }
    else {
        puts("Person not found in storage.");
    }
}

void addPartner(Person arr_Person[SIZE]){
    //declaring variables
    char name[SIZESecondary], name2[SIZESecondary];
    
    //loop to go to null character
    for(int i = 0; i < SIZE; i++){
        name[i] = '\0';
    }
    
    int j;
    
    //prompt
    printf("Enter first person's name: ");
    scanf("%s", name);
    
    //finding in struct
    for(j = 0; j < SIZE; j++){
        if(strcmp(name, arr_Person[j].firstName) == 0){
            break;
        }
    }
    
    int i;
    
    //second prompt
    printf("Enter second person's name: ");
    scanf("%s", name2);
    
    
    //if statement to catch error
    if(!strcmp(name, name2)){
        puts("You cannot enter the same name twice!");
    }
    else {
        for(i = 0; i < SIZE; i++){
            if(strcmp(name2, arr_Person[i].firstName) == 0){
                break;
            }
        }
        
        if((j == SIZE) || (i == SIZE)){
            puts("At least one Person was not found in storage!");
        }
        else {
            for(int x = 0; x < SIZESecondary; x++){
                arr_Person[j].partner[x] = name2[x];
                arr_Person[i].partner[x] = name[x];
            }
            printf("%s is partner of %s and vice versa.\n", arr_Person[i].partner, arr_Person[j].partner);
        }
    }
}

void deletePeople(Person arr_Person[SIZE]){
    //declaring variables
    char name[SIZESecondary], temp[SIZESecondary];
    
    //array to null character
    for(int i = 0; i < SIZE; i++){
        name[i] = '\0';
    }
    
    int j, x;
    
    //prompt
    printf("Enter person's name to be removed: ");
    scanf("%s", name);
    
    //loop to empty all information of the person in system
    for(j = 0; j < SIZE; j++){
        if(strcmp(name, arr_Person[j].firstName) == 0){
            for(x = 0; x < SIZE; x++){
                if (strcmp(arr_Person[x].partner, arr_Person[j].firstName) == 0){
                    for(int i = 0; i < SIZESecondary; i++)
                        arr_Person[x].partner[i] = '\0';
                }
                if (strcmp(arr_Person[x].child1, arr_Person[j].firstName) == 0){
                    for(int i = 0; i < SIZESecondary; i++)
                        arr_Person[x].child1[i] = '\0';
                }
                if (strcmp(arr_Person[x].child2, arr_Person[j].firstName) == 0){
                    for(int i = 0; i < SIZESecondary; i++)
                        arr_Person[x].child2[i] = '\0';
                }
                if (strcmp(arr_Person[x].child3, arr_Person[j].firstName) == 0){
                    for(int i = 0; i < SIZESecondary; i++)
                        arr_Person[x].child3[i] = '\0';
                }
                if (strcmp(arr_Person[x].child4, arr_Person[j].firstName) == 0){
                    for(int i = 0; i < SIZESecondary; i++)
                        arr_Person[x].child4[i] = '\0';
                }
                if (strcmp(arr_Person[x].child5, arr_Person[j].firstName) == 0){
                    for(int i = 0; i < SIZESecondary; i++)
                        arr_Person[x].child5[i] = '\0';
                }
                if (strcmp(arr_Person[x].parent1, arr_Person[j].firstName) == 0){
                    for(int i = 0; i < SIZESecondary; i++)
                        arr_Person[x].parent1[i] = '\0';
                }
                if (strcmp(arr_Person[x].parent2, arr_Person[j].firstName) == 0){
                    for(int i = 0; i < SIZESecondary; i++)
                        arr_Person[x].parent2[i] = '\0';
                }
            }
            
            for(int i = 0; i < SIZESecondary; i++){
                arr_Person[j].firstName[i] = '\0';
                arr_Person[j].lastName[i] = '\0';
                arr_Person[j].partner[i] = '\0';
                arr_Person[j].parent1[i] = '\0';
                arr_Person[j].parent2[i] = '\0';
                arr_Person[j].child1[i] = '\0';
                arr_Person[j].child2[i] = '\0';
                arr_Person[j].child3[i] = '\0';
                arr_Person[j].child4[i] = '\0';
                arr_Person[j].child5[i] = '\0';
            }
            
            arr_Person[j].age = -122;
            arr_Person[j].aliveOrDead = -22;
            break;
        }
    }
    
    //if to catch error or successfully done
    if(j == SIZE){
        puts("Person was not found in storage!");
    }
    else {
        puts("Info deleted successfully!");
    }
}

void addPerson(Person arr_Person[SIZE]){
    //declaring variables
    int num;
    
    //finding first empty spot in struct
    for(num = 0; num < SIZE; num++){
        if(arr_Person[num].age == -122){
            break;
        }
    }
    
    //prompts to follow
    printf("Enter a First Name: ");
    scanf("%s", arr_Person[num].firstName);
    
    printf("Enter a Last Name: ");
    scanf("%s", arr_Person[num].lastName);
    
    do {
        printf("Enter a Age: ");
        scanf("%d", &arr_Person[num].age);
    }while(arr_Person[num].age < 0 || arr_Person[num].age > 130);
    
    do {
        printf("Enter a Alive (1) or Dead (0): ");
        scanf("%d", &arr_Person[num].aliveOrDead);
    }while(arr_Person[num].aliveOrDead != 1 && arr_Person[num].aliveOrDead != 0);
    
    //outputting what was entered
    printf("You have entered the following information: \n");
    printf("First Name: %s\nLast Name: %s\nAge: %d\nAlive or Dead: %s\n", 
            arr_Person[num].firstName, arr_Person[num].lastName, arr_Person[num].age, 
            arr_Person[num].aliveOrDead == 1 ? "Alive" : "Dead");
}

void editPerson(Person arr_Person[SIZE]){
    //declaring variables
    char name[SIZESecondary];
    
    //array to null characters
    for(int i = 0; i < SIZE; i++){
        name[i] = '\0';
    }
    
    int j;
    
    //prompt
    printf("Enter person's first name to edit info: ");
    scanf("%s", name);
    
    //loop to edit a persons information
    for(j = 0; j < SIZE; j++){
        if (strcmp(name, arr_Person[j].firstName) == 0){
            int track;
            puts("You are changing the following persons information: ");
            printf("First Name: %s\nLast Name: %s\nAge: %d\nAlive or Dead: %s\n", 
                    arr_Person[j].firstName, arr_Person[j].lastName, arr_Person[j].age, 
                    arr_Person[j].aliveOrDead == 1 ? "Alive" : "Dead");
            
            do {
                puts("-------------------------------");
                puts("Enter 1 to change First Name");
                puts("Enter 2 to change Last Name");
                puts("Enter 3 to change Age");
                puts("Enter 4 to change Alive or Dead");
                puts("Enter 5 to Save Changes/Exit");
                puts("-------------------------------");
                scanf("%d", &track);
                puts("-------------------------------");
                
                if (track == 1){
                    printf("Enter new First Name: ");
                    scanf("%s", arr_Person[j].firstName);
                }
                else if (track == 2){
                    printf("Enter new Last Name: ");
                    scanf("%s", arr_Person[j].lastName);
                }
                else if (track == 3){
                    do {
                        printf("Enter a Age: ");
                        scanf("%d", &arr_Person[j].age);
                    }while(arr_Person[j].age < 0 || arr_Person[j].age > 130);
                }
                else if (track == 4){
                    do {
                        printf("Enter a Alive (1) or Dead (0): ");
                        scanf("%d", &arr_Person[j].aliveOrDead);
                    }while(arr_Person[j].aliveOrDead != 1 && arr_Person[j].aliveOrDead != 0);
                }
                else if (track == 5){
                    continue;
                }
                else {
                    puts("Invalid Input");
                }
            }while(track != 5);
            
            puts("This is the new Information: ");
            puts("-------------------------------");
            printf("First Name: %s\nLast Name: %s\nAge: %d\nAlive or Dead: %s\n", 
                    arr_Person[j].firstName, arr_Person[j].lastName, arr_Person[j].age, 
                    arr_Person[j].aliveOrDead == 1 ? "Alive" : "Dead");
            puts("-------------------------------");
            break;
        }
    }
    if (j == SIZE){
        puts("No information to be changed in location");
    }
}

void printPeople(Person arr_Person[SIZE]){
    //loop to print all people in system in a table format
    for(int i = 0; i < SIZE; i++){
        if (i == 0){
            puts("|  #  | Name                   |   Age   | Alive or Dead |");
        }
        if (arr_Person[i].age != -122){
        printf("| %2d  | %10s %10s  |   %2d    |     %5s     |\n", i+1, 
                arr_Person[i].firstName, arr_Person[i].lastName, arr_Person[i].age, 
                arr_Person[i].aliveOrDead == 1 ? "Alive" : "Dead");
        }
    }
}







