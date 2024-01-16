// main.c
#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include "user.h"

void greetings() {
    printf("\n\n");
    printf("\t\t\t     ****************************************\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *     ----------------------------     *\n");
    printf("\t\t\t     *      WELCOME TO STUDENT LIBRARY      *\n");
    printf("\t\t\t     *     ----------------------------     *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     ****************************************\n");
    printf("\n\n");
    printf("\t\t\t     ****************************************\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *       ------------------------       *\n");
    printf("\t\t\t     *           STUDENT LIBRARY            *\n");
    printf("\t\t\t     *       ------------------------       *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     *       Meerut,Uttar pradesh,India     *\n");
    printf("\t\t\t     *     Email: studentlib@gmail.com      *\n");
    printf("\t\t\t     *     Contact:+91-xxxxxxxxxx           *\n");
    printf("\t\t\t     *                                      *\n");
    printf("\t\t\t     ****************************************\n");
    printf("\n\n\t\t\t             Press any key to continue: ");
}
int main() 

{
    Book* library = NULL;
    int choice,bookId=0,available;
    Book *current;
    char title[50], author[50];
    char username[20], password[20];
    User userInstance;
    greetings();

    printf("\nLibrary Management System Login\n");
    do {
        printf("Enter your username: ");
        scanf("%s", username);
        printf("Enter your password: ");
        scanf("%s", password);

        if (authenticateUser(username, password)) {
            printf("Login successful!\n");

  do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
		 {
            case 1:
               // library = addBook(library);
                 printf("Enter Book ID: ");
                 scanf("%d", &bookId);
                  printf("Enter Title: ");
                  scanf("%s",title);
                 printf("Enter Author: ");
                 scanf("%s", author);
                 printf("Enter Available no.: ");
                 scanf("%d", &available);
              library = addBookSorted(library, bookId, title, author,available);
                break;
            case 2:
                displayBooks(library);
                break;
            case 3:
                searchBook(library);
                break;
            case 4:
                library = deleteBook(library, bookId);
                break;   
            case 5:
                   issueBook(library, &userInstance);
                   break;
            case 6:
                    returnBook(library, &userInstance);
                    break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
               printf("\n\t\t\t\t      ...Invalid Option!...\n");
                printf("\n\t\t\t\t      Press any key to try again: ");
                
         }
    } while (choice != 7);
}

else{
	printf("Invalid username or password. Please try again.\n");
    }
}
while(1);
    return 0;
}
