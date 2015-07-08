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
using namespace std;
AstExprConst::AstExprConst(AstNodeType ast_node_type, std::string data) :
		AstNode(ast_node_type), data_(data){
}

AstExprConst::~AstExprConst() {
}
void AstExprConst::Print(int level) const {
//	cout << setw(level * 8) << " " << "|selecct list|" << endl;
	cout << setw(level * 8) << " " << "const data:" << data_ << endl;
}

AstExprUnary::AstExprUnary(AstNodeType ast_node_type, AstNode* arg0) :
		AstNode(ast_node_type), arg0_(arg0) {
}

AstExprUnary::~AstExprUnary() {
	delete arg0_;
}

void AstExprUnary::Print(int level) const {
	cout << setw(level * 8) << " " << "|expr unary|" << endl;
	arg0_->Print(level+1);
}

AstExprBinary::AstExprBinary(AstNodeType ast_node_type, AstNode* arg0, AstNode* arg1) :
		AstNode(ast_node_type), arg0_(arg0), arg1_(arg1) {
}

AstExprBinary::~AstExprBinary() {
	delete arg0_;
	delete arg1_;
}

void AstExprBinary::Print(int level) const {
	cout << setw(level * 8) << " " << "|expr binary|" << endl;
	arg0_->Print(level+1);
	arg1_->Print(level+1);
}

AstExprTernary::AstExprTernary(AstNodeType ast_node_type, AstNode* arg0, AstNode* arg1, AstNode* arg2) :
		AstNode(ast_node_type), arg0_(arg0), arg1_(arg1), arg2_(arg2) {
}

AstExprTernary::~AstExprTernary() {
	delete arg0_;
	delete arg1_;
	delete arg2_;
}

void AstExprTernary::Print(int level) const {
	cout << setw(level * 8) << " " << "|expr ternary|" << endl;
	arg0_->Print(level+1);
	arg1_->Print(level+1);
	arg2_->Print(level+1);
}
