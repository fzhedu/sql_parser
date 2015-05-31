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
class AstExprConst : public AstNode {
 public:
    AstExprConst(AstNodeType ast_node_type, std::string data);
    ~AstExprConst();
    void Print(int level = 0) const;
    std::string data_;
};

class AstExprUnary : public AstNode {
 public:
    AstExprUnary(AstNodeType ast_node_type, AstNode* arg0);
    ~AstExprUnary();
    void Print(int level = 0) const;
    AstNode* arg0_;
    std::string expr_str_;
};
class AstExprString : public AstNode {
 public:
    /*enum TrimPara{
     LEADING,
     TRAILING,
     BOTH,
     };*/
    AstExprString(AstNodeType ast_node_type, AstNode* arg0, AstNode* arg1,
                  AstNode* arg2);
    AstExprString(AstNodeType ast_node_type, std::string trim_para,
                  AstNode* arg0, AstNode* arg1);
    ~AstExprString();
    void Print(int level = 0) const;
    AstNode* arg0_;
    AstNode* arg1_;
    AstNode* arg2_;
    std::string expr_str_;
    std::string trim_para_;
};
class AstExprCalBinary : public AstNode {
 public:
    AstExprCalBinary(AstNodeType ast_node_type, AstNode* arg0, AstNode* arg1);
    ~AstExprCalBinary();
    void Print(int level = 0) const;
    AstNode* arg0_;
    AstNode* arg1_;
    std::string expr_str_;
};

class AstExprCmpBinary : public AstNode {
 public:
    enum CmpPara {
        CMP_ALL,
        CMP_ANY,
        CMP_SOME,
        CMP_NULL,
        CMP_SUBQUERY,
    };
    AstExprCmpBinary(AstNodeType ast_node_type, AstNode* arg0, AstNode* arg1);
    AstExprCmpBinary(CmpPara cmp_para, int cmp_type, AstNode* arg0,
                     AstNode* arg1);

    ~AstExprCmpBinary();
    void Print(int level = 0) const;
    AstNode* arg0_;
    AstNode* arg1_;
    std::string expr_str_;
    CmpPara cmp_para_;
};
class AstExprTernary : public AstNode {
 public:
    AstExprTernary(AstNodeType ast_noe_type, AstNode* arg0, AstNode* arg1,
                   AstNode* arg2);
    ~AstExprTernary();
    void Print(int level = 0) const;
    AstNode* arg0_;
    AstNode* arg1_;
    AstNode* arg2_;
    std::string expr_str_;
};
class AstExprList : public AstNode {
 public:
    AstExprList(AstNodeType ast_node_type, AstNode* expr, AstNode* next);
    ~AstExprList();
    void Print(int level = 0) const;
    AstNode* expr_;
    AstNode* next_;
};

#endif /* AST_EXPR_NODE_H_ */
