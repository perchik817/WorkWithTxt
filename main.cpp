#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cctype>
#include <numeric>
#include <iomanip> 
#include <locale>
#include <regex>
#include <sstream>
#include <chrono>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int count_of_words = 0, count_of_characters = 0, count_of_lines = 0, total_income = 0, total_outcome = 0;
    string line, word, fruit, longest_word, beruf, name;
    vector<string> array_of_words = {}, array_of_beruf = {}, array_of_name = {};
    vector<int> array_of_income = {}, array_of_outcome = {};

    array_of_income.reserve(7);
    array_of_outcome.reserve(10);
    array_of_beruf.reserve(6);
    array_of_name.reserve(6);
    array_of_words.reserve(36);

    int n = array_of_words.size();

    map<string, int> counts;
    map<string, double> result;
    map<char, string> translit = { {'�', "a"}, {'�', "k"}, {'�', "h"}, {'�', "b"}, {'�', "l"}, {'�', "c"}, {'�', "v"}, {'�', "m"}, {'�', "ch"}, {'�', "g"}, {'�', "n"},
     {'�', "sh"}, {'�', "d"}, {'�', "o"}, {'�', "shh"}, {'�', "e"}, {'�', "p"}, {'�', "*"}, {'�', "jo"}, {'�', "r"}, {'�', "y"}, {'�', "zh"},
     {'�', "s"}, {'�', "'"}, {'�', "z"}, {'�', "t"}, {'�', "je"}, {'�', "i"}, {'�', "u"}, {'�', "ju"}, {'�', "j"}, {'�', "f"}, {'�', "ya"},
     {'�', "A"}, {'�', "K"}, {'�', "H"}, {'�', "B"}, {'�', "L"}, {'�', "C"}, {'�', "V"}, {'�', "M"}, {'�', "Ch"}, {'�', "G"}, {'�', "N"},
     {'�', "Sh"}, {'�', "D"}, {'�', "O"}, {'�', "Shh"}, {'�', "E"}, {'�', "P"}, {'�', "*"}, {'�', "Jo"}, {'�', "R"}, {'�', "Y"}, {'�', "Zh"},
     {'�', "S"}, {'�', "'"}, {'�', "Z"}, {'�', "T"}, {'�', "Je"}, {'�', "I"}, {'�', "U"}, {'�', "Ju"}, {'�', "J"}, {'�', "F"}, {'�', "Ya"} };

    ifstream books_file("TextFileFirstTask.txt");
    ifstream series_file("TextFileSecondTask.txt");
    ifstream fruit_file("TextFileFourthTask.txt");
    ifstream name_file("TextFileFifthName.txt");
    ifstream position_file("TextFileFifthBeruf.txt");
    ifstream income_file("TextFileSeventhIncome.txt");
    ifstream outcome_file("TextFileSeventhOutcome.txt");
    
    

int main() {
    setlocale(LC_ALL, "Russian");
    string input_filename, output_filename;
    cout << "������� ��� ����� � ������� �������: ";
    cin >> input_filename;
    cout << "������� ��� ����� ��� ���������� ����������: ";
    cin >> output_filename;

    ifstream input_file(input_filename);
    if (!input_file) {
        cerr << "������ �������� ����� " << input_filename << endl;
        return 1;
    }

    ofstream output_file(output_filename);
    if (!output_file) {
        cerr << "������ �������� ����� " << output_filename << endl;
        return 1;
    }

    char c;
    while (input_file.get(c)) {
        if (translit.count(c)) {
            output_file << translit[c];
        }
        else {
            output_file << c;
        }
    }

    input_file.close();
    output_file.close();

    cout << "����� ������� ���������������� � �������� � ���� " << output_filename << endl;

//
//// ������� ��� �������� ������� � ������
//int timeToMinutes(string timeStr) {
//    int hours = stoi(timeStr.substr(0, 2));
//    int minutes = stoi(timeStr.substr(3, 2));
//    return hours * 60 + minutes;
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//    string inputFilename = "crm_log.txt";
//    string outputFilename = "best_employees.txt";
//    int maxTimeInMinutes = 4 * 60;  // ������������ ����� � ������� � �������
//
//    // �������� ����� ��� ������
//    ifstream inputFile(inputFilename);
//    if (!inputFile) {
//        cerr << "������ �������� ����� " << inputFilename << endl;
//        return 1;
//    }
//
//    // ������ ���� � ����������� �������������, ������� ���� � ������� ����� 4 �����
//    string line;
//    vector<string> bestEmployees;
//    while (getline(inputFile, line)) {
//        string name = line.substr(0, line.find(", "));
//        string timeInStr = line.substr(line.find(", ") + 2);
//        string timeIn = timeInStr.substr(0, 5);
//        string timeOut = timeInStr.substr(8);
//        int timeInMinutes = timeToMinutes(timeIn);
//        int timeOutMinutes = timeToMinutes(timeOut);
//        int timeSpent = timeOutMinutes - timeInMinutes;
//        if (timeSpent > maxTimeInMinutes) {
//            bestEmployees.push_back(name);
//        }
//    }
//    inputFile.close();
//
//    // �������� ����� ��� ������
//    ofstream outputFile(outputFilename);
//    if (!outputFile) {
//        cerr << "������ �������� ����� " << outputFilename << endl;
//        return 1;
//    }
//
//    // ������ ���� � ������� ������ ����������� � ����
//    for (const auto& employee : bestEmployees) {
//        outputFile << employee << endl;
//    }
//    outputFile.close();
//
//    cout << "��������� ������� � ���� " << outputFilename << endl;

    //eighth task
    /*ifstream gradesFile("TextFileEighthTask.txt");
    if (!gradesFile.is_open()) {
        cerr << "Failed to open file!" << endl;
        return 1;
    }

    while (getline(gradesFile, line)) {
        istringstream iss(line);
        string name, surname;
        int grade1, grade2, grade3, grade4;
        iss >> surname >> name >> grade1 >> grade2 >> grade3 >> grade4;
        double avg = (grade1 + grade2 + grade3 + grade4) / 4.0;
        if (avg <= 5.0) {
            cout << surname << " " << name << ", ������� ����: " << avg << endl;
        }
    }

    gradesFile.close();*/
   
    //seventh task
    /*if (income_file.is_open()) {
        while (getline(income_file, line)) {
            line.erase(0, 3);
            int income = stoi(line);
            array_of_income.push_back(income);
        }
        for (int j = 0; j < array_of_income.size(); j++) {
            total_income += array_of_income[j];
        }
        income_file.close();
    }
    else {
        cout << "Unable to open file.";
    }

    if (outcome_file.is_open()) {
        while (getline(outcome_file, line)) {
            line.erase(0, 4);
            int outcome = stoi(line);
            array_of_outcome.push_back(outcome);
        }
        for (int j = 0; j < array_of_outcome.size(); j++) {
            total_outcome += array_of_outcome[j];
        }
        outcome_file.close();
    }
    else {
        cout << "Unable to open file.";
    }

    int result = total_income - total_outcome;
    cout << "������� �� ������� �����: " << result << " RUB.";*/

    //sixth task
    /*ofstream alphabet_file;
    alphabet_file.open("TextFileSixthTask.txt");
    for (char letter = 'A'; letter <= 'Z'; ++letter) {
        alphabet_file << letter << (char)(letter + 32) << endl;
    }
    alphabet_file.close();*/

    //fifth task
    /*if (name_file.is_open()) {
        while (getline(name_file, line)) {
            array_of_name.push_back(line);
        }
        name_file.close();
    }
    else {
        cout << "Unable to open file of names.";
    }

    if (position_file.is_open()) {
        while (position_file >> beruf) {
            array_of_beruf.push_back(beruf);
        }
        position_file.close();
    }
    else {
        cout << "Unable to open file of positions.";
    }

    for (int i = 0; i < array_of_name.size(); i++) {
        cout << "���������: " << array_of_name[i] << ", ���������: " << array_of_beruf[i] << endl;
    }*/

    //fourth task
    /*if (fruit_file.is_open()) {
        while (fruit_file >> fruit) {
            for (auto& c : fruit) {
                c = tolower(c);
            }
            ++counts[fruit];
        }
        for (auto it = counts.begin(); it != counts.end(); it++) {           
            cout << '"' << it->first << '"' << ": " << it->second << "���(�)" << endl;
        }
        fruit_file.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }*/
    
    //third task
    /*if (myfile.is_open()) {
        while (getline(myfile, line)) {
            for (int x : line) {
                char ch = x;
                if (ch != '.' && ch != '"' && ch != ',' && ch != '1' && ch != '2' &&
                    ch != '3' && ch != '4' && ch != '5' && ch != '6' && ch != '7' && 
                    ch != '8' && ch != '9' && ch != '0') {
                    word += ch;
                }
            }
        }
        array_of_words.push_back(word);
        for (string book : array_of_words) {
            string word = "";
            for (char c : book) {
                if (c == ' ') {
                    if (word.length() > longest_word.length()) {
                        longest_word = word;
                    }
                    word = "";
                }
                else {
                    word += c;
                }
            }
            if (word.length() > longest_word.length()) {
                longest_word = word;
            }
        }
        myfile.close();        
        cout << "����� ������� �����: " << longest_word << endl;
    }
    else {
        cout << "Unable to open file";
    }*/
    
    //second task
    /*if (series_file.is_open()) {
        while (getline(series_file, line)) {
            count_of_lines++;
            count_of_characters += count_if(line.begin(), line.end(), [](char character) {
                return character != ' ' && character != '.';
                });
            count_of_words += count(line.begin(), line.end(), ' ') - 1;
        }
        
        series_file.close();
        cout << "���������� �����: " << count_of_lines << endl;
        cout << "���������� ����: " << count_of_words << endl;
        cout << "���������� �������� ��� �������� � �����: " << count_of_characters;
    }
    else {
        cout << "Unable to open file";
    }*/

    //first task
    /*if (books_file.is_open()) {
        while (getline(books_file, line)) {
            cout << line << '\n';
            count_of_lines++;
            if (count_of_lines == 3) {
                break;
            }
        }
        books_file.close();
    }
    else {
        cout << "Unable to open file";
    }*/

    return 0;
}