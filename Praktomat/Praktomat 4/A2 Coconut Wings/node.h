#ifndef NODE_H_
#define NODE_H_
#include "island.h"

typedef struct node{

	Island *island;
	struct node *next;

	struct node *prev;
}Node;

Node * Node_New(void);

void Node_Insert(Node *theNode);

#endif /* NODE_H_ */
