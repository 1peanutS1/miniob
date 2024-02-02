/* Copyright (c) 2021-2022 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by wangyunlai on 2024/02/01
//

#include "storage/clog/log_handler.h"

using namespace std;

RC LogHandler::append(LSN &lsn, LogModule::Id module, const char *data, int32_t size)
{
  unique_ptr<char[]> buf(new char[size]);
  memcpy(buf.get(), data, size);
  return append(lsn, module, std::move(buf), size);
}

RC LogHandler::append(LSN &lsn, LogModule::Id module, std::unique_ptr<char[]> data, int32_t size)
{
  return _append(lsn, LogModule(module), std::move(data), size);
}