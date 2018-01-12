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
	A data structure in which each node has some child nodes, and data about itself. A tree has only one root node, can have a great number of leaf nodes. Each node contains some data, and pointers to child
	nodes.
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
	//If there are children to add, add as many as given.
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

/*
Tree node creation: Empty tree node.
	Creates a new tree node with no children, just data.
*/
TREE_NODE* TEMPLATE(newEmpty,TREE_NODE)(TREE_TYPE data){
	TREE_NODE* node = malloc(sizeof(TREE_NODE));
	assert(node != NULL);
	node->data = data;
	node->childCount = 0;
	return node;
}

/*
Free tree node:
	Frees a node, and all children of this node.
*/
void TEMPLATE(free,TREE_NODE)(TREE_NODE* node){
	for (int i = 0; i < node->childCount; i++){
		TEMPLATE(free,TREE_NODE)(node->children[i]);
	}
	free(node->children);
}

/*
Add node:
	Adds a node to a given parent node.
*/
void TEMPLATE(addNode,TREE_NODE)(TREE_NODE* node, TREE_NODE newChild){
	node->childCount = node->childCount + 1;
	TREE_NODE** oldChildren = node->children;
	node->children = malloc(node->childCount * sizeof(TREE_NODE*));
	assert(node->children != NULL);
	memcpy(node->children, oldChildren, node->)
}

/*
Remove a node:
	Removes a node from a given parent, referenced by a pointer.
*/
void TEMPLATE(remove,TREE_NODE)(TREE_NODE* parent, TREE_NODE* child){
	for (int i = 0; i < parent->childCount; i++){
		if (parent->children[i] == child){
			
		}
	}
}

#endif