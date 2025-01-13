#include <iostream>
#include <vector>
#include <GL/glut.h>

const int N = 8;  // Dimensiunea tablei de șah (8x8)
const int TILE_SIZE = 100;  // Dimensiunea fiecărei celule pe tablă

// Funcția care verifică dacă putem plasa un turn pe o anumită poziție (rând și coloană)
bool can_place_tower(const std::vector<std::vector<int>>& board, int r, int c) {
    for (int i = 0; i < N; i++) {
        if (board[r][i] == 1 || board[i][c] == 1)
            return false;
    }
    return true;
}

// Funcția recursivă care încearcă să plaseze turnuri pe tablă
bool place_tower(std::vector<std::vector<int>>& board, int nr_towers) {
    if (nr_towers == N) {
        return true;  // Dacă am plasat toate cele 8 turnuri, soluția este găsită
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (can_place_tower(board, i, j)) {
                board[i][j] = 1;  // Plasăm un turn pe această poziție
                if (place_tower(board, nr_towers + 1))
                    return true;  // Continuăm recursiv să plasăm turnuri
                board[i][j] = 0;  // Dacă nu găsim soluția, revenim (backtrack)
            }
        }
    }
    return false;  // Nu am găsit o soluție
}

// Funcția de inițializare a ferestrei OpenGL
void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);  // Setăm culoarea de fundal la negru
    glMatrixMode(GL_PROJECTION);  // Setăm modul de proiecție
    glOrtho(0.0, N * TILE_SIZE, 0.0, N * TILE_SIZE, -1.0, 1.0);  // Setăm proiecția ortogonală
}

// Funcția de desenare a ferestrei OpenGL
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);  // Curățăm fereastra

    // Creăm un tablou de șah de 8x8
    std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));
    place_tower(board, 0);  // Plasăm cele 8 turnuri pe tablă

    bool f = false;

    // Desenăm tabla de șah
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            // Determinăm culoarea celulei (albă sau neagră)
            if (f) {
                glColor3f(1.0, 1.0, 1.0);  // Alb
            } else {
                glColor3f(0.0, 0.0, 0.0);  // Negru
            }

            // Desenăm fiecare celulă
            glBegin(GL_QUADS);
            glVertex2i(x * TILE_SIZE, y * TILE_SIZE);
            glVertex2i(x * TILE_SIZE, (y + 1) * TILE_SIZE);
            glVertex2i((x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE);
            glVertex2i((x + 1) * TILE_SIZE, y * TILE_SIZE);
            glEnd();

            f = !f;  // Schimbăm culoarea pentru următoarea celulă
        }
        if (N % 2 == 0) f = !f;  // Dacă N este par, inversăm culoarea la începutul fiecărui rând
    }

    // Desenăm turnurile (sub formă de cercuri roșii)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                glColor3f(1.0, 0.0, 0.0);  // Roșu pentru turnuri
                glBegin(GL_POLYGON);
                for (int angle = 0; angle < 360; angle += 10) {
                    float rad = angle * 3.14159f / 180.0f;
                    float x_pos = (j * TILE_SIZE) + TILE_SIZE / 2 + (TILE_SIZE / 4) * cos(rad);
                    float y_pos = (i * TILE_SIZE) + TILE_SIZE / 2 + (TILE_SIZE / 4) * sin(rad);
                    glVertex2f(x_pos, y_pos);
                }
                glEnd();
            }
        }
    }

    glFlush();  // Actualizăm fereastra
}

// Funcția principală
int main(int argc, char* argv[]) {
    glutInit(&argc, argv);  // Inițializăm GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Setăm modul de afișare
    glutInitWindowPosition(300, 50);  // Setăm poziția ferestrei
    glutInitWindowSize(N * TILE_SIZE, N * TILE_SIZE);  // Setăm dimensiunea ferestrei
    glutCreateWindow("8 Towers on a Chessboard");  // Creăm fereastra

    init();  // Inițializăm setările OpenGL
    glutDisplayFunc(display);  // Afișăm tabla și turnurile
    glutMainLoop();  // Pornim bucla principală GLUT

    return 0;
}
