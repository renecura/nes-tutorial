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

LoadNametable:
    LDA PPU_STATUS
    LDA ntpage
    STA PPU_ADDR
    LDA #$00
    STA PPU_ADDR

    LDY #$00
.bgloop
    LDA (bgaddrl),y
    STA PPU_DATA
    INY
    BNE .bgloop
  
  	RTS