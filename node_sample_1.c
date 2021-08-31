#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char name[20];
    int age;
    struct node *next;
};
//panta deixnei sto list_head, vlepe vivlio C

struct node fill_node();

struct node *list_head;

int add_node_to_list(struct node **plh, struct node n);

void display_all_nodes(struct node *lh);

struct node fill_node();

int main() {
    struct node temp;
    list_head = NULL;
    while (1) {
        temp = fill_node();
        if (temp.age <= 0) {
            break;
        }
        if (add_node_to_list(&list_head, temp) == 0) {
            printf("error in node addition\n");
        }
    }
    display_all_nodes(list_head);
    return 0;
}

struct node fill_node() {
    struct node t;
    printf("dwse onoma : ");
    gets(t.name);
    printf("dwse hlikia : ");
    scanf("%d", &t.age);
    fflush(stdin);
    return t;
}


int add_node_to_list(struct node **plh, struct node n) {
    struct node *new;
    new = malloc(sizeof(struct node));
    if (new == NULL) {
        return 0;
    }
    *new = n;
    new->next = *plh;
    *plh = new;
    return 1;
}


void display_all_nodes(struct node *lh) {
    struct node *p;
    p = lh;
    while (p != NULL) {
        printf("%s %d\n", p->name, p->age);
        p = p->next;//se periptwsh poy valeis to p->next prwta,
        // o teleutaios komvos paraleipetai
        // efoson deixneis ston amesws epomeno node kateutheian
    }
}

