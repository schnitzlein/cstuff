MODEL SMALL           ;Kleinstes EXE-Speichermodell
DATA SEGMENT          ;Beginn Data-Seg
ASSUME DS:DATA        ;DS zeigt auf Data-Seg
 text DB "ASM rulez!$";Variable text
DATA ENDS             ;Ende Data-Seg
CODE SEGMENT          ;Beginn Code-Seg
ASSUME CS:CODE        ;CS zeigt auf Code-Seg
 MOV AX,SEG DATA      ;Data-Seg initialisieren
 MOV DS,AX            ;
 MOV AX,0900h         ;Funkt. 9
 MOV DX,OFFSET text   ;Offset -> DX
 INT 21h              ;String ausgeben
 MOV AX,4C00h         ;Funkt. 4Ch, Exit-Code 0
 INT 21h              ;DOS-Exit
CODE ENDS             ;Ende Code-Seg
END                   ;Ende des Proggys
