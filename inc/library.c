#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int addBook(Book *b){
        printf("도서명: ");
        scanf("%s", b->NAME);
        printf("저자: ");
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

void readBook(Book *b){
        printf("%s %s %s %d %d %ld %c %d",
                b->NAME, b->author, b->pub, b->edition, b->year, b->ISBN, b->no_ch);
}

void listBook(Book *b[], int index){
        printf("\n번호 | 도서명           | 출판사 | 판수 | 출판년도 | ISBN | 예약자 수");
}

int selectDataNo(Book *b[], int count){
        int no;
        listBook(b, count);
        printf("번호입력(취소: 0): ");
        scanf("%d", &no);

        return no;
}

int updateBook(Book *b){
        printf("도서명: ");
        scanf("%s", b->NAME);
        printf("저자: ");
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
                if(b[i]->ISBN == 0) continue;
        }
}

int LoadData(Book *b[], char FileName[]){
        int count = 0, i = 0;

        FILE *fp = fopen(FileName, "rt");

        if(fp == NULL){
                printf("파일없음");
                return 0;
        }

        for(i = 0; i < 20; i++){
                b[i] = (Book *)malloc(sizeof(Book));
                fscanf(fp, "%s", b[i]->NAME);

                if(feof(fp)) break;

                fscanf(fp, "%s", &b[i]->author);

        }
}

