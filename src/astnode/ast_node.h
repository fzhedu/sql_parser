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
    AST_EXPR_SUB,
    AST_EXPR_MUL,
    AST_EXPR_DIV,
    AST_EXPR_MOD,
    AST_EXPR_MOD_SIGN,
    AST_EXPR_POSITIVE,
    AST_EXPR_NEGATIVE,

    AST_EXPR_AND,
    AST_EXPR_OR,
    AST_EXPR_XOR,

    AST_EXPR_EQUAL,
    AST_EXPR_LESS,
    AST_EXPR_MORE,
    AST_EXPR_LESSEQU,
    AST_EXPR_MOREEQU,
    AST_EXPR_INEQUAL,
    AST_EXPR_UNKOWN,

    AST_EXPR_EQUAL_SUB,
    AST_EXPR_LESS_SUB,
    AST_EXPR_MORE_SUB,
    AST_EXPR_LESSEQU_SUB,
    AST_EXPR_MOREEQU_SUB,
    AST_EXPR_INEQUAL_SUB,
    AST_EXPR_UNKOWN_SUB,

    AST_EXPR_EQUAL_ALL,
    AST_EXPR_LESS_ALL,
    AST_EXPR_MORE_ALL,
    AST_EXPR_LESSEQU_ALL,
    AST_EXPR_MOREEQU_ALL,
    AST_EXPR_INEQUAL_ALL,
    AST_EXPR_UNKOWN_ALL,

    AST_EXPR_EQUAL_ANY,
    AST_EXPR_LESS_ANY,
    AST_EXPR_MORE_ANY,
    AST_EXPR_LESSEQU_ANY,
    AST_EXPR_MOREEQU_ANY,
    AST_EXPR_INEQUAL_ANY,
    AST_EXPR_UNKOWN_ANY,

    AST_EXPR_EQUAL_SOME,
    AST_EXPR_LESS_SOME,
    AST_EXPR_MORE_SOME,
    AST_EXPR_LESSEQU_SOME,
    AST_EXPR_MOREEQU_SOME,
    AST_EXPR_INEQUAL_SOME,
    AST_EXPR_UNKOWN_SOME,

    AST_EXPR_BIT_AND,
    AST_EXPR_BIT_OR,
    AST_EXPR_BIT_XOR,
    AST_EXPR_LSHIFT,
    AST_EXPR_RSHIFT,
    AST_EXPR_NOR,

    AST_EXPR_ISNULL,
    AST_EXPR_NOTNULL,
    AST_EXPR_ISBOOL,
    AST_EXPR_ISNOTBOOL,

    AST_EXPR_BETWEEN,

    AST_EXPR_IN_LIST,
    AST_EXPR_LIST_IN_LIST,
    AST_EXPR_NOTIN_LIST,
    AST_EXPR_LIST_NOTIN_LIST,
    AST_EXPR_IN_SEL,
    AST_EXPR_LIST_IN_SEL,
    AST_EXPR_NOTIN_SEL,
    AST_EXPR_EXSIST_SEL,
    AST_EXPR_NOT_EXSIST_SEL,

    AST_EXPR_SUBSTRING_EXPR_EXPR,
    AST_EXPR_SUBSTRING_EXPR_FROM_EXPR,
    AST_EXPR_SUBSTRING_EXPR_EXPR_EXPR,
    AST_EXPR_SUBSTRING_EXPR_FROM_EXPR_FOR_EXPR,
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
struct ParseResult {
    void * yyscan_info_;
    AstNode * ast;
    const char * sql_clause;
    int error_number;
// std::vector<AstNode *>*node_pointer;
};

/*
 * used to link every statement in one sql contains multiple statement
 * for example: select a from tb;select max(a) from tb2;
 */
class AstStmtList : public AstNode {
 public:
    AstStmtList(AstNodeType ast_node_type, AstNode* stmt, AstNode* next);
    ~AstStmtList();
    void Print(int level = 0) const;
    AstNode* stmt_;
    AstNode* next_;
};

#endif  // AST_NODE_H__
