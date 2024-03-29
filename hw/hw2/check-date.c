#include <ctype.h>
#include <stdio.h>

#define     MIN_YEAR    1600
#define     MAX_YEAR    2399

int eos = 0;
int value_i;
char value_char;

int month[2] = {0, 0};
int day[2] = {0, 0};
int year[4] = {0, 0, 0, 0};

int days_in_months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// ASCII digit || '/' -> value
int adv(char ascii)
{
    return (int)ascii - 48;
}

int next(int (*state)())
{
    if(eos == 0) {
        value_char = getchar();
        value_i = adv(value_char);
        printf("\nvalue | char : %c | int : %d | ", value_char, value_i);
    }
    return (*state)();
}

// Final state, date check
int ok() {
    printf("\nstate : ok");
    int y = 1000 * year[0] + 100 * year[1] + 10 * year[2] + year[3];
    // Leap year ?
    if(y % 4 == 0 && y % 100 != 0) {
        printf("\nLeap year!");
        days_in_months[1]++;
    }
    int m = month[1] == 0 ? month[0] : 10 * month[0] + month[1];
    int d = day[1] == 0 ? day[0] : 10 * day[0] + day[1];
    printf("\nyear : %d | month : %d | day : %d", y, m, d);
    // Validate date
    if(y < MIN_YEAR || y > MAX_YEAR || m < 0 || m > 12 || d > days_in_months[m-1])
        printf("\nInvalid date.\n");
    else
        printf("\nValid date.\n");
    eos = 0;
    return 0;
}

// Exit state
int y4() { 
    printf("state : y4");
    if(value_i == -38) {
        eos = 1;
        return next(&ok);
    }
    printf("\nNo date found.\n");
    // To clear new line feed '\n' after non digit
    getchar();
    return 0;
}
int y3() {
    printf("state : y3");
    year[3] = value_i;
    if(isdigit(value_char))
        return next(&y4);
    printf("\nNo date found.\n");
    // To clear new line fee '\n' after non digit
    getchar();
    return isdigit(value_char) ? next(&y4) : 1;
}
// Exit state
int y2() {
    printf("state : y2");
    year[2] = value_i;
    if(value_char == '\n') {
        eos = 1;
        // year in [2000, 2099]
        year[2] = year[0];
        year[3] = year[1];
        year[0] = 2;
        year[1] = 0;
        return next(&ok);
    }
    return isdigit(value_char) ? next(&y3) : 1;
}
int yb() {
    printf("state : y1");
    year[1] = value_i;
    if(isdigit(value_char))
        return next(&y2);
    printf("\nNo date found.");
    return 0;
}
int ya() {
    printf("state : y0");
    year[0] = value_i;
    return isdigit(value_char) ? next(&yb) : 1;
}
int d2() {
    printf("state : d2"); 
    return value_i == -1 ? next(&ya) : 1;
}
int d1() {
    printf("state : d1");
    day[1] = value_i != -1 ? value_i : 0;
    return isdigit(value_char) ? next(&d2) : (value_i == -1 ? next(&ya) : 1);
}
int d0() {
    printf("state : d0");
    day[0] = value_i;
    return isdigit(value_char) ? next(&d1) : 1;
}
int m2() {
    printf("state : m2");
    return value_i == -1 ? next(&d0) : 1;
}
int m1() {
    month[1] = value_i != -1 ? value_i : 0;
    printf("state : m1");
    return isdigit(value_char) ? next(&m2) : (value_i == -1 ? next(&d0) : 1);
}
int s() { 
    printf("state : s");
    month[0] = value_i;
    return isblank(value_char) ? next(&s) : (isdigit(value_char) ? next(&m1) : 1);
}

int main()
{
    do {
        // Call DFA
        if(next(&s) == 1) {
            printf("\nInvalid date.\n");
        }
    } while(!feof(stdin));
    return 0;
}