#include <stdio.h>

#define MAX_TEXT_LEN 20

typedef struct employee {
    int empNum;
    char name[MAX_TEXT_LEN];
    char phone[MAX_TEXT_LEN];
    int age;
} EMPLOYEE;

int main()
{
    int i;
    EMPLOYEE EmpList[10] = {
        { 0, "임사장", "01011112222", 55 },
        { 1, "김이사", "01099392373", 49 },
        { 2, "이부장", "01048387738", 46 },
        { 3, "최부장", "01084783764", 43 },
        { 4, "마차장", "01078473981", 40 },
        { 5, "정과장", "01048383737", 36 },
        { 6, "이계장", "01021833473", 35 },
        { 7, "김대리", "01084884887", 30 },
        { 8, "하주임", "01028734784", 28 },
        { 9, "이사원", "01088888888", 26 },
    };

    for (i = 0; i < 10; i++) {
        if (EmpList[i].age >= 20 && EmpList[i].age <= 30) {
            printf("사원번호: %d\n", EmpList[i].empNum);
            printf("이름: %s\n", EmpList[i].name);
            printf("전화번호: %s\n", EmpList[i].phone);
            printf("나이: %d\n\n\n", EmpList[i].age);
        }
    }
    
    return 0;
}

