/*
 * ast_expr_node.h
 *  Created on: May 22, 2015 11:36:17 AM
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */
/*
 * those classes in this file are used to describe the calculation tree of expression,
 * just store some main information, so don't match the class used to describe the
 * calculation tree of execution completely.
 */
#ifndef AST_EXPR_NODE_H_    //NOLINT
#define AST_EXPR_NODE_H_
#include "./ast_node.h"
#include <string>
class AstExprConst : public AstNode {
 public:
    AstExprConst(std::string expr_type, std::string data);
    ~AstExprConst();
    void Print(int level = 0) const;
    std::string expr_type_;
    std::string data_;
};

class AstExprUnary : public AstNode {
 public:
    AstExprUnary(std::string expr_type, AstNode* arg0);
    ~AstExprUnary();
    void Print(int level = 0) const;
    AstNode* arg0_;
    std::string expr_type_;
    std::string expr_str_;
};
/*
 *
 */
class AstExprFunc : public AstNode {
 public:
    AstExprFunc(std::string expr_type, AstNode* arg0, AstNode* arg1,
                AstNode* arg2);
    ~AstExprFunc();
    void Print(int level = 0) const;
    AstNode* arg0_;
    AstNode* arg1_;
    AstNode* arg2_;
    std::string expr_type_;
    std::string expr_str_;
};

class AstExprCalBinary : public AstNode {
 public:
    AstExprCalBinary(std::string expr_type, AstNode* arg0, AstNode* arg1);
    ~AstExprCalBinary();
    void Print(int level = 0) const;
    AstNode* arg0_;
    AstNode* arg1_;
    std::string expr_type_;
    std::string expr_str_;
};

class AstExprCmpBinary : public AstNode {
 public:
    AstExprCmpBinary(std::string expr_type, AstNode* arg0, AstNode* arg1);
    AstExprCmpBinary(std::string cmp_para, int cmp_type, AstNode* arg0,
                     AstNode* arg1);

    ~AstExprCmpBinary();
    void Print(int level = 0) const;
    AstNode* arg0_;
    AstNode* arg1_;
    std::string expr_type_;
    std::string expr_str_;
    std::string cmp_para_;  //  "ALL","ANY","SOME","NULL","SUBQUERY"
};
class AstExprList : public AstNode {
 public:
    AstExprList(AstNode* expr, AstNode* next);
    ~AstExprList();
    void Print(int level = 0) const;
    AstNode* expr_;
    AstNode* next_;
};

#endif /* AST_EXPR_NODE_H_ */    //NOLINT
