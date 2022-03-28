.386
IDEAL
MODEL small
STACK 100h
;NOWARN
DATASEG
; --------------------------
Playerx Float ?
Playery Float ?
; --------------------------
CODESEG

include "utills.inc"


start:
	mov ax, @data
	mov ds, ax	
; --------------------------
proc main basic far
	

	ret
endp main
; --------------------------
	
exit:
	mov ax, 4c00h
	int 21h
END start
