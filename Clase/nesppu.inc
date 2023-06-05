
InitPPU:
	LDA #$00
	STA PPU_CTRL
	STA PPU_MASK
    RTS

WaitVBlank:
	BIT PPU_STATUS		    ; Verifica PPU_STATUS
	BPL WaitVBlank	        ; Espera vblank
    RTS

; Carga las paletas de colores
; Deben estar almacenadas en la etiqueta palettes:
LoadPalettes: subroutine
	LDA #$3F
	STA PPU_ADDR
	LDA #$00
	STA PPU_ADDR
    	
	LDX #$00
.loop:

    LDA palettes,x
    STA PPU_DATA

    INX
    CPX #$20
    BNE .loop
	RTS

; Dibuja un sprite definido en la direccion navecita
DibujarSprite: subroutine
 	LDA navecita,x ; Posicion Y
    CLC
    ADC playery     ; Desplazamiento de la pos Y
    STA OAM_RAM,x
    INX
    LDA navecita,x  ; Lozeta/tile sprite
    STA OAM_RAM,x
    INX
    LDA navecita,x  ; Atributos
    STA OAM_RAM,x
    INX
    LDA navecita,x  ; Posicion X
    CLC
    ADC playerx     ; Desplazamiento de la pos X
    STA OAM_RAM,x

    RTS
