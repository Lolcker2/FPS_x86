CODESEG

Macro %pow num, pow
	push[num]
	push[pow]
	call power
endm %pow


Macro %mod num, num2
	push[num]
	push[num2]
	call modulo
endm %mod


Macro %alloc value, name
	mov ecx, value
	mov bp, si
	call Fake_push
	name equ [bp-2]
	mov name, value
	
endm %alloc


Macro %fact value
	push[value]
	call factorial
endm %fact


Macro %sl value
	push[value]
	call shift_left
endm %sl


Macro %sr value
	push[value]
	call shift_right
endm %sr


Macro %digits num
	push[num]
	call num_of_digits
endm %digits



Macro %sin num
	push[num]
	call F_sin
endm %sin


Macro %cos num
	push[num]
	call F_cos
endm %cos


Macro %exponent_overflow name
	mov si, [name]	;// accessing name
	mov cx, [ds:si + Float.exponent]	;// accessing name.exponent
	cmp cx, max_exponent	;// check if name.exponent it larger than the max exponent
	jng @@end	;// if it's not greater than the max, then proc is done
	
	;// it's larger
	mov [ds:si + Float.exponent], max_exponent	;// set the exponent to the max exponent
	
	mov bx, max_exponent	
	sub cx, bx	;// cx -> name.exponent - max_exponent
	
	;// shift the significand to the right cx times
	mov ebx, [ds:si + Float.significand]	;// accessing name.significand
	counter equ cx	;//  create the name counter for cx
	
	@@right_shift_loop:
		%sr ebx	;// shifts right name.significand
		pop [ebx]	;// retriving the shifted significand
		
		dec counter	;// decrement counter by 1
		cmp counter, 00
		jne @@right_shift_loop ;// if counter isn't 0, loop that

	mov [ds:si + Float.significand], ebx	;// put the shifted significand back in it's place
	
	@@end:
endm %exponent_overflow