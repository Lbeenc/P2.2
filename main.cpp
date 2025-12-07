#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "scanner.h"
#include "parser.h"
#include "printTree.h"

static void usageAndExit(const char* msg = nullptr) {
    if (msg) std::cerr << msg << "\n";
    std::cerr << "Usage: parser [file]\n";
    std::exit(EXIT_FAILURE);
}

int main(int argc, char** argv) {
    if (argc > 2) {
        usageAndExit("Too many arguments.");
    }

    if (argc == 2) {
        const char* path = argv[1];
        FILE* f = std::fopen(path, "r");
        if (!f) {
            usageAndExit("Cannot open input file.");
        }
        initScanner(f);
    } else {
        initScanner(nullptr); // stdin
    }

    Node* root = parser();    // build parse tree from P1 scanner
    printTree(root, 0);       // P2: show the parse tree

    return 0;
}
