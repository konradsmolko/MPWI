.386
.model flat
public _rand_asm
.code
_rand_asm PROC ; extern "C" unsigned int rand_asm(char p, char q, time_t seed, unsigned int invoc);
	push	ebp
	mov		ebp, esp
	push	ebx

	mov		ch, [ebp + 8] ; p = 7
	mov		cl, [ebp + 12] ; q = 3
	mov		edx, [ebp + 16] ; seed
	mov		eax, edx
	;mov		reg, [ebp+20] ; long part of invoc, pewnie nie będzie użyta bo złożoność N^2
	mov		ebx, [ebp+24] ; invoc

	; (2.6) b_i = b_i-p xor b_i-q
	; Niezbyt zoptymalizowane podejście, ale powinno działać
	inc		ebx
ptl:
	rol		eax, cl
	ror		ecx, 8
	rol		edx, cl
	rol		ecx, 8

	dec		ebx
	cmp		ebx, 0
	jne		ptl

	xor		eax, edx

	pop		ebx
	mov		esp, ebp
	pop		ebp
	ret
_rand_asm ENDP
END
