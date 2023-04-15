#include "library.h"

int addBook(Book *b){
    printf("도서명(띄어쓰기 없이): ");
    scanf("%s", b->NAME);
    printf("저자(띄어쓰기 없이): ");
    scanf("%s", b->author);
    printf("출판사(띄어쓰기 없이): ");
    scanf("%s", b->pub);
    printf("판수: ");
    scanf("%hhd", &b->edition);
    printf("출판년도: ");
    scanf("%hd", &b->year);
    printf("ISBN: ");
    scanf("%lld", &b->ISBN);

    b->check = 0;

    return 1;
}

void readBook(Book b){
    printf("%s | %s | %s | %d | %d | %lld | %s\n",
        b.NAME, b.author, b.pub, b.edition, b.year, b.ISBN, b.check? "예약불가":"예약가능");
}

void listBook(Book *b[], int index, int ID){
    printf("\n번호 | 도서명 | 저자 | 출판사 | 판수 | 출판년도 | ISBN | 예약\n");
    printf("===============================================================\n");

    for(int i = 0; i < index; i++){
	if((b[i]->NAME[0] == -1) || (ID == 1 && b[i]->check == 1)) continue;
	printf("%2d || ", i+1);
	readBook(*b[i]);
    }
    printf("===============================================================\n\n");
}

int selectDataNo(Book *b[], int count, int ID){
    int no;
    listBook(b, count, ID);
    printf("번호입력(취소: 0)>> ");
    scanf("%d", &no);

    return no;
}

int updateBook(Book *b){
    printf("도서명(띄어쓰기 없이): ");
    scanf("%s", b->NAME);
    printf("저자(띄어쓰기 없이): ");
    scanf("%s", b->author);
    printf("출판사: ");
    scanf("%s", b->pub);
    printf("판수: ");
    scanf("%hhd", &b->edition);
    printf("출판년도: ");
    scanf("%hd", &b->year);
    printf("ISBN: ");
    scanf("%lld", &b->ISBN);

    return 1;
}

int deleteBook(Book *b){
    b->NAME[0] = -1;
    b->author[0] = -1;
    b->pub[0] = -1;
    b->edition = -1;
    b->year = 0;
    b->ISBN = 0;

    return 1;
}

void reservation(Book *b){
    b->check = 1;
    printf("\n  **예약완료**\n\n");
}

void SaveData(Book *b[], int count, char FileName[]){
    FILE *fp = fopen(FileName, "wt");

    for(int i = 0; i < count; i++){
        if(b[i]->NAME[0] == -1) continue;
	fprintf(fp, "%s %s %s %d %d %lld\n",
	    b[i]->NAME, b[i]->author, b[i]->pub, b[i]->edition, b[i]->year, b[i]->ISBN);
    }

    fclose(fp);
    printf("\n  **저장완료**\n\n");
}

int LoadData(Book *b[], char FileName[]){
    int count = 0, i = 0;

    FILE *fp = fopen(FileName, "rt");
    if(fp == NULL){
        printf("\n  **파일없음**\n\n");
        return 0;
    }

    for(i = 0; i < 20; i++){
        b[i] = (Book *)malloc(sizeof(Book));
        fscanf(fp, "%s",b[i]->NAME);

	if (feof(fp)) break;

	fscanf(fp, "%s", b[i]->author);
	fscanf(fp, "%s", b[i]->pub);
	fscanf(fp, "%hhd", &b[i]->edition);
	fscanf(fp, "%hd", &b[i]->year);
	fscanf(fp, "%lld", &b[i]->ISBN);
	
	count++;
    }

    fclose(fp);

    if(count != 0) printf("\n  **로딩성공**\n\n");
    return i;
}
