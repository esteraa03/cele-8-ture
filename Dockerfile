FROM gcc:latest

WORKDIR /usr/src/MAP

COPY tower.cpp .

RUN gcc -o tower tower.cpp -lstdc++ 

CMD ["./tower"]