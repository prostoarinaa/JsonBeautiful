
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
class MakeBeautiful {
public:
    struct Pair {
        unsigned long Number;
        unsigned long CountTab;
        unsigned long First;
        unsigned long Second;
    };
public:
    void TabEnter(){
        ifstream fileOld;
        ofstream fileNew;
        fileOld.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringOLD.txt");
        fileNew.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt");
        string str = "", s;
        while(true)
        {
            getline(fileOld, str, '[');
            fileNew << str;
            if (!fileOld.eof())
                fileNew << "[\n";
            else break;
        }
        ifstream input("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt");
        ofstream output("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt");
        while(true)
        {
            getline(input, str, ']');
            output << str;
            
            if (!input.eof()) {
                if (str[str.length()-1] != '\n')
                    output << "\n]\n";
                else
                    output << "]\n";
            }
            else break;
        }
        input.close();
        output.close();
        ifstream input1("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt");
        ofstream output1("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt");
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
        ifstream input2("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt");
        ofstream output2("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt");
        while(true)
        {
            getline(input2, str, '}');
            output2 << str;
            if (!input2.eof()) {
                if (str[str.length()-1] != '\n')
                    output2 << "\n}\n";
                else
                    output2 << "}\n";
            }
            else break;
        }
        input2.close();
        output2.close();
        ifstream input3("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt");
        ofstream output3("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt");
        while(true)
        {
            getline(input3, str, ':');
            output3 << str;
            if (!input3.eof()) {
                if (str[str.length()-1] == '\"')
                    output3 << " :  ";
                else
                    output3 << ";";
            }
            else break;
        }
        input3.close();
        output3.close();
        ifstream input4("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt");
        ofstream output4("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt");
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
    };
    struct CheckMisstakeResult {
        string mistake;
        Pair pair;
        long num;
    };
//    CheckMisstakeResult CheckMisstake(vector <Pair> PairVec1, vector <Pair> PairVec2, long num1, long num2) {
//       // Pair pair;
//        CheckMisstakeResult result;
//        for (auto i = num1; i < PairVec1.size(); i++){
//            if ((PairVec1[i].First > 0)&&(PairVec1[i].Second == 0)) {
//                result.mistake1 = "ERROR : EXPECTED ']'";
//                result.pair1 = PairVec1[i];
//                result.num1 = i;
//            }
//            else {
//                result.mistake1 = "CORRECT";
//                result.pair1 = PairVec1[0];
//            }
//        }
//        for (auto i = num2; i < PairVec2.size(); i++){
//            if ((PairVec2[i].First > 0)&&(PairVec2[i].Second == 0)) {
//                result.mistake2 = "ERROR : EXPECTED '}'";
//                result.pair2 = PairVec2[i];
//                result.num2 = i;
//            }
//            else {
//                result.mistake2 = "CORRECT";
//                result.pair2 = PairVec2[0];
//            }
//        }
//        return result;
//    };

    void Tabulation() {
        ifstream fileOld;
        ofstream fileNew;
        fileOld.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt");
        fileNew.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt");
        
        string str = "",s;
        unsigned long pos1 = 0;
        vector <unsigned long> tab = {0};
        vector <Pair> PairVec1;
        vector <Pair> PairVec2;
        unsigned long count = 1;
        Pair pair1, pair2;
        while(true)
        {
            getline(fileOld, str, '\n');
            pos1 += str.size() ;
           
            if (str[str.size()-1] == '[') {
//                Pair pair;
                PairVec1.push_back(pair1);
                pair1.Number = count;
                pair1.First = pos1;
                pair1.Second = -1;
                tab.push_back(tab.size());
                pair1.CountTab = tab[tab.size()-1];
            }
             if (str[str.size()-1] == ']') {
               // Pair pair;
                PairVec1[PairVec1.size()-1].Second = pos1;
            }
             if (str[str.size()-1] == '{') {
                //Pair pair;
                PairVec2.push_back(pair2);
                pair2.Number = count;
                pair2.First = pos1;
                pair2.Second = -1;
                tab.push_back(tab.size());
                pair2.CountTab = tab[tab.size()-1];
            }
            else if (str[str.size()-1] == '}') {
               // Pair pair;
                PairVec2[PairVec2.size()-1].Second = pos1;
            }
//            for ( auto i = 0; i < str.size()-1; i++) {
//                if (str) {
//                }
//            }
            count++;
            string tabstr = "";
            if (!fileOld.eof()) {
                fileNew << "\n";
                for(auto i = 0; i < tab.size(); i++){
                    tabstr += "   ";
                }
                fileNew << tabstr;
                fileNew << str;
            }
            else break;
            if ((str[str.size()-1] == ']')||(str[str.size()-1] == '}')) {
                tab.pop_back();
            }
        }
        fileOld.close();
        fileNew.close();
        ofstream fileMistake;
        fileMistake.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringMistake.txt");
        CheckMisstakeResult result1, result2;
        cout <<PairVec1[1].First << "  " <<PairVec1[1].Second << "  " << PairVec1[1].Number<< endl;
        vector <CheckMisstakeResult> Res1, Res2;
        for (auto i = 0; i < PairVec1.size(); i++){
            if (PairVec1[i].Second == -1) {
                result1.mistake = "ERROR : EXPECTED ']' for string №";
                result1.pair = PairVec1[i];
                result1.num = PairVec1[i].Number;
                Res1.push_back(result1);
            }
        }
        for (auto i = 0; i < PairVec2.size(); i++){
            if (PairVec2[i].Second == -1) {
                result2.mistake = "ERROR : EXPECTED '}' for string №";
                result2.pair = PairVec2[i];
                result2.num = PairVec2[i].Number;
                Res2.push_back(result2);
            }
        }
        for(auto i= 0 ;i<Res1.size();i++){
            if (Res1[i].num != Res1[i-1].num)
                fileMistake << Res1[i].mistake <<"  "<<Res1[i].num<< endl;
        }
        for(auto i= 0 ;i<Res1.size();i++){
            if (Res2[i].num != Res2[i-1].num)
                fileMistake << Res2[i].mistake <<"  "<<Res2[i].num<< endl;
        }
        fileMistake << endl << endl << endl;
        
    };
    
    void LongString() {
        ifstream fileOld;
        ofstream fileNew;
        fileOld.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringNew.txt");
        fileNew.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt");

        string str, timestr;
        long isFirstStr = 0;
        while(true)
        {
            isFirstStr++; //  счет строк
            unsigned long count = 0;
            string tabstr = "";
            getline(fileOld, str, '\n');
            while (str[count] == ' ') {
                count++;
                tabstr += ' ';
            }
            if (str.length() <= 100+count) {
                fileNew << str;
            }
            else {
                string strForLast = "";
                while (str.length() > 100+count) {
                    timestr = str.substr(count, 100+count);
                    str = str.erase(1, 100+count);
                    strForLast = str;
                    if (strForLast.length() <= 100+count)
                        continue;
                    fileNew << tabstr << timestr;
                    fileNew << '\n';
                }
                if(str.length() <= 100+count) {
                    timestr = timestr.erase(timestr.length()+1-strForLast.length());
                    fileNew << tabstr << timestr;
                    fileNew << '\n';
                    fileNew << tabstr << strForLast;
                }
            }
            if (!fileOld.eof())
                fileNew << '\n';
            else break;
        }
    };
    void Validator () {
        ifstream fileOld;
        ofstream fileMistake;
        fileOld.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstring.txt");
        fileMistake.open("/Users/pk/Desktop/OI/TASKS/JsonBeautiful/JsonBeautiful/jsonstringMistake.txt", ios_base::app);
       
        string str;
        while(true)
        {
            int flagK1 = 0;
            getline(fileOld, str, ':');
            for (int i = 1; i < str.length(); i++) {
                    if (str[i] == '\"') {
                        if (str[i-1] != '\\')
                        flagK1++;
                    }
            }
            if (flagK1 %2 == 0 && str[str.length()-1] == ' ') {
                continue;
            }
                else if (flagK1 %2 != 0 && str[str.length()-1] != ' ') {
                    continue;
                }
                    else {
                        fileMistake << endl <<"//////////////////////////////////////////////////////////////////////" << endl<< endl;
                        fileMistake << "ERROR: missed ( \" ) in " << "[ " << str << " ]" << endl << endl;
                        flagK1 = 0;
                    }
            if (!fileOld.eof())
                continue;
            else break;
        }
    };
};

int main()
{
    MakeBeautiful File;
    File.TabEnter();
    File.Tabulation();
    File.LongString();
    File.Validator();
    return 0;
}
