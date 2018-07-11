/****************************************************************************
**
** Copyright (C) 2018 N7 Space sp. z o. o.
** Contact: http://n7space.com
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
#include "testgeneratorparamswidget.h"

using namespace Asn1Acn::Internal::TestGenerator;

TestGeneratorWidget::TestGeneratorWidget(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);
    m_ui.pathChooser->setExpectedKind(Utils::PathChooser::ExistingDirectory);
}

QString TestGeneratorWidget::path() const
{
    return m_ui.pathChooser->path();
}

void TestGeneratorWidget::setPath(const QString &path)
{
    m_ui.pathChooser->setPath(path);
}

QString TestGeneratorWidget::mainStruct() const
{
    return m_ui.comboBox->currentText();
}

void TestGeneratorWidget::addMainStructCandidate(const QString &mainStruct)
{
    m_ui.comboBox->addItem(mainStruct);
}

void TestGeneratorWidget::clearMainStructCandidates()
{
    m_ui.comboBox->clear();
}
