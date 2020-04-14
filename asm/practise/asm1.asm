;erstes Assemblerprogramm

DATEN SEGMENT

Meldung db "Assembler ist gar nicht so schwer."
      db "$"                                  ;damit betriebssystem weis wann zeich

DATEN ENDS

CODE SEGMENT

      ASSUME CS:CODE,DS:DATEN

Anfang: 
      mov ax,DATEN
      mov ds,ax

      mov dx,offset Meldung
      mov ah,9
      int 21h

      mov ah,4Ch

      int 21h

CODE ENDS

      END Anfang
