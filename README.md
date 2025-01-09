### PROIECT SINCRETIC : TEMA NR. 23    
# Golea Andreea Estera   
# ***************************************************   
 **Problema celor 8 turnuri:** Să se scrie un program care plasează 8 turnuri pe tabla de șah, fără ca acestea să se atace reciproc.   

 1. Introducere

 Această implementare are ca scop așezarea a __8 turnuri__ pe o tablă de șah, fără a se ataca reciproc. Conform regulilor șahului turnurile se pot deplasa pe tablă orizontal sau vertical.    
 Limbajul de programare folosit este C++, iar mediul de dezvolatare este __Visual Studio Code__. Alte aplicații folosite sunt: GitHub, GitHub Desktop, Docker Desktop, Docker Hub.    
 Există 92 de moduri unice de a plasa opt turnuri pe tabla de șah (8x8) astfel încât să nu se atace reciproc. Este important de menționat că acest număr include toate permutările distincte și rotirile pentru fiecare configurație.  

 2. Structura codului

 - Biblioteci   
 `#inlcude <iostream>` - Biblioteca standard pentru intrare/ieșire   
 `#include <vector>` - Biblioteca `<vector>` este o parte a Standard Template Library (STL) din C++  
 
 - Funcții

 `bool can_place_tower(const std::vector<std::vector<int>>& board, int r, int c)`  
 Turnurile se pot ataca pe rând și pe coloană, astfel trebuie să verific poziția propusă, lucru pe care îl fac cu ajutorul acestei funcții. Reprezentarea unui **turn** este dată de __cifra 1__. Verificarea se face pe întregul rând și întreaga coloană. Dacă pe una din pozițiile verificate se gasește __cifra 1__, funcția va returna un rezultat de tip `bool`, și anume __false__. În caz contrar rezultatul returnat va fi __true__.

 `bool place_tower(std::vector<std::vector<int>>& board, int nr_towers)`   
Mai întâi se verifică dacă numărul de turnuri este egal cu constanta N=8, acest lucru însemnând că turnurile au fost plasate în totalitate. În acest caz soluția va fi afișată.    
Dacă numărul turnurilor nu s-a îndeplinit vom face o parcurgere cu apelare recursivă, specifică __algoritmului de backtraking__, unde vom verifica dacă se poate așeza un turn pe care îl vom nota cu cifra 1. în cazul în care se ajunge la situația în care un turn nu mai poate fi așezat (pentru că atacă alte turnuri) se va șterge ultima poziție până când se va găsi soluția corectă.  

`int main()`   
Cu ajutorul bibliotecii `<vector>` am creat o matrice bidimensională,   
unde:  
- `board` este numele matricei care reprezintă tabla se șah;   
- `N` este o constantă ce definește dimensiunea tablei (8);
- `std::vector<int>(N, 0)` creează un vector de N elemente, fiecare inițializat cu valoarea 0;
- Linia de cod `std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));` creează o tablă de șah de dimensiune `N x N` utilizând vectori din STL. Iată o explicație detaliată:

- `std::vector<std::vector<int>>`: Este un vector de vectori de întregi, adică o matrice bidimensională.
- `board`: Este numele variabilei care reprezintă tabla de șah.
- `N`: Este o constantă care definește dimensiunea tablei de șah (în acest caz, 8).
- `std::vector<int>(N, 0)`: Creează un vector de `N` elemente, fiecare inițializat cu valoarea `0`.
- `std::vector<std::vector<int>> board(N, ...)` creează un vector de `N` elemente, fiecare element fiind un vector de `N` elemente inițializate cu `0`.

Astfel, `board` este o matrice `N x N` (8x8 în acest caz) inițializată cu `0`, reprezentând o tablă de șah goală.

Exemplu vizual:
```
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
```
3. Soluția găsită    
![Solutie:](https://github.com/esteraa03/cele-8-ture/blob/main/tabla-de-sah.png)  

4. Livrare  


5. Concluzie
Proiectul oferă o implementare eficientă pentru rezolvarea Problemei Celor 8 Turnuri utilizând algoritmul de backtracking. Este o soluție elegantă și ușor de înțeles pentru o problemă clasică în teoria problemei și este utilă pentru înțelegerea principiilor de bază ale algoritmilor de backtracking.