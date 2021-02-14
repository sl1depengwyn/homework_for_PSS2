#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void spaceDeliter(string& s) {
    while (s[0] == ' ') s.erase(0, 1);
    while (s[s.length() - 1] == ' ') s.erase(s.length() - 2, 1);
}

vector<string> split(string s, char delimiter) {

    vector<string> sentences;
    string text = std::move(s);
    int dot;

    while (text.find(delimiter) != string::npos) {
        dot = text.find_first_of(delimiter);
        sentences.push_back(text.substr(0, ++dot));
        text.erase(0, ++dot);
        spaceDeliter(sentences[sentences.size() - 1]);

    }

    return sentences;
}

void makeUpper (string &sentence, string word, string substitution) {
    for (auto i = sentence.find(word); i != string::npos; i = sentence.find(word)) {
        sentence.replace(i, word.length(), substitution);
    }
}

pair<int, vector<string>> search(string query, vector<string> sentences) {

    pair<int, vector<string>> ans = {0, {}};

    string substitution = query;
    for (auto & c : substitution) c = toupper(c);

    string queryAtEnd = ' ' + query + '.';
    string queryInside = ' ' + query + ' ';
    string queryAtStart = char(toupper(query[0])) + query.substr(1) + ' ';

    for (auto elem : sentences) {
        if (elem.find(queryAtEnd) != string::npos ||
            elem.find(queryAtStart) != string::npos ||
            elem.find(queryInside) != string::npos) {

            ans.first++;

            makeUpper(elem, queryAtEnd, ' ' + substitution + '.');
            makeUpper(elem, queryInside, ' ' + substitution + ' ');
            makeUpper(elem, queryAtStart, substitution + ' ');

            ans.second.push_back(elem);

        }
    }

    return ans;
}

int main() {

    ifstream fin;
    ofstream fout;

    string text, query;
    int numberOfQuery;

    fin.open("../in.txt");
    fout.open("../out.txt");

    getline(fin, text);
    fin >> numberOfQuery;

    auto sentences = split(text, '.');

    for (int i = 0; i < numberOfQuery; i++) {
        fin >> query;
        auto result = search(query, sentences);
        fout << result.first << '\n';
        for (auto & el : result.second) {
            fout << el << '\n';
        }
    }

    fin.close();
    fout.close();

    return 0;
}
