/* Adding the Modulus operator and provision for negative numbers
* Program is given the input in a single and and it print the output upon
* getting a \n character.
* For e.g:
*
* 10 10 + 100 + 2 *
*       240
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);

/* reverse polish calculator */

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error:zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("erro:zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        case '^':
            push(pow(pop(), pop()));
            break;
        case '|':
            push(1 / pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;

        }
    }
    return 0;
}

