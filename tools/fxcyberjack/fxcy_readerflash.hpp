/***************************************************************************
    begin       : Thu Mar 26 2009
    copyright   : (C) 2009 by Martin Preuss
    email       : martin@libchipcard.de

 ***************************************************************************
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston,                 *
 *   MA  02111-1307  USA                                                   *
 *                                                                         *
 ***************************************************************************/


#ifndef FXCY_READERFLASH_HPP
#define FXCY_READERFLASH_HPP

#include <fx.h>

#include "libcyberjack/driver.hpp"

class FXCY_App;


class FXCY_ReaderFlash: public FXDialogBox {
  FXDECLARE(FXCY_ReaderFlash)

protected:
  FXCY_ReaderFlash();

public:

  enum {
    ID_EDIT_MODULE=FXDialogBox::ID_LAST,
    ID_BUTTON_MODUL,
    ID_EDIT_SIGNATURE,
    ID_BUTTON_SIGNATURE,
    ID_LAST
  };

  long onCmdAccept(FXObject*, FXSelector, void *ptr);
  long onCmdReject(FXObject*, FXSelector, void *ptr);

  long onCmdButtonModule(FXObject*, FXSelector, void *ptr);
  long onCmdButtonSignature(FXObject*, FXSelector, void *ptr);


  FXCY_ReaderFlash(Cyberjack::Reader *r,
                   FXWindow *owner,
                   const FXString& name,
                   FXuint opts=0,
                   FXint x=0, FXint y=0, FXint w=0, FXint h=0);
  ~FXCY_ReaderFlash();

  void create();

  FXString getModuleFile() const;
  FXString getSignatureFile() const;

protected:
  Cyberjack::Reader *m_reader;
  FXTextField *m_editModuleFile;
  FXTextField *m_editSignatureFile;

  FXString m_lastPath;
};


#endif



