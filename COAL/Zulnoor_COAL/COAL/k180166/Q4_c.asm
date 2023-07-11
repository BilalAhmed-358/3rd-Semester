TITLE My First Program (Test.asm)
INCLUDE Irvine32.inc

.data
prompt1 byte "string1 is greater",0
prompt2 byte "string2 is greater",0
prompt3 byte "both strings are same/equal",0
string1 byte "will",0
string2 byte "william",0
.code
main PROC
mov ecx,lengthof string1
mov esi,offset string1
mov edi,offset string2
cld
repe cmpsb
jb str2
je equal
mov edx,offset prompt1
jmp finish
str2:
mov edx,offset prompt2
jmp finish
equal:
mov edx,offset prompt3
finish:
call writestring
exit
main ENDP
END main