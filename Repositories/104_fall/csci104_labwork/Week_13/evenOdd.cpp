#include "evenOdd.h"

using namespace std;

std::shared_ptr<Node> oddEvenList(std::shared_ptr<Node> head) {
	// TODO
	if(head == NULL)
	{
		return head;
	}

	std::shared_ptr<Node> odd = head;
	std::shared_ptr<Node> even = head->next;
	std::shared_ptr<Node> even_head = even;
	while(even != NULL && even->next != NULL)
	{
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	odd->next = even_head;
	return head;
}