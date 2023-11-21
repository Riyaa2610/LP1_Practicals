// #include<bits/stdc++.h>
// using namespace std;

// class Tables{
//     public:
//         vector<pair<string, string>> SYMTAB;
//         vector<pair<string, string>> LITTAB;

//         Tables()
//         {
//             fstream sym_tab;
//             sym_tab.open("symbol_table.txt", ios::in);
//             if(sym_tab.is_open())
//             {
//                 string line;
//                 while(!sym_tab.eof())
//                 {
//                     string key;
//                     getline(sym_tab, line);
//                     string w = "";
//                     for (int i = 0; i < line.size();i++)
//                     {
//                         if(line[i]!=' ')
//                         {
//                             w += line[i];
//                         }
//                         else
//                         {
//                             key.assign(w);
//                             w = "";
//                         }
//                     }
//                     SYMTAB.push_back(pair<string, string>(key, w));
//                 }
//             }
//             else
//             {
//                 cout << "Error opening file" << endl;
//             }

//             fstream lit_tab;
//             lit_tab.open("literal_table.txt", ios::in);
//             if(lit_tab.is_open())
//             {
//                 string line;
//                 while(!lit_tab.eof())
//                 {
//                     string key;
//                     getline(lit_tab, line);
//                     string w = "";
//                     for (int i = 0; i < line.size();i++)
//                     {
//                         if(line[i]!=' ')
//                         {
//                             w += line[i];
//                         }
//                         else
//                         {
//                             key.assign(w);
//                             w = "";
//                         }
//                     }
//                     LITTAB.push_back(pair<string, string>(key, w));
//                 }
//             }
//             else
//             {
//                 cout << "Error opening file" << endl;
//             }
//         }
// };

// class Assembler{
//     public:
//         Tables t;
//         fstream intCode;
//         fstream file;

//         Assembler()
//         {
//             intCode.open("ic.txt", ios::in);
//             if(!intCode.is_open())
//             {
//                 cout << "Error opening file" << endl;
//             }
//             file.open("output.txt", ios::out);
//             if(!intCode.is_open())
//             {
//                 cout << "Error opening file" << endl;
//             }
//         }

//         void passTwo()
//         {
//             string line;
//             vector<string> words;
//             if(intCode.is_open())
//             {
//                 while(!intCode.eof())
//                 {
//                 getline(intCode, line);
//                 string w = "";
//                 for (int i = 0; i < line.size();i++)
//                 {
//                     if(line[i] != ' ')
//                     {
//                         w += line[i];
//                     }
//                     else
//                     {
//                         words.push_back(w);
//                         w = "";
//                     }
//                 }
//                 words.push_back(w);

//                 if(words[1].at(1) == 'I' && words[1].at(2) == 'S')
//                 {
//                     file << words[0] << " " << words[2].at(0);
//                     if(words[2].at(1) != ')')
//                     {
//                         file << words[2].at(1) << " ";
//                     }
//                     else
//                     {
//                         file << " ";
//                     }

//                     if(words.size() == 5)
//                     {
//                         if(words[3].at(1) == 'S')
//                         {
//                             int index = words[4].at(0) - '0';
//                             file << t.SYMTAB[index - 1].second;
//                         }
//                         else
//                         {
//                             file << words[3].at(1) << " " << words[4].at(1);
//                         }
//                     }
//                     else if(words.size() == 6)
//                     {
//                         file << words[3].at(1) << " ";
//                         if(words[4].at(1) == 'S')
//                         {
//                             int index = words[5].at(0) - '0';
//                             file << t.SYMTAB[index - 1].second;
//                         }
//                         else if(words[4].at(1) == 'L')
//                         {
//                             int index = words[5].at(0) = '0';
//                             file << t.LITTAB[index - 1].second;
//                         }
//                     }
//                     file << endl;
//                 }
//                 words.clear();
//                 }
//             }
//         }
// };


// int main()
// {
//     Assembler a;
//     a.passTwo();
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

class Tables{
    public:
        vector < pair<string, string>> SYMTAB;
        vector <pair<string, string>> LITTAB;

        Tables()
        {
            fstream sym_tab;
            sym_tab.open("symbol_table.txt", ios::in);
            if(sym_tab.is_open())
            {
                string line;
                while(!sym_tab.eof())
                {
                    getline(sym_tab, line);
                    string w = "";
                    string key = "";
                    for (int i = 0; i < line.size();i++)
                    {
                        if(line[i]!=' ')
                        {
                            w += line[i];
                        }
                        else
                        {
                            key.assign(w);
                            w = "";
                        }
                    }
                    SYMTAB.push_back(pair<string, string>(key, w));
                }
            }
            else
            {
                cout << "Error opening file" << endl;
            }

            fstream lit_tab;
            lit_tab.open("literal_table.txt", ios::in);
            if(lit_tab.is_open())
            {
                string line;
                while(!lit_tab.eof())
                {
                    getline(lit_tab, line);
                    string w = "";
                    string key = "";
                    for (int i = 0; i < line.size();i++)
                    {
                        if(line[i] != ' ')
                        {
                            w += line[i];
                        }
                        else
                        {
                            key.assign(w);
                        }
                    }
                    LITTAB.push_back(pair<string, string>(key, w));
                }
            }
            else
            {
                cout << "Error opening file" << endl;
            }
        }
};


class Assembler{
    public:
        Tables t;
        fstream intCode;
        fstream output;
        fstream file;

        Assembler()
        {
            intCode.open("ic.txt",ios::in);
            if(!intCode.is_open())
            {
                cout << "error opening ic file" << endl;
            }

            output.open("output.txt", ios::out);
            if(!output.is_open())
            {
                cout << "error opening output file" << endl;
            }
        }

        void passTwo()
        {
            string line;
            vector<string> words;
            if(intCode.is_open())
            {
                while(!intCode.eof())
                {
                    getline(intCode, line);
                    string w = "";
                    for (int i = 0; i < line.size();i++)
                    {
                        if(line[i]!=' ')
                        {
                            w += line[i];
                        }
                        else
                        {
                            words.push_back(w);
                            w = "";
                        }
                    }
                    words.push_back(w);

                    if(words[1].at(1) == 'I' && words[1].at(2) == 'S')
                    {
                        if(words.size() == 2)
                        {
                            output << words[0] << " " << words[1].at(4) << endl;
                        }
                        else if(words.size() == 3)
                        {
                            int index = int(words[2].at(3) - '0');
                            output << words[0] << " " << words[1].at(4) << " " << t.SYMTAB[index - 1].second << endl;
                        }
                        else
                        {
                            if(words[3].at(1) == 'S')
                            {
                                int index = int(words[3].at(3) - '0');
                                output << words[0] << " " << words[1].at(4) << " " << words[2].at(1) << " " << t.SYMTAB[index - 1].second << endl;
                            }
                            else if(words[3].at(1) == 'L')
                            {
                                int index = int(words[3].at(3) - '0');
                                output << words[0] << " " << words[1].at(4) << " " << words[2].at(1) << " " << t.LITTAB[index - 1].second << endl;
                            }
                            else
                            {
                                //reg reg combination
                                output << words[0] << " " << words[1].at(4) << " " << words[2].at(1) << " " << words[3].at(1);
                            }
                        }
                    }
                    words.clear();
                }
            }
        }
};

int main() {
    Assembler a;
    a.passTwo();
    return 0;
}