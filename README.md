# Famicom/NES assembler paso a paso

## Introducción

## Ambiente de desarrollo

* [Compilador - dasm](https://dasm-assembler.github.io/)
* [Emulador - fceux](https://fceux.com/web/home.html)
* [Editor - vscode](https://code.visualstudio.com/)
    * [Extension: DASM](https://marketplace.visualstudio.com/items?itemName=Settis.dasm)
    * [Extensión: Hex Editor](https://marketplace.visualstudio.com/items?itemName=ms-vscode.hexeditor)

## Compilación

```sh
dasm main.dasm -S -R -f3 -omain.nes
```

```sh
fceux main.nes
```

## Recursos
* http://www.6502.org/
* https://8bitworkshop.com/ 
* https://famicom.party/
* https://www.nesdev.org/

## Paso a paso

### 00 - Inicialización

Establece los espacios de memoria y el código mínimo para verificar el ambiente de desarrollo.

### 01 - Pantalla

Define el modo de uso de la PPU y muestra una pantalla verde.

> Desafio: Cambiar el color

### 02 - Refactoring

Se hacen definiciones para tener el código más claro y separarlo en diferentes archivos.

### 03 - Subrutinas

Definir subrutinas comunes para facilitar el proceso de desarrollo.

### 04 - Sprites

Dibuja un sprite en pantalla compuesto de multiples tiles.
Incluye manejo de interrupciones.

### 05 - Background

Explica el proceso de carga de los datos de nametables para definir el fondo del nivel.
