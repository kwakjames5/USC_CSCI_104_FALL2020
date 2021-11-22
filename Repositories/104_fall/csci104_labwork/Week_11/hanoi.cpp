#include <iostream>

void solveTowers(int disc, char src, char dst, char alt);

int main()
{
	// We will name our src, dst, and alt towers "a", "b", and "c" 
	solveTowers(3,'a','b','c');
	return 0;
}

void move(int disc, char src, char dst) 
{
	std::cout << "Moving disc " << disc << " from " << src << " to " << dst << std::endl;
}

void solveTowers(int disc, char src, char dst, char alt)
{
	// TODO
	if(disc == 1)
	{
		move(disc, src, dst);
	}
	else
	{
		solveTowers(disc - 1, src, alt, dst);
		move(disc, src, dst);
		solveTowers(disc - 1, alt, dst, src);
	}
}