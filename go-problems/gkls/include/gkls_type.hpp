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

\authors Лебедев И.
\date 2015-2016
\copyright ННГУ им. Н.И. Лобачевского

\brief Объявление свойств для GKLS

*/

#include "types.h"
#include "gkls_function.hpp"

/**
Класс для перечисления типов задач GKLS
*/
template <class Owner>
class TEGKLSClass : public TParameterProperty<gkls::GKLSClass, Owner>
{
public:
  /// Базовые переопределения
  BasicMethods(TEGKLSClass, gkls::GKLSClass);

  TEGKLSClass(gkls::GKLSClass value = gkls::Hard) :
      TParameterProperty<gkls::GKLSClass, Owner>(gkls::GKLSClass(value)) {}

  /// Парсер строки
  virtual void operator = (string data);

  /// Приведение к строке
  virtual operator string();
};

/**
Класс для перечисления типов задач GKLS
*/
template <class Owner>
class TEGKLSFuncionType : public TParameterProperty<gkls::GKLSFuncionType, Owner>
{
public:
  /// Базовые переопределения
  BasicMethods(TEGKLSFuncionType, gkls::GKLSFuncionType);

  TEGKLSFuncionType(gkls::GKLSFuncionType value = gkls::TD) :
      TParameterProperty<gkls::GKLSFuncionType, Owner>(gkls::GKLSFuncionType(value)) {}

  /// Парсер строки
  virtual void operator = (string data);

  /// Приведение к строке
  virtual operator string();
};



/* ======================================================================== *\
**  Реализация методов класса     TEGKLSFuncionType                         **
\* ======================================================================== */
  //enum GKLSClass { Hard, Simple };
  //enum gkls::GKLSFuncionType { TND, TD, TD2 };

/// Парсер строки
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

/// Приведение к строке
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
**  Реализация методов класса     TEGKLSClass                               **
\* ======================================================================== */
  //enum GKLSClass { Hard, Simple };
  //enum GKLSFuncionType { TND, TD, TD2 };

/// Парсер строки
template <class Owner>
void TEGKLSClass<Owner>::operator = (string data)
{
  if ((data == "Hard") || (data == "0"))
    *this = gkls::Hard;
  if ((data == "Simple") || (data == "1"))
    *this = gkls::Simple;
}

/// Приведение к строке
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
