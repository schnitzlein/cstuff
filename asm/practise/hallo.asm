ORG 100h                    ; Startoffset auf 100h setzen (Startpunkt f�r COM-Programme)
 
mov ax, cs                  ; Wert des Codesegmentregisters in Register ax �bertragen
mov ds, ax                  ; Datensegment auf Wert von ax setzen
 
mov ah, 09h                 ; DOS-Funktion zum Schreiben von Text
mov dx, Meldung             ; Adresse des Textes
int 21h                     ; DOS-Funktion ausf�hren
 
mov ax, 4C00h               ; DOS-Funktion um das Programm zu beenden
int 21h
 
Meldung: db "Hello World"   ; Unser Text
         db "$"             ; Markiert das Ende der Zeichenkette