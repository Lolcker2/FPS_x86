DATASEG
	depth dw 10	;// the depth for the loop at the tylor series

CODESEG


proc F_cos basic far
uses bx, eax, edx
arg returns @@result:dword, @@num:dword
	mov bp, si
	
	counter equ bx	;// pointer so si, di, bp, or bx
	mov counter, [depth]
	
	@@loop1:
	
		;// computing the (-1)^counter
		%mod counter, 2		;// pushes counter % 2 into the stack
		pop[edx]	;// retrives counter % 
		mov eax, -1
		mul edx	;// multiplying by -1
		%alloc eax, min_one	;// allocating min_one as a variable
		;// containing the value of (-1)^counter
		
		mov eax, 2
		mov edx, [dword ptr counter]
		mul edx	;// multiplying counter by 2
		%alloc eax, two_count	;// allocating two_count as a variable
		;// containing the value of counter * 2
		
		%fact eax	;// pushes the factorial of 2 * counter
		pop[edx]	;// retriving it
		%alloc edx, two_count_fact	;// allocating two_count_fact as a variable
		;// containing the value of (counter * 2)!
		
		
	
		mov eax, min_one	;// (-1)^counter
		mov edx, two_count
		%pow @@num, edx	;// num^(2 * counter)
		pop [edx]	;// retrive that into ebx
		mul edx		;// eax -> (-1)^counter * num^(2 * counter)
		
		
		mov edx, two_count_fact	;//  (counter * 2)!
		div edx		;// eax -> [(-1)^counter * num^(2 * counter)] : (counter * 2)!
		
		add [@@result], eax		;// resut += [(-1)^counter * num^(2 * counter)] : (counter * 2)!
		
		dec counter
		cmp counter, 00
		jne @@loop1
	
	ret
endp F_cos








proc F_sin basic far
uses bx, eax, edx
arg returns @@result:dword, @@num:dword
	
	counter equ bx	;// pointer so si, di, bp, or bx
	mov counter, [depth]
	
	@@loop1:
	
		;// computing the (-1)^counter
		%mod counter, 2		;// pushes counter % 2 into the stack
		pop[edx]	;// retrives counter % 
		mov eax, -1
		mul edx	;// multiplying by -1
		%alloc eax, min_one	;// allocating min_one as a variable
		;// containing the value of (-1)^counter
		
		mov eax, 2
		mov edx, [dword ptr counter]
		mul edx	;// multiplying counter by 2
		mov edx, 1
		add eax, edx 
		%alloc eax, two_count	;// allocating two_count as a variable
		;// containing the value of counter * 2 + 1
		
		%fact eax	;// pushes the factorial of 2 * counter + 1
		pop[edx]	;// retriving it
		%alloc edx, two_count_fact	;// allocating two_count_fact as a variable
		;// containing the value of (counter * 2 + 1)!
	
	
		mov eax, min_one	;// (-1)^counter
		mov edx, two_count
		%pow @@num, edx	;// num^(2 * counter + 1)
		pop [edx]	;// retrive that into ebx
		mul edx		;// eax -> (-1)^counter * num^(2 * counter + 1)
		
		
		mov edx, two_count_fact	;//  (counter * 2 + 1)!
		div edx		;// eax -> [(-1)^counter * num^(2 * counter + 1)] : (counter * 2 + 1)!
		
		add [@@result], eax		;// resut += [(-1)^counter * num^(2 * counter + 1)] : (counter * 2 + 1)!
		
		dec counter
		cmp counter, 00
		jne @@loop1
		
	ret
endp F_sin


