/*
 * ast_expr_node.cpp
 *  Created on: May 22, 2015 11:36:17 AM
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */

#include "./ast_expr_node.h"
#include <iostream>   //  NOLINT
#include <iomanip>
#include <string>
#include <bitset>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::setw;
using std::bitset;

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
    switch (ast_node_type_) {
        case AST_COUNT_ALL: {
            cout << setw(level * 8) << " " << "|COUNT expr|" << endl;
            break;
        }
        case AST_COUNT_EXPR: {
            cout << setw(level * 8) << " " << "|COUNT expr|" << endl;
            break;
        }
        case AST_SUM_EXPR: {
            cout << setw(level * 8) << " " << "|SUM expr|" << endl;
            break;
        }
        case AST_MIN_EXPR: {
            cout << setw(level * 8) << " " << "|MIN expr|" << endl;
            break;
        }
        case AST_MAX_EXPR: {
            cout << setw(level * 8) << " " << "|MAX expr|" << endl;
            break;
        }
        case AST_AVG_EXPR: {
            cout << setw(level * 8) << " " << "|AVG expr|" << endl;
            break;
        }
        default: {
            break;
        }
    }
    if (arg0_ != NULL) {
        arg0_->Print(level + 1);
    } else {
        cout << setw((level + 1) * 8) << " " << "column name: *(All)" << endl;
    }
}

AstExprCalBinary::AstExprCalBinary(AstNodeType ast_node_type, AstNode* arg0,
                                   AstNode* arg1)
        : AstNode(ast_node_type),
          arg0_(arg0),
          arg1_(arg1) {
}
AstExprCmpBinary::AstExprCmpBinary(AstNodeType ast_node_type, AstNode* arg0,
                                   AstNode* arg1)
        : AstNode(ast_node_type),
          arg0_(arg0),
          arg1_(arg1) {
}
AstExprCmpBinary::AstExprCmpBinary(CmpPara cmp_para, int cmp_type,
                                   AstNode* arg0, AstNode* arg1)
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
AstExprCmpBinary::~AstExprCmpBinary() {
    delete arg0_;
    delete arg1_;
}

AstExprCalBinary::~AstExprCalBinary() {
    delete arg0_;
    delete arg1_;
}

void AstExprCalBinary::Print(int level) const {
    cout << setw(level * 8) << " " << "|expr binary|";
    switch (ast_node_type_) {
        case AST_EXPR_ADD: {
            cout << " " << '+' << endl;
            break;
        }
        case AST_EXPR_SUB: {
            cout << " " << '-' << endl;
            break;
        }
        case AST_EXPR_MUL: {
            cout << " " << '*' << endl;
            break;
        }
        case AST_EXPR_DIV: {
            cout << " " << '/' << endl;
            break;
        }
        case AST_EXPR_MOD: {
            cout << " " << '%' << endl;
            break;
        }
        case AST_EXPR_MOD_SIGN: {
            cout << " " << '%' << endl;
            break;
        }
        case AST_EXPR_AND: {
            cout << " " << "AND" << endl;
            break;
        }
        case AST_EXPR_OR: {
            cout << " " << "OR" << endl;
            break;
        }
        case AST_EXPR_XOR: {
            cout << " " << "XOR" << endl;
            break;
        }
        case AST_EXPR_BIT_OR: {
            cout << " " << "|" << endl;
            break;
        }
        case AST_EXPR_BIT_AND: {
            cout << " " << "&" << endl;
            break;
        }
        case AST_EXPR_BIT_XOR: {
            cout << " " << "^" << endl;
            break;
        }
        case AST_EXPR_LSHIFT: {
            cout << " " << "LEFT_SHIFT" << endl;
            break;
        }
        case AST_EXPR_RSHIFT: {
            cout << " " << "RIGHT_SHIFT" << endl;
            break;
        }
        default: {
            cout << endl;
        }
    }
    if (arg0_ != NULL)
        arg0_->Print(level + 1);
    if (arg1_ != NULL)
        arg1_->Print(level + 1);
}

void AstExprCmpBinary::Print(int level) const {
    cout << setw(level * 8) << " " << "|expr binary|";
    switch (ast_node_type_) {
        case AST_EXPR_EQUAL: {
            cout << " " << '=' << endl;
            break;
        }
        case AST_EXPR_LESS: {
            cout << " " << '<' << endl;
            break;
        }
        case AST_EXPR_MORE: {
            cout << " " << '>' << endl;
            break;
        }
        case AST_EXPR_LESSEQU: {
            cout << " " << "<=" << endl;
            break;
        }
        case AST_EXPR_MOREEQU: {
            cout << " " << ">=" << endl;
            break;
        }
        case AST_EXPR_INEQUAL: {
            cout << " " << "!=" << endl;
            break;
        }
        case AST_EXPR_UNKNOWN: {
            cout << " " << "UNKNOWN" << endl;
            break;
        }
        default: {
            cout << endl;
        }
    }

    if (arg0_ != NULL)
        arg0_->Print(level + 1);
    if (arg1_ != NULL)
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
    if (arg0_ != NULL)
        arg0_->Print(level + 1);
    if (arg1_ != NULL)
        arg1_->Print(level + 1);
    if (arg2_ != NULL)
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
    // cout << "level= " << level << endl;
    cout << setw(level * 8) << " " << "|expr list|" << endl;
    if (expr_ != NULL)
        expr_->Print(level);
    if (next_ != NULL)
        next_->Print(level);
}

AstExprString::AstExprString(AstNodeType ast_node_type, AstNode* arg0,
                             AstNode* arg1, AstNode* arg2)
        : AstNode(ast_node_type),
          expr_para_(NULL),
          arg0_(arg0),
          arg1_(arg1),
          arg2_(arg2) {
}

AstExprString::AstExprString(AstNodeType ast_node_type, std::string expr_para,
                             AstNode* arg0, AstNode* arg1)
        : AstNode(ast_node_type),
          expr_para_(new AstExprConst(AST_EXPR_CONST, expr_para)),
          arg0_(arg0),
          arg1_(arg1),
          arg2_(NULL) {
}

AstExprString::~AstExprString() {
    delete arg0_;
    delete arg1_;
    delete arg2_;
}

void AstExprString::Print(int level) const {
    cout << setw(level * 8) << " " << "|expr about string|" << endl;
    if (arg0_ != NULL)
        arg0_->Print(level + 1);
    if (arg1_ != NULL)
        arg1_->Print(level + 2);
    if (arg2_ != NULL)
        arg2_->Print(level + 3);
}

AstExprJoin::AstExprJoin(AstNodeType ast_node_type, int join_type,
                         AstNode* reference, AstNode* left_right_next,
                         AstNode* condition)
        : AstNode(ast_node_type),
          join_type_(join_type),
          reference_(reference),
          left_right_next_(left_right_next),
          condition_(condition) {
}

AstExprJoin::~AstExprJoin() {
    delete reference_;
    delete left_right_next_;
    delete condition_;
}

void AstExprJoin::Print(int level) const {
    bitset < 10 > bit_num;
    bit_num = join_type_;
    cout << setw(level * 8) << " " << "|expr join|" << endl;
    cout << setw((level + 1) * 8) << " " << "|reference expr|" << endl;
    if (reference_ != NULL)
        reference_->Print(level + 1);
    cout << setw((level + 1) * 8) << " " << "|join type|";
    if (bit_num[9] == 1) {
        cout << " " << "straight join" << endl;
    } else {
        if (bit_num[0] == 1) {
            cout << " " << "inner join,";
        }
        if (bit_num[1] == 1) {
            cout << " " << "cross join,";
        }
        if (bit_num[2] == 1) {
            cout << " " << "outer join,";
        }
        if (bit_num[3] == 1) {
            cout << " " << "left join,";
        }
        if (bit_num[4] == 1) {
            cout << " " << "right join,";
        }
        if (bit_num[5] == 1) {
            cout << " " << "natural join,";
        }
    }
    if (join_type_ == 0)
        cout << " " << "join";
    cout << endl;
    // cout << setw((level + 1) * 8) << " " << bit_num << endl;
    if (left_right_next_ != NULL) {
        cout << setw((level + 1) * 8) << " " << "|left or right |" << endl;
        left_right_next_->Print(level + 1);
    }
    if (condition_ != NULL) {
        cout << setw((level + 1) * 8) << " " << "|condition|" << endl;
        condition_->Print(level + 1);
    }
}

