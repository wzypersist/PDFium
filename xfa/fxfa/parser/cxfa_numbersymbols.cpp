// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_numbersymbols.h"

#include <memory>

#include "fxjs/xfa/cjx_node.h"

namespace {

const CXFA_Node::PropertyData kNumberSymbolsPropertyData[] = {
    {XFA_Element::NumberSymbol, 5, 0},
};

}  // namespace

CXFA_NumberSymbols::CXFA_NumberSymbols(CXFA_Document* doc,
                                       XFA_PacketType packet)
    : CXFA_Node(doc,
                packet,
                XFA_XDPPACKET_LocaleSet,
                XFA_ObjectType::Node,
                XFA_Element::NumberSymbols,
                kNumberSymbolsPropertyData,
                {},
                std::make_unique<CJX_Node>(this)) {}

CXFA_NumberSymbols::~CXFA_NumberSymbols() = default;
