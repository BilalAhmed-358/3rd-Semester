TITLE My First Program (Test.asm)
INCLUDE Irvine32.inc

.data
st1 byte "before sign extension",0
st2 byte "after sign extension",0
var SBYTE -48
.code
main PROC
mov EAX,0
mov edx ,0
mov AL,var
mov BL,5
mov edx,offset st1
call writestring
mov edx,0
IDIV BL
call DumpRegs
mov edx ,0
mov AL,var
CBW
mov edx,offset st2
call writestring
mov edx,0
IDIV BL
call DumpRegs
exit
main ENDP
END main