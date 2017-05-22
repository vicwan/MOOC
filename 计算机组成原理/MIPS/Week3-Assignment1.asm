.data
caps:	.asciiz	"Alpha", "Bravo", "China", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliet", "Kilo", "Lima", "Mary", "November", "Oscar", "Paper", "Quebec", "Research", "Sierra", "Tango", "Uniform", "Victor", "Whisky", "X-ray", "Yankee", "Zulu"
lows:	.asciiz "alpha", "bravo", "china", "delta", "echo", "foxtrot", "golf", "hotel", "india", "juliet", "kilo", "lima", "mary", "november", "oscar", "paper", "quebec", "research", "sierra", "tango", "uniform", "victor", "whisky", "x-ray", "yankee", "zulu"
letter_offset:	.word 0, 6, 12, 18, 24, 29, 37, 42, 48, 54, 61, 66, 71, 76, 85, 91, 97, 104, 113, 120, 126, 134, 141, 148, 154, 161 

nums:	.asciiz	"zero", "First", "Second", "Third", "Fourth", "Fifth", "Sixth", "Seventh", "Eighth", "Ninth"
num_offset:	.word 0, 5, 11, 18, 24, 31, 37, 43, 51, 58, 64

char:	.asciiz	"*"

.text
.globl load

load:				# Load the addresses of these arrays.
la $s1, caps
la $s2, lows
la $s3, letter_offset
la $s4, nums
la $s5, num_offset

main:
# listen to the input and select a branch 
li $v0, 12
syscall
move $t0, $v0			# Load input character into $t0, as global. 
beq $t0, 63, termination	# Firstly, judge the input character is '?' or not. If yes, turn 'termination' to terminate the program.
# if	64 < x < 91  -> Capital letter
li $t3, 64			# A (Ascii) = 65
li $t4, 91			# Z (Ascii) = 90 
jal judge			# Turn to 'judge' to judge if the input character is CAPITAL letter.
bnez $t1, getCap		# If yes, turn to 'getCap' to print the supposed word.

				# if	96 < x < 123 -> Lowercase letter
li $t3, 96
li $t4, 123
jal judge
bnez $t1, getLo
				# if	47 < x < 58  -> Number
li $t3, 47
li $t4, 58
jal judge
bnez $t1, getNum
				
j else				# If all of the judgements from the above failed, turn to 'else' to print '*'.
				
getCap:				# Got capital letter input
sub $t1, $t0, 65		# To get the offset of 'letter_offset' array
mul $t1, $t1, 4			# Load the offset into $t1
add $t1, $t1, $s3		# Load supposed address in 'letter_offset' array
lw $t2, ($t1)			# To get the offset of 'letter_offset' array
add $t2, $t2, $s1		# Load supposed address in 'caps' array
la $a0, ($t2)			# Load the string into $a0
li $v0, 4			# System call to print a string
syscall
j main

getLo:				# Got lowercase letter input
sub $t1, $t0, 97
mul $t1, $t1, 4
add $t1, $t1, $s3
lw $t2, ($t1)
add $t2, $t2, $s2
la $a0, ($t2)
li $v0, 4
syscall
j main

getNum:				# Got number input
sub $t1, $t0, 48
mul $t1, $t1, 4
add $t1, $t1, $s5
lw $t2, ($t1)
add $t2, $t2, $s4
la $a0, ($t2)
li $v0, 4
syscall
j main

else:				# If the input character is not supposed to, print '*'.
la $a0, char
li $v0, 4
syscall
j main

judge:				# Judge whether the value in $t1.
slt $t4, $v0, $t4
slt $t3, $t3, $v0
and $t1, $t4, $t3		# If value in $t1 is equal to 1, then the branch is the right one.
jr $ra				# Jump back.

# terminate the program
termination:
li $v0, 10
syscall
