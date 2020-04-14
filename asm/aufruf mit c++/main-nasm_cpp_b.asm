
;	to compile this code
;	first create an object file
;	nasm -f elf -o main.o main-nasm.asm
;
;	to create an executeable, link it
;	gcc -o run main.o
;

SECTION .text
global getDivisorCount_b

	;push	ebp
	;mov	ebp, esp
	;sub	esp, 8
	;and	esp, -16
	;mov	eax, 0
	;sub	esp, eax
    
        
;add code from here
getDivisorCount_b:
        push ebp
        mov ebp,esp
        push edx

	mov edx, [ebp+8]
	mov ebx, edx
	mov ecx, edx
	mov eax, 0
	
schleife:
	cmp ecx,0
	je ende
	sub ebx, ecx
	cmp ebx, 0
	je inccount
	jg schleife
	jl decdivisor

inccount:
	inc eax

decdivisor:
	mov ebx, edx
	sub ecx,1
	jmp schleife	

ende:
	mov edx, [ebp+12] ; adresse für ergebnis zwischenspeichern	
	mov [edx],eax ; ergebniss an seine adresse schreiben
	pop edx
        pop ebp

;to here
	
	;mov	eax, 0
	;leave
	ret
