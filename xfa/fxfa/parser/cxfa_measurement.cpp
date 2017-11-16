// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fxfa/parser/cxfa_measurement.h"

#include "core/fxcrt/fx_extension.h"

namespace {

constexpr float kPtToInch = 72;
constexpr float kPtToCm = kPtToInch / 2.54f;
constexpr float kPtToMm = kPtToCm / 10;
constexpr float kPtToMp = 0.001f;
constexpr float kPtToPc = 12;

}  // namespace

CXFA_Measurement::CXFA_Measurement(const WideStringView& wsMeasure) {
  SetString(wsMeasure);
}

CXFA_Measurement::CXFA_Measurement() {
  Set(-1, XFA_Unit::Unknown);
}

CXFA_Measurement::CXFA_Measurement(float fValue, XFA_Unit eUnit) {
  Set(fValue, eUnit);
}

void CXFA_Measurement::SetString(const WideStringView& wsMeasure) {
  if (wsMeasure.IsEmpty()) {
    m_fValue = 0;
    m_eUnit = XFA_Unit::Unknown;
    return;
  }
  int32_t iUsedLen = 0;
  int32_t iOffset = (wsMeasure[0] == L'=') ? 1 : 0;
  float fValue = FXSYS_wcstof(wsMeasure.unterminated_c_str() + iOffset,
                              wsMeasure.GetLength() - iOffset, &iUsedLen);
  XFA_Unit eUnit = GetUnitFromString(
      wsMeasure.Right(wsMeasure.GetLength() - (iOffset + iUsedLen)));
  Set(fValue, eUnit);
}

WideString CXFA_Measurement::ToString() const {
  WideString wsMeasure;
  switch (GetUnit()) {
    case XFA_Unit::Mm:
      wsMeasure.Format(L"%.8gmm", GetValue());
      break;
    case XFA_Unit::Pt:
      wsMeasure.Format(L"%.8gpt", GetValue());
      break;
    case XFA_Unit::In:
      wsMeasure.Format(L"%.8gin", GetValue());
      break;
    case XFA_Unit::Cm:
      wsMeasure.Format(L"%.8gcm", GetValue());
      break;
    case XFA_Unit::Mp:
      wsMeasure.Format(L"%.8gmp", GetValue());
      break;
    case XFA_Unit::Pc:
      wsMeasure.Format(L"%.8gpc", GetValue());
      break;
    case XFA_Unit::Em:
      wsMeasure.Format(L"%.8gem", GetValue());
      break;
    case XFA_Unit::Percent:
      wsMeasure.Format(L"%.8g%%", GetValue());
      break;
    default:
      wsMeasure.Format(L"%.8g", GetValue());
      break;
  }
  return wsMeasure;
}

float CXFA_Measurement::ToUnit(XFA_Unit eUnit) const {
  float f;
  return ToUnitInternal(eUnit, &f) ? f : 0;
}

bool CXFA_Measurement::ToUnitInternal(XFA_Unit eUnit, float* fValue) const {
  *fValue = GetValue();
  XFA_Unit eFrom = GetUnit();
  if (eFrom == eUnit)
    return true;

  switch (eFrom) {
    case XFA_Unit::Pt:
      break;
    case XFA_Unit::Mm:
      *fValue *= kPtToMm;
      break;
    case XFA_Unit::In:
      *fValue *= kPtToInch;
      break;
    case XFA_Unit::Cm:
      *fValue *= kPtToCm;
      break;
    case XFA_Unit::Mp:
      *fValue *= kPtToMp;
      break;
    case XFA_Unit::Pc:
      *fValue *= kPtToPc;
      break;
    default:
      *fValue = 0;
      return false;
  }
  switch (eUnit) {
    case XFA_Unit::Pt:
      return true;
    case XFA_Unit::Mm:
      *fValue /= kPtToMm;
      return true;
    case XFA_Unit::In:
      *fValue /= kPtToInch;
      return true;
    case XFA_Unit::Cm:
      *fValue /= kPtToCm;
      return true;
    case XFA_Unit::Mp:
      *fValue /= kPtToMp;
      return true;
    case XFA_Unit::Pc:
      *fValue /= kPtToPc;
      return true;
    default:
      NOTREACHED();
      return false;
  }
}

// static
XFA_Unit CXFA_Measurement::GetUnitFromString(const WideStringView& wsUnit) {
  if (wsUnit == L"mm")
    return XFA_Unit::Mm;
  if (wsUnit == L"pt")
    return XFA_Unit::Pt;
  if (wsUnit == L"in")
    return XFA_Unit::In;
  if (wsUnit == L"cm")
    return XFA_Unit::Cm;
  if (wsUnit == L"pc")
    return XFA_Unit::Pc;
  if (wsUnit == L"mp")
    return XFA_Unit::Mp;
  if (wsUnit == L"em")
    return XFA_Unit::Em;
  if (wsUnit == L"%")
    return XFA_Unit::Percent;
  return XFA_Unit::Unknown;
}
