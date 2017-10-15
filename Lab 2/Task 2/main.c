#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// This program takes the input text file "input.txt" and replaces all occurences of specific phrases
// with other specific phrases 
//-----------------------------------------------------------------------------------------

int main(int argc, char *argv[])
{

printf("in main, starting program \n");

//intialize f and f2 as file type variables
FILE *f;
FILE *f2;

//Initialize all the strings to look for, and all the corresponding strings to change them to

char *str1 = "Inferno";
char *str2 = "In dark woods";
char *str3 = "those woods";
char *str4 = "to enter";
char *str5 = "crest";
char *str6 = "Below a hill";
char *str7 = "shoulders";
char *str8 = "planet";
char *str9 = "dante";

char *str1b = "Paradisio";
char *str2b = "using Windows 8.1";
char *str3b = "Windows 8.1";
char *str4b = "to use 8.1";
char *str5b = "screen";
char *str6b = "Before a monitor";
char *str7b = "GUI";
char *str8b = "UNIX";
char *str9b = "Shakespeare";

//intialize a character array where the input.txt will be put
char *buffer = 0;
long length;

f=fopen("input.txt","r");
f2=fopen("dante.txt","w");

if(!f){
printf("file didnt open properly\n");
exit(1);} // if file doesnt open properly, exit program

printf("file opened properly\n");


//Putting input.txt into a manipulatable c string 
//---------------------------------------------------
fseek(f,0,SEEK_END);
length = ftell(f); //find length of the text file
fseek(f,0,SEEK_SET);
buffer = malloc(length); //change the buffer size to fit the input
if (buffer)
{
fread(buffer,1,length,f); // puts all contents of input.txt into the buffer char array
}

printf("\n");
fclose(f); //closes input.txt
//----------------------------------------------------


if (&buffer) // is true if buffer is not 0
{

for(int i=0; i<strlen(buffer)-1 ; i++){
int flag = 0; //this flag variable is 1 if one of the key phrases are found and replaced, otherwise it is 0 

//checks if substring is "Inferno", if so, then it replaces it
char substring1[7];
memcpy(substring1 , &buffer[i],7);
substring1[7] = '\0';

if(strcmp(substring1, str1) == 0)
	{
	printf("%s\n",str1);
	printf("\n");
	printf("changing substring\n");
	fputs(str1b, f2); //replaces inferno with Pardisio
	//increments i counter so it doesnt read the rest of the substrings characters 	
	i += (strlen(str1))-1;
	flag = 1; 
	}



//checks for "in dark woods"
char substring2[13];
memcpy(substring2 , &buffer[i],13);
substring2[13]='\0';


if(strcmp(substring2, str2) == 0)
	{
	printf("%s\n",str2);
	printf("\n");
	printf("changing substring\n");
	fputs(str2b, f2); //replaces in dark woods with using Windows 8.1
	i += (strlen(str2)-1);
	flag = 1;
	}


printf("current substring is:\n");
printf("%s\n",substring2);

printf("string comparison number is:");
printf("%d\n",strcmp(substring1, str1));



//checks for "those woods"
char substring3[11];
memcpy(substring3 , &buffer[i],11);
substring3[11]='\0';

if(strcmp(substring3, str3) == 0)
	{
	printf("%s\n",str3);
	printf("\n");
	printf("changing substring\n");
	fputs(str3b, f2); //replaces those woods with Windows 8.1
	i += (strlen(str3)-1);
	flag =1;
	}



// checks for "to enter"
char substring4[8];
memcpy(substring4 , &buffer[i],8);
substring4[8]='\0';

if(strcmp(substring4, str4) == 0)
	{
	printf("%s\n",str4);
	printf("\n");
	printf("changing substring\n");
	fputs(str4b, f2); //replaces to enter with to use 8.1
	i += (strlen(str4)-1);
	flag =1;
	}

//checks for "crest"
char substring5[5];
memcpy(substring5 , &buffer[i],5);
substring5[5]='\0';

if(strcmp(substring5, str5) == 0)
	{
	printf("%s\n",str5);
	printf("\n");
	printf("changing substring\n");
	fputs(str5b, f2); //replaces inferno with pardisio
	i += (strlen(str5)-1);
	flag = 1;	
	}

//checks for "below a hill"
char substring6[12];
memcpy(substring6 , &buffer[i],12);
substring6[12]='\0';

if(strcmp(substring6, str6) == 0)
	{
	printf("%s\n",str6);
	printf("\n");
	printf("changing substring\n");
	fputs(str6b, f2); //replaces inferno with pardisio
	i += (strlen(str6)-1);
	flag=1;
	}

//checks for "shoulders"
char substring7[9];
memcpy(substring7 , &buffer[i],9);
substring7[9]='\0';

if(strcmp(substring7, str7) == 0)
	{
	printf("%s\n",str7);
	printf("\n");
	printf("changing substring\n");
	fputs(str7b, f2); //replaces inferno with pardisio
	i += (strlen(str7)-1);
	flag=1;	
	}

//checks for "planet"
char substring8[6];
memcpy(substring8 , &buffer[i],6);
substring8[6]='\0';

if(strcmp(substring8, str8) == 0)
	{
	printf("%s\n",str8);
	printf("\n");
	printf("changing substring\n");
	fputs(str8b, f2); //replaces inferno with pardisio
	i += (strlen(str8)-1);
	flag=1;
	}


//checks for "dante"
char substring9[5];
memcpy(substring9 , &buffer[i],5);
substring9[5]='\0';

if(strcmp(substring9, str9) == 0)
	{
	printf("%s\n",str9);
	printf("\n");
	printf("changing substring\n");
	fputs(str9b, f2); //replaces inferno with pardisio
	i += (strlen(str9)-1);
	}





// if no phrases are replaced, prints the current character to dante.txt
if (flag == 0)
	{
	fputc(buffer[i],f2);
	}


}
}
printf("end of program \n");
fclose(f2);
return 0;
}


