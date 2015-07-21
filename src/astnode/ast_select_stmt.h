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
    AstSelectList(bool is_all, AstNode* args, AstNode* next);
    ~AstSelectList();
    void Print(int level = 0) const;
    bool is_all_;
    AstNode* args_;
    AstNode* next_;
};
class AstSelectExpr : public AstNode {
 public:
    AstSelectExpr(std::string expr_alias, AstNode* expr);
    ~AstSelectExpr();
    void Print(int level = 0) const;

    std::string expr_alias_;
    AstNode* expr_;
};
class AstFromList : public AstNode {
 public:
    AstFromList(AstNode* args, AstNode* next);
    ~AstFromList();
    void Print(int level = 0) const;

    AstNode* args_;
    AstNode* next_;
    AstNode* condition_;  // TODO(fzh)
};

class AstTable : public AstNode {
 public:
    AstTable(std::string db_name, std::string table_name,
             std::string table_alias);
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
    AstSubquery(std::string subquery_alias, AstNode* subquery);
    ~AstSubquery();
    void Print(int level = 0) const;

    std::string subquery_alias_;
    AstNode* subquery_;
};
class AstJoinCondition : public AstNode {
 public:
    AstJoinCondition(std::string join_condition_type, AstNode* condition);
    ~AstJoinCondition();
    void Print(int level = 0) const;
    std::string join_condition_type_;
    AstNode* condition_;
};
class AstJoin : public AstNode {
 public:
    AstJoin(int join_type, AstNode* left_table, AstNode* right_table,
            AstNode* join_condition);
    ~AstJoin();
    void Print(int level = 0) const;
    std::string join_type_;
    AstNode* left_table_;
    AstNode* right_table_;
    AstJoinCondition* join_condition_;
};
class AstWhereClause : public AstNode {
 public:
    explicit AstWhereClause(AstNode* expr);
    ~AstWhereClause();
    void Print(int level = 0) const;

    AstNode* expr_;
};
class AstGroupByList : public AstNode {
 public:
    AstGroupByList(AstNode* expr, AstNode* next);
    ~AstGroupByList();
    void Print(int level = 0) const;
    AstNode* expr_;
    AstNode* next_;
};
class AstGroupByClause : public AstNode {
 public:
    AstGroupByClause(AstNode* groupby_list, bool with_roolup);
    ~AstGroupByClause();
    void Print(int level = 0) const;
    AstGroupByList* groupby_list_;
    bool with_roolup_;
};
class AstOrderByList : public AstNode {
 public:
    explicit AstOrderByList(AstNode* expr, int orderby_type, AstNode* next);
    ~AstOrderByList();
    void Print(int level = 0) const;
    AstNode* expr_;
    std::string orderby_type_;
    AstNode* next_;
};
class AstOrderByClause : public AstNode {
 public:
    explicit AstOrderByClause(AstNode* orderby_list);
    ~AstOrderByClause();
    void Print(int level = 0) const;
    AstOrderByList* orderby_list_;
};
class AstHavingClause : public AstNode {
 public:
    explicit AstHavingClause(AstNode* expr);
    ~AstHavingClause();
    void Print(int level = 0) const;
    AstNode* expr_;
};
class AstLimitClause : public AstNode {
 public:
    AstLimitClause(AstNode* offset, AstNode* row_count);
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
    AstColumn(std::string relation_name, std::string column_name);
    AstColumn(std::string relation_name, std::string column_name,
              AstNode* next);
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
    AstSelectStmt(int select_opts, AstNode* select_list, AstNode* from_list,
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
