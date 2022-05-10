#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void supplyNQ(int num1, int num2, int type)
{
    switch (type)
    {
    case 1:
        cout << "How much is" << num1 << "plus" << num2 << endl;
        break;
    case 2:
        cout << "How much is" << num1 << "substract" << num2 << endl;
        break;
    case 3:
        cout << "How much is" << num1 << "times" << num2 << endl;
        break;
    case 4:
        cout << "How much is" << num1 << "divided by" << num2 << endl;
        break;
    }
}

void True()
{
    int n3;
    n3 = 1 + rand() % 4;
    switch (n3)
    {
    case 1:
        cout << "Very good!" << endl;
        cout << endl;
        break;

    case 2:
        cout << "Excellent!" << endl;
        cout << endl;
        break;

    case 3:
        cout << "Nice work!" << endl;
        cout << endl;
        break;

    case 4:
        cout << "Keep up the good work!" << endl;
        cout << endl;
        break;
    }
}

void False()
{
    int n4;
    n4 = 1 + rand() % 4;
    switch (n4)
    {
    case 1:
        cout << "No,please try again." << endl;
        cout << endl;
        break;

    case 2:
        cout << "Wrong.Try once more." << endl;
        cout << endl;
        break;

    case 3:
        cout << "Don't give up." << endl;
        cout << endl;
        break;

    case 4:
        cout << "No.Keep trying." << endl;
        cout << endl;
        break;
    }
}
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int time;
    int result;
    int type;
    int answer;
    int number1, number2;
    int FrequenceT = 0, FrequenceF = 0;
    int a;
    int level;
    cout << "Please select the level of arithmetic that you want" << endl;
    cout << "1:single digit" << endl;
    cout << "2:double digit" << endl;
    cout << "level=";
    cin >> level;
    cout << "Please select the type of arithmetic that you want" << endl;
    cout << "1:plus" << endl;
    cout << "2:subtraction" << endl;
    cout << "3:multiplication" << endl;
    cout << "4:division" << endl;
    cout << "5:random" << endl;
    cout << "type=";
    cin >> type;
    a = type;
    for (time = 1; time <= 10; time++)
    {
        if (a == 5)
            type = 1 + rand() % 4;
        if (level == 1)
        {
            number1 = 1 + rand() % 9;
            number2 = 1 + rand() % 9;
        }
        else
        {
            number1 = 10 + rand() % 90;
            number2 = 10 + rand() % 90;
        }
        if (type == 1)
        {
            answer = number1 + number2;
            supplyNQ(number1, number2, type);
        }
        else if (type == 2)
        {
            do
            {
                swap(number1, number2);
            } while (number1 < number2);
            answer = number1 - number2;
            supplyNQ(number1, number2, type);
        }
        else if (type == 3)
        {
            answer = number1 * number2;
            supplyNQ(number1, number2, type);
        }
        else if (type == 4)
        {
            if (level == 1)
            {
                do
                {
                    number1 = 1 + rand() % 9;
                    number2 = 1 + rand() % 9;
                } while (number1 % number2 != 0);
            }
            if (level == 2)
            {
                do
                {
                    number1 = 10 + rand() % 90;
                    number2 = 10 + rand() % 90;
                } while (number1 % number2 != 0);
            }
            answer = number1 / number2;
            supplyNQ(number1, number2, type);
        }
        cin >> result;
        if (result == answer)
        {
            FrequenceT += 1;
            True();
        }
        else
        {
            FrequenceF += 1;
            False();
            if (type == 1)
            {
                do
                {
                    cout << "How much is" << number1 << "plus" << number2 << endl;
                    cin >> result;
                } while (result != answer);
            }
            else if (type == 2)
            {
                do
                {
                    cout << "How much is" << number1 << "substract" << number2 << endl;
                    cin >> result;
                } while (result != answer);
            }
            else if (type == 3)
            {
                do
                {
                    cout << "How much is" << number1 << "times" << number2 << endl;
                    cin >> result;
                } while (result != answer);
            }
            else if (type == 4)
            {
                do
                {
                    cout << "How much is" << number1 << "divided by" << number2 << endl;
                    cin >> result;
                } while (result != answer);
            }
            True();
        }
    }
    if (FrequenceT / 10.0 >= 0.75)
        cout << "Congradulation,you are ready to go to the next level." << endl;
    else
        cout << "Please ask you teacher for extra help." << endl;

    return 0;
}