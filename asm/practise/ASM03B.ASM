MODEL TINY            ;Fr COM-Files
CODE SEGMENT          ;Beginn Code-Seg
ASSUME CS:CODE,DS:CODE;CS und DS zeigen auf Code-Seg
ORG 100h              ;Startadresse COM
start:                ;Startlabel
 JMP begin            ;Sprung zu Label begin
 text DB "ASM rulez!$";Variable text
begin:                ;'Richtiger' Beginn des Proggys
 MOV AX,0900h         ;Funkt. 9
 MOV DX,OFFSET text   ;Offset -> DX
 INT 21h              ;String ausgeben
 MOV AX,4C00h         ;Funkt. 4Ch, Exit-Code 0
 INT 21h              ;DOS-Exit
CODE ENDS             ;Ende Code-Seg
END start             ;Ende des Proggys
