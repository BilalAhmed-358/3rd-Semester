INCLUDE Irvine32.inc

.code
main PROC
push ebp
mov ebp,esp
mov eax,1
mov dh,1
mov dl,35
mov cl,1
mov ch,0
mov esi,1
call pyramid
pop ebp
ret

exit
main ENDP


pyramid PROC
push ebp
mov ebp,esp
movzx ebx,cl
push ebx
mov ebx,0
L1:
call gotoxy
call writedec
add eax,eax
add dl,8
add ebx,1
cmp ebx,esi
jb L1
call crlf
call crlf
add esi,2
inc dh
add ch,16
sub dl,ch
pop ebx
mov cl,bl
ADD cl,1
cmp cl,5
ja L2
call pyramid
L2: pop ebp
ret
pyramid ENDP
END main