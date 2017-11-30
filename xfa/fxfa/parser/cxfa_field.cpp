// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_field.h"

namespace {

const CXFA_Node::PropertyData kPropertyData[] = {
    {XFA_Element::Ui, 1, 0},        {XFA_Element::Margin, 1, 0},
    {XFA_Element::Para, 1, 0},      {XFA_Element::Format, 1, 0},
    {XFA_Element::Border, 1, 0},    {XFA_Element::Assist, 1, 0},
    {XFA_Element::Traversal, 1, 0}, {XFA_Element::Keep, 1, 0},
    {XFA_Element::Validate, 1, 0},  {XFA_Element::Caption, 1, 0},
    {XFA_Element::Bind, 1, 0},      {XFA_Element::Desc, 1, 0},
    {XFA_Element::Font, 1, 0},      {XFA_Element::Value, 1, 0},
    {XFA_Element::Calculate, 1, 0}, {XFA_Element::Extras, 1, 0},
    {XFA_Element::Items, 2, 0},     {XFA_Element::Unknown, 0, 0}};
const CXFA_Node::AttributeData kAttributeData[] = {
    {XFA_Attribute::H, XFA_AttributeType::Measure,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)L"0in"},
    {XFA_Attribute::W, XFA_AttributeType::Measure,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)L"0in"},
    {XFA_Attribute::X, XFA_AttributeType::Measure,
     XFA_XDPPACKET_Config | XFA_XDPPACKET_Template | XFA_XDPPACKET_Form,
     (void*)L"0in"},
    {XFA_Attribute::Y, XFA_AttributeType::Measure,
     XFA_XDPPACKET_Config | XFA_XDPPACKET_Template | XFA_XDPPACKET_Form,
     (void*)L"0in"},
    {XFA_Attribute::Id, XFA_AttributeType::CData,
     XFA_XDPPACKET_SourceSet | XFA_XDPPACKET_Template |
         XFA_XDPPACKET_ConnectionSet | XFA_XDPPACKET_Form,
     nullptr},
    {XFA_Attribute::HAlign, XFA_AttributeType::Enum,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form,
     (void*)XFA_ATTRIBUTEENUM_Left},
    {XFA_Attribute::Name, XFA_AttributeType::CData,
     XFA_XDPPACKET_SourceSet | XFA_XDPPACKET_Config | XFA_XDPPACKET_LocaleSet |
         XFA_XDPPACKET_Template | XFA_XDPPACKET_Datasets | XFA_XDPPACKET_Form |
         XFA_XDPPACKET_ConnectionSet | XFA_XDPPACKET_Form,
     nullptr},
    {XFA_Attribute::Use, XFA_AttributeType::CData,
     XFA_XDPPACKET_SourceSet | XFA_XDPPACKET_Template |
         XFA_XDPPACKET_ConnectionSet | XFA_XDPPACKET_Form,
     nullptr},
    {XFA_Attribute::Access, XFA_AttributeType::Enum,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form,
     (void*)XFA_ATTRIBUTEENUM_Open},
    {XFA_Attribute::Rotate, XFA_AttributeType::Integer,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)0},
    {XFA_Attribute::Presence, XFA_AttributeType::Enum,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form,
     (void*)XFA_ATTRIBUTEENUM_Visible},
    {XFA_Attribute::VAlign, XFA_AttributeType::Enum,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)XFA_ATTRIBUTEENUM_Top},
    {XFA_Attribute::MaxH, XFA_AttributeType::Measure,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)L"0in"},
    {XFA_Attribute::MaxW, XFA_AttributeType::Measure,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)L"0in"},
    {XFA_Attribute::MinH, XFA_AttributeType::Measure,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)L"0in"},
    {XFA_Attribute::MinW, XFA_AttributeType::Measure,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)L"0in"},
    {XFA_Attribute::Relevant, XFA_AttributeType::CData,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, nullptr},
    {XFA_Attribute::ColSpan, XFA_AttributeType::Integer,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)1},
    {XFA_Attribute::Usehref, XFA_AttributeType::CData,
     XFA_XDPPACKET_SourceSet | XFA_XDPPACKET_Template |
         XFA_XDPPACKET_ConnectionSet | XFA_XDPPACKET_Form,
     nullptr},
    {XFA_Attribute::Locale, XFA_AttributeType::CData,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, nullptr},
    {XFA_Attribute::AnchorType, XFA_AttributeType::Enum,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form,
     (void*)XFA_ATTRIBUTEENUM_TopLeft},
    {XFA_Attribute::AccessKey, XFA_AttributeType::CData,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, nullptr},
    {XFA_Attribute::Unknown, XFA_AttributeType::Integer, 0, nullptr}};

constexpr wchar_t kName[] = L"field";

}  // namespace

CXFA_Field::CXFA_Field(CXFA_Document* doc, XFA_XDPPACKET packet)
    : CXFA_Node(doc,
                packet,
                (XFA_XDPPACKET_Template | XFA_XDPPACKET_Form),
                XFA_ObjectType::ContainerNode,
                XFA_Element::Field,
                kPropertyData,
                kAttributeData,
                kName) {}

CXFA_Field::~CXFA_Field() {}
