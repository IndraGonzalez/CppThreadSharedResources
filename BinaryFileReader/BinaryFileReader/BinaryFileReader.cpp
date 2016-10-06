#include "BinaryFileReader.h"

BinaryFileReader::BinaryFileReader(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	reader = new Reader(this);

	connect(ui.startButton, SIGNAL(clicked()), reader, SLOT(start()));
	connect(ui.stopButton, SIGNAL(clicked()), reader, SLOT(stop()));
}
