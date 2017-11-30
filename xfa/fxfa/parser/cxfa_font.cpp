// Copyright 2017 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_font.h"

namespace {

const CXFA_Node::PropertyData kPropertyData[] = {{XFA_Element::Fill, 1, 0},
                                                 {XFA_Element::Extras, 1, 0},
                                                 {XFA_Element::Unknown, 0, 0}};
const CXFA_Node::AttributeData kAttributeData[] = {
    {XFA_Attribute::Id, XFA_AttributeType::CData,
     XFA_XDPPACKET_SourceSet | XFA_XDPPACKET_Template |
         XFA_XDPPACKET_ConnectionSet | XFA_XDPPACKET_Form,
     nullptr},
    {XFA_Attribute::LineThrough, XFA_AttributeType::Integer,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)0},
    {XFA_Attribute::Typeface, XFA_AttributeType::CData,
     XFA_XDPPACKET_Config | XFA_XDPPACKET_Template | XFA_XDPPACKET_Form,
     (void*)L"Courier"},
    {XFA_Attribute::FontHorizontalScale, XFA_AttributeType::CData,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)L"100%"},
    {XFA_Attribute::Use, XFA_AttributeType::CData,
     XFA_XDPPACKET_SourceSet | XFA_XDPPACKET_Template |
         XFA_XDPPACKET_ConnectionSet | XFA_XDPPACKET_Form,
     nullptr},
    {XFA_Attribute::KerningMode, XFA_AttributeType::Enum,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form,
     (void*)XFA_ATTRIBUTEENUM_None},
    {XFA_Attribute::Underline, XFA_AttributeType::Integer,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)0},
    {XFA_Attribute::BaselineShift, XFA_AttributeType::Measure,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)L"0in"},
    {XFA_Attribute::OverlinePeriod, XFA_AttributeType::Enum,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)XFA_ATTRIBUTEENUM_All},
    {XFA_Attribute::LetterSpacing, XFA_AttributeType::CData,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, nullptr},
    {XFA_Attribute::LineThroughPeriod, XFA_AttributeType::Enum,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)XFA_ATTRIBUTEENUM_All},
    {XFA_Attribute::FontVerticalScale, XFA_AttributeType::CData,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)L"100%"},
    {XFA_Attribute::PsName, XFA_AttributeType::CData, XFA_XDPPACKET_Config,
     nullptr},
    {XFA_Attribute::Size, XFA_AttributeType::Measure,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)L"10pt"},
    {XFA_Attribute::Posture, XFA_AttributeType::Enum,
     XFA_XDPPACKET_Config | XFA_XDPPACKET_Template | XFA_XDPPACKET_Form,
     (void*)XFA_ATTRIBUTEENUM_Normal},
    {XFA_Attribute::Usehref, XFA_AttributeType::CData,
     XFA_XDPPACKET_SourceSet | XFA_XDPPACKET_Template |
         XFA_XDPPACKET_ConnectionSet | XFA_XDPPACKET_Form,
     nullptr},
    {XFA_Attribute::Weight, XFA_AttributeType::Enum,
     XFA_XDPPACKET_Config | XFA_XDPPACKET_Template | XFA_XDPPACKET_Form,
     (void*)XFA_ATTRIBUTEENUM_Normal},
    {XFA_Attribute::UnderlinePeriod, XFA_AttributeType::Enum,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)XFA_ATTRIBUTEENUM_All},
    {XFA_Attribute::Overline, XFA_AttributeType::Integer,
     XFA_XDPPACKET_Template | XFA_XDPPACKET_Form, (void*)0},
    {XFA_Attribute::GenericFamily, XFA_AttributeType::Enum,
     XFA_XDPPACKET_Config, (void*)XFA_ATTRIBUTEENUM_Serif},
    {XFA_Attribute::Unknown, XFA_AttributeType::Integer, 0, nullptr}};

constexpr wchar_t kName[] = L"font";

}  // namespace

CXFA_Font::CXFA_Font(CXFA_Document* doc, XFA_XDPPACKET packet)
    : CXFA_Node(
          doc,
          packet,
          (XFA_XDPPACKET_Template | XFA_XDPPACKET_Config | XFA_XDPPACKET_Form),
          XFA_ObjectType::Node,
          XFA_Element::Font,
          kPropertyData,
          kAttributeData,
          kName) {}

CXFA_Font::~CXFA_Font() {}
