TITLE My First Program (Test.asm)
INCLUDE Irvine32.inc

.data
prompt byte "Sum of odd numbers in array is: ",0
prompt1 byte "Array",0
space byte " ",0
array1 sword 100 DUP(?)
num sword 2
result sword 0

.code

main PROC
mov ecx ,lengthof array1
mov ebx,0
mov esi,offset array1
mov eax,0
mov edx,offset prompt1
call writestring
call crlf
mov edx,offset space
call randomize 
loop1:
		mov eax,100
		call randomrange 
		sub eax,50
		mov [esi],ax
		call writeint
		call writestring
		add esi,2
		loop loop1

call crlf

mov ecx,0
mov ecx, lengthof array1
mov eax,0
mov esi,offset array1
call oddsum
mov edx,offset prompt
call crlf
call writestring
movsx eax,result
call writeint
call crlf
exit
main ENDP

oddsum proc
cmp ecx,0
jz L1
mov edx,0
mov eax,[esi]
mov ebx,eax
idiv num
cmp edx,0
je L2
add result,bx
L2:
add esi,2
dec ecx
call oddsum
L1:
ret
oddsum ENDP
END main