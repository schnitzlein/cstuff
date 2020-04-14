
;	to compile this code
;	first create an object file
;	nasm -f elf -o main.o main-nasm.asm
;
;	to create an executeable, link it
;	gcc -o run main.o
;

SECTION .text
global getDivisorCount_a

	;push	ebp
	;mov	ebp, esp
	;sub	esp, 8
	;and	esp, -16
	;mov	eax, 0
	;sub	esp, eax
    
        
;add code from here
getDivisorCount_a:
        push ebp         ; basispointer des programms auf den stack schieben
        mov ebp,esp      ; stackpointer zeigt auf basispointer
        push edx         ; edx auf den stack schieben

	mov edx, [ebp+8] ; erster parameter der extern funktion in edx laden
	mov ebx, edx     ; edx inhalt nach ebx
	mov ecx, edx     ; edx inhalt nach ecx
	mov eax, 0       ; 0 nach eax
	
schleife:
	cmp ecx,0        ; ecx == 0 ?
	je ende          ; springe zu ende wenn equal
	sub ebx, ecx     ; ebx - ecx
	cmp ebx, 0       ; ebx == 0 ?
	je inccount      ; springe zu inccount wenn equal
	jg schleife      ; springe zu schleife wenn greater (>)
	jl decdivisor    ; springe zu decdivisor wenn lower (<)

inccount:
	inc eax          ; eax++

decdivisor:
	mov ebx, edx     ; ebx inhalt nach edx
	loop schleife    ; for ecx > 0 ? do schleife
ende:	
	pop edx          ; aufraeumen edx vom stack entfernen
        pop ebp          ; dito ebp

;to here
	
	;mov	eax, 0
	;leave
	ret
