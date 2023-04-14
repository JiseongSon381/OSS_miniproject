typedef struct {
    char NAME[20];
    char author[20];
    char pub[10];
    char edition;
    short year;
    long long ISBN;
    char check;
    unsigned char no_ch;
}Book;

int addBook(Book *b);
void readBook(Book *b);
void listBook(Book *b[], int index);
int selectDataNo(Book *b[], int count);
int updateBook(Book *b);
int deleteBook(Book *b);
void SaveData(Book *b[], int count, char FileName[]);
int LoadData(Book *b[], char FileName[]);
