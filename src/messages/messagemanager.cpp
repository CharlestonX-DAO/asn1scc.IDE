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

#include "messagemanager.h"

#include <QDateTime>

#include <coreplugin/messagemanager.h>

using namespace Asn1Acn::Internal;
using namespace Asn1Acn::Internal::Messages;

namespace {
QString currentTime()
{
    return QDateTime::currentDateTime().toString("hh:mm:ss.zzz ");
}

QString prefix(MessageManager::Type type)
{
    QString typeName;
    switch (type) {
    case MessageManager::Type::Process:
        typeName = "Process:";
        break;
    case MessageManager::Type::Communication:
        typeName = "Communication:";
        break;
    case MessageManager::Type::Metadata:
        typeName = "Metadata:";
        break;
    }

    return QString("ASN1ACN: " + typeName + "    ");
}

QString decorateMessage(const QString &message, MessageManager::Type type)
{
    return currentTime() + prefix(type) + message;
}
} // namespace

void MessageManager::write(const QString &message, MessageManager::Type type)
{
    Core::MessageManager::writeSilently(decorateMessage(message, type));
}
