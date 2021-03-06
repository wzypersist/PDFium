// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_deltas.h"

#include <memory>

#include "fxjs/xfa/cjx_list.h"

CXFA_Deltas::CXFA_Deltas(CXFA_Document* doc)
    : CXFA_List(doc, std::make_unique<CJX_List>(this)) {}

CXFA_Deltas::~CXFA_Deltas() {}
