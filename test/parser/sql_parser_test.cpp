/*
 * sql_parser_test.cpp
 *  Created on: May 25, 2015 2:49:58 PM
 *      Author: fzh
 *       Email: fzhedu@gmail.com
 *   Copyright: Copyright (c) @ ECNU.DaSE
 * Description:
 */
#include <stdio.h>
#include <string>
#include "../../src/astnode/ast_node.h"
#include "../../src/parser/sql_parser.h"
#include <glog/logging.h>
#include <glog/raw_logging.h>
using namespace std;
#define THREAD_NUM 5	//thread number, test for guaranteeing the parser is reentrant
string SqlStmt[THREAD_NUM];
AstNode* MyAst[THREAD_NUM];
void* my_thread(void* args) {
	int id = *(int *) args;
	Parser* my_parser = new Parser(SqlStmt[id % 2]);
	AstNode* my_ast = my_parser->GetRawAST();
	MyAst[id] = my_ast;	//save parser result
//	my_ast->Print();
	RAW_LOG(INFO,"one thread over!");

	return NULL;
}
void test_multi_thread() {
	SqlStmt[0] = string("select AAA from BBB where CCC limit 333;");
	SqlStmt[1] = string("select a as A from tb as TB where c group by d having e order by f limit 10,3;");
	pthread_t ptid[THREAD_NUM];
	int id[THREAD_NUM];
	FLAGS_logtostderr=1;
	for (int i = 0; i < THREAD_NUM; i++) {
		id[i] = i;
		int flag = pthread_create(&ptid[i], NULL, my_thread, &id[i]);
		if (flag != 0) {
		    LOG(WARNING) << "warning:failed create my thread";
		} else {
			LOG(INFO)<<"info:succeed create my thread";
		}
	}
	for (int i = 0; i < THREAD_NUM; i++) {
		pthread_join(ptid[i], NULL);
	}
	for (int i = 0; i < THREAD_NUM; i++) {
		MyAst[i]->Print();
	}
}
