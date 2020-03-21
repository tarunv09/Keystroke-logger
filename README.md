# Keystroke Logger
A keystroke logger (also known as keylogger) is software that tracks or logs the keys when struck on the keyboard. The main purpose is to log everything that is typed on a keyboard and store it in text files for later assessment. 

## DISCLAIMER:
I built this project to learn and improve something that I was curious about back in my sophomore days. I don't promote this or similar softwares to be used in any malicious manner or for illegitimate purposes. 

### Keylogger comprises of three main components:
1. Log: A log is the automatically produced and time-stamped documentation of events relevant to a particular system. 
2. GetKeyState(): It returns a specific value when the ASCII/hex value of the character keypressed.
3. Hidden Mode: The whole software isn’t visible or detectable by the user.

### Modules 
There are various ways by keys can be intercepted and three of them are:
1. kbhit()<br />
Prototype: int kbhit(void);<br />
Header File: conio.h<br />
Explanation: This function is not defined as part of the ANSI C/C++ standard. It is  generally used by Borland's family of compilers. It returns a non-zero integer if a key is in the keyboard buffer. It will not wait for a key to be pressed.<br />

2. GetAsyncKeyState()
Prototype: short GetAsyncKeyState(int vKey);<br />
Header File: Windows.h<br />
Explanation: Determines whether a key is up or down at the time the function is called, and whether the key was pressed after a previous call to GetAsyncKeyState. If the function succeeds, the return value specifies whether the key was pressed since the last call to GetAsyncKeyState, and whether the key is currently up or down. If the most significant bit is set, the key is down, and if the least significant bit is set, the key was pressed after the previous call to GetAsyncKeyState.<br />

3. GetKeyState()
Prototype: short GetKeyState(int vKey);<br />
Header File: Windows.h<br />
Explanation: Retrieves the status of the specified virtual key. The status specifies 
whether the key is up, down, or toggled. The return value specifies the status of  
the specified virtual key, as follows:<br />
•	If the high-order bit is 1, the key is down; otherwise, it is up.<br />
•	If the low-order bit is 1, the key is toggled. A key, such as the CAPS LOCK key, is toggled if it is turned on. The key is off and untoggled if the low-order bit is 0. A toggle key's indicator light (if any) on the keyboard will be on when the key is toggled, and off when the key is untoggled.


## Prerequisite 
1. MinGW for Windows<br />
2. VS Code editor 

## Usage
For (cmd-admin) users:
``` 
    cd <Directory Name>
    gcc -mwindows keylogger.c -o test.exe
    test
```
For vs code users:
``` 
    install extension 'Code Runner'
    Right-Click inside the code editor
    Run Code
```

## Screenshots
![output1](/Output/output1.jpg)

![output2](/Output/output2.jpg)
    
## References
[getasynckeystate](https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getasynckeystate)<br />
[getkeystate](https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getkeystate)<br />
[virtual-key-codes](https://docs.microsoft.com/en-us/windows/desktop/inputdev/virtual-key-codes)<br />
