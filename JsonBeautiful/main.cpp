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
    fileOld.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt");
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
    string str = "",s;
    
    while(true)
    {
       
        getline(fileOld, str, '[');
        fileNew << str;
        if (!fileOld.eof())
            fileNew << "[\n";
        else break;
    }
    ifstream input("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt"); //Открываешь первый файл для чтения
        ofstream output("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt"); //Открываешь второй файл для записи
       // output << input.rdbuf();

    while(true)
    {
        
        getline(input, str, ']');
        output << str;
        if (!input.eof())
            output << "\n]\n";
        else break;
    }
    input.close();
    output.close();
    ifstream input1("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt"); //Открываешь первый файл для чтения
        ofstream output1("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt"); //Открываешь второй файл для записи
    while(true)
    {
        
        getline(input1, str, '{');
        output1 << str;
        if (!input1.eof())
            output1 << "{\n";
        else break;
    }
    input1.close();
    output1.close();
    ifstream input2("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt"); //Открываешь первый файл для чтения
        ofstream output2("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt"); //Открываешь второй файл для записи
    while(true)
    {
        
        getline(input2, str, '}');
        output2 << str;
        if (!input2.eof())
            output2 << "\n}\n";
        else break;
    }
    input2.close();
    output2.close();
    ifstream input3("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt"); //Открываешь первый файл для чтения
        ofstream output3("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt"); //Открываешь второй файл для записи
    while(true)
    {
        
        getline(input3, str, ':');
        output3 << str;
        if (!input3.eof())
            output3 << ":  ";
        else break;
    }
    input3.close();
    output3.close();
    ifstream input4("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt"); //Открываешь первый файл для чтения
        ofstream output4("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt"); //Открываешь второй файл для записи
    while(true)
    {
        
        getline(input4, str, ',');
        output4 << str;
        if (!input4.eof())
            output4 << "\n";
        else break;
    }
    input4.close();
    output4.close();
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
    
    return 0;
}
