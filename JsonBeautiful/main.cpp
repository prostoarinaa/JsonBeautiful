//
//  main.cpp
//  JsonBeautiful
//
//  Created by ПК on 15.09.2021.
//

#include <iostream>
#include <fstream>
#include <string>
//class Beautiful {
//
//};
using namespace std;
int main()
{
    ifstream fileOld;
    ofstream fileNew;
    fileOld.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/jsonstring.txt");
    fileNew.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt");
    cout << "hjkhkj" << endl;
    if (!fileOld.is_open()) {
        cout << "no" << endl;
    }
    else {
        cout << "yes"
        <<endl;
    }
    if (!fileNew.is_open()) {
        cout << "no" << endl;
    }
    else {
        cout << "yes"
        <<endl;
    }
    string str = "";
    while(true)
    {
        getline(fileOld, str, '[');
        fileNew << str;
        if (!fileOld.eof())
            fileNew << "[\n";
        else break;
    }
//    ifstream input("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt"); //Открываешь первый файл для чтения
//        ofstream output("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/jsonstring.txt"); //Открываешь второй файл для записи
//        output << input.rdbuf();
//    
//    while(true)
//    {
//        getline(input, str, ']');
//        fileNew << str;
//        if (!input.eof())
//            output << "]\n";
//        else break;
//    }
//    while(true)
//    {
//        getline(fileOld, str, '{');
//        fileNew << str;
//        if (!fileOld.eof())
//            fileNew << "{\n";
//        else break;
//    }
//    while(true)
//    {
//        getline(fileOld, str, '}');
//        fileNew << str;
//        if (!fileOld.eof())
//            fileNew << "}\n";
//        else break;
//    }
//    while(true)
//    {
//        getline(fileOld, str, ':');
//        fileNew << str;
//        if (!fileOld.eof())
//            fileNew << ":  ";
//        else break;
//    }
    fileOld.close();
    fileNew.close();
//    input.close();
//    output.close();
//    while (getline(fileOld, str))
//    {
//        s += str;
//    }
//    int i = -1;
//    while (i < str.size())
//    {
//        i++;
//        switch(str[i])
//        {
//            case '[':
//                str[]
//        }
//
//    }
    return 0;
}
