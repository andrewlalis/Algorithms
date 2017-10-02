/*
handytree.h
Created By:
	Andrew Lalis (andrewlalisofficial@gmail.com)
	02 October 2017
This file is free to use, as long as the above comment remains in the file.
Please contact the author regarding bugs and/or feature requests.
*/

#ifdef TREE_TYPE

#include "templates.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>

/*
Tree:
	A data structure in which each node has some child nodes, and data about itself. A tree has only one root node, can have a great number of leaf nodes.
*/

/*
TREE_NODE: the tree type for a tree node.
*/
#define TREE_NODE TEMPLATE(TREE_TYPE,tree_node)

/*
Tree structure:
	Each tree node has some data, and a list of pointers to its child nodes, if any.
*/
typedef struct {
	TREE_NODE** children;
	int childCount;
	TREE_TYPE data;
} TREE_NODE;

/*
Tree node creation:
	Creates a new tree node, with some amount of child nodes, and data.
*/
TREE_NODE* TEMPLATE(new,TREE_NODE)(TREE_TYPE data, int childNum, ...){
	TREE_NODE* node = malloc(sizeof(TREE_NODE));
	assert(node != NULL);
	node->data = data;
	node->childCount = childNum;
	if (childNum > 0){
		va_list args;
		va_start(args, childNum);
		node->children = malloc(childNum*sizeof(TREE_NODE*));
		assert(node->children != NULL);
		for (int i = 0; i < childNum; i++){
			node->children[i] = va_arg(args, TREE_NODE*);
		}
		va_end(args);
	}
	return node;
}

#endif