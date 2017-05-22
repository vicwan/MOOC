
# Programmed by Vic	2017 / 05 / 22




######   		data segment			###########	
.data 
succ_string:	.asciiz "Success! Location: "
fail_string: 	.asciiz "Fail!"
string_space:	.space 50


######    		text segment                    ###########

.text

load:	la $s6, succ_string
	la $s7, fail_string
	
	la $a0, string_space
	move $t8, $a0			# Preserve input string	
	li $a1, 30			# Maximum characters
	li $v0, 8			
	syscall 			# Read string

main:	li $v0, 12			# Read character
	syscall
	beq $v0, 63, termination
	
	li $t0, 0			# Initialize $t0
judge:	add $t1, $t8, $t0		# $t1 loads the address of charater being compared with
	addi $t0, $t0, 1		# $t0 as a pointer which points to a character
	lb $t2, ($t1)
	beqz  $t2, fail			# If compared with the null character, jump to fail. 
	bne $t2, $v0, judge		# If not matched, 

success:jal print_lf			# Print line-feed
	move $a0, $s6			
	li $v0, 4			
	syscall				# Print 'Success!Location: '
	move $a0, $t0			
	li $v0, 1
	syscall				# Print location
	jal print_lf
	j main

fail:	jal print_lf
	move $a0, $s7
	li $v0, 4
	syscall				# Print 'Fail!' string
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
