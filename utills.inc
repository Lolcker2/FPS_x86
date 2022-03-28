CODESEG
include "macros.inc"
include "Float.inc"
include "Ray.inc"
include "Trigo.inc"
include "var.inc"


;// returns num^pow as a dword
proc power basic far
uses eax, ebx, ecx
arg returns @@result:dword, @@num:dword, @@pow:word
	mov bx, [@@pow]	;// prep for comparing pow to zero
	mov [@@result], 1
	
	@@loop_start:	
		cmp bx, 00
		jz	@@loop_end ;// if pow is zero, end the calculation
		
		;// else (pow is not zero),
		;// (it be greater than zero)
		
		mov ecx, [@@num]
		mov eax, [@@result]
		
		mul ecx	;// multiplying result by num, the result goes to DX|AX,
		;// though i only need the first 16bits (AKA word), (AX)
		
		mov [@@result], eax	;// result = result * num
		jmp @@loop_start	;// loop that
	@@loop_end:
	ret
endp power



;// returns a % b as a word
proc Modulo basic far
uses ax	;// reset ax to its original value at a return
arg returns @@result:word, @@a:word, @@b:byte	;// the arguments
	mov ax, [@@a]	
	div [@@b]	;// divide

	xor al, al	;// reset al, cuz the reminderis at ah
	mov [byte ptr @@result], ah
	ret
endp Modulo



;// calculates the factorial of any given number 
;// returns it as a dword
proc factorial basic far
uses eax, ebx
arg returns @@result:dword, @@num:word
	
	mov eax, 1	;// the value i'll be multiplying by at the start
	mov ebx, [dword ptr @@num]	;// get num into ebx so i could multiply it
	@@loop_start:	;// multiply by ebx, then dec .... till 0
	
		cmp ebx, 00	;// if ebx is zero
		je @@loop_end	;// then we done
		;// not done
		mul ebx		;// then multiply by ebx
		dec ebx		;// and decrment ebx
		jmp @@loop_start	;// loop that
		
	@@loop_end:
	mov [@@result], eax	;// we done, then return the result
	ret
endp factorial


;// shifts any base 10 number,
;// one digit to the left
proc shift_left basic far
uses eax, ebx, edx
arg returns @@result:dword, @@num:dword

	mov eax, [@@num]
	mov ebx, 10	
	mul ebx	;// nultiply @@num by 10
	mov [@@result], eax	;// set the result
	ret	;// return
endp shift_left




;// shifts any base 10 number,
;// one digit to the right
proc shift_right basic far
uses eax, ebx, edx
arg returns @@result:dword, @@num:dword

	mov eax, [@@num]
	mov ebx, 10	
	div ebx	;// nultiply @@num by 10
	mov [@@result], eax	;// set the result
	ret	;// return
endp shift_right


proc num_of_digits basic far
uses eax, ecx
arg returns @@digits:byte, @@num:dword

	counter equ cl	;// for comfort reasons
	mov counter, 00	;// reset the counter
	
	mov eax, [@@num]	;// inserting @@num into eax, to preform instructions on it
	
	@@loop1:
		
		cmp eax,00	;// compare num to zero
		je @@loop_end	;// if it is, then stop looping, isn't, then continue
		
		%sr eax		;// shift num to the right (010 -> 001)
		pop[eax]	;// num = shift_right(num)
		inc counter	;//	counter++
		jmp @@loop1	;// loop that
	@@loop_end:
	
	mov [@@digits], counter	;// return the number of digits
	ret	;// return
endp num_of_digits


