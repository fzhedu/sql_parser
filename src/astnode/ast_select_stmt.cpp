/*
 * ast_select_stmt.cpp
 *  Created on: May 22, 2015 11:32:03 AM
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */

#include "ast_select_stmt.h"
#include <iostream>
#include <iomanip>
using namespace std;
AstSelectList::AstSelectList(AstNodeType ast_node_type, bool is_all,
                             AstNode* args, AstNode* next)
        : AstNode(ast_node_type),
          is_all_(is_all),
          args_(args),
          next_(next) {
}

AstSelectList::~AstSelectList() {
    delete args_;
    delete next_;
}

void AstSelectList::Print(int level) const {
    cout << setw(level * 8) << " " << "|select list|" << endl;
    if (args_ != NULL) {
        args_->Print(level);
    }
    if (next_ != NULL) {
        next_->Print(level + 1);
    }
}

AstSelectExpr::AstSelectExpr(AstNodeType ast_node_type, std::string expr_alias,
                             AstNode* expr)
        : AstNode(ast_node_type),
          expr_alias_(expr_alias),
          expr_(expr) {
}

AstSelectExpr::~AstSelectExpr() {
    delete expr_;
}

void AstSelectExpr::Print(int level) const {
    cout << setw(level * 8) << " " << "|select expr|" << endl;
    if (expr_ != NULL) {
        expr_->Print(level);
    }
    cout << setw(level * 8) << " " << "expr alias: " << expr_alias_ << endl;
}

AstFromList::AstFromList(AstNodeType ast_node_type, AstNode* args,
                         AstNode* next)
        : AstNode(ast_node_type),
          args_(args),
          next_(next) {
}

AstFromList::~AstFromList() {
    delete args_;
    delete next_;
}

void AstFromList::Print(int level) const {
    cout << setw(level * 8) << " " << "|from list|" << endl;
    if (args_ != NULL) {
        args_->Print(level);
    }
    if (next_ != NULL) {
        next_->Print(level + 1);
    }
}

AstTable::AstTable(AstNodeType ast_node_type, string db_name, string table_name,
                   string table_alias)
        : AstNode(ast_node_type),
          db_name_(db_name),
          table_name_(table_name),
          table_alias_(table_alias) {
}

AstTable::~AstTable() {

}

void AstTable::Print(int level) const {
    cout << setw(level * 8) << " " << "|table| " << endl;
    level++;
    cout << setw(level * 8) << " " << "db_name: " << db_name_ << endl;
    cout << setw(level * 8) << " " << "table_name: " << table_name_ << endl;
    cout << setw(level * 8) << " " << "table_alias: " << table_alias_ << endl;
}

AstSubquery::AstSubquery(AstNodeType ast_node_type, std::string subquery_alias,
                         AstNode* subquery)
        : AstNode(ast_node_type),
          subquery_alias_(subquery_alias),
          subquery_(subquery) {
}

AstSubquery::~AstSubquery() {
    delete subquery_;
}

void AstSubquery::Print(int level) const {
    cout << setw(level * 8) << " " << "|subquery| " << " subquery_alias: "
            << subquery_alias_ << endl;
    if (subquery_ != NULL) {
        subquery_->Print(level);
    }
}

AstJoinCondition::AstJoinCondition(AstNodeType ast_node_type,
                                   JoinConditionType join_condition_type,
                                   AstNode* condition)
        : AstNode(ast_node_type),
          join_condition_type_(join_condition_type),
          condition_(condition) {
}

AstJoinCondition::~AstJoinCondition() {
    delete condition_;
}

AstJoin::AstJoin(AstNodeType ast_node_type, AstNode* left_node,
                 AstNode* right_node, AstJoinCondition* join_condition)
        : AstNode(ast_node_type),
          left_node_(left_node),
          right_node_(right_node),
          join_condition_(join_condition) {
}

AstJoin::~AstJoin() {
    delete left_node_;
    delete right_node_;
    delete join_condition_;
}

void AstJoin::Print(int level) const {
    cout << setw(level * 8) << " " << "|subquery| " << endl;
    cout << setw(level * 8) << " " << "|subquery left node| " << endl;
    if (left_node_ != NULL)
        left_node_->Print(level + 1);
    cout << setw(level * 8) << " " << "|subquery right node| " << endl;
    if (right_node_ != NULL)
        right_node_->Print(level + 1);
    cout << setw(level * 8) << " " << "|subquery condition| " << endl;
    join_condition_->Print(level + 1);
}

AstWhereClause::AstWhereClause(AstNodeType ast_node_type, AstNode* expr)
        : AstNode(ast_node_type),
          expr_(expr) {
}

AstWhereClause::~AstWhereClause() {
    delete expr_;
}

void AstWhereClause::Print(int level) const {
    cout << setw(level * 8) << " " << "|where clause| " << endl;
    if (expr_ != NULL)
        expr_->Print(level + 1);
}

AstGroupByList::AstGroupByList(AstNodeType ast_node_type, AstNode* expr,
                               AstNode* next)
        : AstNode(ast_node_type),
          expr_(expr),
          next_(next) {
}

AstGroupByList::~AstGroupByList() {
    delete expr_;
    delete next_;
}

void AstGroupByList::Print(int level) const {
    cout << setw(level * 8) << " " << "|groupby list| " << endl;
    if (expr_ != NULL)
        expr_->Print(level);
    if (next_ != NULL) {
        next_->Print(level + 1);
    }
}

AstGroupByClause::AstGroupByClause(AstNodeType ast_node_type,
                                   AstNode* groupby_list, bool with_roolup)
        : AstNode(ast_node_type),
          groupby_list_((AstGroupByList*) groupby_list),
          with_roolup_(with_roolup) {
}

AstGroupByClause::~AstGroupByClause() {
    delete groupby_list_;
}

void AstGroupByClause::Print(int level) const {
    cout << setw(level * 8) << " " << "|groupby clause| " << "with rool_up: "
            << with_roolup_ << endl;
    groupby_list_->Print(level + 1);
}

AstOrderByList::AstOrderByList(AstNodeType ast_node_type, AstNode* expr,
                               int orderby_type, AstNode* next)
        : AstNode(ast_node_type),
          expr_(expr),
          orderby_type_((OrderByType) orderby_type),
          next_(next) {
}

AstOrderByList::~AstOrderByList() {
    delete expr_;
    delete next_;
}

void AstOrderByList::Print(int level) const {
    cout << setw(level * 8) << " " << "|orderby list| " << endl;
    if (expr_ != NULL)
        expr_->Print(level);
    cout << setw(level * 8) << " " << "orderby type: " << orderby_type_ << endl;
    if (next_ != NULL) {
        next_->Print(level + 1);
    }
}

AstOrderByClause::AstOrderByClause(AstNodeType ast_node_type,
                                   AstNode* orderby_list)
        : AstNode(ast_node_type),
          orderby_list_((AstOrderByList*) orderby_list) {
}

AstOrderByClause::~AstOrderByClause() {
    delete orderby_list_;
}

void AstOrderByClause::Print(int level) const {
    cout << setw(level * 8) << " " << "|orderby clause| " << endl;
    if (orderby_list_ != NULL) {
        orderby_list_->Print(level + 1);
    }
}

AstHavingClause::AstHavingClause(AstNodeType ast_node_type, AstNode* expr)
        : AstNode(ast_node_type),
          expr_(expr) {
}

AstHavingClause::~AstHavingClause() {
    delete expr_;
}

void AstHavingClause::Print(int level) const {
    cout << setw(level * 8) << " " << "|having clause| " << endl;
    if (expr_ != NULL)
        expr_->Print(level + 1);
}

AstLimitClause::AstLimitClause(AstNodeType ast_node_type, AstNode* offset,
                               AstNode* row_count)
        : AstNode(ast_node_type),
          offset_(offset),
          row_count_(row_count) {
}

AstLimitClause::~AstLimitClause() {
    delete offset_;
    delete row_count_;
}

void AstLimitClause::Print(int level) const {
    cout << setw(level * 8) << " " << "|limit clause| " << endl;
    level++;
    cout << setw(level * 8) << " " << " offset: " << endl;
    if (offset_ != NULL)
        offset_->Print(level + 1);
    cout << setw(level * 8) << " " << " row_count " << endl;
    if (row_count_ != NULL)
        row_count_->Print(level + 1);
}

AstColumn::AstColumn(AstNodeType ast_node_type, std::string relation_name,
                     std::string column_name)
        : AstNode(ast_node_type),
          relation_name_(relation_name),
          column_name_(column_name) {
}

AstColumn::~AstColumn() {
}

void AstColumn::Print(int level) const {
    cout << setw(level * 8) << " " << "|column| " << endl;
    level++;
    cout << setw(level * 8) << " " << "relation name: " << relation_name_
            << endl;
    cout << setw(level * 8) << " " << "column name: " << column_name_ << endl;
}

AstSelectStmt::AstSelectStmt(AstNodeType ast_node_type, int select_opts,
                             AstNode* select_list, AstNode* from_list,
                             AstNode* where_clause, AstNode* groupby_clause,
                             AstNode* having_clause, AstNode* orderby_clause,
                             AstNode* limit_clause, AstNode* select_into_clause)
        : AstNode(ast_node_type),
          select_opts_((SelectOpts) select_opts),
          select_list_(select_list),
          from_list_(from_list),
          where_clause_(where_clause),
          groupby_clause_(groupby_clause),
          having_clause_(having_clause),
          orderby_clause_(orderby_clause),
          limit_clause_(limit_clause),
          select_into_clause_(select_into_clause) {
}

AstSelectStmt::~AstSelectStmt() {
    delete select_list_;
    delete from_list_;
    delete where_clause_;
    delete groupby_clause_;
    delete having_clause_;
    delete orderby_clause_;
    delete limit_clause_;
    delete select_into_clause_;
}

void AstSelectStmt::Print(int level) const {
    cout << setw(level * 8) << " " << "|select statement| " << endl;
    level++;
    select_list_->Print(level);
    from_list_->Print(level);
    if (where_clause_ != NULL)
        where_clause_->Print(level);
    if (groupby_clause_ != NULL)
        groupby_clause_->Print(level);
    if (orderby_clause_ != NULL)
        orderby_clause_->Print(level);
    if (having_clause_ != NULL)
        having_clause_->Print(level);
    if (limit_clause_ != NULL)
        limit_clause_->Print(level);
    if (select_into_clause_ != NULL)
        select_into_clause_->Print(level);
    cout << "------------select ast print over!------------------" << endl;
}
