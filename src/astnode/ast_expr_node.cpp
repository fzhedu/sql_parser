/*
 * ast_expr_node.cpp
 *  Created on: May 22, 2015 11:36:17 AM
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */

#include "ast_expr_node.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
AstExprConst::AstExprConst(AstNodeType ast_node_type, std::string data)
        : AstNode(ast_node_type),
          data_(data) {
}

AstExprConst::~AstExprConst() {
}
void AstExprConst::Print(int level) const {
    // cout << setw(level * 8) << " " << "|selecct list|" << endl;
    cout << setw(level * 8) << " " << "const data:" << data_ << endl;
}

AstExprUnary::AstExprUnary(AstNodeType ast_node_type, AstNode* arg0)
        : AstNode(ast_node_type),
          arg0_(arg0) {
}

AstExprUnary::~AstExprUnary() {
    delete arg0_;
}

void AstExprUnary::Print(int level) const {
    cout << setw(level * 8) << " " << "|expr unary|" << endl;
    arg0_->Print(level + 1);
}

AstExprBinary::AstExprCalBinary(AstNodeType ast_node_type, AstNode* arg0,
                                AstNode* arg1)
        : AstNode(ast_node_type),
          arg0_(arg0),
          arg1_(arg1) {
}
AstExprBinary::AstExprCmpBinary(AstNodeType ast_node_type, AstNode* arg0,
                                AstNode* arg1)
        : AstNode(ast_node_type),
          arg0_(arg0),
          arg1_(arg1) {
}
AstExprBinary::AstExprCmpBinary(CmpPara cmp_para, int cmp_type, AstNode* arg0,
                                AstNode* arg1)
        : AstNode(AST_EXPR_ADD),
          cmp_para_(cmp_para),
          arg0_(arg0),
          arg1_(arg1) {
    switch (cmp_type) {
        case 1: {
            ast_node_type_ = AST_EXPR_LESS;
            break;
        }
        case 2: {
            ast_node_type_ = AST_EXPR_MORE;
            break;
        }
        case 3: {
            ast_node_type_ = AST_EXPR_INEQUAL;
            break;
        }
        case 4: {
            ast_node_type_ = AST_EXPR_EQUAL;
            break;
        }
        case 5: {
            ast_node_type_ = AST_EXPR_LESSEQU;
            break;
        }
        case 6: {
            ast_node_type_ = AST_EXPR_MOREEQU;
            break;
        }
        case 12: {
            ast_node_type_ = AST_EXPR_UNKNOWN;
            break;
        }
        default: {
        }
    }
}
AstExprBinary::~AstExprBinary() {
    delete arg0_;
    delete arg1_;
}

void AstExprBinary::Print(int level) const {
    cout << setw(level * 8) << " " << "|expr binary|" << endl;
    arg0_->Print(level + 1);
    arg1_->Print(level + 1);
}

AstExprTernary::AstExprTernary(AstNodeType ast_node_type, AstNode* arg0,
                               AstNode* arg1, AstNode* arg2)
        : AstNode(ast_node_type),
          arg0_(arg0),
          arg1_(arg1),
          arg2_(arg2) {
}

AstExprTernary::~AstExprTernary() {
    delete arg0_;
    delete arg1_;
    delete arg2_;
}

void AstExprTernary::Print(int level) const {
    cout << setw(level * 8) << " " << "|expr ternary|" << endl;
    arg0_->Print(level + 1);
    arg1_->Print(level + 1);
    arg2_->Print(level + 1);
}
AstExprList::AstExprList(AstNodeType ast_node_type, AstNode* expr,
                         AstNode* next)
        : AstNode(ast_node_type),
          expr_(expr),
          next_(next) {
}

AstExprList::~AstExprList() {
    delete expr_;
    delete next_;
}

void AstExprList::Print(int level) const {
}

AstExprString::AstExprString(AstNodeType ast_node_type, AstNode* arg0,
                             AstNode* arg1, AstNode* arg2)
        : AstNode(ast_node_type),
          arg0_(arg0),
          arg1_(arg1),
          arg2_(arg2) {
}

AstExprString::AstExprString(AstNodeType ast_node_type, std::string trim_para,
                             AstNode* arg0, AstNode* arg1)
        : AstNode(ast_node_type),
          trim_para_(trim_para),
          arg0_(arg0),
          arg1_(arg1) {
}

AstExprString::~AstExprString() {
    delete arg0_;
    delete arg1_;
    delete arg2_;
}

void AstExprString::Print(int level) const {
}
