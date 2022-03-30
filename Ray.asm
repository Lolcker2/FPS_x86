CODESEG


proc coord_calc basic far
uses si, eax,
arg @@self:ptr Ray

mov si, [@@self];// accessing @@self

%sin [ds:si + Ray.angle];// pushes the sin of ray angle
call [ds:si+ Ray.dist_to_wall] METHOD Float:multiplication;// calls the multiplication method , while the latest pushed item is the sin of ray angle
;// pushes sin(ray_angle) * dist_to_wall.
call playerx METHOD Float:addition;// calls the addition method , while the latest pushed item is sin(ray_angle) * dist_to_wall
;// pushes sin(ray_angle) * dist_to_wall + playerx.

pop[eax];// retrive that into eax
%alloc  eax, coordx;// allocating coordx as a variable, holding the value of sin(ray_angle) * dist_to_wall + playerx.



%cos [ds:si + Ray.angle];// pushes the cos of ray angle
call [ds:si+ Ray.dist_to_wall] METHOD Float:multiplication;// calls the multiplication method , while the latest pushed item is the cos of ray angle
;// pushes cos(ray_angle) * dist_to_wall.
call playery METHOD Float:addition;// calls the addition method , while the latest pushed item is cos(ray_angle) * dist_to_wall
;// pushes cos(ray_angle) * dist_to_wall + playery.

pop[eax];// retrive that into eax
%alloc  eax, coordy;// allocating coordy as a variable, holding the value of cos(ray_angle) * dist_to_wall + playery. 

ret
endp coord_calc



proc cast basic far
uses eax, ebx, ebp, edx
arg @@self:ptr Ray

@@loop1: 

mov si, [@@self]
mov bl, [ds:si + Ray.wall] 

cmp bl, 1
je @@wall 

mov ebx, [ds:si + Ray.dist]
cmp ebx, [max_ray_length]
je @@wall 

push[ebx]*
call [ds:si + Ray.speed] METHOD Float.addition
pop[ds:si + Ray.dist] 

call si METHOD Ray:coord_calc* 

mov eax, coordx
cmp eax, 00
je @@out_of_bounds 

cmp eax, [Map_width]
je @@out_of_bounds 

mov eax, coordy
cmp eax, 00
je @@out_of_bounds 

cmp eax, [Map_height]
je @@out_of_bounds


mov ebp, coordx
mov eax, [Map_width]
mul ebp 

mov ebp, eax
mov eax, coordy
add ebp, eax


mov bx, [Map + ebp]
cmp bx, '#'
jne @@loop1 

mov [ds: si + Ray.wall], 1
jmp @@loop1


@@out_of_bounds: 

mov [ds:si + Ray.dist], [max_ray_length]
mov [ds:si + Ray.wall], 1


@@wall:



mov eax, [screen_height]
mov ebx, 2
div ebx
mov ebx, eax 

mov eax, [screen_height]
mov edx, [ds:si + Ray.dist]
div edx 

sub ebx, eax
%alloc ebx, ceiling 

mov eax, [screen_height]
sub eax, ceiling
%alloc eax, floor 

ret
endp cast

