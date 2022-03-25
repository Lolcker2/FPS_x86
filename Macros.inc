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
