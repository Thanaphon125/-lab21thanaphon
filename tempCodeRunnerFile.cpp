#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <cstdlib>
#include <cstring>
#include <stdio.h>

HWND textfield, buttonPlus, buttonMinus, buttonMultiply, buttonDivide, TextBoxOne, TextBoxTwo;
char textOne[20], textTwo[20], answerStr[20];
double valueOne, valueTwo, numOne, numTwo, answer;

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
    switch(Message) {
        case WM_CREATE:
            textfield = CreateWindow("STATIC", "Please input two numbers",
                                    WS_VISIBLE|WS_CHILD, 20,20,195,20,
                                    hwnd,NULL,NULL,NULL);
            buttonPlus = CreateWindow("BUTTON", "+", WS_VISIBLE|WS_CHILD,
                                    70,115,25,25, hwnd,(HMENU) 1,NULL,NULL);
            buttonMinus = CreateWindow("BUTTON", "-", WS_VISIBLE|WS_CHILD,
                                    100,115,25,25, hwnd,(HMENU) 2,NULL,NULL);
            buttonMultiply = CreateWindow("BUTTON", "*", WS_VISIBLE|WS_CHILD,
                                        130,115,25,25, hwnd,(HMENU) 3,NULL,NULL);
            buttonDivide = CreateWindow("BUTTON", "/", WS_VISIBLE|WS_CHILD,
                                        160,115,25,25, hwnd,(HMENU) 4,NULL,NULL);
            TextBoxOne = CreateWindow("EDIT", "", WS_VISIBLE|WS_CHILD,
                                    50,50,150,20, hwnd,NULL,NULL,NULL);
            TextBoxTwo = CreateWindow("EDIT", "", WS_VISIBLE|WS_CHILD,
                                    50,75,150,20, hwnd,NULL,NULL,NULL);
            break;

        case WM_COMMAND:
            switch(LOWORD(wParam)) {
                case 1:
                    valueOne = GetWindowText(TextBoxOne, textOne, 20);
                    valueTwo = GetWindowText(TextBoxTwo, textTwo, 20);
                    if(valueOne > 0 && valueTwo > 0){
                        numOne = atof(textOne);
                        numTwo = atof(textTwo);
                        answer = numOne + numTwo;
                    }
                    sprintf(answerStr, "%f", answer);
                    MessageBox(hwnd, answerStr, "Result", MB_OK);
                    break;
                case 2:
                    valueOne = GetWindowText(TextBoxOne, textOne, 20);
                    valueTwo = GetWindowText(TextBoxTwo, textTwo, 20);
                    if(valueOne > 0 && valueTwo > 0){
                        numOne = atof(textOne);
                        numTwo = atof(textTwo);
                        answer = numOne - numTwo;
                    }
                    sprintf(answerStr, "%f", answer);
                    MessageBox(hwnd, answerStr, "Result", MB_OK);
                    break;
                case 3:
                    valueOne = GetWindowText(TextBoxOne, textOne, 20);
                    valueTwo = GetWindowText(TextBoxTwo, textTwo, 20);
                    if(valueOne > 0 && valueTwo > 0){
                        numOne = atof(textOne);
                        numTwo = atof(textTwo);
                        answer = numOne * numTwo;
                    }
                    sprintf(answerStr, "%f", answer);
                    MessageBox(hwnd, answerStr, "Result", MB_OK);
                    break;
                case 4:
                    valueOne = GetWindowText(TextBoxOne, textOne, 20);
                    valueTwo = GetWindowText(TextBoxTwo, textTwo, 20);
                    if(valueOne > 0 && valueTwo > 0){
                        numOne = atof(textOne);
                        numTwo = atof(textTwo);
                        if(numTwo == 0){
                            MessageBox(hwnd, "Cannot divide by zero.", "Result", MB_ICONEXCLAMATION|MB_OK);
                            break;
                        } else {
                            answer = numOne / numTwo;
                        }
                    }
                    sprintf(answerStr, "%f", answer);
                    MessageBox(hwnd, answerStr, "Result", MB_OK);
                    break;
            }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, Message, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    MSG msg;

    memset(&wc, 0, sizeof(wc));
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 139)); // เปลี่ยนเป็นสีน้ำเงินเข้ม
    wc.lpszClassName = "WindowClass";
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION|MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "WindowClass", "My Calculator", WS_VISIBLE|WS_SYSMENU,
        CW_USEDEFAULT, CW_USEDEFAULT, 250, 200, NULL, NULL, hInstance, NULL);

    if(hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION|MB_OK);
        return 0;
    }

    while(GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
