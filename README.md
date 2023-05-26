# Famicom/NES assembler paso a paso

## Introducción

## Ambiente de desarrollo

* Compilador - dasm
* Emulador - fceux
* Editor - vscode

## Compilación

```sh
dasm main.dasm -S -R -f3 -omain.nes
```

```sh
fceux main.nes
```

## Recursos

* https://8bitworkshop.com/ 
* https://famicom.party/

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
