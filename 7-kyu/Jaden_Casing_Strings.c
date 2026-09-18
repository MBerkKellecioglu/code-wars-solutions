#include<string.h>

char *to_jaden_case (char *jaden_case, const char *string)
{
  
  int i;
  
	*jaden_case = '\0';
  
  strcpy(jaden_case,string);
  
  jaden_case[0] = toupper(jaden_case[0]);
  
  for(i = 1; jaden_case[i]!= '\0'; i++){
    if(jaden_case[i-1] == ' '){
      jaden_case[i] = toupper(jaden_case[i]);
    }
  }
  
	return jaden_case;
}