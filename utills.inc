CODESEG



;// returns num^pow as a word
proc power basic far
uses ax, bx, cx
arg returns @@result:word, @@num:word, @@pow:byte
	mov bh, [@@pow]	;// prep for comparing pow to zero
	mov [@@result], 1
	
	@@loop_start:	
		cmp bh, 00
		jz	@@loop_end ;// if pow is zero, end the calculation
		
		;// else (pow is not zero),
		;// (it be greater than zero)
		
		mov cx, [@@num]
		mov ax, [@@result]
		
		mul cx	;// multiplying result by num, the result goes to DX|AX,
		;// though i only need the first 16bits (AKA word), (AX)
		
		mov [@@result], ax	;// result = result * num
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
uses eax, ebx
arg returns @@result:dword, @@num:dword

	mov eax, [@@num]
	mov ebx, 10	
	mul ebx	;// nultiply @@num by 10
	mov [@@result], eax	;// set the result
	ret	;// return
endp shift_left




