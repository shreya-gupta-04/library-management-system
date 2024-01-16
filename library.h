// library.h
#ifndef LIBRARY_H
#define LIBRARY_H

struct Book {
    int bookId;
    char title[50];
    char author[50];
    int available;
    struct Book* next;
    
};

typedef struct Book Book;
typedef struct User User;

// Function declarations
void displayMenu();
//Book* addBook(Book* library);
Book* addBookSorted(Book* library, int bookId, const char* title, const char* author,int available) ;
void displayBooks(const Book* library);
void searchBook(Book* library);
Book* deleteBook(Book* library, int bookId);
void issueBook(Book* library, User* user);
void returnBook(Book* library, User* user);


#endif




