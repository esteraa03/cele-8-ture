# Folosește imaginea de bază cu GCC
FROM gcc:latest

# Setează directorul de lucru
WORKDIR /usr/src/MAP

# Copiază fișierul C++ în container
COPY tower.cpp .

# Instalează librăriile necesare pentru OpenGL și GLUT
RUN apt-get update && apt-get install -y \
    libgl1-mesa-glx \
    libglu1-mesa \
    freeglut3-dev \
    g++ \
    && rm -rf /var/lib/apt/lists/*

# Compilarea fișierului C++ cu librăriile necesare
RUN g++ -o tower tower.cpp -lglut -lGLU -lGL -lstdc++

# Comanda de rulare a aplicației
CMD ["./tower"]
