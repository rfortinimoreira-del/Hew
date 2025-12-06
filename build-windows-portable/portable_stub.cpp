#include <windows.h>
#include <stdio.h>

int main() {
    MessageBoxA(NULL, 
        "Hubble - Jogo 3D Magico\n\n"
        "Versao em desenvolvimento\n\n"
        "A versao completa requer bibliotecas OpenGL\n"
        "Compile no Linux/Mac para melhor compatibilidade",
        "Hubble", 
        MB_OK | MB_ICONINFORMATION);
    return 0;
}
