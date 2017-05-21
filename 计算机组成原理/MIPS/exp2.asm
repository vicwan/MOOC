##
#####################################################
#    
#       输入两个整数并打印它们的和                  #
#        programed by stevie zou                    #                  
#           10-12-2008                              #      
#####################################################
##



######    text segment                    ###########
   
       .text
       .globl main

main:  la $t0, value       #$t0 保存初始值的地址
         
       li $v0, 5           #读取整数值（kernel serice 5）
       syscall
       sw $v0, 0($t0)      #保存读取的整数值

       li $v0, 5           #读取第二个整数
       syscall
       sw $v0, 4($t0)

       lw $t1, 0($t0)
       lw $t2, 4($t0)
       add $t3,  $t1, $t2   #求两个整数之和
       sw  $t3,8($t0)

       li $v0, 4            #打印字符串（kernel service 4)    
       la $a0, msg1   
       syscall

       li $v0, 1            #打印整数（kernel service 1）
       move  $a0, $t3
       syscall

######   data segment####################################

       .data
value: .word 0,0,0
msg1:  .asciiz "result= "

##end of file 