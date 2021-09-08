#include "tree.h"

/*********************************************
* CONSTRUCTOR, create the branches of the tree 
* and the leaves
*********************************************/
Tree::Tree(const Point &tL, const Point &bR, int size, float xPos, float height, float angleLeft, float angleRight)
{
	Point begin(tL.getX() + xPos, bR.getY());
	Point end(begin.getX(), begin.getY() + height);

	branches.push_back(new Branch(begin, end));

	//Create branches
	for (int i = 0;i < size;++i)
	{
		branches.push_back(branches[i]->newBranch(angleLeft));  //left
		branches.push_back(branches[i]->newBranch(angleRight)); //right
	}

	//create Leaves
	for (int i = branches.size() / 2; i < branches.size();++i)
	{
		leaves.push_back(new Leaf(branches[i]->getEnd()));
	}
}

/*********************************************
* DESTRUCTOR, free memory
*********************************************/
Tree::~Tree()
{
	//delete Branches
	for (int i = 0; i < branches.size();++i)
		delete branches[i];

	//delte Leaves
	for (int i = 0; i < leaves.size();++i)
		delete leaves[i];
}

/*********************************************
* ADVANCE LEAVES
*********************************************/
void Tree::advance()
{
	for (int i = 0;i < leaves.size();)
	{
		if (leaves[i]->isAlive())
		{
			leaves[i]->advance();
			++i;
		}
		else
		{
			delete leaves[i];
			std::swap(leaves[i], leaves.back());//swap with the last
			leaves.pop_back(); //delete the last
		}
	}	
}

/*********************************************
* DRAW TREE, branches and the leaves
*********************************************/
void Tree::draw()
{
	//draw Branches
	for (int i = 0; i < branches.size();++i)
		branches[i]->draw();

	//draw Leaves
	for (int i = 0; i < leaves.size();++i)
		leaves[i]->draw();
}
