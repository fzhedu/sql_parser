/*
 * ast_select_stmt.h
 *  Created on: May 22, 2015 11:32:03 AM
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */

#ifndef AST_SELECT_STMT_H_
#define AST_SELECT_STMT_H_
#include "./ast_node.h"
#include <string>
class AstSelectList : public AstNode {
 public:
    AstSelectList(AstNodeType ast_node_type, bool is_all, AstNode* args,
                  AstNode* next);
    ~AstSelectList();
    void Print(int level = 0) const;

    bool is_all_;
    AstNode* args_;
    AstNode* next_;
};
class AstSelectExpr : public AstNode {
 public:
    AstSelectExpr(AstNodeType ast_node_type, std::string expr_alias,
                  AstNode* expr);
    ~AstSelectExpr();
    void Print(int level = 0) const;

    std::string expr_alias_;
    AstNode* expr_;
};
class AstFromList : public AstNode {
 public:
    AstFromList(AstNodeType ast_node_type, AstNode* args, AstNode* next);
    ~AstFromList();
    void Print(int level = 0) const;

    AstNode* args_;
    AstNode* next_;
    AstNode* condition_;  // TODO
};

class AstTable : public AstNode {
 public:
    AstTable(AstNodeType ast_node_type, std::string db_name,
             std::string table_name, std::string table_alias);
    ~AstTable();
    void Print(int level = 0) const;

    std::string db_name_;
    std::string table_name_;
    std::string table_alias_;
    int table_id_;
// AstNode* condition_; //
};

class AstSubquery : public AstNode {
 public:
    AstSubquery(AstNodeType ast_node_type, std::string subquery_alias,
                AstNode* subquery);
    ~AstSubquery();
    void Print(int level = 0) const;

    std::string subquery_alias_;
    AstNode* subquery_;
};
class AstJoinCondition : public AstNode {
 public:
    enum JoinConditionType {
        JOIN_NONE,
        JOIN_ON,
        JOIN_USING
    };
    AstJoinCondition(AstNodeType ast_node_type,
                     JoinConditionType join_condition_type, AstNode* condition);
    ~AstJoinCondition();
    JoinConditionType join_condition_type_;
    AstNode* condition_;
};
class AstJoin : public AstNode {
 public:
    enum JoinType {
        NONE_JOIN,
        INNER_JOIN,
        CROSS_JOIN,
        STRAIGHT_JOIN,
        NATUAL_JOIN,
        NATUAL_OUTER_LEFT_JOIN,
        NATUAL_OUTER_RIGHT_JOIN,
        NATUAL_FULL_OUTER_JOIN,
        LEFT_OUTER_JOIN,
        RIGHT_OUTER_JOIN,
        FULL_OUTER_JOIN
    };
    AstJoin(AstNodeType ast_node_type, AstNode* left_node, AstNode* right_node,
            AstJoinCondition* join_condition);
    ~AstJoin();
    void Print(int level = 0) const;
    AstNode* left_node_;
    AstNode* right_node_;
    AstJoinCondition* join_condition_;
};
class AstWhereClause : public AstNode {
 public:
    AstWhereClause(AstNodeType ast_node_type, AstNode* expr);
    ~AstWhereClause();
    void Print(int level = 0) const;

    AstNode* expr_;
};
class AstGroupByList : public AstNode {
 public:
    AstGroupByList(AstNodeType ast_node_type, AstNode* expr, AstNode* next);
    ~AstGroupByList();
    void Print(int level = 0) const;
    AstNode* expr_;
    AstNode* next_;
};
class AstGroupByClause : public AstNode {
 public:
    AstGroupByClause(AstNodeType ast_node_type, AstNode* groupby_list,
                     bool with_roolup);
    ~AstGroupByClause();
    void Print(int level = 0) const;
    AstGroupByList* groupby_list_;
    bool with_roolup_;
};
class AstOrderByList : public AstNode {
 public:
    enum OrderByType {
        ORDER_ASC,
        ORDER_DESC,
    };
    explicit AstOrderByList(AstNodeType ast_node_type, AstNode* expr,
                            int orderby_type, AstNode* next);
    ~AstOrderByList();
    void Print(int level = 0) const;
    AstNode* expr_;
    OrderByType orderby_type_;
    AstNode* next_;
};
class AstOrderByClause : public AstNode {
 public:
    AstOrderByClause(AstNodeType ast_node_type, AstNode* orderby_list);
    ~AstOrderByClause();
    void Print(int level = 0) const;
    AstOrderByList* orderby_list_;
};
class AstHavingClause : public AstNode {
 public:
    AstHavingClause(AstNodeType ast_node_type, AstNode* expr);
    ~AstHavingClause();
    void Print(int level = 0) const;
    AstNode* expr_;
};
class AstLimitClause : public AstNode {
 public:
    AstLimitClause(AstNodeType ast_node_type, AstNode* offset,
                   AstNode* row_count);
    ~AstLimitClause();
    void Print(int level = 0) const;
    AstNode* offset_;
    AstNode* row_count_;
};
class AstSelectIntoClause : public AstNode {
 public:
// AstSelectIntoClause();
// ~AstSelectIntoClause();
// void Print(int level = 0) const;
};
class AstColumn : public AstNode {
 public:
    AstColumn(AstNodeType ast_node_type, std::string relation_name,
              std::string column_name);
    AstColumn(AstNodeType ast_node_type, std::string relation_name,
              std::string column_name, AstNode* next);
    ~AstColumn();
    void Print(int level = 0) const;
    std::string relation_name_;
    std::string column_name_;
    AstNode* next_;
};
class AstSelectStmt : public AstNode {
 public:
    enum SelectOpts {
        SELECT_ALL,
        SELECT_DISTINCT,
        SELECT_DISTINCTROW,
    };
    AstSelectStmt(AstNodeType ast_node_type, int select_opts,
                  AstNode* select_list, AstNode* from_list,
                  AstNode* where_clause, AstNode* groupby_clause,
                  AstNode* having_clause, AstNode* orderby_clause,
                  AstNode* limit_clause, AstNode* select_into_clause);
    ~AstSelectStmt();
    void Print(int level = 0) const;
    std::string select_str_;
    SelectOpts select_opts_;
    AstNode* select_list_;
    AstNode* from_list_;
    AstNode* where_clause_;
    AstNode* groupby_clause_;
    AstNode* having_clause_;
    AstNode* orderby_clause_;
    AstNode* limit_clause_;
    AstNode* select_into_clause_;
};

#endif /* AST_SELECT_STMT_H_ */
