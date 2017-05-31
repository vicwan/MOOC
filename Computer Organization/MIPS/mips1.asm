.data 
int_value:	.space  4

.text
li	$v0, 5
syscall
sw	$v0, int_value