#include<bits/stdc++.h>
using namespace std;

class MNTValues{
    public:
        int PP;
        int KP;
        int MDTP;
        int KPDTP;

        MNTValues()
        {
            PP = 0;
            KP = 0;
            MDTP = 0;
            KPDTP = 0;
        }
};

class MacroProcessor{
    public:
        vector<pair<string, MNTValues>> MNT;
        vector<vector<string>> MDT;
        vector<pair<string, string>> KPDTAB;
        vector<string> PNTAB;
        fstream file;
        fstream MacroNameTable;
        fstream MacroDefinitionTable;
        fstream KeywordParameterTable;
        fstream ParameterTable;

        MacroProcessor()
        {
            file.open("macro_input.txt", ios::in);
            if(!file.is_open())
            {
                cout << "Error opening file" << endl;
            }

            MacroNameTable.open("mnt.txt", ios::out);
            if(!MacroNameTable.is_open())
            {
                cout << "Error opening mnt file" << endl;
            }

            KeywordParameterTable.open("kpdtab.txt", ios::out);
            if(!KeywordParameterTable.is_open())
            {
                cout << "Error opening kpdtab file" << endl;
            }

            ParameterTable.open("pntab.txt", ios::out);
            if(!ParameterTable.is_open())
            {
                cout << "Error opening pntab file" << endl;
            }

            MacroDefinitionTable.open("mdt.txt", ios::out);
            if(!MacroDefinitionTable.is_open())
            {
                cout << "Error opening mdt file" << endl;
            }
        }

        int searchParameter(string name,string parameter)
        {
            int reference;
            for (int i = 0; i < PNTAB.size();i++)
            {
                if(PNTAB[i] == name)
                {
                    reference = i;
                    break;
                }
            }

            for (int i = reference + 1; i < PNTAB.size();i++)
            {
                if(PNTAB[i] == parameter)
                {
                    return i - reference;
                }
            }
            return -1;
        }


        void passOne()
        {
            vector<string> words;
            vector<string> temp;
            string line;
            bool firstLine;
            bool insideMacro;
            string name;

            int pcounter = 0;
            int kcounter = 0;
            int mcounter = 0;
            MNTValues m;

            if(file.is_open())
            {
                while(!file.eof())
                {
                    string w = "";
                    getline(file, line);
                    for (int i = 0; i < line.size();i++)
                    {
                        if(line[i] != ' ')
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


                    if(words[0] == "MACRO")
                    {
                        firstLine=true;
                        insideMacro = true;
                    }
                    else if(firstLine && insideMacro)
                    {
                        name = words[0];
                        PNTAB.push_back(name);
                        for (int i = 0; i < words.size();i++)
                        {
                            if(words[i].at(0) == '&')
                            {
                                PNTAB.push_back(words[i]);
                                pcounter++;
                            }
                            else if(words[i] == "=")
                            {
                                if(i == words.size()-1 || words[i+1].at(0) == '&')
                                {
                                    KPDTAB.push_back({words[i], ""});
                                    kcounter++;
                                }
                                else
                                {
                                    KPDTAB.push_back({words[i - 1], words[i + 1]});
                                    kcounter++;
                                }
                            }
                        }
                        if(kcounter!=0)
                        {
                            m.KPDTP = KPDTAB.size() - kcounter + 1;
                        }
                        m.KP = kcounter;
                        m.PP = pcounter - kcounter;
                        m.MDTP = MDT.size() + 1;
                        firstLine = false;

                        kcounter = 0;
                        pcounter = 0;
                        MNT.push_back({words[0], m});
                    }
                    else if(!firstLine && insideMacro)
                    {
                        for (int i = 0; i < words.size();i++)
                        {
                            if(words[i].at(0) == '&')
                            {
                                string index = to_string(searchParameter(name,words[i]));
                                cout << index << endl;
                                if(index != "-1")
                                {
                                    string parameter = "(P,";
                                    parameter += index;
                                    parameter += ")";
                                    temp.push_back(parameter);
                                }
                                else
                                {
                                    temp.push_back(words[i]);
                                }
                            }
                            else
                            {
                                temp.push_back(words[i]);
                            }
                        }
                        MDT.push_back(temp);
                        // temp.clear();
                    }
                    else
                    {
                        continue;
                    }
                    if(words[0] == "MEND")
                    {
                        insideMacro = false;
                    }
                    words.clear();
                }
            }
            for (int i = 0; i < temp.size();i++)
            {
                cout << temp[i] << " ";
            }
        }

        void displayPNTAB()
        {
            for (auto x:PNTAB)
            {
                ParameterTable << x << endl;
            }
        }

        void displayKPDTAB()
        {
            for(auto x:KPDTAB)
            {
                KeywordParameterTable << x.first << " " << x.second << endl;
            }
        }

        void displayMNT()
        {
            for(auto x:MNT)
            {
                MacroNameTable << x.first << " " << x.second.PP << " " << x.second.KP << " " << x.second.KPDTP << " " << x.second.MDTP << endl;
            }
        }

        void displayMDT()
        {
            for (int i = 0; i < MDT.size();i++)
            {
                for (int j = 0; j < MDT[i].size();j++)
                {
                    MacroDefinitionTable << MDT[i][j] <<" ";
                }
            }
        }
};

int main()
{
    MacroProcessor m;
    m.passOne();
    m.displayKPDTAB();
    m.displayPNTAB();
    m.displayMNT();
    m.displayMDT();
    cout << "executed successfully" << endl;
    return 0;
}