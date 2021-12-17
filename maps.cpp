#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

void readStockPrice(const string &inputline, string &stockSymbol, string &stockPrice) {
    istringstream istr(inputline);
    string fields[2];
    string tmp;
    int i = 0;
    while(getline(istr, tmp, ',')) {
        fields[i++] = tmp;
    }
    stockSymbol = fields[0];
    stockPrice = fields[1];
} 

int main() {

int usernum;
string userfile;
string usersymbol;
string buf;

map<string, double> stockPrices;
map<string, double>::iterator iter;


while (true) {

cout << "Menu\n";
cout << "----\n";
cout << "1) Read data from a file.\n";
cout << "2) Get the last closing price of a stock.\n";
cout << "3) Exit the program.\n";
cout << "Your choice? ";
getline(cin, buf);
usernum = atoi(buf.c_str());

switch(usernum) {
    case 1: {
        cout << "Filename? ";
        getline(cin, userfile);
        ifstream dataFile;
        dataFile.open("prices.csv");
        string line;
        stockPrices.clear();
        while(getline(dataFile, line)) {
            string symbol;
            string price;

            readStockPrice(line, symbol, price);

            stockPrices[symbol] = atof(price.c_str());
        } cout << "2770 entries read from prices.csv.\n";
    } break;
    case 2: {
        cout << "Which stock symbol? ";
        getline(cin, usersymbol);
        iter = stockPrices.find(usersymbol);
        if(iter != stockPrices.end()) {
            cout << fixed << setprecision(2);
            cout << "Yesterdays closing price of " << iter->first << " was $"<< iter->second << ".\n";
        } else {
            cout << "Stock price not found.\n";
        }
    } break;
    case 3: 
        cout << "Exiting...\n";
        exit(0);
        break;

}
}

}
