#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct node {
    int number;
    struct node* p_next;
} N;

void AddNumber(N** pp_head, N** pp_tail, int data) {
    // 첫 번째 노드 추가하는 경우
    if (*pp_head == NULL) {
        *pp_head = (N*)malloc(sizeof(N));  // 첫 번째 노드를 위한 메모리 할당
        *pp_tail = *pp_head;  // 첫 번째 노드가 p_head와 p_tail 모두 가리키게 설정
    }
    else {
        // 두 번째 이후 노드 추가하는 경우
        (*pp_tail)->p_next = (N*)malloc(sizeof(N));  // 새 노드를 추가
        *pp_tail = (*pp_tail)->p_next;  // p_tail을 새 노드를 가리키게 설정
    }
    (*pp_tail)->number = data;  // 데이터를 저장
    (*pp_tail)->p_next = NULL;  // 새 노드는 항상 마지막이므로 p_next는 NULL
}

int main() {
    N* p_head = NULL, * p_tail = NULL, * p;
    int sum = 0, temp;

    // 사용자 입력 받기
    while (1) {
        printf("Enter number; press 9999 to exit: ");
        scanf("%d", &temp);
        if (temp == 9999) break;  // 9999가 입력되면 종료
        AddNumber(&p_head, &p_tail, temp);
    }

    // 리스트 출력 및 합계 계산
    p = p_head;
    while (p != NULL) {
        if (p != p_head) printf(" + ");
        printf("%d", p->number);
        sum += p->number;
        p = p->p_next;
    }
    printf(" = %d\n", sum);

    // 메모리 해제
    while (p_head != NULL) {
        p = p_head;
        p_head = p_head->p_next;
        free(p);  // 노드 메모리 해제
    }

    p_tail = NULL;  // p_tail은 메모리 해제 후 NULL로 설정
    return 0;
}
