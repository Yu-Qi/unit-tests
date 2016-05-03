#include "stdio.h"
#include "stdlib.h"
#include "merge.h"

#define set_node_and_recursive(NAME1,NAME2) { 	\
		(*result) = _##NAME1 ;			\
		if( ! _##NAME1->next){			\
			(*result) -> next = _##NAME2;	\
			return *result;			\
		}					\
}
	
List* combine(List **result, List *_left, List *_right)
{
	if( ! _right)
		return _left;
	else if( ! _left)
		return _right;
	// sorting it by decreasing order 
	if(_left -> val < _right -> val){
		set_node_and_recursive(right, left);
		(*result) -> next = combine( &((*result)->next), _left , _right -> next);
	}
	else{
		set_node_and_recursive(left, right);	
		(*result) -> next = combine( &((*result)->next), _left -> next, _right);
	}
	return (*result);

}
void mergesort(List **head)
{
	if( ! *head || ! (*head) ->next )
		return;
	
	List *left = NULL, *right = NULL;
	List *result = NULL;

	divide_two_node(head, &left, &right);

	mergesort(&left);
	mergesort(&right);

	(*head) = combine(&result ,left, right);
}

void divide_two_node(List **head, List **left, List **right) { 		
	List *left_last = (*head); 	
	List *sub_head =*head;
	(*left) = (*head);		 
	(*right) = (*head) -> next; 	
	while (sub_head){ 			
		if( !( sub_head ->next) )
			break; 				

		sub_head = sub_head ->next ->next; 
		if( ! sub_head)
			break;

		left_last = *right; 	
		(*right) = (*right)->next; 			
	}				
	left_last ->next = NULL;		
}