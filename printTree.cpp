#include <iostream>
#include "printTree.h"

static void printLabel(NodeType t) {
    using std::cout;
    switch (t) {
        case NodeType::PROGRAM: cout << "<program>";     break;
        case NodeType::VARS:    cout << "<vars>";        break;
        case NodeType::VARLIST: cout << "<varList>";     break;
        case NodeType::BLOCK:   cout << "<block>";       break;
        case NodeType::STATS:   cout << "<stats>";       break;
        case NodeType::MSTAT:   cout << "<mStat>";       break;
        case NodeType::STAT:    cout << "<stat>";        break;
        case NodeType::READ:    cout << "<read>";        break;
        case NodeType::PRINT:   cout << "<print>";       break;
        case NodeType::COND:    cout << "<cond>";        break;
        case NodeType::LOOP:    cout << "<loop>";        break;
        case NodeType::ASSIGN:  cout << "<assign>";      break;
        case NodeType::REL:     cout << "<relational>";  break;
        case NodeType::EXP:     cout << "<exp>";         break;
        case NodeType::M:       cout << "<M>";           break;
        case NodeType::N:       cout << "<N>";           break;
        case NodeType::R:       cout << "<R>";           break;
    }
}

void printTree(Node* n, int depth) {
    if (!n) return;

    for (int i = 0; i < depth; ++i)
        std::cout << "  ";

    printLabel(n->label);
    std::cout << "\n";

    printTree(n->child1, depth + 1);
    printTree(n->child2, depth + 1);
    printTree(n->child3, depth + 1);
    printTree(n->child4, depth + 1);
}
