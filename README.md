   # PROIECT SINCRETIC : TEMA NR. 23    
  
***************************************************   
 **Problema celor 8 turnuri:** Să se scrie un program care plasează 8 turnuri pe tabla de șah, fără ca acestea să se atace reciproc.   

 1. Introducere

 Această implementare are ca scop așezarea a __8 turnuri__ pe o tablă de șah, fără a se ataca reciproc. Conform regulilor șahului turnurile se pot deplasa pe tablă orizontal sau vertical.    
 Limbajul de programare folosit este C++, iar mediul de dezvolatare este __Visual Studio Code__. Alte aplicații folosite sunt: GitHub, GitHub Desktop, Docker Desktop, Docker Hub.    
 
 2. Structura codului

 - Biblioteci   
 `#inlcude <iostream>` - Biblioteca standard pentru intrare/ieșire   
 `#include <vector>` - Biblioteca `<vector>` este o parte a Standard Template Library (STL) din C++  
 `#include <GL/glut.h>` - Biblioteca standard utilizată pentru crearea aplicațiilor grafice 3D folosind OpenGL

- Funcții ale bibliotecii GLUT folosite:   
 - [x] `glColor3f()`         
 - [x] `glBegin()`         
 - [x] `glVertex2i()`           
 - [x] `glEnd()`   
 - [x] `glVertex2f()`         
 - [x] `glFlush()`          
 - [x] `glutInit()`         
 - [x] `glutInitWindowPosition()`        
 - [x] `glutWindowSize`   
 - [x] `glutCreateWindow()`   
 - [x] `init()`   
 - [x] `glutDisplayFunc()`   
 - [x] `glutMainLoop()`   
 
 - Funcții

 `bool can_place_tower(const std::vector<std::vector<int>>& board, int r, int c)`  
 Turnurile se pot ataca pe rând și pe coloană, astfel trebuie să verific poziția propusă, lucru pe care îl fac cu ajutorul acestei funcții. Reprezentarea unui **turn** este dată de __cifra 1__. Verificarea se face pe întregul rând și întreaga coloană. Dacă pe una din pozițiile verificate se gasește __cifra 1__, funcția va returna un rezultat de tip `bool`, și anume __false__. În caz contrar rezultatul returnat va fi __true__.

 `bool place_tower(std::vector<std::vector<int>>& board, int nr_towers)`   
Mai întâi se verifică dacă numărul de turnuri este egal cu constanta N=8, acest lucru însemnând că turnurile au fost plasate în totalitate.  
Dacă numărul turnurilor nu s-a îndeplinit vom face o parcurgere cu apelare recursivă, specifică __algoritmului de backtraking__, unde vom verifica dacă se poate așeza un turn pe care îl vom nota cu cifra 1. în cazul în care se ajunge la situația în care un turn nu mai poate fi așezat (pentru că atacă alte turnuri) se va șterge ultima poziție până când se va găsi soluția corectă.  

`void init(void)`   
Funcția de inițializare a ferestrei OpenGL. În această funcție setăm culoarea de fundal la negru, setăm modul de proiecție și proiecția ortogonală. Toate acestea cu ajutorul funcțiilor din biblioteca `<GL/glut.h>`.

`void display(void)`
Cu ajutorul acestei funcții am desenat fereastra OpenGL. Am început prin a curăța fereastra, apoi am creat tabla de șah de dimensiune 8x8, desenând fiecare celulă în alb și negru, iar în final am desenat turnurile(sub formă de cercuri) de culoare babyblue, raportat la soluția găsită cu ajutorul funcțiilor `can_place_tower` & `place_tower`.

`int main(int argc, char* argv[])`
În acestă funcție inițializăm GLUT, setăm modul de afișare, poziția ferestrei, dimensiunea acesteia, iar cu toate aceste caracteristici creăm fereastra.
Următorii pași sunt să inițializăm setările OpenGl, afișăm tabla și turnurile, iar în final pornim bucla principală GLUT.   

3. Resurse     
Ca și resurse extra, am folosit pentru crearea ferestrei OpenGL implementarea oferită de [acest repository GitHub](https://github.com/RUHANI77/computer-graphics/blob/main/chess_Board.cpp)

4. Soluția găsită    
![Solutie:](https://github.com/esteraa03/cele-8-ture/blob/main/board-with-solution.png)  

5. Livrare  
  [https://github.com/esteraa03/cele-8-ture] (Link GitHub)       
  [https://github.com/esteraa03/cele-8-ture/pkgs/container/cele-8-ture] (Container Docker creat automat de platformă)       
  - **Pull the pre-built Docker Image:**
  ```bash
  docker pull ghcr.io/esteraa03/cele-8-ture:latest
  ```   

  - **Run the container:**
  ```bash
  docker run -it -e DISPLAY=host.docker.internal:0 ghcr.io/esteraa03/cele-8-ture:latest    
  ``` 
  

6. Concluzie   
Proiectul oferă o implementare eficientă pentru rezolvarea Problemei Celor 8 Turnuri utilizând algoritmul de backtracking. Este o soluție elegantă și ușor de înțeles pentru o problemă clasică în teoria problemei și este utilă pentru înțelegerea principiilor de bază ale algoritmilor de backtracking.