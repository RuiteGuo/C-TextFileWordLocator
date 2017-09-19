//
// File: wl.h
// 
//  Description: contains main that take textfile input and store it in a tree structure to locate words 
//  Author Name: Ruite Guo 
//  enamil:rguo34@wisc.edu



#include <iostream>
#include <cstdio>
#include <cstdarg>
#include <vector>
#include <sstream>
#include <string>
#include "wl.h"
#include <cstdarg>
#include <fstream>
#include <algorithm>
#include "wl.h"


using namespace std;
void invalidArgs();
bool checkDirectory(string path);
stringBST *storageTree;
void fileLoading(string path);
void treeClear();
int typeChecker(char check);
void locate (string data, int duplicates);

int main() {



    storageTree = new stringBST;

    int loopInvariants = 0;
    int fileOpenFlag = 0;



    while (loopInvariants == 0) {

    string input;

    cout << "<";

    int wordLocation = 0;

  // the following is command line parsing
    getline(cin, input);
    stringstream parse;
    parse.str(input);
    string one, two, three,four;
    parse >> one >> two >> three >> four;
    string testCase = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789'0";
        // this variable is declared to store the third argument of locate command only
        int result;

// command to lowercase
        transform(one.begin(), one.end(), one.begin(),::tolower);

  // change the option according to the command
    int option = 0;
    if (four.empty()) {
        if (one.compare("load")==0) {
            if ((!(two.empty())) && (three.empty())) {
                // load string unsuccessful?
                if (checkDirectory(two) == true) {
                    option = 1;
                }

            }

        } else if (one.compare("locate")==0) {

            stringstream numConversion(three);
            std::size_t found = two.find_first_not_of(testCase);

            // if successfully convert the third argument into number
            // and the second argument only contains letter
            if ((numConversion >> result)
                && (found == std::string::npos)) {
                option = 2;
            }


        } else if (one.compare("new")==0) {
            if ((two.empty()) && (three.empty())) {
                option = 3;
            }

        } else if (one.compare("end") == 0) {
            if ((two.empty()) && (three.empty())) {
                option = 4;
            }

        }
    }

    switch (option) {
        case 1:
    cout<<"case 1 load option entered"<<endl;
             if (fileOpenFlag == 1) {
                 treeClear();
             }
            fileLoading(two);
            fileOpenFlag = 1;
            break;



        case 2:
    cout<< "case 2 locate option entered"<<endl;
    // transform second argument into all lowercase
            transform(two.begin(), two.end(), two.begin(),::tolower);
           locate(two, result);
            break;



        case 3:
     cout<< "case 3 new option entered"<<endl;
            treeClear();
            fileOpenFlag = 0;
            break;



        case 4:
    cout<< "case 4 end option entered"<<endl;
            loopInvariants = 1;
            break;



        default:
            invalidArgs();
            break;


    }




}

// loop is stopped , starting execute exit code
    // task: delete tree, clear out memory
    delete storageTree;
    return 0;

}

bool checkDirectory(string path) {

  fstream fileStr;
  fileStr.open(path.c_str());
    if (fileStr.is_open ()) {
        fileStr.close();
        return true;
    }
    cout<< "failed to open file or wrong directory"<<endl;
    return false;
}

void fileLoading (string path) {
    fstream inFile;
    inFile.open(path.c_str());
    string words;
    stringstream ss;
    int positionCount = 0;

    // this variable is for testing only
    string tolstoy;
    while (!(inFile.eof())) {
        char candidate;
        inFile >> std::noskipws;
        inFile >>candidate;

        if (typeChecker(candidate) == 0) {
            if (words != "" && words !="\n") {
                positionCount++;
                transform(words.begin(), words.end(), words.begin(), ::tolower);
                cout << "----treenode Printing  " << words << "position count is "<< positionCount<<"\n" << endl;
                storageTree->insert(words, positionCount);
                if (words == "tolstoy") {
                    stringstream numString;
                    numString << positionCount;
                    tolstoy += words + numString.str() + " -";
                }

                words.clear();


            }
        } else {
            words += candidate;

        }

    }

  cout<<"\n******"<<tolstoy<< "-----\n";

    inFile.close();
}



void treeClear () {
    storageTree->clearReset();
    storageTree = new stringBST;
}


void locate(string data, int duplicateNum) {
    TreeNode* target = storageTree->search(data);
    cout <<"potential candidate found"<<endl;

    if (target == NULL) {
        cout <<"\n no match found in entry due to null return\n";
        return;
    }
    bool nodeFound = false;

    if (((target->words.compare(data))==0)) {
        if (duplicateNum == 1) {
            nodeFound = true;
            cout << target->words<<" node found, duplicate Num is 1, pos Num is "<<target->wordLocation<<endl;
            return;
        }
    }

  int loopCount = 1;
    if (duplicateNum > 1) {
            target = target->rightChild;
               while (target != NULL) {
                   target = storageTree->searchNode(target, data);
                   if (target != NULL) {
                       loopCount ++;
                       if (loopCount == duplicateNum) {
                           nodeFound =true;
                           break;
                       } else {
                           target = target->rightChild;
                       }
                   }

               }

    }



    if (nodeFound == true) {
        cout<<"\n word found: "<<target->words<<" position Num is: "<<target->wordLocation<<" duplicate is "<<loopCount<<endl;

    } else {
        cout <<"\n no match found in entry\n";
    }



}

void invalidArgs () {
    printf("ERROR: Invalid command\n");
}

int typeChecker(char check) {
if (check==39) {
    return 1;
}
else if (check >= 97 && check <= 122) return 2;
else if (check >= 48 && check <= 57)  return 3;
else if (check >=65 && check <= 90) return 4;

    return 0;

}


