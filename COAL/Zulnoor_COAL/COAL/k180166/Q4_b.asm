TITLE My First Program (Test.asm)
INCLUDE Irvine32.inc

.data
prompt1 byte " found",0
prompt2 byte  " notfound",0
string1 byte "william",0
string2 byte "well",0
count byte 1
.code
main PROC
mov ecx,lengthof string1
mov edi,offset string1
mov esi,offset string2
mov al,string2
cld
repne scasb
jnz notfound
dec edi
mov ecx,lengthof string2-1
l1:
	mov bl,[edi]
	mov bh,[esi]
	cmp bl,bh
	jne notfound
	inc edi
	inc esi
	loop l1
found:
mov edx,offset string2
call writestring
mov edx,offset prompt1
jmp endd
notfound:
mov edx,offset string2
call writestring
mov edx,offset prompt2
jmp endd
endd:
call writestring
call crlf
exit
main ENDP
END main