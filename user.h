#ifndef USER_H
#define USER_H

struct User {
    char username[100];
    char password[100];
    int booksIssued;
    struct User* next;
};

typedef struct User User;
int authenticateUser(const char* username, const char* password);

#endif
