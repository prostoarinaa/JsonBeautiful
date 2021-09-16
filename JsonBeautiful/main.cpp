
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
void enter(){
    ifstream fileOld;
    ofstream fileNew;
    fileOld.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt");
    fileNew.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt");
    cout << "hjkhkj" << endl;
    if (!fileOld.is_open()) {
        cout << "no" << endl;
    }
    else {
        cout << "yes" << endl;
    }
    if (!fileNew.is_open()) {
        cout << "no" << endl;
    }
    else {
        cout << "yes"
        <<endl;
    }
    string str = "", s;
    
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
      

    while(true)
    {
        
        getline(input, str, ']');
        output << str;
        
        if (!input.eof())
            
            output << "]\n";
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
            output2 << "}\n";
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
    fileOld.close();
    fileNew.close();
}
struct Pair {
    unsigned long Number;
    unsigned long CountTab;
    unsigned long First;
    unsigned long Second;
};
void Tabulation() {
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
    unsigned long pos1 = 0;
    vector <unsigned long> tab = {0};
    vector <Pair> PairVec1;
    vector <Pair> PairVec2;
//    map<unsigned long, pairss > Pairs;
    unsigned long count = 0;
    while(true)
    {
        getline(fileOld, str, '\n');
        pos1 += str.size() - 1;
       // count += pos1;
        if (str[str.size()-1] == '[') {
            Pair pair;
            PairVec1.push_back(pair);
            pair.Number = count;
            pair.First = pos1;
            tab.push_back(tab.size());
            pair.CountTab = tab[tab.size()-1];
        }
        else if (str[str.size()-1] == ']') {
            Pair pair;
            pair = PairVec1[PairVec1.size()-1];
           // pair.Number2 = count;
            pair.Second = pos1;
//            tab.pop_back();
            //pair.CountTab = tab[tab.size()-1];
        }
        else if (str[str.size()-1] == '{') {
            Pair pair;
            PairVec2.push_back(pair);
            pair.Number = count;
            pair.First = pos1;
            tab.push_back(tab.size());
            pair.CountTab = tab[tab.size()-1];
        }
        else if (str[str.size()-1] == '}') {
            Pair pair;
            pair = PairVec2[PairVec2.size()-1];
           // pair.Number2 = count;
            pair.Second = pos1;
//            tab.pop_back();
            //pair.CountTab = tab[tab.size()-1];
        }
        
        count++;
        string tabstr = "";
        if (!fileOld.eof()) {
            fileNew << "\n";
            for(auto i = 0; i < tab.size(); i++){
                tabstr += "   ";
            }
            str = tabstr + str;
            fileNew << str;
        }
        else break;
        if ((str[str.size()-1] == ']')||(str[str.size()-1] == '}')) {
            tab.pop_back();
        }
    }
    fileOld.close();
    fileNew.close();
}
int main()
{
    enter();
    Tabulation();
    ifstream fileOld;
    ofstream fileNew;
    fileOld.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt");
    fileNew.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt");
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
    string str, timestr;
    long isFirstStr = 0;
    while(true)
    {
        isFirstStr++;
        cout << isFirstStr<<endl;
        unsigned long count = 0;
        string tabstr = "";
        getline(fileOld, str, '\n');
        while (str[count] == ' ') {
            count++;
            tabstr += ' ';
        }
        if (str.length() <= 100)
            fileNew << str;
        else{
            while (str.length() > 100) {
             
               // fileNew << str;
                fileNew << '\n';
                timestr = str.substr(1+count, 100);
                str = str.erase(1, 100+count);
                if(isFirstStr != 1)
                    fileNew << tabstr << timestr;
                else
                    fileNew << timestr;
            }
        }
        if (!fileOld.eof())
            fileNew << '\n';
        else break;
    }
    return 0;
}
