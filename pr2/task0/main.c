#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "pointnode.h"

int main(){
    PointNode* head = pointnode_init(point_initxyzm(1, 2, 3, 5), NULL, NULL);
    head->next = pointnode_init(point_initxyzm(2, 3, 4, 6), head, NULL);
    head->next->next = pointnode_init(point_initxyzm(0, 0, 0, 15), head, NULL);

    pointnode_print(head);
    burn(head);
    printf("\nAfterburn:\n");
    pointnode_print(head);
}


