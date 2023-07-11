TITLE My First Program (Test.asm)
INCLUDE Irvine32.inc

.data
prmain byte "Enter 24 elements in array",0
prompt byte "Array",0
prompt1 Byte "average of rows",0
prompt2 Byte "average of coloumns",0
prompt3 Byte "average of whole table",0
space byte " ",0
table	word 6 dup(?) 
row_size=($-table)		
		word 6 dup(?) 
		word 6 dup(?) 
		word 6 dup(?) 
row_index dword 0
col_index dword 0
count1 dword ?
count2 dword 6
num word 6
.code
main PROC
mov esi,0
mov ecx,4
mov count2,6
mov edx,offset prmain
call writeString
mov eax,0
call crlf
mov ebx,offset table
looop1:
	mov esi,0
	mov count1,ecx
	mov ecx,count2
	mov edx,0
	looop2: 
		call readhex
		mov [ebx+esi*type table],ax
		add esi,1
		loop looop2
	mov ecx, count1
	add ebx,row_size
	loop looop1
call clrscr
mov esi,0
mov ecx,4
mov count2,6
mov edx,offset prompt
call writeString
mov eax,0
call crlf
mov ebx,offset table
mov edx,offset space
looop3:
	mov esi,0
	mov count1,ecx
	mov ecx,count2
	looop4: 
		mov aL,[ebx+esi*type table]
		call writeHEX
		call writestring
		add esi,1
		loop looop4
	call crlf
	mov ecx, count1
	add ebx,row_size
	loop looop3
call crlf

mov ecx,4
mov ebx,offset table
mov edx,offset prompt1
call writeString
L1:
	mov esi,col_index
	mov eax,0
	mov count1 ,ecx
	mov ecx ,count2
	mov edx,0
	L2:
		add ax,[ebx+esi*type table]
		add esi,1
		loop L2
	div num
	call crlf
	call writeDec
	mov ecx,count1
	add ebx,row_size
	loop L1

call crlf
mov esi,0
mov ecx,6
mov count2,4
mov num,4
mov edx,offset prompt2
call writeString
L3:
	mov ebx,offset table
	mov count1,ecx
	mov ecx,count2
	mov edx,0
	mov eax,0
	L4: 
		add ax,[ebx+esi*type table]
		add ebx,row_size
		loop l4
	div num
	call crlf
	call writedec
	mov ecx, count1
	add esi,1
	loop l3

call crlf
mov esi,0
mov ecx,4
mov count2,6
mov num,24
mov edx,offset prompt3
call writeString
mov eax,0
call crlf
mov ebx,offset table
L5:
	mov esi,0
	mov count1,ecx
	mov ecx,count2
	mov edx,0
	L6: 
		add ax,[ebx+esi*type table]
		add esi,1
		loop l6
	mov ecx, count1
	add ebx,row_size
	loop l5
div num
call writedec
exit
main ENDP
END main