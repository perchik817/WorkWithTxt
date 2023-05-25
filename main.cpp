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
    map<char, string> translit = { {'а', "a"}, {'к', "k"}, {'х', "h"}, {'б', "b"}, {'л', "l"}, {'ц', "c"}, {'в', "v"}, {'м', "m"}, {'ч', "ch"}, {'г', "g"}, {'н', "n"},
     {'ш', "sh"}, {'д', "d"}, {'о', "o"}, {'щ', "shh"}, {'е', "e"}, {'п', "p"}, {'ъ', "*"}, {'ё', "jo"}, {'р', "r"}, {'ы', "y"}, {'ж', "zh"},
     {'с', "s"}, {'ь', "'"}, {'з', "z"}, {'т', "t"}, {'э', "je"}, {'и', "i"}, {'у', "u"}, {'ю', "ju"}, {'й', "j"}, {'ф', "f"}, {'я', "ya"},
     {'А', "A"}, {'К', "K"}, {'Х', "H"}, {'Б', "B"}, {'Л', "L"}, {'Ц', "C"}, {'В', "V"}, {'М', "M"}, {'Ч', "Ch"}, {'Г', "G"}, {'Н', "N"},
     {'Ш', "Sh"}, {'Д', "D"}, {'О', "O"}, {'Щ', "Shh"}, {'Е', "E"}, {'П', "P"}, {'Ъ', "*"}, {'Ё', "Jo"}, {'Р', "R"}, {'Ы', "Y"}, {'Ж', "Zh"},
     {'С', "S"}, {'Ь', "'"}, {'З', "Z"}, {'Т', "T"}, {'Э', "Je"}, {'И', "I"}, {'У', "U"}, {'Ю', "Ju"}, {'Й', "J"}, {'Ф', "F"}, {'Я', "Ya"} };

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
    cout << "Введите имя файла с русским текстом: ";
    cin >> input_filename;
    cout << "Введите имя файла для сохранения результата: ";
    cin >> output_filename;

    ifstream input_file(input_filename);
    if (!input_file) {
        cerr << "Ошибка открытия файла " << input_filename << endl;
        return 1;
    }

    ofstream output_file(output_filename);
    if (!output_file) {
        cerr << "Ошибка открытия файла " << output_filename << endl;
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

    cout << "Текст успешно транслитерирован и сохранен в файл " << output_filename << endl;

//
//// Функция для перевода времени в минуты
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
//    int maxTimeInMinutes = 4 * 60;  // максимальное время в системе в минутах
//
//    // Открытие файла для чтения
//    ifstream inputFile(inputFilename);
//    if (!inputFile) {
//        cerr << "Ошибка открытия файла " << inputFilename << endl;
//        return 1;
//    }
//
//    // Чтение лога и определение пользователей, которые были в системе более 4 часов
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
//    // Открытие файла для записи
//    ofstream outputFile(outputFilename);
//    if (!outputFile) {
//        cerr << "Ошибка открытия файла " << outputFilename << endl;
//        return 1;
//    }
//
//    // Запись имен и фамилий лучших сотрудников в файл
//    for (const auto& employee : bestEmployees) {
//        outputFile << employee << endl;
//    }
//    outputFile.close();
//
//    cout << "Результат записан в файл " << outputFilename << endl;

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
            cout << surname << " " << name << ", средний балл: " << avg << endl;
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
    cout << "Прибыль за прошлый месяц: " << result << " RUB.";*/

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
        cout << "Сотрудник: " << array_of_name[i] << ", должность: " << array_of_beruf[i] << endl;
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
            cout << '"' << it->first << '"' << ": " << it->second << "раз(а)" << endl;
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
        cout << "Самое длинное слово: " << longest_word << endl;
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
        cout << "Количество строк: " << count_of_lines << endl;
        cout << "Количество слов: " << count_of_words << endl;
        cout << "Количество символов без пробелов и точек: " << count_of_characters;
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