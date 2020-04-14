ORG 100h                    ; Startoffset auf 100h setzen (Startpunkt für COM-Programme)
 
mov ax, cs                  ; Wert des Codesegmentregisters in Register ax übertragen
mov ds, ax                  ; Datensegment auf Wert von ax setzen
 
mov ah, 09h                 ; DOS-Funktion zum Schreiben von Text
mov dx, Meldung             ; Adresse des Textes
int 21h                     ; DOS-Funktion ausführen
 
mov ax, 4C00h               ; DOS-Funktion um das Programm zu beenden
int 21h
 
Meldung: db "Hello World"   ; Unser Text
         db "$"             ; Markiert das Ende der Zeichenkette