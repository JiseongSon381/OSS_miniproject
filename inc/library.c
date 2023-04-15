#include "library.h"

int addBook(Book *b){
    printf("도서명(20자 이내): ");
    scanf("%s", b->NAME);
    printf("저자(10자 이내): ");
    scanf("%s", b->author);
    printf("출판사(10자 이내): ");
    scanf("%s", b->pub);
    printf("판수: ");
    scanf("%s", b->edition);
    printf("출판년도: ");
    scanf("%s", b->year);
    printf("ISBN: ");
    scanf("%s", b->ISBN);

    return 1;
}

void readBook(Book b){
    printf("%20s | %10s | %10s | %2d | %4d | %13ld | %s",
        b.NAME, b.author, b.pub, b.edition, b.year, b.ISBN, b.check? "예약가능":"예약불가" );
}

void listBook(Book *b[], int index){
    printf("========================================================================================================\n");
    printf("번호 | 도서명                  | 저자         | 출판사        | 판수 | 출판년도 | ISBN          | 예약  \n");
    printf("========================================================================================================\n");

    for(int i = 0; i < index; i++){
	if(b[i]->NAME[0] == -1);
	printf("%2d | ", i+1);
	readBook(*b[i]);
    }
}

int selectDataNo(Book *b[], int count){
    int no;
    listBook(b, count);
    printf("번호입력(취소: 0): ");
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
    scanf("%s", b->edition);
    printf("출판년도: ");
    scanf("%s", b->year);
    printf("ISBN: ");
    scanf("%s", b->ISBN);

    return 1;
}

int deleteBook(Book *b){
    b->NAME[0] = -1;
    b->author[0] = -1;
    b->pub[0] = -1;
    b->edition = -1;
    b->year = 0;
    b->ISBN = 0;
}

void SaveData(Book *b[], int count, char FileName[]){
    FILE *fp = fopen(FileName, "wt");

    for(int i = 0; i < count; i++){
        if(b[i]->NAME[0] == -1) continue;
	fprintf(fp, "%20s %10s %10s %10s %d %d %ld\n",
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
        fgets(b[i]->NAME, 20, fp);

	if (feof(fp)) break;

	fgets(b[i]->author, 10, fp);
	fgets(b[i]->pub, 10, fp);
	fscanf(fp, "%d", &b[i]->edition);
	fscanf(fp, "%d", &b[i]->year);
	fscanf(fp, "%ld", &b[i]->ISBN);
	
	count++;
    }

    fclose(fp);

    if(count != 0) printf("\n  **로딩성공**\n\n");
    return i;
}
