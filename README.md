# FPS_x86




tk


tk is a copy of Wolfenstein 3D / Doom2
these are 2 different games but very similar

tk is a 3D FPS game (First Person Shooter), that uses raycasting to create the illution of 3D.

raycasting is the act of "shooting laser beams" across the screen, so that we would know the distance between objects (mesured by that laser),
and so different shades apply to object with different distances.

tk is a project that consists of xxx files.
let's walk through them (purpose and contant):

- Float.inc:
	this file is the file that contains include instructions, for all of the neccery files,
	so that we could use the "Float" struct.
	
- Float.aso:
	this file contains the definition of the "Float" struct,
	for the variables, to pointers for the mehods of that struct.
	
- Float.asm:
	this file contains all the procs & methods that are pointed to at the "Float.aso" file.
	let's go over those.
	
		- F_int:
			takes 1 param (Float pointer).
			returns a dword.
			
			*additional notes:
				returns the whole part of the given Float
				
				EXAMPLE:
					for the Float 7.99,
					F_int(7.99) -> returns 7
					
	
		- F_addition:
			takes 2 params (Float pointer, Float pointer).
			returns a Float pointer.
			
			*additional notes:
				returns the sum of the 2 floats
				
				EXAMPLE:
					for the 2 params 7.99, 1.01,
					F_addition(7.99, 1.01) -> returns 9.0
					
					
		- F_subtruction:
			takes 2 params (Float pointer, Float pointer).
			returns a Float pointer.
			
			*additional notes:
				returns the diffrance between the first float, and the second one,
				(first - second).
				
				EXAMPLE:
					for the 2 params 9.0, 1.01,
					F_addition(9.0, 1.01) -> returns 7.99
					
					
		- F_divition:
			takes 2 params (Float pointer, Float pointer).
			returns a Float pointer.
			
			*additional notes:
				returns the first float divided by the second one,
				(first / second).
				
				EXAMPLE:
					for the 2 params 9.0, 2.0,
					F_addition(9.0, 2.0) -> returns 4.5
					
					
		- F_multiplication:
			takes 2 params (Float pointer, Float pointer).
			returns a Float pointer.
			
			*additional notes:
				returns the multiplicaion between the first float and the second one,
				(first * second).
				
				EXAMPLE:
					for the 2 params 2.0, 4.5,
					F_addition(2.0, 4.5) -> returns 9.0
					
					


- Macros.inc:
	this file includes the implemintation of all the macros
	* since all of the macros call a proc,
	  then you can press "ctrl + f", then type the procs name (sarounded by double qoutes "),
	  or look at the next files
	
	let's go over them:
		
		- %pow:
			takes 2 params
			& calls "power"
			
		
		- %mod:
			takes 2 params
			& calls "Modulo"
		
		
		- %fact:
			takes 1 param
			& calls "factorial"
			
			
		- %sl:
			takes 1 param
			& calls "shift_left"
			
			
		- %sr:
			takes 1 param
			& calls "shift_right"


		- %alloc:
			takes 2 params
			& calls "Fake_push"
			(which allocates mem for the dinamic variable),
			%alloc sets that pointed value to the given one,
			& using the 'equ' instruction, creates a one word macro
			based on the given name
			
			
			
			
- utils.inc:
	this file includes the include instructions for all of the files (except main), also
	includes the implemintation of all the procs and mehods that have a wide range of use.
	let's go over them all:
		
		- power:
			takes 2 params (dword, word).
			returns a dword.
			
			*additional notes:
				returns the first variable raised to the second variable,
				(first^second)
				
				EXAMPLE:
					for the 2 params: 2, 3,
					power(2, 3) -> returns 8
					
					
		- Modulo:
			takes 2 params (word, byte).
			returns word.
			
			*additional notes:
				returns the first param mod second param,
				(first % second)
				
				EXAMPLE:
					for the 2 params:  21, 10,
					Modulo(21, 10) -> returns 1
					
					
		- factorial:
			takes 1 param(word).
			returns dword.
			
			*additional notes:
				returns the factorial of the given number,
				(number!)
				
				EXAMPLE:
					for the param: 8,
					factorial(8) -> returns 40,320
					
					
		- shift_left:
			takes 1 param(dword).
			returns dword.
			
			*additional notes:
				shifts the given number , 1 time, to the left.
				this instruction already exist at asm x86, but using numberic base '2',
				this however uses the numberic base '10'.
				
				EXAMPLE:
					for the param: 2,
					shift_left(2) -> returns 20
					
					
		- shift_right:
			takes 1 param(dword).
			returns dword.
			
			*additional notes:
				shifts the given number , 1 time, to the right.
				this instruction already exist at asm x86, but using numberic base '2',
				this however uses the numberic base '10'.
				
				EXAMPLE:
					for the param: 20,
					shift_left(20) -> returns 2
					
					
		- num_of_digits:
			takes 1 param(dword).
			returns byte.
			
			*additional notes:
				returns the number of digits that are in the given number.
				
				EXAMPLE:
					for the param 365,
					num_of_digits(365) -> returns 3
					
					
					
					
- var.inc:
	this file adds 2 variables to the data segment
	(Malloc & malloc_index),
	and implements a system for allocating variables in a dinamic way
	(using the 2 variables Malloc & malloc_index).
	
	- Malloc is an array of 120 dwords (thats treater as a second stack)
	- malloc_index acts on Malloc, just like sp acts on the stack (for the times that the register si is int use).
	
	let's take a look over the implemintation of that system:
	
		- Fake_push:
			takes no params.
			returns void.
			
			*additional notes:
				increments malloc_index (to signal for a new memory cell that has been allocated),
				and pushes the value of ecx (which doesn't really work, so I mov it after every call).
				
				
				
		- Fake_pop:
			takes no params.
			returns void.
			
			*additional notes:
				acts on Malloc, in a similar way that 'pop' acts on the stack,
				('frees' the lastest allocated memory cell).
				
				
				
				
				
- Trigo.inc:
	this file includes the implemintation of a couple of trigonometric functions,
	it works based of the Float struct, so it's able to return decimal numbers.
	let's go over those trigonometric functions:
	
		- F_cos:
			takes 1 param (dword).
			returns dword.
			
			*additional notes:
				uses Tylors seires to esstimate the value of
				cos(x), where x, is the given number.
				
				
		- F_sin:
			takes 1 param (dword).
			returns dword.
			
			*additional notes:
				uses Tylors seires to esstimate the value of
				sin(x), where x, is the given number.
				
				
				
				
				
* all the rays
				
			
				
