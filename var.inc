DATASEG
	Malloc dd 120 dup(0)	;// "fake" stack
	malloc_index dw 0	;// the index of the "fake" stack

CODESEG


;// pushed the last allocated pointer to the stack 
proc get_pointer basic far
	mov si, [malloc_index]	;// gets the current index
	push [word ptr Malloc + si]	;// pushes the current element
	ret 0
endp get_pointer


;// appends ECX to the fake stack 'Malloc'
proc Fake_push basic far 
	inc si;// next index (init must be: mov si, [malloc_index])
	cmp si, 120 ;// the end of the stack
	jge Fake_push_Error ;// there is an error (overflow)
	mov [Malloc+si], ecx	;// the inserting action
	mov [malloc_index], si	;// update the index
	
Fake_push_Error:
	;// overflow error
	ret 0
endp Fake_push



;// pops from the fake stack 'Malloc'
proc Fake_pop basic far
	mov si, [malloc_index]	;// get the index at si, in order to use it
	mov [Malloc+si], 00 	;// put 00 at the current cell
	dec si	;// current cell -> prev cell
	mov [malloc_index], si	;// save the new index
	ret 0
endp Fake_pop
