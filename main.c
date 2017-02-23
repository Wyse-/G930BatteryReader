#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define BASEPOINTER 0x004833D4
#define OFFSET 0x000067C0

int main(){
    UINT_PTR address = BASEPOINTER; // Base address which holds the pointer to the battery value (the pointer which points to the battery value will often change, but the base address which points to it will always stay the same
    UINT_PTR value = NULL; // Initialize value to NULL, will be used in lines 24-32
    DWORD pid; // Initializing the pid value, which is later used in line 14
    HANDLE hwnd = FindWindowA(NULL, "G930"); // Gets the handle of the G930 window and saves it to the variable hwnd
    if(hwnd == NULL){ // Displays an error and exits the program with code 1 if the G930 window does not exist
        printf("FindWindow Error.");
        exit(1);
    }
    GetWindowThreadProcessId(hwnd,&pid); // Gets the G930 window process ID and saves it to the pid variable
    HANDLE phandle = OpenProcess(PROCESS_VM_READ,0,pid); // Opens the G930 process to memory reading
    if(phandle == NULL){ // If not able to apply the memory read flag to the process exits the program with code 1
        printf("OpenProcess Error.");
        exit(1);
    }
    while(1){ // Endless loop
        ReadProcessMemory(phandle,(void*)address,&value,sizeof(value),0); // Reads the pointer stored in the base address and stores it to
        address = value + OFFSET; // Adds the offset to the pointer stored in the base address
        ReadProcessMemory(phandle,(void*)address,&value,sizeof(value),0); // Reads the battery value from the pointer
        printf("G930 Battery Level = %d\n", value); // Prints the battery value
        FILE *f = fopen("batteryLevel.txt", "w"); // Opens file "batteryLevel.txt" for writing
        if (f == NULL){ // If not able to open file with write flag exits the program with code 1
            printf("Error opening file!\n");
            exit(1);
        }
        fprintf(f, "%d", value); // Writes the battery value to the txt file
        fclose(f); // Closes the txt file
        Sleep(5000); // Wait for 5 seconds
    }
    return 0;
}
