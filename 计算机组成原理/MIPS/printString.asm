.data
str:	.asciiz	"this is a string"


.text
.globl main

main:	
li $t1, 1
li $v0, 5
syscall

beq $v0, $t1, print
j end

print:
la $a0, str
li $v0, 4


syscall
j end

end: 
li $v0, 12
syscall

lala:
li $v0, 4
jr $ra