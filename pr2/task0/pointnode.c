
#include "stdlib.h"
#include "pointnode.h"
#include "stdio.h"

PointNode* pointnode_init(Point point, PointNode* prev, PointNode* next){
    PointNode* pointNode = malloc(sizeof *pointNode);
    pointNode -> point = point;
    pointNode -> prev = prev;
    pointNode -> next = next;

    return pointNode;
}

PointNode* findPointNodeWithSmallestMass(PointNode* head){
    PointNode* smallest = head;
    PointNode* current = head;

    while (current != NULL)
    {
        if (current->point.mass < smallest->point.mass)
        {
            smallest = current;
        }
        current = current->next;
    }

    return smallest;
}

PointNode* findClosestPointNode(PointNode* head, PointNode* closest_to){
    PointNode* closest = head->next;
    PointNode* current = head;

    while (current != NULL)
    {
        if (point_finddistance(current->point, closest_to->point) < point_finddistance(closest->point, closest_to->point) 
            && current != closest_to)
        {
            closest = current;
        }
        current = current->next;
    }

    return closest;
}

void transferMassAndDestroy(PointNode* head, PointNode* to_destroy, PointNode* to_receive){
    to_receive->point.mass += to_destroy->point.mass;
    if (to_destroy->prev != NULL)
    {
        to_destroy->prev->next = to_destroy->next;
        to_destroy->next->prev = to_destroy->prev;
    }
    else
    {
        *head = *to_destroy->next;
    }
    
    free(to_destroy);
}

PointNode* burn(PointNode* head){
    PointNode* smallest = findPointNodeWithSmallestMass(head);
    printf("\nSmallest point is: "); point_print(smallest->point);
    PointNode* closest = findClosestPointNode(head, smallest);
    printf("\nClosest point is: "); point_print(closest->point);
    transferMassAndDestroy(head, smallest, closest);
    return head;
}

void pointnode_print(PointNode* head){
    PointNode* current = head;
    while (current != NULL)
    {
        point_print(current->point);
        printf("\n");
        current = current->next;
    }
}

