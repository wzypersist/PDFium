// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_xfa.h"

#include "fxjs/xfa/cjx_xfa.h"

namespace {

const CXFA_Node::AttributeData kXfaAttributeData[] = {
    {XFA_Attribute::TimeStamp, XFA_AttributeType::CData, nullptr},
    {XFA_Attribute::Uuid, XFA_AttributeType::CData, nullptr},
};

}  // namespace

CXFA_Xfa::CXFA_Xfa(CXFA_Document* doc, XFA_PacketType packet)
    : CXFA_Node(doc,
                packet,
                XFA_XDPPACKET_XDP,
                XFA_ObjectType::ModelNode,
                XFA_Element::Xfa,
                {},
                kXfaAttributeData,
                std::make_unique<CJX_Xfa>(this)) {}

CXFA_Xfa::~CXFA_Xfa() = default;
