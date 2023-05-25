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