##
#####################################################
#    
#       ����������������ӡ���ǵĺ�                  #
#        programed by stevie zou                    #                  
#           10-12-2008                              #      
#####################################################
##



######    text segment                    ###########
   
       .text
       .globl main

main:  la $t0, value       #$t0 �����ʼֵ�ĵ�ַ
         
       li $v0, 5           #��ȡ����ֵ��kernel serice 5��
       syscall
       sw $v0, 0($t0)      #�����ȡ������ֵ

       li $v0, 5           #��ȡ�ڶ�������
       syscall
       sw $v0, 4($t0)

       lw $t1, 0($t0)
       lw $t2, 4($t0)
       add $t3,  $t1, $t2   #����������֮��
       sw  $t3,8($t0)

       li $v0, 4            #��ӡ�ַ�����kernel service 4)    
       la $a0, msg1   
       syscall

       li $v0, 1            #��ӡ������kernel service 1��
       move  $a0, $t3
       syscall

######   data segment####################################

       .data
value: .word 0,0,0
msg1:  .asciiz "result= "

##end of file 