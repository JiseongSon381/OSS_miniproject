#include <string.h>
#include "library.h"

#define FileName "library.txt"

int selectMU();
int selectMenu();

// 시작화면:: 관리자, 일반 이용자
// 일반 모드:: 조회, 검색, 설정, 종료
// 관리자 모드:: 조회, 추가, 수정, 삭제, 저장, 로그아웃, 종료

int main(){
        Book *bp[20];
        int count = LoadData(bp, FileName), menu = 0;
        int index = count;
	
	char ID = selectMU();

	

        while(1){
                menu = seletMenu();

                if (menu == 0) break;
                if (menu == 1 || menu == 3 || menu == 4){
                        if (count == 0) continue;
                }

                if (menu == 1){ // read
                        if(count > 0) listBook(bp, index);
                        else printf("데이터가 없습니다.\n");
                }
                else if (menu == 2){ // add
                        bp[index] = (Book *)malloc(sizeof(Book));
                        count += addBook(bp[index]);
                        index++;
                        printf("=> 추가됨!\n");
                }
                else if (menu == 3){ // update
                        int no = selectDataNo(bp, index);
                        if(no == 0){
                                printf("=> 취소됨!\n");
                                continue;
                        }
                        int isUpdate = updateBook(bp[no-1]);

                        if(isUpdate == 1)
                                printf("=> 수정성공!\n");
                        }
                else if (menu == 4){ // delete
                        int no = selectDataNo(bp, index);
                        if(no == 0){
                                printf("=> 취소됨!\n");
                                continue;
                        }
                        int deleteOk;
                        printf("정말로 삭제하시겠습니까? (삭제 :1)");
                        scanf("%d", &deleteOk);
                        if(deleteOk == 1){
                        if(deleteBook(bp[no-1])) count--;
                        }
                }
                else if (menu == 5){ // save
                        SaveData(bp, index, FileName);

                }
                else if (menu == 6){ // search
                        searchName(bp, index);
                }
        }

        for(int i = 0; i < index; i++){
                free(bp[i]);
        }

        printf("종료됨!\n");
        return 0;
}

int selectMenu(){
        int menu;

        printf("1. 도서조회\n");
        printf("2. 추가\n");
        printf("3. 수정\n");
        printf("4. 삭제\n");
        printf("5. 저장\n");
        printf("6. 도서검색\n");
        printf("0. 종료\n");
        scanf("%d", &menu);

        return menu;
}

int selectMU(){
	int menu;

	printf("0. 관리자 모드\n");
	printf("1. 일반사용자 모드\n");
	printf("로그인 방법 선택>> ");
	scanf("%d", &menu);

	return menu;
}
