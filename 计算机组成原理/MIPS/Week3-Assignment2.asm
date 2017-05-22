

.data 
succ_string: .asciiz "Success! Location: "
fail_string: .asciiz "Fail!"
string_space:.space 50

.text

# use $t8 to store location

load:	lw $s6, succ_string
	lw $s7, fail_string
	
	la $a0, string_space
	li $a1, 30
	li $v0, 8	# Read string
	syscall 

main:	li $v0, 12	# Read character
	syscall
	beq $v0, 63, termination
	
	
	li $t0, 0
judge:	add $t1, $t0, $s1	# $t1 loads the address of charater being compared with
	addi $t0, $t0, 1
	
	beq $t0, $s1, fail

	
	lw $t2, ($t1)
	
	bne $v0, $t2, judge
	
	
success:li $t0, 0
	move $a0, $s6
	li $v0, 4
	syscall
	move $a0, $t0
	li $v0, 1
	syscall
	jal print_lf
	j main

fail:	li $t0, 0	
	jal print_lf
	lw $a0, ($s7)
	li $v0, 4
	syscall
	jal print_lf
	j main

termination:	
	li $v0, 10
	syscall



print_lf:	
	li $a0, 10
	li $v0, 11
	syscall
	jr $ra