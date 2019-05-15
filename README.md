# Àlgebra lineal numèrica
En aquest directori s'hi troben totes les pràctiques i programes útils per la assignatura d'Àlgebra Lineal Numèrica, especialment com a recursos per l'examen de pràctiques. Està obert a la participació d'estudiants de la FME. 

## Instruccions de descàrrega/instal·lació

Per baixar-vos tot el contingut del repo a una carpeta, des de la terminal de comandes feu
```sh
git clone --recurse-submodules https://github.com/AlferesChronos/ALN.git
```

A la carpeta on hagueu executat aquesta comanda tindreu una carpeta `ALN` amb el contingut d'aquest repositori. Feu-ne ús responsable! :wink:

Si hi ha canvis, per actualitzar els continguts de la còpia (un cop ja heu clonat el repositori), dins de `ALN` podeu executar

```sh
git pull --recurse-submodules
```



## C++
Programes en C++. També inclouen `Makefile`.
### Descomposició LU
Un programa que resol sistemes d'equacions descomposant A = LU.

Hi ha tres versions:
- Versió clàssica amb punters (el que es demanava a la pràctica)
- Versió amb `std::vector`s (millor que punters segur :wink:)
- Versió "extensible" – està disennyada per ser fàcilment extensible i modificable (per exemple, per afegir el càlcul de la inversa). És un submòdul d'aquest repositori; el seu repo està [aquí](https://www.github.com/plammens/LU).

### Càlcul de la inversa
Un programa que troba la inversa d'una matriu quadrada A, descomposant-la LU.

### funcions
Un gran conjunt de funcions útils que poden facilitar molt la feina.

### Altres coses
Simplement hi ha altres coses.

## Matlab
Hi ha de tot.

> *Nota:* algunes funcions depenen d'altres que estan definides a un arxiu diferent. Per tant, utilitzeu sempre tots els arxius de la carpeta en qüestió.

### Ajustament per mínims quadrats
### Mètodes Iteratius
Jacobi, Gauss-Siedel, Over-Relaxation
### Pràctiques
Coses fetes a classe, potser hi ha algo útil

**ATENCIÓ:** No assegurem la convergencia de la teva nota
