#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char NAME[64];
    char author[64];
    char pub[64];
    unsigned char edition;
    short year;
    long long ISBN;
    unsigned char check;
}Book;

int addBook(Book *b);
void readBook(Book b);
void listBook(Book *b[], int index, int ID);
int selectDataNo(Book *b[], int count, int ID);
int updateBook(Book *b);
int deleteBook(Book *b);
void reservation(Book *b);
void SaveData(Book *b[], int count, char FileName[]);
int LoadData(Book *b[], char FileName[]);
