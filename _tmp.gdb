b main
r
source scripts/create_list.gdb
source scripts/printf_list.gdb
source scripts/find_node_address.gdb
set $head = (List*)0
set $node1 = (List*)0
set $node2 = (List*)0
create_list $head 4
set logging file result-swap
set logging on
p "test begin"
p "old_list"
printf_list $head
set logging off
find_node_address $head 1 $node1
find_node_address $head 3 $node2
p $head = swap($head,$node1,$node2)
set logging on
p "change 1  3"
p "new_list"
printf_list $head
set logging off
set logging on
p "test begin"
p "old_list"
printf_list $head
set logging off
find_node_address $head 2 $node1
find_node_address $head 4 $node2
p $head = swap($head,$node1,$node2)
set logging on
p "change 2  4"
p "new_list"
printf_list $head
set logging off
b main
r
source scripts/create_list.gdb
source scripts/print_list.gdb
source scripts/free_list.gdb
set $head = (List**)malloc(sizeof(List*))
set logging file result-bubble
create_list (*($head)) 12 4 5
set $_head = (*($head))
set logging on
p "test begin"
p "old_list"
printf_list (*($head))
set logging off
p bubble_sort($head)
set logging on
p "new_list"
printf_list (*($head))
set logging off
free_list (*($head))
create_list (*($head)) 456 78 41 25 1 47
set $_head = (*($head))
set logging on
p "test begin"
p "old_list"
printf_list (*($head))
set logging off
p bubble_sort($head)
set logging on
p "new_list"
printf_list (*($head))
set logging off
free_list (*($head))
create_list (*($head)) 7 5 97 6 3 7 8
set $_head = (*($head))
set logging on
p "test begin"
p "old_list"
printf_list (*($head))
set logging off
p bubble_sort($head)
set logging on
p "new_list"
printf_list (*($head))
set logging off
free_list (*($head))
q
y
