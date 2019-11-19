#include <iostream>

struct node {
	int value;
	struct node* adjust[50];
	int size;
};

struct list {
	struct node *n;
	struct list *next;
};

struct node nodes[10];

struct list *path = NULL, *head = NULL;


int InsertToPath(struct list *path, struct node *x) {
	struct list *temp = head;
	while (temp) {
		if (temp->n == x)
			return 0;
		temp = temp->next;
	}
	delete temp;
	if (head == NULL) {
		path = new (struct list);
		//head = path;
		path->n = x;
		path->next = NULL;
		head = path;
	}
	else {
		path = head;
		while (path->next != NULL) {
			path = path->next;
		}
		path->next = new (struct list);
		path = path->next;
		path->n = x;
		path->next = NULL;
	}
	return 1;
}

int findPath(struct node *x, struct node *y, struct list *path) {
	//if one of the adjuscents is y return
	int test = InsertToPath(path, x);
	if (test == 0)
		return 0;
	for (int i = 0; i < x->size; i++) {
		if (y->value == x->adjust[i]->value) {
			InsertToPath(path, y);
			return 1;
		}
	}

	for (int i = 0; i < x->size; i++) {
		return findPath(x->adjust[i], y, path);
	}
}

int main()
{
	struct node *x = NULL, *y = NULL;


	nodes[0].value = 1;
	nodes[1].value = 2;
	nodes[2].value = 3;
	nodes[3].value = 4;
	nodes[4].value = 5;

	nodes[0].size = 2;
	nodes[1].size = 2;
	nodes[2].size = 2;
	nodes[3].size = 3;
	nodes[4].size = 1;

	nodes[0].adjust[1] = &nodes[1];
	nodes[0].adjust[0] = &nodes[2];
	nodes[1].adjust[0] = &nodes[3];
	nodes[1].adjust[1] = &nodes[0];
	nodes[2].adjust[0] = &nodes[3];
	nodes[2].adjust[1] = &nodes[0];
	nodes[3].adjust[2] = &nodes[4];
	nodes[3].adjust[0] = &nodes[1];
	nodes[3].adjust[1] = &nodes[2];
	nodes[4].adjust[0] = &nodes[3];

	int isPath = findPath(&(nodes[0]), &(nodes[4]), path);

	if (isPath == 1) {
		path = head;
		while (path) {
			printf("%d->", path->n->value);
			path = path->next;
		}
		//printf("%d", path->n->value);
	}
	else {
		printf("baasa - no path");
	}
	//printf("%d", isPath);
}