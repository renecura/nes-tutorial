; Inicializa la PPU
InitPPU:
	LDA #$00
	STA PPU_CTRL
	STA PPU_MASK
	RTS

; Espera suceda la vblank
WaitVBlank:
	BIT PPU_STATUS	    ; Verifica PPU_STATUS
	BPL WaitVBlank      ; Espera vblank
	RTS

; Carga las paletas de colores
; Deben estar almacenadas en la etiqueta palettes:
LoadPalettes:
	LDA #$3F
	STA PPU_ADDR
	LDA #$00
	STA PPU_ADDR
    	
	LDX #$00
.load_pallete:
    LDA palettes,x
    STA PPU_DATA
    INX
    CPX #$20
    BNE .load_pallete
	RTS

; Carga 1KB completo de memoria a la nametable de la PPU
; Estos deben ser datos binarios bajo la etiqueta background
LoadNametable: subroutine
    LDA #<background
    STA bgaddrl
    LDA #>background
    STA bgaddrh

    LDA #$20
    STA PPU_ADDR
    LDA #$00
    STA PPU_ADDR

    LDX #$04
.loopX:
    
    LDY #$00
.loopY
    LDA (bgaddrl),y
    STA PPU_DATA
    INY
    BNE .loopY

    INC bgaddrh
    DEX
    BNE .loopX
  
  	RTS