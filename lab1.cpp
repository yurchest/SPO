#include <windows.h>
#include <iostream>
#include <math.h>
using namespace std;

int main() {

    // Точные замеры времени. Указатели и структуры
    LARGE_INTEGER t0, t1, frequency;
    QueryPerformanceCounter(&t0);


    double result = sqrt(t0.QuadPart);

    QueryPerformanceCounter(&t1);
    QueryPerformanceFrequency(&frequency);
    
    double ticks = t1.QuadPart - t0.QuadPart;

    double ticks_per_sec = frequency.QuadPart;
    double usec_per_sec = 1e6;

    double usec = usec_per_sec * ticks / ticks_per_sec;
    printf("result=%g, duration=%f usec\n\n", result, usec);


    // Получение версии Windows. Битовые операции

    DWORD info = GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD version = info & mask;
    DWORD platform = info >> 16;

    DWORD mask2 = 0x00ff;
    DWORD version_major = version & mask2;
    DWORD version_minor = version >> 8;



    DWORD build = 0;
    if ((info & 0x40000000) == 0) {
        build = platform >> 8;
    }

    printf("Windows v%d.%d (build %d).\n", version_major, version_minor, build);


    // Получение текстовых данных.Кодировки и строки C

    char system_dir[MAX_PATH];
    GetSystemDirectoryA(system_dir, MAX_PATH);
    printf("System directory: %s\n", system_dir);

    DWORD BufCharCount = 256;

    char user_name[MAX_PATH];
    char computer_name[MAX_PATH];
    GetUserNameA(user_name, &BufCharCount);
    GetComputerNameA(computer_name, &BufCharCount);
    printf("Computer Name: %s\n", computer_name);
    printf("User Name: %s\n", user_name);

    


    
    
}

