#include <string.h>
#include "./inc/library.h"

#define FileName "library.txt"

int selectSignin();
int C_selectMenu();
int M_selectMenu();
void PW();
void searchName(Book *b[], int count);

int main(){
    Book *bp[20];
    int count = LoadData(bp, FileName), menu = 0;
    int index = count;

    int ID = selectSignin();
    if (ID == 0) PW();

    while(1){
        if (ID == 0){
	    menu = M_selectMenu();
	}else{
	    menu = C_selectMenu();
	}

        if (menu == 0) break;
        if (menu == 1 || menu == 3 || menu == 4){
            if (count == 0) continue;
        }

        if (menu == 1){
            listBook(bp, index, ID);
        }
        else if (ID == 0 && menu == 2){
            bp[index] = (Book *)malloc(sizeof(Book));
            count += addBook(bp[index]);
            index++;
            printf("\n  **추가완료**\n\n");
        }
        else if (ID == 0 && menu == 3){
            int no = selectDataNo(bp, index, ID);
            if(no == 0){
                printf("\n  **취소완료**\n\n");
                continue;
            }
            int isUpdate = updateBook(bp[no-1]);

            if(isUpdate == 1)
                printf("\n **수정했습니다.**\n");
        }
        else if (ID == 0 && menu == 4){
            int no = selectDataNo(bp, index, ID);
            if(no == 0){
                printf("\n  **취소완료**\n\n");
                continue;
            }
            int deleteOk;
            printf("정말로 삭제하시겠습니까? (삭제 :1)>> ");
            scanf("%d", &deleteOk);
            if(deleteOk == 1){
            if(deleteBook(bp[no-1])) count--;
            }
        }
        else if (ID == 0 && menu == 5){
            SaveData(bp, index, FileName);
        }
        else if ((ID == 1 && menu == 2) || (ID == 0 && menu == 6)){
            searchName(bp, index);
        }else if (ID == 1 && menu == 3){
	    int no = selectDataNo(bp, index, ID);
	    if(no == 0){
		printf("\n  **취소완료**\n\n");
		continue;
	    }
	    reservation(bp[no-1]);
	}
    }

    for(int i = 0; i < index; i++){
        free(bp[i]);
    }

    printf("\n  **프로그램 종료**\n\n");
    return 0;
}

int selectSignin(){
    int menu;
    printf("0. 관리자 모드\n");
    printf("1. 일반사용자 모드\n");
    printf("로그인 방법 선택>> ");
    scanf("%d", &menu);

    return menu;
}

int C_selectMenu(){
    int menu;

    printf("\n1. 도서조회\n");
    printf("2. 도서검색\n");
    printf("3. 도서예약\n");
    printf("0. 종료\n");
    printf("번호선택>> ");
    scanf("%d", &menu);

    return menu;
}

int M_selectMenu(){
    int menu;

    printf("\n1. 도서조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 도서검색\n");
    printf("0. 종료\n");
    printf("번호선택>> ");
    scanf("%d", &menu);

    return menu;
}

void PW(){
    char PW[5] = "0000";
    char u_PW[5];
    int count = 0;

    while(strcmp(PW, u_PW) != 0){
	count++;
	if(count > 9){
	    printf("\n  **비밀번호 10회 오류로 종료합니다.**\n\n");
	    exit(1);
	}
        printf("비밀번호 입력>> ");
	scanf("%s", u_PW);
    }
}

void searchName(Book *b[], int count){
    int scnt = 0;
    char search[20];

    printf("\n검색어(도서제목)>> ");
    scanf("%s", search);

    printf("\n번호 | 도서명 | 저자 | 출판사 | 판수 | 출판년도 | ISBN | 예약\n");
    printf("=============================================================\n");

    for(int i = 0; i < count; i++){
        if(b[i]->NAME[0] == -1) continue;
	if(strstr(b[i]->NAME, search)){
	    printf("%2d || ", i+1);
	    readBook(*b[i]);
	    scnt++;
	}
    }
    printf("=============================================================\n");
    
    if(scnt == 0) printf("\n  **검색된 데이터 없음**\n");
    putchar('\n');
}

