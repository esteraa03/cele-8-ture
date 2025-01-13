#include <iostream>
#include <vector>
#include <GL/glut.h>
#include <cmath>

const int N = 8;

// Tabla de sah - 0 pentru spatii libere, 1 pentru turnuri
std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));

bool can_place_tower(const std::vector<std::vector<int>>& board, int r, int c)
{
    for (int i = 0; i < N; i++)
    {
        if (board[r][i] == 1 || board[i][c] == 1)
            return false;
    }
    return true;
}

bool place_tower(std::vector<std::vector<int>>& board, int nr_towers)
{
    if (nr_towers == N)
    {
        // Afisare solutie
        return true;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (can_place_tower(board, i, j))
            {
                board[i][j] = 1;
                if (place_tower(board, nr_towers + 1))
                    return true;
                board[i][j] = 0;
            }
        }
    }
    return false;
}

// Functie pentru a desena tabla de sah si turnurile
void draw_board()
{
    glClear(GL_COLOR_BUFFER_BIT); // Curata ecranul

    bool f = false;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            // Coloram in alb sau negru
            if (f)
            {
                glColor3f(1.0, 1.0, 1.0); // Alb
            }
            else
            {
                glColor3f(0.0, 0.0, 0.0); // Negru
            }

            glBegin(GL_QUADS);
            glVertex2i(x * 100, y * 100);
            glVertex2i(x * 100, (y + 1) * 100);
            glVertex2i((x + 1) * 100, (y + 1) * 100);
            glVertex2i((x + 1) * 100, y * 100);
            glEnd();

            f = !f; // Alternam culoarea

        }
        if (N % 2 == 0)
            f = !f;
    }

    // Desenam turnurile (ca cercuri)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1)
            {
                // Desenam turnul sub forma unui cerc
                glColor3f(0.53f, 0.81f, 0.92f); // Baby blue pentru turn

                // Desenam turnul ca cerc
                glBegin(GL_POLYGON);
                for (int k = 0; k < 360; k++)
                {
                    float angle = k * 3.14159f / 180.0f;
                    float x_offset = 25 * cos(angle);
                    float y_offset = 25 * sin(angle);
                    glVertex2f(j * 100 + 50 + x_offset, i * 100 + 50 + y_offset);
                }
                glEnd();
            }
        }
    }

    glFlush(); // Procesam toate rutinele OpenGL
}

// Functie de initializare pentru OpenGL
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0); // Seteaza culoarea de fundal (negru)
    glMatrixMode(GL_PROJECTION); // Seteaza modul de proiectie
    glLoadIdentity();
    glOrtho(0.0, N * 100.0, 0.0, N * 100.0, -1.0, 1.0);
}

int main(int argc, char* argv[])
{
    place_tower(board, 0); // Plasam cele 8 turnuri

    glutInit(&argc, argv); // Initializam GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Setam modul de afisare
    glutInitWindowPosition(300, 50); // Pozitionam fereastra
    glutInitWindowSize(800, 800); // Setam dimensiunea ferestrei
    glutCreateWindow("Problema celor 8 Turnuri"); // Cream fereastra

    init(); // Initializam OpenGL
    glutDisplayFunc(draw_board); // Functia care va desena tabla
    glutMainLoop(); // Rulam bucla principala GLUT

    return 0;
}
