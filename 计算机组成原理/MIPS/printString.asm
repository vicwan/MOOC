.data
str:	.asciiz	"this is a string"
space:	.space 20

.text
.globl main

main:	

li $a1, 8
la $a0, space
li $v0, 8
syscall

lw $a0, 3($a0)
li $v0, 11
syscall

