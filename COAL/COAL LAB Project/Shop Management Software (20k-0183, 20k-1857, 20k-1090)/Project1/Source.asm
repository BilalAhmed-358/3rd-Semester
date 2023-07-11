TITLE My First Program (Test.asm)
INCLUDE Irvine32.inc
BUFFER_SIZE=500
TitleHeading proto, arr: ptr byte
CompHeading proto, arr: ptr byte
CustomerPanelHeading proto, arr: ptr byte
AdminPanelHeading proto, arr: ptr byte
PrintCurrentBill proto, arr: dword




.data 
CustomerBill byte 500 DUP(?)
ItemPsent byte "Enter the products you want to buy:",0
ProductFileName byte "Products.txt",0
Deletemessage byte "The product has been deleted",0
CustomerNameSent byte "Enter the name of the customer",0
EnterProductPrompt byte "Enter the products the customer has bought:",0
ProductName byte 10 DUP(0)
CustomerName byte 9 DUP(0)
DelProdsent byte " ",0
ProdAvailableMessage byte "The Products currently available are ",0
productNamePrompt byte "Enter the name of the product you want to enter",0
fileHandle HANDLE ?
wrongpassprompt byte "You entered the wrong password enter again",0
thankyouprompt byte "Thank You so much for choosing your store",0dh,0ah
			   byte "Regards from Zulnoor, Wamiq and Bilal :)",0
passwordprompt byte "Enter the password",0
adminpanelsent byte "Choose any of the give options", 0dh, 0ah
	byte "1. Add new items ",0dh,0ah
	byte "2. View available items",0dh,0ah
	byte "3. Delete items",0dh,0ah
	byte "4. Return to main menu",0dh,0ah
	byte "5. Exit",0

main_message byte "Choose any of the give options", 0dh, 0ah
	byte "1. Buy Products ",0dh,0ah
	byte "2. Login as Administrator",0dh,0ah
	byte "3. Exit",0
TitleHeadingsent byte	"====================================",0dh,0ah 
	byte "Proudly Presented by:", 0dh, 0ah
	byte "1) Bilal Ahmed Khan (20k-0183)",0dh,0ah
	byte "2) Zulnoor Siddiqui (20k-1090)",0dh,0ah
	byte "1) Mohammad Wamiq Akram (20k-1857)",0dh,0ah
	byte	"====================================",0dh,0ah 
	byte	"Press any key to continue....",0


CompHeadingsent byte "==========================================================",0dh,0ah
	   byte "		Stationary Shop Managment Software",0dh,0ah
	   byte "Provider of best sationary items at most reasonable prices",0dh,0ah
	   byte	"==========================================================",0

customerpanelheadingsent byte "==========================================================",0dh,0ah
	 
	   byte "			CUSTOMER PURCHASE			",0dh,0ah
	   byte	"==========================================================",0

adminpanelheadingsent byte "==========================================================",0dh,0ah
	 
	   byte "			ADMIN PANEL			",0dh,0ah
	   byte	"==========================================================",0


PrintCurrentBillsent BYTE "Current Bill is ",0




.code



main PROC
mov eax, 0
mov ebx, 0
mov ecx, 0
mov edx, 0
strt:
invoke TitleHeading, addr TitleHeadingsent
invoke CompHeading, addr CompHeadingsent
mov edx, offset main_message
call writestring
mov eax,0
call crlf
call readdec

cmp eax, 1
je ItemP
cmp eax, 2
je AdmP
cmp eax, 3
je EE
jmp EE

ItemP:
call ItemPurchase
jmp EE
AdmP:
call AdminPanel
EE:
mov edx, offset thankyouprompt
call writestring
call DumpRegs
exit
main ENDP



TitleHeading proc, arr: ptr byte
call clrscr
mov edx, arr
call writestring
mov eax, 1000
call delay
call clrscr
ret 4
TitleHeading endp



CompHeading proc, arr: ptr byte
call clrscr
mov edx, arr
call writestring
call readchar
call crlf
ret 4
CompHeading endp



CustomerPanelHeading proc, arr: ptr byte
call clrscr
mov edx, arr
call writestring
ret 4
CustomerPanelHeading endp



AdminPanelHeading proc, arr: ptr byte
call clrscr
mov edx, arr
call writestring
ret 4
AdminPanelHeading endp

PrintCurrentBill proc, arr: dword
mov edx, offset PrintCurrentBillsent
call writestring
mov eax, arr
call writedec
ret 4
PrintCurrentBill endp


ItemPurchase Proc
Local strlegth : dword
mov edx, offset CustomerNameSent
call writestring
call crlf
mov edx, offset CustomerName
mov ecx, 10
call readstring
call crlf
mov [CustomerName+5],"." 
mov [CustomerName+6],"t" 
mov [CustomerName+7],"x" 
mov [CustomerName+8],"t" 
mov [CustomerName+9],0
mov edx, offset EnterProductPrompt
call writestring
call crlf
mov edx, offset CustomerName
call CreateOutputFile
mov fileHandle, eax
mov edx, offset CustomerBill
mov ecx, 500
call Readstring
mov strlegth,eax

mov eax, fileHandle
mov edx, OFFSET CustomerBill
mov ecx, strlegth
call WriteToFile
ret
ItemPurchase endp



AdminPanel proc
Local var1: dword, var2:dword, var3:dword, choice:dword
EnterPass:
call crlf
mov edx, offset passwordprompt
call writestring
call crlf 
call readdec
mov var1,eax
call readdec
mov var2,eax
call readdec
mov var3, eax
cmp var1,1
jne wrongpass
cmp var2,2
jne wrongpass
cmp var3,3
jne wrongpass
mov edx, offset adminpanelsent
call writestring
call crlf
call readdec
mov choice, eax
cmp choice, 1
je AddProd
cmp choice,2
je ViewProd
cmp choice,3
je DelProd
cmp choice, 4
jmp Maanmenu
AddProd:
mov edx, offset ProductFileName
call CreateOutputFile
mov fileHandle, eax
mov edx, offset productNamePrompt
call writestring
call crlf

mov edx, offset ProductName
mov ecx, 11
call readstring
mov eax, fileHandle
mov edx, offset ProductName
call WriteToFile
jmp Maanmenu

ViewProd:
mov edx, offset ProductFileName
call OpenInputFile
mov fileHandle,eax
mov edx, offset ProductName
mov ecx, 10
call ReadFromFile
mov ProductName[eax],0
mov edx, offset ProductName
call writestring
mov eax, 1000
call delay
call crlf
jmp Maanmenu


DelProd:
mov edx, offset ProductFileName
call CreateOutputFile
mov fileHandle, eax
mov edx, offset DelProdSent
mov eax, fileHandle
mov edx, offset ProductName
call WriteToFile
mov edx, offset Deletemessage
call writestring
mov eax, 1000
call delay
jmp Maanmenu


Maanmenu:
call main
wrongpass:
mov edx, offset wrongpassprompt
call writestring
call crlf
jmp EnterPass
ret
AdminPanel endp

END main