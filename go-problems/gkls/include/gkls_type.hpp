/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//             LOBACHEVSKY STATE UNIVERSITY OF NIZHNY NOVGOROD             //
//                                                                         //
//                       Copyright (c) 2016 by UNN.                        //
//                          All Rights Reserved.                           //
//                                                                         //
//  File:      gkls_type.h                                                 //
//                                                                         //
//  Purpose:   Header file GKLS property types                             //
//                                                                         //
//  Author(s): Lebedev I.                                                  //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#ifndef __GKLS_TYPE_H__
#define __GKLS_TYPE_H__

/**
\file gkls_type.h

\authors ������� �.
\date 2015-2016
\copyright ���� ��. �.�. ������������

\brief ���������� ������� ��� GKLS

*/

#include "types.h"
#include "gkls_function.hpp"

/**
����� ��� ������������ ����� ����� GKLS
*/
template <class Owner>
class TEGKLSClass : public TParameterProperty<gkls::GKLSClass, Owner>
{
public:
  /// ������� ���������������
  BasicMethods(TEGKLSClass, gkls::GKLSClass);

  TEGKLSClass(gkls::GKLSClass value = gkls::Hard) :
      TParameterProperty<gkls::GKLSClass, Owner>(gkls::GKLSClass(value)) {}

  /// ������ ������
  virtual void operator = (string data);

  /// ���������� � ������
  virtual operator string();
};

/**
����� ��� ������������ ����� ����� GKLS
*/
template <class Owner>
class TEGKLSFuncionType : public TParameterProperty<gkls::GKLSFuncionType, Owner>
{
public:
  /// ������� ���������������
  BasicMethods(TEGKLSFuncionType, gkls::GKLSFuncionType);

  TEGKLSFuncionType(gkls::GKLSFuncionType value = gkls::TD) :
      TParameterProperty<gkls::GKLSFuncionType, Owner>(gkls::GKLSFuncionType(value)) {}

  /// ������ ������
  virtual void operator = (string data);

  /// ���������� � ������
  virtual operator string();
};



/* ======================================================================== *\
**  ���������� ������� ������     TEGKLSFuncionType                         **
\* ======================================================================== */
  //enum GKLSClass { Hard, Simple };
  //enum gkls::GKLSFuncionType { TND, TD, TD2 };

/// ������ ������
template <class Owner>
void TEGKLSFuncionType<Owner>::operator = (string data)
{
  if ((data == "TND") || (data == "0"))
    *this = gkls::TND;
  if ((data == "TD") || (data == "1"))
    *this = gkls::TD;
  if ((data == "TD2") || (data == "2"))
    *this = gkls::TD2;
}

/// ���������� � ������
template <class Owner>
TEGKLSFuncionType<Owner>::operator string()
{
  string s;
  if (this->mValue == gkls::TND)
    s = "TND";
  if (this->mValue == gkls::TD)
    s = "TD";
  if (this->mValue == gkls::TD2)
    s = "TD2";
  return s;
}


/* ======================================================================== *\
**  ���������� ������� ������     TEGKLSClass                               **
\* ======================================================================== */
  //enum GKLSClass { Hard, Simple };
  //enum GKLSFuncionType { TND, TD, TD2 };

/// ������ ������
template <class Owner>
void TEGKLSClass<Owner>::operator = (string data)
{
  if ((data == "Hard") || (data == "0"))
    *this = gkls::Hard;
  if ((data == "Simple") || (data == "1"))
    *this = gkls::Simple;
}

/// ���������� � ������
template <class Owner>
TEGKLSClass<Owner>::operator string()
{
  string s;
  if (this->mValue == gkls::Hard)
    s = "Hard";
  if (this->mValue == gkls::Simple)
    s = "Simple";
  return s;
}


#endif //__GKLS_TYPE_H__
// - end of file ----------------------------------------------------------------------------------
