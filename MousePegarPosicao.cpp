#include <iostream>
#include <Windows.h> // GetCursorPos(), SetCursorPos()

int main()
{
  while (true)
  {
    POINT p;
    // Pega posi��o do cursor
    GetCursorPos(&p);

    std::cout << p.x << ", " << p.y << std::endl;

    // Define a posi��o do cursor
    //SetCursorPos(100, 100);

    Sleep(1000);
  }

  return 0;
}
