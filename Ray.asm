CODESEG


proc cast basic far
uses si, eax, 
arg @@self:ptr Ray
	
	mov si, [@@self]	;// accessing @@self
	
	%sin [ds:si + Ray.angle]	;// pushes the sin of ray angle
	call [ds:si+ Ray.dist_to_wall] METHOD Float:multiplication	;// calls the multiplication method , while the latest pushed item is the sin of ray angle
	;// pushes sin(ray_angle) * dist_to_wall.
	call playerx METHOD Float:addition	;// calls the addition method , while the latest pushed item is sin(ray_angle) * dist_to_wall
	;// pushes sin(ray_angle) * dist_to_wall + playerx.
	
	pop[eax]	;// retrive that into eax
	%alloc  eax, coordx	;// allocating coordx as a variable, holding the value of sin(ray_angle) * dist_to_wall + playerx.
	
	
	
	%cos [ds:si + Ray.angle]	;// pushes the cos of ray angle
	call [ds:si+ Ray.dist_to_wall] METHOD Float:multiplication	;// calls the multiplication method , while the latest pushed item is the cos of ray angle
	;// pushes cos(ray_angle) * dist_to_wall.
	call playery METHOD Float:addition	;// calls the addition method , while the latest pushed item is cos(ray_angle) * dist_to_wall
	;// pushes cos(ray_angle) * dist_to_wall + playery.
	
	pop[eax]	;// retrive that into eax
	%alloc  eax, coordy	;// allocating coordy as a variable, holding the value of cos(ray_angle) * dist_to_wall + playery.


	ret
endp cast

























