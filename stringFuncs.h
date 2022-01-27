#pragma once
#include <string>
#include <iostream>
using namespace std;

class myString {
public:
    string userString;
    myString()
    {
        initString();
    }
    myString(string a)
    {
        setString(a);
    }
    void setString(string a)
    {
        this->userString = a;
    }
    int size() {
        int l = 0;
        int i = 0;
        while (userString[i])
        {
            l++;
            i++;
        }
        return l;
    }
    string addStart(myString m)
    {
        this->userString = m.getString() + userString;
        return userString;
    }
    string addEnd(myString m)
    {
        this->userString = userString + m.getString();
        return userString;
    }
    void partString(int startPos, int length) {
        if (startPos < 0 || startPos > length)
            cout << "Starting position for string was less than 0 or greater than string length. Try again!\n";
        else if (startPos == length)
            cout << "";
        else {
            startPos--;
            for (int i = startPos; i <= length; i++)
            {
                cout << userString[i];
            }
            cout << endl;
        }
    }
    void replPartString(myString m, int startPos)
    {
        startPos--;
        int k = 0;
        for (int i = startPos; i < startPos + m.size(); i++)
        {
            userString[i] = m.userString[k];
            k++;
        }
    }
    string replWholeString(myString m)
    {
        userString = m.getString();
        return userString;
    }
    int compareString(myString m)
    {
        if (userString == m.userString)
            return 0;
        else {
            int compare = 0;
            for (int i = 0; i <= m.size(); i++)
            {
                if (userString[i] != m.userString[i]) {
                    compare = i - 1;
                }
                else
                    i++;
            }
            return compare;
        }
    }
    void initString()
    {
        userString = "";
    }
    string getString()
    {
        return userString;
    }
    string printStringScreen()
    {
        return userString;
    }
    bool numericString()
    {
        for (int i = 0; i < userString.size(); i++) {
            if (isdigit(userString[i]) == false)
                return false;
            else if (isdigit(userString[i]) == true)
                return true;
        }
    }
    bool alphabeticString()
    {
        for (int i = 0; i < userString.size(); i++) {
            if (isalpha(userString[i]) == true)
                return true;
            else if (isalpha(userString[i]) == false)
                return false;
        }
    }
};