# Càlcul de la inversa d'una matriu
## Introducció
El programa compleix el següent objectiu: **Calcular la inversa d'una matriu A quadrada.** I es caracteritza per fer-ho mitjançant la **descomposició LU** de la matriu A.

L'algoritme està subdividit en 4 parts:
* Llegir i guardar les dades de la matriu A.
* Realitzar la factorizació LU de la matriu.
* Resoldre dos sistemes triangulars per cada vector de la base canònica, per acabar trobant la solució.
* Guardar la solució en un fitxer.

A més hi ha una secció opcional que calcula la norma del residu amb les normes sub2 i subinfinit.

## Arquitectura
El conjunt del programa està separat en diferents fitxers. El **main.cc** és el programa principal i el que s'executa en primer lloc. Aquest crida a **inversa.cc** qui separa la tasca de resoldre el sistema AX = I en dos. Primer crida a **lu.cc** per factoritzar la matriu A, segon crida a **resol.cc** per acabar resolent els n sistemes quan la matriu ja està factoritzada.

Nota: en tot moment tant vectors com matrius es passen per referència per així evitar còpies innecessàries.

La secció opcional funciona semblant: el **main.cc** fa una crida a **residu.cc** i aquest fa dues crides, primer a **res_2.cc** i després a **res_Inf.cc** que calculen les seves respectives normes.

Finalment també hi ha un arxiu **Makefile** per simplificar el funcionament del programa.

## Exemple d'ús
Primer ens situem, a través de la consola, al directori on hi hagi el programa. A continuació, executem escrivint ``` make ```,  aleshores el programa compilarà (aquesta instrucció només cal fer-la un cop). El següent que hem de fer és ``` ./main.exe exemple.txt ``` i s'executarà el programa, mostrarà per pantalla la solució i també la guardarà en un fitxer. Aquí *exemple.txt* pot ser qualsevol tipus de fitxer (amb el nom que calgui) sempre que pugui ser llegit per la llibreria estàndard de c++ *fstream*. Si volem que ens mostri per pantalla els móduls del residu només cal afegir un *1* després del nom del fitxer. És a dir: ``` ./main.exe exemple.txt 1```, i a continuació de la solució apareixeran les normes del residu, que si tot ha funcionat bé serà 0 o molt proper a 0.

## Altres consideracions
### Sobre el format de les dades
Tal com es veu en *exemple.txt*.

El fitxer de les dades cal que tingui un format concret per ser llegides correctament. El primer que ha d'apareixer és la dimensió de la matriu (quadrada). A continuació, ve la matriu, primer hi ha el nombre de components diferents de 0, després precedit per la seva fila i columna els components diferents de 0. Sempre indexat a partir del 0.

### Sobre el nom del fitxer de sortida

El nom del fitxer de sortida per defecte és **out.txt**.

En el cas que es volgui canviar es pot fer anant a dalt de tot de *main.cc*, en l'apartat de variables globals, allà on el comentari indiqui.

### Sobre la tolerància admesa

La tolerància admesa per defecte és **10E-2**.

En el cas que es volgui canviar es pot fer anant a dalt de tot de *main.cc*, en l'apartat de variables globals, allà on el comentari indiqui.

### Sobre els decimals utilitzats quan s'imprimeix per pantalla

El nombre de decimals utilitzats quan s'imprimeix per pantalla per defecte són **5**.

En el cas que es volgui canviar es pot fer anant a dalt de tot de *main.cc*, en l'apartat de variables globals, allà on el comentari indiqui.

### Sobre els decimals utilitzats quan es guarda la solució en un fitxer

El nombre de decimals utilitzats quan s'imprimeix per pantalla per defecte són **15**.

En el cas que es volgui canviar es pot fer anant a dalt de tot de *main.cc*, en l'apartat de variables globals, allà on el comentari indiqui.


### Sobre l'ús de la llibreria estàndard de c++ <vector\>
"No utilitzeu punters a menys que sigui absolutament necessari" ~Jordi Cortadella
