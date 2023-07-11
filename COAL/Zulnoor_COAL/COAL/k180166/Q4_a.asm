include Irvine32.inc
.data
string byte "Hey there!!! you okay? Are you feeling well now??",0
slfPtr byte ($ - string)
p1 byte "Enter start index : ",0
p2 byte "Enter last index : ",0
subString byte 50 dup(?)
.code

main proc

mov edx , offset string
call writeString
call crlf
mov edx , offset p1
call writeString
call readInt
mov ebx , eax
mov edx , offset p2
call writeString
call readInt

mov esi , offset string
add esi , ebx
mov edi , offset subString

mov ecx , eax
l1:
 movsb
 loop l1

 mov esi , 0
 mov ecx , lengthof subString
 mov eax,0
 l2 :
 mov al , subString[esi]
 call writeChar
 inc esi
 loop l2
 call crlf
main endp
end main