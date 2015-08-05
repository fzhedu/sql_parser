/*
 *  /sql_parser/src/astnode/ast_load_stmt.h
 *
 *  Created on: Aug 4, 2015
 *      Author: fish
 *       Email: youngfish93@hotmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSe
 *
 */

#ifndef SRC_ASTNODE_AST_LOAD_STMT_H_
#define SRC_ASTNODE_AST_LOAD_STMT_H_

#include "./ast_node.h"
#include <string>
#include <iostream>  //NOLINT

using std::string;

/***
 * @brief
 */
class AstLoadTable : public AstNode {
 public:
  /**
   * @brief AstLoadTable Constructor.
   * @param
   * @details  here is an example (additional)
   */
  AstLoadTable(AstNodeType ast_node_type, string table_name, AstNode* path,
               string column_separator, string tuple_separator, double sample,
               int mode);
  /**
   * @brief AstLoadTable Destructor.
   * @param
   * @details  here is an example (additional)
   */
  ~AstLoadTable();
  void Print(int level = 0) const;
  AstNodeType ast_node_type_;
  string table_name_;
  AstNode* path_;
  string column_separator_;
  string tuple_separator_;
  double sample_;
  int mode_;

 private:
};

#endif  // SRC_ASTNODE_AST_LOAD_STMT_H_
