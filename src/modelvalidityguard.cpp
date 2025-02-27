/****************************************************************************
**
** Copyright (C) 2017-2022 N7 Space sp. z o. o.
** Contact: https://n7space.com
**
** This file is part of ASN.1/ACN Plugin for QtCreator.
**
** Plugin was developed under a programme and funded by
** European Space Agency.
**
** This Plugin is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This Plugin is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#include "modelvalidityguard.h"

#include "parseddatastorage.h"

using namespace Asn1Acn::Internal;

ModelValidityGuard *ModelValidityGuard::instance()
{
    static ModelValidityGuard instance_;
    return &instance_;
}

ModelValidityGuard::ModelValidityGuard()
    : m_modifiersCnt(0)
{}

bool ModelValidityGuard::isValid() const
{
    QMutexLocker locker(&m_dataMutex);

    return m_modifiersCnt == 0;
}

void ModelValidityGuard::invalidate()
{
    QMutexLocker locker(&m_dataMutex);

    m_modifiersCnt++;

    emit modelAboutToChange();
}

void ModelValidityGuard::validate()
{
    {
        QMutexLocker locker(&m_dataMutex);

        m_modifiersCnt--;
        if (m_modifiersCnt != 0)
            return;
    }

    ParsedDataStorage::instance()->resetProjectBuildersCount();
    emit modelChanged();
}
