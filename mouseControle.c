#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void limpartela(){
    COORD coord;
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO info;

    coord.X = 0;
    coord.Y = 0;
    GetConsoleScreenBufferInfo ( GetStdHandle ( STD_OUTPUT_HANDLE ), &info );
    FillConsoleOutputCharacter ( GetStdHandle ( STD_OUTPUT_HANDLE ), ' ',
    info.dwSize.X * info.dwSize.Y, coord, &written );
    SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), coord );
    return;
}

int main()
{
	srand(time(NULL));
    int x, y;
    char novamente = 's';
    int contador = 10000;
    do{
        printf("Digite as coordenadas no formato x,y: ");
        //scanf("%d,%d", &x, &y);
        x = 1+rand()%1024;
        y = 1+rand()%720;
		SetCursorPos(x, y); //Muda a posição do cursor
		getCursorPos();
        //printf("\nQuer testar novamente (s/n)? ");
        //scanf("\n%c", &novamente);
        //if (novamente == 's'){
            limpartela(); //Limpa a tela se quiser testar novamente
        //}
        contador--;
    }while(contador != 0);
    
	return 0;
}
