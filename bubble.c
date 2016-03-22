/* FIXME : introduce elegant ways to reuse */
#include "swap.c"

void bubble_sort(List **head)
{
    if (head == NULL || (*head == NULL))
        return;

    int num_list = 0;
    int sub_for_Max;
    List **pre_sub_head = head;
    List *sub_head = *head;

    while ( sub_head && sub_head->next ) {

        num_list = num_list + 1;
        pre_sub_head = &((*pre_sub_head)->next);
        sub_head = sub_head->next;
    }

    for (int i = 0; i < num_list; i++) {
        sub_head = *head;
        sub_for_Max = num_list - i;
        pre_sub_head = head;
        int have_swap= 0 ; //equal false
        for (int sub_i = 0; sub_i < sub_for_Max ; sub_i++ ){
            if (sub_head->value < sub_head->next->value) {  //for decreasing order
                sub_head = swap(sub_head,sub_head,sub_head->next);
                *pre_sub_head = sub_head;
                have_swap = 1; 
            }

            pre_sub_head = &((*pre_sub_head)->next);
            sub_head = sub_head->next;
        }
        if(have_swap == 0 )  //mean there is no swap
            return ;
    }

    return;
}
