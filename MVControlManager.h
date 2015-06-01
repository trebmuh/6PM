/*
    6PM
     Copyright (c) 2015, Michel Vergnaud

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MVCONTROLMANAGER_H
#define MVCONTROLMANAGER_H

#include "MVGlobals.h"

#include <QMap>

class MVController;

class MVControlManager
{
public:
    MVControlManager();

    void processCC(unsigned char controlNum, unsigned char param);
    void setMidiLearning(bool b, MVController * c);
    bool isMidiLearning();
    MVController * controllerLearning();

    QList<MVController *> getControllers(int);
    int getAssignNum( MVController*) const;
    void registerAssign(int, MVController*);
    void removeAssign( MVController*);

private:
    QMultiMap<int, MVController *> assignMap;
    bool bMidiLearning;
    MVController * ctrLearning;
};

#endif // MVCONTROLMANAGER_H
