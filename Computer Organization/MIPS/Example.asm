      .data  
alphabet: .asciiz "Alpha ","Bravo ","Charlie ","Delta ","Echo ","Foxtrot ","Golf ","Hotel ","India ","Juliet ","Kilo ","Lima ","Mike ","November ","Oscar ","Papa ","Quebec ","Romeo ","Sierra ","Tango ","Uniform ","Victor ","Whisky ","X-ray ","Yankee ","Zulu "  
al_offset: .word 0,7,14,23,30,36,45,51,58,65,73,79,85,91,101,108,114,122,129,137,144,153,161,169,176,184  
number: .asciiz "zero ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ","eight ","nine "  
n_offset: .word 0,6,11,16,23,29,35,40,47,54   
myname: .asciiz "\r\nNAME: Wu Yiting\r\n"  
myid:   .asciiz "ID: 1200012875\r\n"  
  
      .text  
      .globl main  
      #? word length[] = 4  
main:   li $v0, 12  
    syscall  
    sub $t1, $v0, 63    # is '?" ?  
    beqz $t1, exit  
    sub $t1, $v0, 48    # 0 ascii  
    slt $s0, $t1, $0    # if t1 < 0 then s0 = 1  
    bnez $s0, others  
      
    sub $t2, $t1, 10  
    slt $s1, $t2, $0  
    bnez $s1, getnum  
      
    # is capital?  
    sub $t2, $v0, 91  
    slt $s3, $t2, $0    # if v0 <= 'Z' then s3 = 1  
    sub $t3, $v0, 64      
    sgt $s4, $t3, $0    # if v0 >='A' then s4 = 1  
    and $s0, $s3, $s4   # if s3 == 1 && s4 == 1   
    bnez $s0, getword     
      
    # is lower case?  
    sub $t2, $v0, 123  
    slt $s3, $t2, $0    # if v0 <= 'z' then s3 = 1  
    sub $t3,$v0, 96       
    sgt $s4, $t3, $0    # if v0 >= 'a' then s4 = 1  
    and $s0, $s3, $s4  
    bnez $s0, getword  
    j others  
      
getnum: add $t2, $t2, 10  
    sll $t2, $t2, 2  
    la $s0, n_offset  
    add $s0, $s0, $t2  
    lw $s1, ($s0)  
    #sll $s1, $s1, 1  
    la $a0, number  
    add $a0, $a0, $s1  
    li $v0, 4  
    syscall  
    j main  
      
getword:sub $t3, $t3, 1  
    sll $t3, $t3,2  
    la $s0, al_offset  
    add $s0, $s0, $t3  
    lw $s1, ($s0)  
    #sll $s1, $s1, 1  
    la $a0, alphabet  
    add $a0, $s1, $a0  
    li $v0, 4  
    syscall  
    j main  
      
others: and $a0, $0, $0  
    add $a0, $a0, 42  
    li $v0, 11  
    syscall  
    j main  
      
exit:   la $a0, myname  
    li $v0, 4  
    syscall  
    la $a0, myid  
    li $v0, 4  
    syscall  
    li $v0, 1  
    syscall  