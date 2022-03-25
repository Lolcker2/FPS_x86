CODESEG


;// returns the whole part
;// of the decimal number
proc F_int basic far
uses eax, ebx, si
arg returns @@int:dword, @@self:ptr Float
	mov si, [@@self]	;// accessing @@self
	%pow 10, ds:si + Float.exponent	;// 10^exponent
	pop[dword ptr ebx]	;// insert that value into ebx
	
	mov si, [@@self]	;// accessing @@self
	mov eax, [ds:si + Float.significand]
	div ebx	;// significand / 10^exponent
	;// result at eax
	
	mov [@@int], eax	;// return the result  (the int part)
  ret	
endp F_int



proc F_addition basic far
uses eax, ebx, cx, dx, si
arg returns @@result: ptr Float, @@self:ptr Float, @@num:ptr Float
	
		;// compare self.significand to zero			
		mov si, [@@self]		;// accessing @@self		 
		mov eax,[ds:si + Float.significand]
		mov dx, [ds: si + Float.exponent]
		cmp eax, 00
		
		;// if self.significand is zero
		;// then self + num = num
		;// so return num
		mov si, [@@num]	;// accessing @@num
		mov ebx, [ds:si + Float.significand]
		mov cx, [ds:si + Float.exponent]
		jne @@Addition1		;// if self.significand isn't zero, jump to the next section
		
		mov si, [@@result]	;// accessing @@result
		mov [ds:si + Float.significand], ebx	;// set result.significand
		mov [ds:si + Float.exponent], cx	;// set result.exponent
		ret	;// return

	@@Addition1:
	
		;// if num.significand is zero
		;// then self + num = self
		;// so return self
		cmp ebx, 00
		jne @@Addition2
		mov [ds:si + Float.significand], eax	;// set result.significand
		mov [ds:si + Float.exponent], dx	;// set result.exponent
		ret	;// return
		
	@@Addition2:
		
		;// compare the exponents
		;// and goto the right section based on the exponents
		cmp dx, cx
		jg @@Addition4	;// if self.exponent > num.exponent
		jne @@Addition5	;// if self.exponent < num.exponent
		
	@@Addition3:
		
		;// if the program got here
		;// then self.exponent == num.exponent
		;// meaning, I can add the significands, then return the result
		add eax, ebx	;// adds the significands 
		mov [ds:si + Float.exponent], dx	;// set result.exponent
		mov [ds:si + Float.significand], eax	;// set result.significand
		ret	;// return
		
	@@Addition4:
	
		;// if the program got here
		;// then self.exponent > num.exponent
		;// here I'll correct that, then go back to Addition3
		counter equ dx	;// for comfort purposes
		sub counter, cx	;// the number of times the loop must run
		;// self.exponent - num.exponent
		
		@@loop1:
			
			%sl ebx	;// shifts left num.significand
			pop [ebx]	;// retriving the shifted significand
			
			inc cx	;// increment num.exponent
			dec counter
			
			cmp counter, 00
			jne @@loop1		;// if the loop isn't done, loop it
			jmp @@Addition3	;// if it's done, then the exponents are equal
	
	
	@@Addition5:
	
		;// if the program got here
		;// then self.exponent < num.exponent
		;// here I'll correct that, then go back to Addition3
		counter equ cx	;// for comfort purposes
		sub counter, dx	;// the number of times the loop must run
		;// num.exponent - self.exponent
		
		@@loop2:
			
			%sl eax	;// shifts left slef.significand
			pop [eax]	;// retriving the shifted significand
			
			inc dx	;// increment self.exponent
			dec counter
			
			cmp counter, 00
			jne @@loop2		;// if the loop isn't done, loop it
			jmp @@Addition3	;// if it's done, then the exponents are equal
	ret
endp F_addition


;// ------------------------------------------------- must go over ------------------------------------------------- 


proc F_subtruction basic far
uses eax, ebx
arg returns @@result:ptr Float, @@self:ptr Float, @@num:ptr Float
	mov si, [@@num]	;// accessing @@num
	mov eax, [ds:si + Float.significand]	;// get num.significand into eax
	mov ebx, -1
	
	mul ebx	;// multiply num.significand by (-1)
	mov [ds:si + Float.significand], eax	;// antyaliasing
	
	push[@@self]
	push[@@num]
	call F_addition
	
	pop[@@result]
	ret
endp F_subtruction



proc F_divition basic far
uses eax, ebx
arg returns @@result:ptr Float, @@self:ptr Float, @@num:ptr Float
	mov si, [@@self]	;// accessing @@self
	mov ax, [ds:si + Float.exponent]
	
	mov si, [@@num]		;// accessing @@num
	mov bx, [ds:si + Float.exponent]
	
	sub ax, bx	;// self.exponent - num.exponent
	mov si, [@@result]
	mov [ds:si + Float.exponent], ax	;// result.exponent = self.exponent - num.exponent

	
	mov si, [@@self]	;// accessing @@self
	mov eax, [ds:si + Float.significand]
	
	mov si, [@@num]		;// accessing @@num
	mov ebx, [ds:si + Float.significand]
	
	div ebx	;// self.significand / num.significand
	
	mov si, [@@result]
	mov [ds:si + Float.significand], eax	;// result.significand = self.significand / num.significand
	
	ret	;// return
endp F_divition




proc F_multiplication basic far
uses eax, ebx
arg returns @@result:ptr Float, @@self:ptr Float, @@num:ptr Float
	mov si, [@@self]	;// accessing @@self
	mov ax, [ds:si + Float.exponent]
	
	mov si, [@@num]		;// accessing @@num
	mov bx, [ds:si + Float.exponent]
	
	add ax, bx	;// self.exponent + num.exponent
	mov si, [@@result]
	mov [ds:si + Float.exponent], ax	;// result.exponent = self.exponent + num.exponent

	
	mov si, [@@self]	;// accessing @@self
	mov eax, [ds:si + Float.significand]
	
	mov si, [@@num]		;// accessing @@num
	mov ebx, [ds:si + Float.significand]
	
	mul ebx	;// self.significand * num.significand
	
	mov si, [@@result]
	mov [ds:si + Float.significand], eax	;// result.significand = self.significand * num.significand
	
	ret	;// return
endp F_multiplication



