// Лабораторна робота No10 варіант 16 група СН-11 Дурас А.С.
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text;
    int count = 0;
    cout << "Please enter your text: ";
    getline(cin, text);
    cout << endl;

    // Пошук слів "one" та підрахунок кількості
    for (int i = 0; i < text.size(); i++)
    {
        if (text.substr(i, 3) == "one")
        {
            count++;
        }
    }

    // Виведення результату
    if (count > 0)
    {
        cout << "The word one occurs " << count << " times." << endl;
    }
    else
    {
        cout << "Word one is not found." << endl;
    }

    return 0;
}