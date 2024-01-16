
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "user.h"
#include<stdlib.h>

//struct User {
//    char username[100];
//    char password[100];
//    int booksIssued;
//    struct User* next;
//};

void displayMenu() {
    printf("\nLibrary Management System\n");
    printf("1. Add a Book\n");
    printf("2. Display Books\n");
    printf("3. Search for a Book\n");
    printf("4. Delete a Book\n");
    printf("5. Issue a Book\n");
    printf("6. return a Book\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

//Book* addBook(Book* library) {
//    Book* newBook = (Book*)malloc(sizeof(Book));
//
//    if (newBook == NULL) {
//        printf("Memory allocation failed.\n");
//        return library;
//    }
//     printf("Enter Book ID: ");
//    scanf("%d", &(newBook->bookId));
//    printf("Enter Title: ");
//    scanf("%s", newBook->title);
//    printf("Enter Author: ");
//    scanf("%s", newBook->author);
////    printf("Enter available Copies: ");
////    scanf("%d", newBook->availableCopies); 
//    newBook->next = library;
//    library = newBook;
//    printf("Book added successfully.\n");
//    return library;
//}
Book* addBookSorted(Book* library, int bookId, const char* title, const char* author, int available) {
    Book* newBook = (Book*)malloc(sizeof(Book));

    if (newBook == NULL) {
        printf("Memory allocation failed.\n");
        return library;
    }

    newBook->bookId = bookId;
    strncpy(newBook->title, title, sizeof(newBook->title) - 1);
    strncpy(newBook->author, author, sizeof(newBook->author) - 1);
    newBook->available = available;
    newBook->next = NULL;

    if (library == NULL || bookId < library->bookId) {
        // Insert at the beginning
        newBook->next = library;
        library = newBook;
    } else {
        // Insert in sorted order
        Book* current = library;
        Book* prev = NULL;

        while (current != NULL && bookId >= current->bookId) {
            prev = current;
            current = current->next;
        }

        if (prev != NULL) {
            prev->next = newBook;
        }

        newBook->next = current;
    }

    printf("Book added successfully.\n");
    return library;
}

// Function to display the linked list of books
void displayBooks(const Book* library) {
    const Book* current = library;

    printf("\nBook List\n");
    printf("--------------------------------------------------------\n");
    printf("Book ID\t\tTitle\t\tAuthor\t\tAvailable Copies\n");
    printf("--------------------------------------------------------\n");

    while (current != NULL) {
        printf("%d\t\t%s\t\t%s\t\t%d\n", current->bookId, current->title, current->author, current->available);
        current = current->next;
    }
}
void searchBook(Book* library) {
    int bookId;
    printf("Enter the Book ID to search: ");
    scanf("%d", &bookId);

    while (library != NULL) {
        if (library->bookId == bookId) {
            printf("Book found!\n");
            printf("Book ID: %d\nTitle: %s\nAuthor: %s\n", library->bookId, library->title, library->author);
            return;
        }
        library = library->next;
    }

    printf("Book not found.\n");
}
Book* deleteBook(Book* library, int bookId) {
    Book* current = library;
    Book* prev = NULL;

    while (current != NULL) {
        if (current->bookId == bookId) {
            if (prev == NULL) {
                // Deleting the first node
                library = current->next;
            } else {
                prev->next = current->next;
            }

            free(current);
            printf("Book deleted successfully.\n");
            return library;
        }

        prev = current;
        current = current->next;
    }

    printf("Book not found.\n");
    return library;
}

void issueBook(Book* library, User* user) {
    int bookId;

    // Display the available books
    displayBooks(library);

    printf("Enter the Book ID to issue: ");
    scanf("%d", &bookId);

    Book* current = library;
    while (current != NULL) {
        if (current->bookId == bookId && current->available > 0) {
            current->available--;
            user->booksIssued++;
            printf("Book issued successfully.\n");
            return;
        }
        current = current->next;
    }

    printf("Book not available or invalid Book ID.\n");
}

void returnBook(Book* library, User* user) {
    int bookId;
    printf("Enter the Book ID to return: ");
    scanf("%d", &bookId);

    Book* current = library;
    while (current != NULL) {
        if (current->bookId == bookId && user->booksIssued > 0) {
            current->available++;
            user->booksIssued--;
            printf("Book returned successfully.\n");
            return;
        }
        current = current->next;
    }

    printf("Book not issued to the student or invalid Book ID.\n");
}
