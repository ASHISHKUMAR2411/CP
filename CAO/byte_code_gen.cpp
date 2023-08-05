#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
    ofstream fout;
    fout.open("symtable.txt");
    ifstream fin;
    fin.open("asmcode.txt");

    // First Pass
    string line;
    int address=0;
    while (! fin.eof())
    {
        getline(fin, line);
        if (line[3] == ',')
        {
            string label = "";
            for (int i = 0; i < 3; i++)
            {
                label += line[i];
            }   
            fout << label << " ";
            fout << setfill('0') << setw(3) << hex << uppercase << address-1;
            fout << "\n";
        }
        address++;
    }
    
    fin.close();
    fout.close();


    //Second Pass
    
    ifstream fin_symtable;
    ifstream fin_opcodes;
    ifstream fin2;

    ofstream fout_bytecode;
    fout_bytecode.open("bytecode.txt");

    string labeladdress;
    string opcode;

    fin2.open("asmcode.txt");
    
    while (! fin2.eof())
    {
        getline(fin2, line);
        if(line.substr(5,3) == "ORG")
        {
            continue;
        }
        else if(line.substr(5,3) == "END")
        {
            break;
        }
        else
        {
            if(line.substr(5,3) == "DEC")
            {
                fout_bytecode << setfill('0') << setw(4) << hex << uppercase << stoi(line.substr(9));
            }
            else if(line.substr(5,3) == "HEX")
            {
                fout_bytecode << setfill('0') << setw(4) << line.substr(9) ;
            }
            // else if(line[13] == 'I')
            // {
            //     fin_opcodes.open("indirect_opcode.txt");
            //     while( !fin_opcodes.eof())
            //     {
            //         getline(fin_opcodes,opcode);
            //         if(line.substr(5,3) == opcode.substr(0,3))
            //         {
            //             fout_bytecode << opcode.substr(4);
            //             if(stoi(opcode.substr(4)) < 10)
            //             {
            //                 //i.e. there is a label in instruction
            //                 fin_symtable.open("symtable.txt");
            //                 while( ! fin_symtable.eof())
            //                 {
            //                     getline(fin_symtable,labeladdress);
            //                     if(line.split(' ')[9] == labeladdress.substr(0,(line.split(' ')[9]).length()))
            //                     {
            //                         fout_bytecode << labeladdress.substr(4);
            //                     }
            //                 }
            //                 fin_symtable.close();
            //             }
            //         }  
            //     }
            //     fin_opcodes.close();
            // }
            else
            {
                fin_opcodes.open("direct_opcode.txt");
                while( !fin_opcodes.eof())
                {
                    getline(fin_opcodes,opcode);
                    if(line.substr(5,3) == opcode.substr(0,3))
                    {
                        fout_bytecode << opcode.substr(4);
                        if(stoi(opcode.substr(4)) < 10)
                        {
                            //i.e. there is a label in instruction
                            fin_symtable.open("symtable.txt");
                            while( ! fin_symtable.eof())
                            {
                                getline(fin_symtable,labeladdress);
                                if(line.substr(9) == labeladdress.substr(0,(line.substr(9)).length()))
                                {
                                    fout_bytecode << labeladdress.substr(4);
                                }
                            }
                            fin_symtable.close();
                        }
                    }
                    
                }

                fin_opcodes.close();
            }
        }
    }
    fin2.close();
    return 0;
}