#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BinaryFileReader.h"
#include "Reader.h"

class BinaryFileReader : public QMainWindow
{
    Q_OBJECT

public:
    BinaryFileReader(QWidget *parent = Q_NULLPTR);

private:
    Ui::BinaryFileReaderClass ui;
	Reader* reader;
};
