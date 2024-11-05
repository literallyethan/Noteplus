#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <tlhelp32.h>

int isProcessRunning(const char* app){
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 processEntry;

    if (hSnapshot == INVALID_HANDLE_VALUE) {
        return 0; // Error creating snapshot
    }

    processEntry.dwSize = sizeof(PROCESSENTRY32);
    
    if (Process32First(hSnapshot, &processEntry)) {
        do {
            if (strcmp(processEntry.szExeFile, app) == 0) {
                CloseHandle(hSnapshot);
                return 1; // Process is running
            }
        } while (Process32Next(hSnapshot, &processEntry));
    }

    CloseHandle(hSnapshot);

    return 0;
}

int detectProcess(const char* app){
    
    while(isProcessRunning(app) == 0){
        Sleep(1000);
    }
    printf("yay the app opened\n");
    return 0;
}




int main(int argc, char* argv[]) {
    char path[MAX_PATH];
    printf("Enter the path of the executable (e.g., notepad.exe): ");
    fgets(path, sizeof(path), stdin);

    path[strcspn(path, "\n")] = 0;
    
    char *exeName = strrchr(path, '\\');
    if (exeName != NULL) {
        exeName++; // Move past the backslash
    } else {
        exeName = path; // No backslash found, assume it's the name
    }

    printf("detecting program: %s\n", exeName);
    detectProcess(exeName);
    return 0;
}
