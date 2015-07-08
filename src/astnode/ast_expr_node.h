/*
 * ast_expr_node.h
 *  Created on: May 22, 2015 11:36:17 AM
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */

#ifndef AST_EXPR_NODE_H_
#define AST_EXPR_NODE_H_
#include "ast_node.h"
#include <string>
class AstExprConst: public AstNode {
public:
	AstExprConst(AstNodeType ast_node_type, std::string data);
	~AstExprConst();
	void Print(int level = 0) const;
	std::string data_;
};
class AstExprUnary: public AstNode {
public:
	AstExprUnary(AstNodeType ast_node_type, AstNode* arg0);
	~AstExprUnary();
	void Print(int level = 0) const;
	AstNode* arg0_;
	std::string expr_str_;
};
class AstExprBinary: public AstNode {
public:
	AstExprBinary(AstNodeType ast_node_type, AstNode* arg0, AstNode* arg1);
	~AstExprBinary();
	void Print(int level = 0) const;
	AstNode* arg0_;
	AstNode* arg1_;
	std::string expr_str_;
};
class AstExprTernary: public AstNode {
public:
	AstExprTernary(AstNodeType ast_node_type, AstNode* arg0, AstNode* arg1, AstNode* arg2);
	~AstExprTernary();
	void Print(int level = 0) const;
	AstNode* arg0_;
	AstNode* arg1_;
	AstNode* arg2_;
	std::string expr_str_;
};

#endif /* AST_EXPR_NODE_H_ */
