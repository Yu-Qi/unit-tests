#include "stdio.h"
#include "stdlib.h"
#include "merge.h"

void build_list(List **head);
void answer(List *head);
int main()
{
	List *head = NULL;
	build_list(&head);
	answer(head);

}
void build_list(List **head)
{
	int array[ ]={38,27,43,3,9,82,10};
	printf("first: ");	
	for( int i = 0;i < 7;i++){
		List *t = (List*) malloc(sizeof(List));
		t -> val = array[i];
		t -> next =(*head);
		(*head) = t;
		printf("%d ",t->val);
	}
	puts("");
	mergesort(head);
}
	
void answer(List *_head)
{
	while(_head){
		printf("%d ",_head -> val );
		_head = _head -> next;
	}
	puts("");
}