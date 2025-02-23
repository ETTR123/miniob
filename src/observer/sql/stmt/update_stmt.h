/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/5/22.
//

#pragma once

#include "rc.h"
#include "common/log/log.h"
#include "sql/stmt/stmt.h"
#include "sql/parser/parse_defs.h"


class Table;
class FilterStmt;

class UpdateStmt : public Stmt
{
public:

  UpdateStmt(Table *table, const Value &value, const char *attribute_name, FilterStmt *filter_stmt);
  ~UpdateStmt() override;

  Table *table() const { return table_;}
  const Value &value() const { return value_;}
  const char *attribute_name() { return attribute_name_; }
  FilterStmt *filter_stmt() const { return filter_stmt_;}
  
  StmtType type() const override { return StmtType::UPDATE;}
public:
  static RC create(Db *db, const Updates &update_sql, Stmt *&stmt);

private:
  Table *table_ = nullptr;
  const Value &value_;
  const char *attribute_name_ = nullptr;
  FilterStmt *filter_stmt_ = nullptr;
};

