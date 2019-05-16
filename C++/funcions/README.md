# Funcions per matrius en c++

Hi havia un petit error en la funció multiply, ha estat corregit, a més, s'ha introduit una nova funció: norm_one_vector, per tant, guardeu la versió actual.

Aquest projecte consisteix en una capçalera amb diverses funcions implementades que actuen sobre matrius. S'explicarà breument com utilitzar-lo i com funciona. Important: tot està implementat amb vectors i vectors de vectors, així que podeu fer copies de matrius tranquilament, per simplicitat els vectors de vectors s'anomenen matrius i els vectors de **double** vec. Si voleu utilitzar vectors d'enters utilitzeu simplements vector \<int\>. La tolerancia que s'utilitza per defecte és 1e-12, si la voleu canviar canvieu la constat epsilon en l'arxiu funcions.h.
    
Si voleu afegir una funció heu d'afegir l'especificació en funcions.h (és a dir, el nom de la funció i paràmetres que rep) i escriure l'implementació en el fitxer funcions.cpp


# Instalació

Per començar cal descarregar aquesta carpeta (funcions) amb els seus fitxers. A continuació podeu executar el programa principal simplement fent:
    
   
    g++ -std=c++11 main.cpp funcions.cpp
    ./a.out (nom de l'arxiu amb les dades)
   

Però també es pot utilitzar la commanda make:

   
    make
    ./main.exe (nom de l'arxiu amb les dades)
    
    
en aquest ultim cas podeu fer:

   
    make clean
    
    
per borrar els arxius .o si ja no voleu seguir utilitzant el programa.

# Funcions

Aquí s'explicarà breument les funcions que han estat implementades i que fan:

Primer expliquem operacions de matrius:

### funció `multiply`
La funció `multiply` rep dues matrius A i B i retorna una matriu A·B

### funció `add` i `subtract`
La funció `add` rep dues matrius A i B i retorna una matriu A+B i la funció `subtract` retorna en canvi A-B

### funció `transpose`
La funció `transpose` rep una matriu i retorna la seva transposta

### funció `transform`
La funció `transform` rep un vector i retorna una matriu, el vector com a vector columna (una matriu nx1). Aquesta funció és important de cara a multiplicar matrius per vectors

### funció `norm_two`
La funció `norm_two` rep un **vector** i retorna la seva norma 2

### funció `norm_one`
La funció `norm_one` rep una **matriu** i retorna la seva norma 1

### funció `norm_inf`
La funció `norm_inf` rep una **matriu** i retorna la seva norma infinit

### funció `norm_one_vector`
La funció `norm_one_vector` rep un **vector** i retorna la seva norma 1

### funció `condition_one`
La funció `condition_one` rep una **matriu** i retorna el seu nombre de condició sub 1

### funció `condition_inf`
La funció `condition_inf` rep una **matriu** i retorna el seu nombre de condició sub infinit

### funció `determinant`
La funció `determinant` rep una **matriu** i retorna el seu determinant

### funció `identity`
La funció `identity` rep un enter n i retorna una matriu identitat nxn

### funció `print_matriu`
La funció `print_matriu` rep una matriu i l'escriu al terminal

### funció `print_matlab`
La funció `print_matlab` rep una matriu i l'escriu al terminal en el format en que matlab llegeix les matrius, és a dir, podeu copiar l'output del terminal i enganxar-lo a Matlab.

Altres funcions més importants:

### funció `lu`
La funció `lu` rep una matriu A i un vector d'enters (vector de permutació) i retorna un número 0 si el determinant d'A és menor a epsilon, 1 si s'ha fet un nombre parell de permutacions i -1 altrament. A més, la matriu A acaba sent la matriu A expressada en forma LU i el vector d'enters que s'havia passat originalment acaba sent el vector de permutació. Atenció els dos estan passats per referència:

#### exemple

Donada la matriu del mock exam:

<table>
<tr>
<td>

```
n = A.size();

vector <int> perm (n, 0);
matriu LU = A;
lu(LU, perm);

for (int i = 0; i < n; ++i) cout << perm[i] << ", ";
cout << endl;
```

</td>
<td>

```
0, 1, 7, 3, 13, 2, 9, 8, 6, 14, 10, 12, 5, 11, 4,

```

</td>
</tr>
</table>

Nota: fer matriu LU és exactament el mateix que fer vector \<vector \<double\> \> LU

Nota2: Aquí copiem la matriu A i utilitzem LU per fer lu perquè si volem calcular després el determinant, la inversa d'A etc, ho podem fer directament, ja que la matriu que passem a LU canvia.

### funció `solve`
La funció `solve` rep una matriu A i un vector b i retorna un vector x tal que Ax = b. Aquí la matriu A és normal, no està en forma LU.

#### exemple

Resolució del sistema M00.DAT i càlcul de ||Ax-b||

<table>
<tr>
<td>

```
vec x = solve(A, b);
for (int i = 0; i < x.size(); ++i) cout << i << " " << x[i] << endl;

// res = Ax-b com a matriu i residu = Ax-b com a vector
matriu res = subtract(multiply(A, transform(x)), transform(b));
vec residu = transpose(res)[0];

cout << norm_two(residu) << endl;
```

</td>
<td>

```
0 -1.13591992015e+01
1 -8.15119193061e-01
2 -5.97039709365e-01
3 4.72477811642e+00
4 5.15388873894e+00
5 3.73105422667e+00
6 -8.57946616057e+00
7 8.47914822817e-01
8 -3.80721757848e+00
9 -3.44023384034e+00
10 -5.29462802072e+00
11 -1.74280934298e+00
12 2.00662194467e+00
13 -5.39824206640e+00

3.50246771780e-14
```

</td>
</tr>
</table>

Nota: fer vec x és exactament el mateix que fer vector \<double\> x

### funció `inverse`
La funció `inverse` rep una matriu A i retorna la seva inversa.

#### exemple

Donada la matriu del mock exam:

<table>
<tr>
<td>

```
matriu inv = inverse(A);

cout << norm_one( subtract( multiply(A, inv), identity(A.size()) ) ) << endl;
cout << condition_one(A) << endl;
cout << condition_inf(A) << endl;
cout << determinant(A) << endl;
```

</td>
<td>

```
2.09554595898e-14
3.50494999919e+02
3.20142629249e+02
-1.49677108263e+15

```

</td>
</tr>
</table>
 
Altres funcions auxiliars:

### funció `pivoting`
La funció `pivoting` rep una matriu A i un enter index indicant en quin pas de factorització de la LU estem i retorna l'index de la fila que té el pivot.

### funció `Gauss`
La funció `Gauss` rep una matriu A i un enter row indicant quina es la fila sobre la que s'efectuarà Gauss (totes les files amb fila major que row canviaran de manera que A[>row][row] = 0)

#### exemple

Un altre exemple, la part de c++ de l'exercici 4:

<table>
<tr>
<td>

```
cout << scientific << setprecision(11);
ofstream output;

output.open("normx.dat", ofstream::out);
output << scientific << setprecision(11);

vec eps (101, 0.01);
for (int i = 0; i <= 100; ++i) eps[i] *= i;

vector <vec> bk (101, b);
for (int i = 0; i <= 100; ++i){
    bk[i][0] += 0.1*i*cos(eps[i]);
}

for (int i = 0; i <= 100; ++i){
    double f = norm_one_vector(solve(A, bk[i]));
    output << eps[i] << " " << f << endl;

    if (i == 100) cout << "f(e100) = " << f << endl;
}

output.close();
```

</td>
<td>

```
f(e100) = 2.20874847044e+01
```
