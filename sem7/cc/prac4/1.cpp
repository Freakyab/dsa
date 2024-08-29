#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

// Function to split a string into a vector of symbols
vector<string> split(const string &str, char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to compute the FIRST set for a given non-terminal
void computeFirst(const string &nonTerminal, unordered_map<string, vector<string>> &expression, unordered_map<string, set<string>> &firstSet)
{
    if (!firstSet[nonTerminal].empty())
    {
        // If FIRST set already computed, return
        return;
    }

    for (const string &production : expression[nonTerminal])
    {
        vector<string> symbols = split(production, ' ');
        for (const string &symbol : symbols)
        {
            if (isupper(symbol[0]))
            {
                // If the symbol is a non-terminal, compute its FIRST set recursively
                computeFirst(symbol, expression, firstSet);
                for (const string &firstSymbol : firstSet[symbol])
                {
                    if (firstSymbol != "?")
                    {
                        firstSet[nonTerminal].insert(firstSymbol);
                    }
                }
                // If epsilon is in the FIRST set of the non-terminal, continue to the next symbol
                if (firstSet[symbol].find("?") == firstSet[symbol].end())
                {
                    break;
                }
            }
            else
            {
                // If the symbol is a terminal, add it to the FIRST set
                firstSet[nonTerminal].insert(symbol);
                break;
            }
        }
    }
}

void computeFollow(const string &nonTerminal, unordered_map<string, vector<string>> &expression, unordered_map<string, set<string>> &firstSet, unordered_map<string, set<string>> &followSet)
{
    if (!followSet[nonTerminal].empty())
    {
        // If FOLLOW set already computed, return
        return;
    }

    if (nonTerminal == "E")
    {
        followSet[nonTerminal].insert("$");
    }

    for (const auto &x : expression)
    {
        for (const string &production : x.second)
        {
            vector<string> symbols = split(production, ' ');
            for (size_t i = 0; i < symbols.size(); i++)
            {
                if (symbols[i] == nonTerminal)
                {
                    if (i == symbols.size() - 1)
                    {
                        // If non-terminal is the last symbol in the production
                        if (x.first != nonTerminal)
                        {
                            computeFollow(x.first, expression, firstSet, followSet);
                            for (const string &symbol : followSet[x.first])
                            {
                                followSet[nonTerminal].insert(symbol);
                            }
                        }
                    }
                    else
                    {
                        for (size_t j = i + 1; j < symbols.size(); j++)
                        {
                            if (isupper(symbols[j][0]))
                            {
                                // If the next symbol is a non-terminal
                                for (const string &firstSymbol : firstSet[symbols[j]])
                                {
                                    if (firstSymbol != "?")
                                    {
                                        followSet[nonTerminal].insert(firstSymbol);
                                    }
                                }
                                if (firstSet[symbols[j]].find("?") == firstSet[symbols[j]].end())
                                {
                                    break;
                                }
                            }
                            else
                            {
                                // If the next symbol is a terminal
                                followSet[nonTerminal].insert(symbols[j]);
                                break;
                            }
                        }
                        if (i == symbols.size() - 1)
                        {
                            // If epsilon is in the FIRST set of the last symbol
                            if (x.first != nonTerminal)
                            {
                                computeFollow(x.first, expression, firstSet, followSet);
                                for (const string &symbol : followSet[x.first])
                                {
                                    followSet[nonTerminal].insert(symbol);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    unordered_map<string, vector<string>> expression;
    unordered_map<string, set<string>> firstSet;
    unordered_map<string, set<string>> followSet;

    // Updated production rules as per the provided grammar
    expression["E"] = {"T E'"};         // E  -> T E’
    expression["E'"] = {"+ T E'", "?"}; // E' -> + T E' | ?
    expression["T"] = {"F T'"};         // T  -> F T’
    expression["T'"] = {"* F T'", "?"}; // T' -> * F T' | ?
    expression["F"] = {"( E )", "id"};  // F  -> ( E ) | id

    // Compute the FIRST set for all non-terminals
    for (const auto &x : expression)
    {
        computeFirst(x.first, expression, firstSet);
    }

    // Compute the FOLLOW set for all non-terminals
    for (const auto &x : expression)
    {
        computeFollow(x.first, expression, firstSet, followSet);
    }

    // Output the FOLLOW set
    for (const auto &x : followSet)
    {
        cout << "FOLLOW(" << x.first << ") = { ";
        for (auto it = x.second.begin(); it != x.second.end(); ++it)
        {
            cout << *it;
            if (next(it) != x.second.end())
            {
                cout << ", ";
            }
        }
        cout << " }" << endl;
    }

    cout << endl;

    // Output the FIRST set
    for (const auto &x : firstSet)
    {
        cout << "FIRST(" << x.first << ") = { ";
        for (auto it = x.second.begin(); it != x.second.end(); ++it)
        {
            cout << *it;
            if (next(it) != x.second.end())
            {
                cout << ", ";
            }
        }
        cout << " }" << endl;
    }

    return 0;
}
