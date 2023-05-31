; Direcciones de los controladores
CONTROLLER1 = $4016
CONTROLLER2 = $4017

; Máscaras para los botones
BTN_RIGHT   = %00000001
BTN_LEFT    = %00000010
BTN_DOWN    = %00000100
BTN_UP      = %00001000
BTN_START   = %00010000
BTN_SELECT  = %00100000
BTN_B       = %01000000
BTN_A       = %10000000


ReadController1: subroutine
    ; Envía una señal al controlador
    ; para iniciar la lectura    
    LDA #$01
    STA CONTROLLER1
    LDA #$00
    STA CONTROLLER1

    ; Inicializa el espacio de memoria
    LDA #%00000001 ; Este 1 es la señal de que terminó de leer 
    STA pad1

    ; Obtiene los botones un bit a la vez
    ; (Comunicación serie)
.get_buttons:
    LDA CONTROLLER1 ; Lee el estado del proxmo botón
    LSR             ; Desplaza el bit del acumulador al carry
    ROL pad1        ; Mete el carry en el espacio de memoria del pad
    BCC .get_buttons ; Continúa hasta que haya 1 en el carry

    RTS

ReadController2: subroutine
    ; Envía una señal al controlador
    ; para iniciar la lectura    
    LDA #$01
    STA CONTROLLER2
    LDA #$00
    STA CONTROLLER2

    ; Inicializa el espacio de memoria
    LDA #%00000001 ; Este 1 es la señal de que terminó de leer 
    STA pad2

    ; Obtiene los botones un bit a la vez
    ; (Comunicación serie)
.get_buttons:
    LDA CONTROLLER2  ; Lee el estado del proxmo botón
    LSR              ; Desplaza el bit del acumulador al carry
    ROL pad2         ; Mete el carry en el espacio de memoria del pad
    BCC .get_buttons ; Continúa hasta que haya 1 en el carry

    RTS

; Verifica los direccionales para cambiar la posición del jugador
; No hace ningún chequeo de límites
MovePlayer1: subroutine
.check_right:
    LDA pad1
    AND #BTN_RIGHT
    BEQ .check_left
    INC playerx
.check_left:
    LDA pad1
    AND #BTN_LEFT
    BEQ .check_up
    DEC playerx
.check_up:
    LDA pad1
    AND #BTN_UP
    BEQ .check_down
    DEC playery
.check_down:
    LDA pad1
    AND #BTN_DOWN
    BEQ .check_done
    INC playery
.check_done:
    RTS