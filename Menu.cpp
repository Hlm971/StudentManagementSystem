#include "Menu.h"
#include <iostream>
#include <limits>
using namespace std;

Menu::Menu(string title)
{
    this->title = title;
}

Menu& Menu::operator<<(const string& option)
{
    options.push_back(option);
    return *this;
}

void Menu::display() const
{
    cout << "\n===== " << title << " =====\n";
    for (size_t i = 0; i < options.size(); i++)
    {
        cout << i << ". " << options[i] << endl;
    }
}

int Menu::choose() const
{
    int ch;
    while (true)
    {
        display();
        cout << "Moi chon: ";
        if (cin >> ch)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ch >= 0 && ch < (int)options.size())
                return ch;
            cout << "Lua chon khong hop le!\n";
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nhap sai, vui long nhap lai!\n";
        }
    }
}
