.data
caps:	.asciiz	"Alpha", "Bravo", "China", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliet", "Kilo", "Lima", "Mary", "November", "Oscar", "Paper", "Quebec", "Research", "Sierra", "Tango", "Uniform", "Victor", "Whisky", "X-ray", "Yankee", "Zulu"
lows:	.asciiz "alpha", "bravo", "china", "delta", "echo", "foxtrot", "golf", "hotel", "india", "juliet", "kilo", "lima", "mary", "november", "oscar", "paper", "quebec", "research", "sierra", "tango", "uniform", "victor", "whisky", "x-ray", "yankee", "zulu"
letter_offset:	.word 0, 6, 12, 18, 24, 29, 37, 42, 48, 54, 61, 66, 71, 76, 85, 91, 97, 104, 113, 120, 126, 134, 141, 148, 154, 161 

nums:	.asciiz	"First", "Second", "Third", "Fourth", "Fifth", "Sixth", "Seventh", "Eighth", "Ninth", "zero"
num_offset:	.word 0, 6, 13, 19, 26, 32, 38, 46, 53, 59

char:	.asciiz	"*"

.text
.globl load

load:
la $s1, caps
la $s2, lows
la $s3, letter_offset
la $s4, nums
la $s5, num_offset

main:
# listen to the input and select a branch 
li $v0, 12
syscall
move $t0, $v0
beq $t0, 63, termination
# if	64 < x < 91  -> Capital letter
li $t3, 64
li $t4, 91
jal judge
bnez $t1, getCap
j termination
# if	96 < x < 123 -> Lowercase letter

# if	47 < x < 58  -> Number
# else  -> print '*'


getCap:
sub $t1, $t0, 65
mul $t1, $t1, 4
add $t1, $t1, $s3
lw $t2, ($t1)
add $t2, $t2, $s1
la $a0, ($t2)
li $v0, 4
syscall
j main


getLo:


getNum:


else:
la $a0, char
li $v0, 4
syscall

judge:
slt $t4, $v0, $t4
slt $t3, $t3, $v0
and $t1, $t4, $t3
jr $ra

termination:
li $v0, 12
syscall