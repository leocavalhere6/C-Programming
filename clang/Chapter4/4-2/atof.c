#include <ctype.h>  
#include <math.h>  

float atof(char s[])
{
    double val, power, exp;
    int i, sign, esign;

    for (i = 0; isspace(s[i]); i++) 
        ;
    sign = (s[i] =='-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)    
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.') {                      
        i++;
        for (power = 1.0; isdigit(s[i]); i++) {
            val = 10.0 * val + (s[i] - '0');
            power *= 10.0;
        }
        val *= sign / power;
    }
    if (s[i] == 'e' || s[i] == 'E') {       
        esign = (s[++i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0.0; isdigit(s[i]); i++)
            exp = 10.0 * exp + (s[i] - '0');
        val *= pow(10, esign * exp);
    }
    return val;
}
