#include <iostream>
#include "printTree.h"
#include "token.h"

// Map NodeType to simple labels (no angle brackets)
static const char* nodeLabel(NodeType t) {
    switch (t) {
        case NodeType::PROGRAM: return "program";
        case NodeType::VARS:    return "vars";
        case NodeType::VARLIST: return "varList";
        case NodeType::BLOCK:   return "block";
        case NodeType::STATS:   return "stats";
        case NodeType::MSTAT:   return "mStat";
        case NodeType::STAT:    return "stat";
        case NodeType::READ:    return "read";
        case NodeType::PRINT:   return "print";
        case NodeType::COND:    return "cond";
        case NodeType::LOOP:    return "loop";
        case NodeType::ASSIGN:  return "assign";
        case NodeType::REL:     return "relational";
        case NodeType::EXP:     return "exp";
        case NodeType::M:       return "M";
        case NodeType::N:       return "N";
        case NodeType::R:       return "R";
    }
    return "unknown";
}

// Print one token as group:instance:line (if it’s actually set)
static void printTok(const Token& tk) {
    if (tk.id == TokenID::ERR_tk) return;        // our "unused" sentinel
    std::cout << " "
              << tokenName[static_cast<int>(tk.id)] << ":"
              << tk.instance << ":"
              << tk.line;
}

void printTree(Node* n, int depth) {
    if (!n) return;

    // indentation
    for (int i = 0; i < depth; ++i)
        std::cout << "  ";

    // node label
    std::cout << nodeLabel(n->label);

    // any tokens associated with this node
    printTok(n->tk1);
    printTok(n->tk2);
    printTok(n->tk3);

    std::cout << "\n";

    // preorder traversal
    printTree(n->child1, depth + 1);
    printTree(n->child2, depth + 1);
    printTree(n->child3, depth + 1);
    printTree(n->child4, depth + 1);
}
