/*
 * ast_node.h
 *  Created on: May 21, 2015 4:10:35 PM
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */

#ifndef AST_NODE_H_
#define AST_NODE_H_
#include <vector>

enum AstNodeType {
	AST_NODE,
	AST_STMT_LIST,

	AST_SELECT_LIST,
	AST_SELECT_EXPR,
	AST_FROM_LIST,
	AST_TABLE,
	AST_SUBQUERY,
	AST_JOIN_CONDITION,
	AST_JOIN,
	AST_WHERE_CLAUSE,
	AST_GROUPBY_LIST,
	AST_GROUPBY_CLAUSE,
	AST_ORDERBY_LIST,
	AST_ORDERBY_CLAUSE,
	AST_HAVING_CLAUSE,
	AST_LIMIT_CLAUSE,
	AST_SELECT_INTO_CLAUSE,
	AST_COLUMN,
	AST_SELECT_STMT,

	AST_EXPR_CONST,
	AST_EXPR_CONST_STRING,
	AST_EXPR_CONST_DOUBLE,
	AST_EXPR_CONST_INT,
	AST_EXPR_CONST_BOOL,

	AST_EXPR_UNARY,
	AST_EXPR_BINARY,
	AST_EXPR_TERNARY,

	AST_EXPR_ADD,
};


class AstNode {
public:
	explicit AstNode(AstNodeType ast_node_type);
	virtual ~AstNode();
	virtual void Print(int level = 0) const;
	AstNodeType ast_node_type();
private:
	AstNodeType ast_node_type_;
};
struct ParseResult
{
	void * yyscan_info_;
	AstNode * ast;
	const char * sql_clause;
	int error_number;
//	std::vector<AstNode *>*node_pointer;
};

/*
 * used to link every statement in one sql contains multiple statement
 * for example: select a from tb;select max(a) from tb2;
 */
class AstStmtList: public AstNode {
public:
	AstStmtList(AstNodeType ast_node_type, AstNode* stmt, AstNode* next);
	~AstStmtList();
	void Print(int level = 0) const;
	AstNode* stmt_;
	AstNode* next_;
};

#endif /* AST_NODE_H_ */
