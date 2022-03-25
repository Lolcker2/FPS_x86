.386
IDEAL
MODEL small
STACK 100h
DATASEG
; --------------------------

; --------------------------
CODESEG

include "macros.inc"
include "utills.inc"
include "Float.inc"
include "Ray.inc"
include "Trigo.inc"
include "var.inc"

start:
	mov ax, @data
	mov ds, ax	
; --------------------------

mov bp, sp
%alloc 2, varA

mov dx, varA
;mov dl, 2
mov ah, 2h
int 21h

%alloc 3, varA

;// the ascii 3
mov dx, varA
mov ah, 2h
int 21h


; --------------------------
	
exit:
	mov ax, 4c00h
	int 21h
END start
