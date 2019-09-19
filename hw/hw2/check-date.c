#include <ctype.h>
#include <stdio.h>
#include <math.h>

int i = 0;
char value;
char buffer[128];

char month[2];
char day[2];
char year[4];

int days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// ASCII Digit -> Value
int adv(char ascii)
{
    return (int)ascii - 48;
}

void leapyear()
{
    int date = 1000 * adv(year[0]) + 100 * adv(year[1]) + 10 * adv(year[2]) + adv(year[3]);
    if(date % 4 == 0 && date % 100 != 0)
        days_in_months[1]++;
}

int next(int (*state)())
{
    i++;
    value = buffer[i];
    printf(", next value : %c\n", value);
    return (*state)();
}

// Circled
int ok() { 
    printf("Valid date.\n");
    leapyear();
    char temp = month[0];
    int month = 10 * adv(month[0]) + adv(month[1]);
    return 0;
}

// Circled
int y4() { 
    printf("state y4 with the value of %d", (int) value);
    if(isblank(value) || (int)value == 0)
        return next(&ok);
    printf("No date found.");
    return 0;
}
int y3() {
    printf("state y3");
    year[3] = value;
    return isdigit(value) ? next(&y4) : 1;
}
// Circled
int y2() {
    printf("state y2");
    year[2] = value;
    if(isblank(value) || (int)value == 0) {
        // year in [2000, 2099]
        year[2] = year[0];
        year[3] = year[1];
        year[0] = 2;
        year[1] = 0;
        return next(&ok);
    }
    if(isdigit(value)) {
        return next(&y3);
    }
    printf("No date found.");
    return 0;
}
int yb() {
    printf("state y1");
    year[1] = value;
    return isdigit(value) ? next(&y2) : 1; 
}
int ya() {
    printf("state y0");
    year[0] = value;
    return isdigit(value) ? next(&yb) : 1;
}
int d2() {
    printf("state d2"); 
    day[1] = value;
    return value == 47 ? next(&ya) : 1;
}
int d1() {
    printf("state d1");
    day[0] = value;
    return isdigit(value) ? next(&d2) : (value == 47 ? next(&ya) : 1);
}
int d0() {
    printf("state d0");
    return isdigit(value) ? next(&d1) : 1;
}
int m2() {
    printf("state m2");
    month[1] = value;
    return value == 47 ? next(&d0) : 1;
}
int m1() { 
    printf("state m1");
    month[0] = value;
    return isdigit(value) ? next(&m2) : (value == 47 ? next(&d0) : 1);
}
int s() { 
    printf("state s");
    return isblank(value) ? next(&s) : (isdigit(value) ? next(&m1) : 1);
}

int main()
{
    scanf("%s", buffer);
    value = buffer[0];
    if(s() == 1) {
        printf("\nInvalid date.");
        return 1;
    }
    return 0;
}