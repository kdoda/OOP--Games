#pragma once
#ifndef TREE_H
#define TREE_H

#include "branch.h"
#include "uiDraw.h"
#include "leaf.h"
#include <vector>

/*********************************************
* TREE class
*********************************************/
class Tree
{
public:
	Tree(){}
	Tree(const Point &tL, const Point &bR, int size, float xPos, float height, float angleLeft, float angleRight);
	~Tree();
	void advance();
	void draw();
private:
	std::vector<Branch*> branches;
	std::vector<Leaf*> leaves;
};
#endif /* LEAF_H */