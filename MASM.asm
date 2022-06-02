.586
.MODEL FLAT, STDCALL
PUBLIC fun1
_DATA SEGMENT    
    StrMas    db    11 dup(?), 0
    dec1      dd    10
_DATA ENDS
_TEXT SEGMENT
    fun1 PROC par1:DWORD
    lea EBX, StrMas
    mov ECX, 11
label1:
    mov BYTE PTR[EBX], ' '
    INC EBX
    loop label1
mov EAX, par1
push EAX
or EAX, EAX 
jns label2  
neg EAX
label2:
    xor EDX, EDX
    div dec1 
    add DX, '0'
    dec EBX
    mov BYTE PTR[EBX], DL
    inc ECX
    or EAX, EAX
    jnz label2
pop EAX
OR EAX, EAX
jns label3
dec EBX
mov BYTE PTR [EBX], '-'
inc ECX
label3:
    mov EAX, EBX
    ret
fun1 ENDP
_TEXT ENDS
END