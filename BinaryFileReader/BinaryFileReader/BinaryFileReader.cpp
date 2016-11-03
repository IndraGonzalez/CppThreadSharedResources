#include "BinaryFileReader.h"

BinaryFileReader::BinaryFileReader(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	reader = new Reader(this);
	reader->start();
}
