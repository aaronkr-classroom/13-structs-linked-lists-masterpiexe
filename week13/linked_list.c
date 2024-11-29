#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

typedef struct node {
    int number;
    struct node* p_next;
} N;

void AddNumber(N** pp_head, N** pp_tail, int data) {
    // ù ��° ��� �߰��ϴ� ���
    if (*pp_head == NULL) {
        *pp_head = (N*)malloc(sizeof(N));  // ù ��° ��带 ���� �޸� �Ҵ�
        *pp_tail = *pp_head;  // ù ��° ��尡 p_head�� p_tail ��� ����Ű�� ����
    }
    else {
        // �� ��° ���� ��� �߰��ϴ� ���
        (*pp_tail)->p_next = (N*)malloc(sizeof(N));  // �� ��带 �߰�
        *pp_tail = (*pp_tail)->p_next;  // p_tail�� �� ��带 ����Ű�� ����
    }
    (*pp_tail)->number = data;  // �����͸� ����
    (*pp_tail)->p_next = NULL;  // �� ���� �׻� �������̹Ƿ� p_next�� NULL
}

int main() {
    N* p_head = NULL, * p_tail = NULL, * p;
    int sum = 0, temp;

    // ����� �Է� �ޱ�
    while (1) {
        printf("Enter number; press 9999 to exit: ");
        scanf("%d", &temp);
        if (temp == 9999) break;  // 9999�� �ԷµǸ� ����
        AddNumber(&p_head, &p_tail, temp);
    }

    // ����Ʈ ��� �� �հ� ���
    p = p_head;
    while (p != NULL) {
        if (p != p_head) printf(" + ");
        printf("%d", p->number);
        sum += p->number;
        p = p->p_next;
    }
    printf(" = %d\n", sum);

    // �޸� ����
    while (p_head != NULL) {
        p = p_head;
        p_head = p_head->p_next;
        free(p);  // ��� �޸� ����
    }

    p_tail = NULL;  // p_tail�� �޸� ���� �� NULL�� ����
    return 0;
}
