TITLE My First Program (Test.asm)
INCLUDE Irvine32.inc

.data
prompt byte "copied",0
prompt2 byte "string2: ",0
string1 byte "william",0
count byte sizeof string1
string2 byte 20 dup(?)
.code
main PROC
mov ecx,lengthof string1
mov esi,offset string1
mov edi,offset string2
cld
rep movsb
mov edx,offset prompt2
call writestring
call crlf
mov edx,offset string2
call writestring
call crlf
mov edx,offset prompt
call writestring
call crlf
exit
main ENDP
END main