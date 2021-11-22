#include <iostream>
#include "Person.h"

using namespace std;

int main() {
	UscStudent* u = new UscStudent("Tommy Trojan", "Computer Science", 100);
	Person* p = new UscStudent("James Kwak", "Comp sci 8)" , 1000);
	//u->setGPA(20);
	u->printTranscript();
	p->printTitle();
	// delete u;
	// delete p;
	return 0;
}
