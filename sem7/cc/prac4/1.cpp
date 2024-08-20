#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

// Function to split a string into a vector of symbols
vector<string> split(const string &str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to compute the FIRST set for a given non-terminal
void computeFirst(const string &nonTerminal, unordered_map<string, vector<string>> &expression, unordered_map<string, set<string>> &firstSet) {
    if (!firstSet[nonTerminal].empty()) {
        // If FIRST set already computed, return
        return;
    }

    for (const string &production : expression[nonTerminal]) {
        vector<string> symbols = split(production, ' ');
        for (const string &symbol : symbols) {
            if (isupper(symbol[0])) {
                // If the symbol is a non-terminal, compute its FIRST set recursively
                computeFirst(symbol, expression, firstSet);
                for (const string &firstSymbol : firstSet[symbol]) {
                    if (firstSymbol != "?") {
                        firstSet[nonTerminal].insert(firstSymbol);
                    }
                }
                // If epsilon is in the FIRST set of the non-terminal, continue to the next symbol
                if (firstSet[symbol].find("?") == firstSet[symbol].end()) {
                    break;
                }
            } else {
                // If the symbol is a terminal, add it to the FIRST set
                firstSet[nonTerminal].insert(symbol);
                break;
            }
        }
    }
}

int main() {
    unordered_map<string, vector<string>> expression;
    unordered_map<string, set<string>> firstSet;

    // Updated production rules as per the provided grammar
    expression["E"] = {"T E'"};     // E  -> T E’
    expression["E'"] = {"+ T E'", "?"}; // E' -> + T E' | ?
    expression["T"] = {"F T'"};     // T  -> F T’
    expression["T'"] = {"* F T'", "?"}; // T' -> * F T' | ?
    expression["F"] = {"( E )", "id"};  // F  -> ( E ) | id

    // Compute the FIRST set for all non-terminals
    for (const auto &x : expression) {
        computeFirst(x.first, expression, firstSet);
    }

    // Output the FIRST set
    for (const auto &x : firstSet) {
        cout << "FIRST(" << x.first << ") = { ";
        for (auto it = x.second.begin(); it != x.second.end(); ++it) {
            cout << *it;
            if (next(it) != x.second.end()) {
                cout << ", ";
            }
        }
        cout << " }" << endl;
    }

    return 0;
}
