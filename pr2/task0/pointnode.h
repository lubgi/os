#include "point.h"

typedef struct PointNode
{
    struct PointNode* prev;
    struct PointNode* next;
    Point point;
} PointNode;

PointNode* pointnode_init(Point point, PointNode* prev, PointNode* next);

PointNode* findPointNodeWithSmallestMass(PointNode* head);

void transferMassAndDestroy(PointNode* head, PointNode* to_destroy, PointNode* to_receive);

PointNode* burn(PointNode* head);

void pointnode_print(PointNode* head);