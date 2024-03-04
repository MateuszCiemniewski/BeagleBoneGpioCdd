#include "GPIO_Cdd.h"

/*********************************************************************/
/* MAIN FUNCTION - FOR TESTS                                         */
/*********************************************************************/
//int main() { }

/*********************************************************************/
/*                                                                   */
/*********************************************************************/
char gpio_export(char gpio_pin)
{
    FILE *file;
    char path[50] = "";
	strcat(path, "/sys/class/gpio/gpio");
	char temp[5] = "";
	IntToString(gpio_pin, temp);
	strcat(path, temp);
	int8_t i = 0;
	do
	{
    file = fopen("/sys/class/gpio/export", "w");
    char pin[4] = "";
    IntToString(gpio_pin, pin);

    if (!file)
    {
        fprintf(stderr, "Error opening the export file\n");
        return -1;
    } else
    {
        fprintf(file, pin);
        fclose(file);
    }
    } while (access(path, F_OK) || (i == 3));
    return 0;
}

/*********************************************************************/
/*                                                                   */
/*********************************************************************/
char gpio_uexport(char gpio_pin)
{
    FILE *file;

    file = fopen("/sys/class/gpio/unexport", "w");
    char pin[4] = "";
    IntToString(gpio_pin, pin);

    if (!file)
    {
        fprintf(stderr, "Error opening the export file\n");
        return -1;
    } else
    {
        fprintf(file, pin);
        fclose(file);
    }
    return 0;
}

/*********************************************************************/
/*                                                                   */
/*********************************************************************/
char gpio_direction(char direct, char gpio_pin)
{
    FILE *file;
    char path[50] = "/sys/class/gpio/gpio";
    char temp[5] = "";
    IntToString(gpio_pin, temp);
    strcat(path, temp);
    strcat(path, "/direction");

    file = fopen(path, "w");
    if (!file)
    {
        fprintf(stderr, "Error opening the export file %s\n", path);
        return -1;
    } else
    {
        if (direct)
        {
            fprintf(file, "out");
        } else
        {
            fprintf(file, "in");
        }
        fclose(file);
    }
        return 0;
}

/*********************************************************************/
/*                                                                   */
/*********************************************************************/
char gpio_value(char value, char gpio_pin)
{
    FILE *file;
    char path[50] = "/sys/class/gpio/gpio";
    char temp[5] = "";
    IntToString(gpio_pin, temp);
    strcat(path, temp);
    strcat(path, "/value");

    file = fopen(path, "w");
    if (!file)
    {
        fprintf(stderr, "Error opening the export file %s\n", path);
        return -1;
    } else
    {
        if (value)
        {
            fprintf(file, "1");
        } else
        {
            fprintf(file, "0");
        }
        fclose(file);
    }
        return 0;
}

/*********************************************************************/
/*                                                                   */
/*********************************************************************/
char unexport_all()
{
    char i;
    for (i = 0; i < 100; i++)
    {
        gpio_uexport(i);
    }
}

/*********************************************************************/
/*                                                                   */
/*********************************************************************/
void IntToString(int number, char *string)
{
    char ii = 0;
    char next_digit_status = 0;
    for (int i = 9; i >= 0; i--)
    {
        if (number >= (potega(10, i)) || next_digit_status)
        {
            next_digit_status = 1;
            char digit = number / (potega(10, i));
            string[ii] = digit + 48;
            number %= (potega(10, i));
            ii++;
        }
    }
}

/*********************************************************************/
/*                                                                   */
/*********************************************************************/
int potega(int liczba, char stopien)
{
    int liczba_org = liczba;
    if (liczba > 0)
    {
        if (stopien != 0)
        {
            for(int i = 1; i < stopien; i++)
                {
                    liczba *= liczba_org;
                }
        } else
        {
            liczba = 1;
        }
    } else
    {
        liczba = 0;
    }
    return liczba;
}
